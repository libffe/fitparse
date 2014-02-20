////////////////////////////////////////////////////////////////////////////////
// The following FIT Protocol software provided may be used with FIT protocol
// devices only and remains the copyrighted property of Dynastream Innovations Inc.
// The software is being provided on an "as-is" basis and as an accommodation,
// and therefore all warranties, representations, or guarantees of any kind
// (whether express, implied or statutory) including, without limitation,
// warranties of merchantability, non-infringement, or fitness for a particular
// purpose, are specifically disclaimed.
//
// Copyright 2014 Dynastream Innovations Inc.
////////////////////////////////////////////////////////////////////////////////


#include <string.h>

#include "fit_convert.h"
#include "fit_crc.h"

//////////////////////////////////////////////////////////////////////////////////
// Private Variables
//////////////////////////////////////////////////////////////////////////////////

#if !defined(FIT_CONVERT_MULTI_THREAD)
   static FIT_CONVERT_STATE state_struct;
   #define state  (&state_struct)
#endif

//////////////////////////////////////////////////////////////////////////////////
// Public Functions
//////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
#if defined(FIT_CONVERT_MULTI_THREAD)
   void FitConvert_Init(FIT_CONVERT_STATE *state, FIT_BOOL read_file_header)
#else
   void FitConvert_Init(FIT_BOOL read_file_header)
#endif
{
   state->mesg_offset = 0;
   state->data_offset = 0;

#if defined(FIT_CONVERT_CHECK_CRC)
   state->crc = 0;
#endif
#if defined(FIT_CONVERT_TIME_RECORD)
   state->timestamp = 0;
   state->last_time_offset = 0;
#endif

   if (read_file_header)
   {
      state->file_bytes_left = 3; // Header size byte + CRC.
      state->decode_state = FIT_CONVERT_DECODE_FILE_HDR;
   }
   else
   {
      state->file_bytes_left = 0; // Don't read header or check CRC.
      state->decode_state = FIT_CONVERT_DECODE_RECORD;
   }
}

///////////////////////////////////////////////////////////////////////
#if defined(FIT_CONVERT_MULTI_THREAD)
   FIT_CONVERT_RETURN FitConvert_Read(FIT_CONVERT_STATE *state, const void *data, FIT_UINT32 size)
#else
   FIT_CONVERT_RETURN FitConvert_Read(const void *data, FIT_UINT32 size)
#endif
{
   while (state->data_offset < size)
   {
      FIT_UINT8 datum = *((FIT_UINT8 *) data + state->data_offset);
      state->data_offset++;

      //printf("fit_convert: 0x%02X - %d\n",datum, state->decode_state);

      if (state->file_bytes_left > 0)
      {
         #if defined(FIT_CONVERT_CHECK_CRC)
            state->crc = FitCRC_Get16(state->crc, datum);
         #endif

         state->file_bytes_left--;

         if (state->file_bytes_left == 1) // CRC low byte.
         {
            if (state->decode_state != FIT_CONVERT_DECODE_RECORD)
               return FIT_CONVERT_ERROR;

            continue; // Next byte.
         }
         else if (state->file_bytes_left == 0) // CRC high byte.
         {
            #if defined(FIT_CONVERT_CHECK_CRC)
               if (state->crc != 0)
                  return FIT_CONVERT_ERROR;
            #endif

            return FIT_CONVERT_END_OF_FILE;
         }
      }

      switch (state->decode_state)
      {
         case FIT_CONVERT_DECODE_FILE_HDR:
            if (state->mesg_offset < FIT_FILE_HDR_SIZE)
               *((FIT_UINT8 *) &state->u.file_hdr + state->mesg_offset) = datum;

            if (state->mesg_offset == 0)
               state->file_bytes_left = state->u.file_hdr.header_size + 2; // Increase to read header and CRC.

            state->mesg_offset++;

            if (state->mesg_offset >= state->u.file_hdr.header_size)
            {
               state->file_bytes_left = *((FIT_UINT8 *) &state->u.file_hdr.data_size);
               state->file_bytes_left |= (FIT_UINT32)*((FIT_UINT8 *) &state->u.file_hdr.data_size + 1) << 8;
               state->file_bytes_left |= (FIT_UINT32)*((FIT_UINT8 *) &state->u.file_hdr.data_size + 2) << 16;
               state->file_bytes_left |= (FIT_UINT32)*((FIT_UINT8 *) &state->u.file_hdr.data_size + 3) << 24;
               state->file_bytes_left += 2; // CRC.

               #if defined(FIT_CONVERT_CHECK_FILE_HDR_DATA_TYPE)
                  if (memcmp(state->u.file_hdr.data_type, ".FIT", 4) != 0)
                     return FIT_CONVERT_DATA_TYPE_NOT_SUPPORTED;
               #endif

               if ((state->u.file_hdr.protocol_version & FIT_PROTOCOL_VERSION_MAJOR_MASK) > (FIT_PROTOCOL_VERSION_MAJOR << FIT_PROTOCOL_VERSION_MAJOR_SHIFT))
                  return FIT_CONVERT_PROTOCOL_VERSION_NOT_SUPPORTED;

               state->decode_state = FIT_CONVERT_DECODE_RECORD;
            }
            break;

         case FIT_CONVERT_DECODE_RECORD:
            if (datum & FIT_HDR_TIME_REC_BIT)
            {
               // This is a message data record with time.
               state->mesg_index = (datum & FIT_HDR_TIME_TYPE_MASK) >> FIT_HDR_TIME_TYPE_SHIFT;

               #if defined(FIT_CONVERT_TIME_RECORD)
                  {
                     FIT_UINT8 time_offset = datum & FIT_HDR_TIME_OFFSET_MASK;
                     state->timestamp += (time_offset - state->last_time_offset) & FIT_HDR_TIME_OFFSET_MASK;
                     state->last_time_offset = time_offset;
                  }
               #endif

               state->decode_state = FIT_CONVERT_DECODE_FIELD_DATA;
            }
            else
            {
               state->mesg_index = datum & FIT_HDR_TYPE_MASK;

               if ((datum & FIT_HDR_TYPE_DEF_BIT) == 0)
               {
                  // This is a message data record.
                  state->decode_state = FIT_CONVERT_DECODE_FIELD_DATA;
               }
               else
               {
                  // This is a message definition record.
                  state->mesg_sizes[state->mesg_index] = 0;
                  state->decode_state = FIT_CONVERT_DECODE_RESERVED1;
               }
            }

            if (state->decode_state == FIT_CONVERT_DECODE_FIELD_DATA)
            {
               if (state->mesg_index < FIT_LOCAL_MESGS)
               {
                  state->mesg_def = Fit_GetMesgDef(state->convert_table[state->mesg_index].global_mesg_num);
                  Fit_InitMesg(state->mesg_def, state->u.mesg);

                  #if defined(FIT_CONVERT_TIME_RECORD)
                     if (datum & FIT_HDR_TIME_REC_BIT)
                     {
                        FIT_UINT8 field_offset = Fit_GetFieldOffset(state->mesg_def, FIT_FIELD_NUM_TIMESTAMP);

                        if (field_offset != FIT_UINT8_INVALID)
                           memcpy(&state->u.mesg[field_offset], &state->timestamp, sizeof(state->timestamp));
                     }
                  #endif
               }

               if (state->mesg_sizes[state->mesg_index] == 0)
                  state->decode_state = FIT_CONVERT_DECODE_RECORD;
            }

            state->mesg_offset = 0; // Reset the message byte count.
            state->field_index = 0;
            state->field_offset = 0;
            break;

         case FIT_CONVERT_DECODE_RESERVED1:
            if (state->mesg_index < FIT_LOCAL_MESGS)
               state->convert_table[state->mesg_index].reserved_1 = datum;

            state->decode_state = FIT_CONVERT_DECODE_ARCH;
            break;

         case FIT_CONVERT_DECODE_ARCH:
            if (state->mesg_index < FIT_LOCAL_MESGS)
               state->convert_table[state->mesg_index].arch = datum;

            state->decode_state = FIT_CONVERT_DECODE_GTYPE_1;
            break;

         case FIT_CONVERT_DECODE_GTYPE_1:
            if (state->mesg_index < FIT_LOCAL_MESGS)
               state->convert_table[state->mesg_index].global_mesg_num = datum;

            state->decode_state = FIT_CONVERT_DECODE_GTYPE_2;
            break;

         case FIT_CONVERT_DECODE_GTYPE_2:
            if (state->mesg_index < FIT_LOCAL_MESGS)
            {
               if ((state->convert_table[state->mesg_index].arch & FIT_ARCH_ENDIAN_MASK) == FIT_ARCH_ENDIAN_BIG)
               {
                  state->convert_table[state->mesg_index].global_mesg_num <<= 8;
                  state->convert_table[state->mesg_index].global_mesg_num |= datum;
               }
               else
               {
                  state->convert_table[state->mesg_index].global_mesg_num |= ((FIT_UINT16) datum << 8);
               }

               state->convert_table[state->mesg_index].num_fields = 0; // Initialize.
               state->mesg_def = Fit_GetMesgDef(state->convert_table[state->mesg_index].global_mesg_num);
            }

            state->decode_state = FIT_CONVERT_DECODE_NUM_FIELD_DEFS;
            break;

         case FIT_CONVERT_DECODE_NUM_FIELD_DEFS:
            state->num_fields = datum;

            if (state->num_fields == 0)
            {
               state->decode_state = FIT_CONVERT_DECODE_RECORD;
               break;
            }

            state->field_index = 0;
            state->decode_state = FIT_CONVERT_DECODE_FIELD_DEF;
            break;

         case FIT_CONVERT_DECODE_FIELD_DEF:
            state->field_num = FIT_FIELD_NUM_INVALID;

            if (state->mesg_index < FIT_LOCAL_MESGS)
            {
               if (state->mesg_def != FIT_NULL)
               {
                  FIT_UINT8 local_field_index;
                  FIT_UINT8 local_field_offset = 0;

                  // Search for the field definition in the local mesg definition.
                  for (local_field_index = 0; local_field_index < state->mesg_def->num_fields; local_field_index++)
                  {
                     FIT_UINT8 field_size = state->mesg_def->fields[FIT_MESG_DEF_FIELD_OFFSET(size, local_field_index)];

                     if (state->mesg_def->fields[FIT_MESG_DEF_FIELD_OFFSET(field_def_num, local_field_index)] == datum)
                     {
                        state->field_num = datum;
                        state->convert_table[state->mesg_index].fields[state->convert_table[state->mesg_index].num_fields].offset_in = state->mesg_offset;
                        state->convert_table[state->mesg_index].fields[state->convert_table[state->mesg_index].num_fields].offset_local = local_field_offset;
                        state->convert_table[state->mesg_index].fields[state->convert_table[state->mesg_index].num_fields].size = field_size;
                        break;
                     }

                     local_field_offset += field_size;
                  }
               }
            }

            state->decode_state = FIT_CONVERT_DECODE_FIELD_DEF_SIZE;
            break;

         case FIT_CONVERT_DECODE_FIELD_DEF_SIZE:
            if (state->mesg_index < FIT_LOCAL_MESGS)
            {
               state->mesg_offset += datum;

               if (state->field_num != FIT_FIELD_NUM_INVALID)
               {
                  if (datum < state->convert_table[state->mesg_index].fields[state->convert_table[state->mesg_index].num_fields].size)
                     state->convert_table[state->mesg_index].fields[state->convert_table[state->mesg_index].num_fields].size = datum;
               }
            }

            state->mesg_sizes[state->mesg_index] += datum;

            state->decode_state = FIT_CONVERT_DECODE_FIELD_BASE_TYPE;
            break;

         case FIT_CONVERT_DECODE_FIELD_BASE_TYPE:
            if (state->field_num != FIT_FIELD_NUM_INVALID)
            {
               state->convert_table[state->mesg_index].fields[state->convert_table[state->mesg_index].num_fields].base_type = datum;
               state->convert_table[state->mesg_index].num_fields++;
            }

            state->field_index++;

            if (state->field_index >= state->num_fields)
               state->decode_state = FIT_CONVERT_DECODE_RECORD;
            else
               state->decode_state = FIT_CONVERT_DECODE_FIELD_DEF;
            break;

         case FIT_CONVERT_DECODE_FIELD_DATA:
            state->mesg_offset++;

            if (state->mesg_offset >= state->mesg_sizes[state->mesg_index])
            {
               state->decode_state = FIT_CONVERT_DECODE_RECORD;
            }

            if (state->mesg_index < FIT_LOCAL_MESGS)
            {
               if ((state->mesg_def != FIT_NULL) && (state->field_index < state->convert_table[state->mesg_index].num_fields))
               {
                  if (state->mesg_offset == (state->convert_table[state->mesg_index].fields[state->field_index].offset_in + state->field_offset + 1))
                  {
                     FIT_UINT8 *field = &state->u.mesg[state->convert_table[state->mesg_index].fields[state->field_index].offset_local];

                     field[state->field_offset] = datum; // Store the incoming byte in the local mesg buffer.
                     state->field_offset++;

                     if (state->field_offset >= state->convert_table[state->mesg_index].fields[state->field_index].size)
                     {
                        if (
                              (state->convert_table[state->mesg_index].fields[state->field_index].base_type & FIT_BASE_TYPE_ENDIAN_FLAG) &&
                              ((state->convert_table[state->mesg_index].arch & FIT_ARCH_ENDIAN_MASK) != (Fit_GetArch() & FIT_ARCH_ENDIAN_MASK))
                           )
                        {
                           FIT_UINT8 type_size;
                           FIT_UINT8 element_size;
                           FIT_UINT8 element;
                           FIT_UINT8 index;

                           index = state->convert_table[state->mesg_index].fields[state->field_index].base_type & FIT_BASE_TYPE_NUM_MASK;

                           if (index >= FIT_BASE_TYPES)
                              return FIT_CONVERT_ERROR;

                           type_size = fit_base_type_sizes[index];
                           element_size = state->convert_table[state->mesg_index].fields[state->field_index].size / type_size;

                           for (element = 0; element < element_size; element++)
                           {
                              for (index = 0; index < (type_size / 2); index++)
                              {
                                 FIT_UINT8 tmp = field[element * type_size + index];
                                 field[element * type_size + index] = field[element * type_size + type_size - 1 - index];
                                 field[element * type_size + type_size - 1 - index] = tmp;
                              }
                           }
                        }

                        // Null terminate last character if multi-byte beyond end of field.
                        if (state->convert_table[state->mesg_index].fields[state->field_index].base_type == FIT_BASE_TYPE_STRING)
                        {
                           FIT_UINT8 length = state->convert_table[state->mesg_index].fields[state->field_index].size;
                           FIT_UINT8 index = 0;

                           while (index < length)
                           {
                              FIT_UINT8 char_size;
                              FIT_UINT8 size_mask = 0x80;

                              if (field[index] & size_mask)
                              {
                                 char_size = 0;

                                 while (field[index] & size_mask) // # of bytes in character = # of MSBits
                                 {
                                    char_size++;
                                    size_mask >>= 1;
                                 }
                              }
                              else
                              {
                                 char_size = 1;
                              }

                              if ((FIT_UINT16)(index + char_size) > length)
                              {
                                 while (index < length)
                                 {
                                    field[index++] = 0;
                                 }
                                 break;
                              }

                              index += char_size;
                           }
                        }

                        state->field_offset = 0; // Reset the offset.
                        state->field_index++; // Move on to the next field.

                        if (state->field_index >= state->convert_table[state->mesg_index].num_fields)
                        {
                           #if defined(FIT_CONVERT_TIME_RECORD)
                              {
                                 FIT_UINT8 timestamp_offset = Fit_GetFieldOffset(state->mesg_def, FIT_FIELD_NUM_TIMESTAMP);

                                 if (timestamp_offset != FIT_UINT8_INVALID)
                                 {
                                    if (*((FIT_UINT32 *)&state->u.mesg[timestamp_offset]) != FIT_DATE_TIME_INVALID)
                                    {
                                       memcpy(&state->timestamp, &state->u.mesg[timestamp_offset], sizeof(state->timestamp));
                                       state->last_time_offset = (FIT_UINT8)(state->timestamp & FIT_HDR_TIME_OFFSET_MASK);
                                    }
                                 }
                              }
                           #endif

                           // We have successfully decoded a mesg.
                           return FIT_CONVERT_MESSAGE_AVAILABLE;
                        }
                     }
                  }
               }
            }
            break;

         default:
            // This shouldn't happen.
            return FIT_CONVERT_ERROR;
      }
   }

   state->data_offset = 0;
   return FIT_CONVERT_CONTINUE;
}

///////////////////////////////////////////////////////////////////////
#if defined(FIT_CONVERT_MULTI_THREAD)
   FIT_UINT16 FitConvert_GetMessageNumber(FIT_CONVERT_STATE *state)
#else
   FIT_UINT16 FitConvert_GetMessageNumber(void)
#endif
{
   return state->convert_table[state->mesg_index].global_mesg_num;
}

///////////////////////////////////////////////////////////////////////
#if defined(FIT_CONVERT_MULTI_THREAD)
   const FIT_UINT8 *FitConvert_GetMessageData(FIT_CONVERT_STATE *state)
#else
   const FIT_UINT8 *FitConvert_GetMessageData(void)
#endif
{
   return state->u.mesg;
}

///////////////////////////////////////////////////////////////////////
#if defined(FIT_CONVERT_MULTI_THREAD)
   void FitConvert_RestoreFields(FIT_CONVERT_STATE *state, const void *mesg)
#else
   void FitConvert_RestoreFields(const void *mesg)
#endif
{
   FIT_UINT8 offset = 0;
   FIT_UINT8 field_index;
   FIT_UINT8 convert_field;

   if (state->mesg_def == FIT_NULL)
      return;

   for (field_index = 0; field_index < state->mesg_def->num_fields; field_index++)
   {
      for (convert_field=0; convert_field < state->convert_table[state->mesg_index].num_fields; convert_field++)
      {
         if (state->convert_table[state->mesg_index].fields[convert_field].offset_local == offset)
            break;
      }

      if (convert_field == state->convert_table[state->mesg_index].num_fields)
         memcpy(&state->u.mesg[offset], &((FIT_UINT8 *)mesg)[offset], state->mesg_def->fields[FIT_MESG_DEF_FIELD_OFFSET(size, field_index)]);

      offset += state->mesg_def->fields[FIT_MESG_DEF_FIELD_OFFSET(size, field_index)];
   }
}
