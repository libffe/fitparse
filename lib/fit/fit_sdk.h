/**********
 * FIT CONFIG
 **********/
#define FIT_USE_STDINT_H // Define to use stdint.h types. By default size in bytes of integer types assumed to be char=1, short=2, long=4.

#define FIT_LOCAL_MESGS     16 // 1-16. Sets maximum number of local messages that can be decoded. Lower to minimize RAM requirements.
#define FIT_ARCH_ENDIAN     FIT_ARCH_ENDIAN_LITTLE   // Set to correct endian for build architecture.

#define FIT_CONVERT_CHECK_CRC // Define to check file crc.
//#define FIT_CONVERT_CHECK_FILE_HDR_DATA_TYPE // Define to check file header for FIT data type.  Verifies file is FIT format before starting decode.
#define FIT_CONVERT_TIME_RECORD // Define to support time records (compressed timestamp).
//#define FIT_CONVERT_MULTI_THREAD // Define to support multiple conversion threads.

/**********
 * FIT H
 **********/

#if defined(FIT_USE_STDINT_H)
   #include <stdint.h>
#else
   typedef unsigned char uint8_t;
   typedef signed char int8_t;
   typedef unsigned short uint16_t;
   typedef signed short int16_t;
   typedef unsigned long uint32_t;
   typedef signed long int32_t;
#endif

#if defined(__cplusplus)
   extern "C" {
#endif


///////////////////////////////////////////////////////////////////////
// Version
///////////////////////////////////////////////////////////////////////

#define FIT_PROTOCOL_VERSION_MAJOR           1 // Non-backwards compatible changes. Decode compatible with this version and earlier.
#define FIT_PROTOCOL_VERSION_MINOR           0 // Backwards compatible changes.
#define FIT_PROTOCOL_VERSION_MAJOR_SHIFT     4
#define FIT_PROTOCOL_VERSION_MAJOR_MASK      ((FIT_UINT8) (0x0F << FIT_PROTOCOL_VERSION_MAJOR_SHIFT))
#define FIT_PROTOCOL_VERSION_MINOR_MASK      ((FIT_UINT8) 0x0F)
#define FIT_PROTOCOL_VERSION                 ((FIT_UINT8) (FIT_PROTOCOL_VERSION_MAJOR << FIT_PROTOCOL_VERSION_MAJOR_SHIFT) | FIT_PROTOCOL_VERSION_MINOR)

#define FIT_PROFILE_VERSION_MAJOR            10
#define FIT_PROFILE_VERSION_MINOR            2
#define FIT_PROFILE_VERSION_SCALE			 100
#define FIT_PROFILE_VERSION					 ((FIT_UINT16) (FIT_PROFILE_VERSION_MAJOR * 100 + FIT_PROFILE_VERSION_MINOR))


///////////////////////////////////////////////////////////////////////
// Type Definitions
///////////////////////////////////////////////////////////////////////

#define FIT_ANTFS_FILE_DATA_TYPE    128

#define FIT_BASE_TYPE_ENDIAN_FLAG   ((FIT_UINT8)0x80)
#define FIT_BASE_TYPE_RESERVED      ((FIT_UINT8)0x60)
#define FIT_BASE_TYPE_NUM_MASK      ((FIT_UINT8)0x1F)

typedef uint8_t FIT_ENUM;
typedef const FIT_ENUM * FIT_CONST_ENUM_PTR;
#define FIT_ENUM_INVALID            ((FIT_ENUM)0xFF)
#define FIT_BASE_TYPE_ENUM          ((FIT_UINT8)0x00)

typedef int8_t FIT_SINT8;
typedef const FIT_SINT8 * FIT_CONST_SINT8_PTR;
#define FIT_SINT8_INVALID           ((FIT_SINT8)0x7F)
#define FIT_BASE_TYPE_SINT8         ((FIT_UINT8)0x01)

typedef uint8_t FIT_UINT8;
typedef const FIT_UINT8 * FIT_CONST_UINT8_PTR;
#define FIT_UINT8_INVALID           ((FIT_UINT8)0xFF)
#define FIT_BASE_TYPE_UINT8         ((FIT_UINT8)0x02)

typedef int16_t FIT_SINT16;
typedef const FIT_SINT16 * FIT_CONST_SINT16_PTR;
#define FIT_SINT16_INVALID          ((FIT_SINT16)0x7FFF)
#define FIT_BASE_TYPE_SINT16        ((FIT_UINT8)0x83)

typedef uint16_t FIT_UINT16;
typedef const FIT_UINT16 * FIT_CONST_UINT16_PTR;
#define FIT_UINT16_INVALID   ((FIT_UINT16)0xFFFF)
#define FIT_BASE_TYPE_UINT16 ((FIT_UINT8)0x84)

typedef int32_t FIT_SINT32;
typedef const FIT_SINT32 * FIT_CONST_SINT32_PTR;
#define FIT_SINT32_INVALID   ((FIT_SINT32)0x7FFFFFFF)
#define FIT_BASE_TYPE_SINT32 ((FIT_UINT8)0x85)

typedef uint32_t FIT_UINT32;
typedef const FIT_UINT32 * FIT_CONST_UINT32_PTR;
#define FIT_UINT32_INVALID   ((FIT_UINT32)0xFFFFFFFF)
#define FIT_BASE_TYPE_UINT32 ((FIT_UINT8)0x86)

typedef char FIT_STRING; // UTF-8 null terminated string
typedef const FIT_STRING * FIT_CONST_STRING_PTR;
#define FIT_STRING_INVALID   ((FIT_STRING)0x00)
#define FIT_BASE_TYPE_STRING ((FIT_UINT8)0x07)

typedef float FIT_FLOAT32;
typedef const FIT_FLOAT32 * FIT_CONST_FLOAT32_PTR;
#define FIT_FLOAT32_INVALID   ((FIT_FLOAT32)0xFFFFFFFF)
#define FIT_BASE_TYPE_FLOAT32 ((FIT_UINT8)0x88)

typedef double FIT_FLOAT64;
typedef const FIT_FLOAT64 * FIT_CONST_FLOAT64_PTR;
#if defined (_BORLANDC_)
   #define FIT_FLOAT64_INVALID   ((FIT_FLOAT64)0xFFFFFFFFFFFFFFFFui64)
#else
   #define FIT_FLOAT64_INVALID   ((FIT_FLOAT64)0xFFFFFFFFFFFFFFFFull)
#endif
#define FIT_BASE_TYPE_FLOAT64 ((FIT_UINT8)0x89)

typedef uint8_t FIT_UINT8Z;
typedef const FIT_UINT8Z * FIT_CONST_UINT8Z_PTR;
#define FIT_UINT8Z_INVALID   ((FIT_UINT8Z)0x00)
#define FIT_BASE_TYPE_UINT8Z ((FIT_UINT8)0x0A)

typedef uint16_t FIT_UINT16Z;
typedef const FIT_UINT16Z * FIT_CONST_UINT16Z_PTR;
#define FIT_UINT16Z_INVALID   ((FIT_UINT16Z)0x0000)
#define FIT_BASE_TYPE_UINT16Z ((FIT_UINT8)0x8B)

typedef uint32_t FIT_UINT32Z;
typedef const FIT_UINT32Z * FIT_CONST_UINT32Z_PTR;
#define FIT_UINT32Z_INVALID   ((FIT_UINT32Z)0x00000000)
#define FIT_BASE_TYPE_UINT32Z ((FIT_UINT8)0x8C)

typedef uint8_t FIT_BYTE;
typedef const FIT_BYTE * FIT_CONST_BYTE_PTR;
#define FIT_BYTE_INVALID   ((FIT_BYTE)0xFF) // Field is invalid if all bytes are invalid.
#define FIT_BASE_TYPE_BYTE ((FIT_UINT8)0x0D)

#define FIT_BASE_TYPES    14

typedef FIT_ENUM FIT_BOOL;
#define FIT_BOOL_INVALID      FIT_ENUM_INVALID
#define FIT_BOOL_FALSE        ((FIT_BOOL)0)
#define FIT_BOOL_TRUE         ((FIT_BOOL)1)
#define FIT_FALSE             FIT_BOOL_FALSE
#define FIT_TRUE              FIT_BOOL_TRUE
#define FIT_NULL              0

typedef FIT_UINT32 (*FIT_READ_BYTES_FUNC)(void *, FIT_UINT32, FIT_UINT32);
#define FIT_MESG_DEF_HEADER_SIZE  FIT_STRUCT_OFFSET(fields, FIT_MESG_DEF)


///////////////////////////////////////////////////////////////////////
// File Header
///////////////////////////////////////////////////////////////////////

typedef struct
{
   FIT_UINT8 header_size; // FIT_FILE_HDR_SIZE (size of this structure)
   FIT_UINT8 protocol_version; // FIT_PROTOCOL_VERSION
   FIT_UINT16 profile_version; // FIT_PROFILE_VERSION
   FIT_UINT32 data_size; // Does not include file header or crc.  Little endian format.
   FIT_UINT8 data_type[4]; // ".FIT"
   FIT_UINT16 crc; // CRC of this file header in little endian format.
} FIT_FILE_HDR;

#define FIT_FILE_HDR_SIZE         14


///////////////////////////////////////////////////////////////////////
// Record Definitions
///////////////////////////////////////////////////////////////////////

#define FIT_HDR_SIZE              1
#define FIT_HDR_TIME_REC_BIT      ((FIT_UINT8) 0x80)
#define FIT_HDR_TIME_TYPE_MASK    ((FIT_UINT8) 0x60)
#define FIT_HDR_TIME_TYPE_SHIFT   5
#define FIT_HDR_TIME_OFFSET_MASK  ((FIT_UINT8) 0x1F)
#define FIT_HDR_TYPE_DEF_BIT      ((FIT_UINT8) 0x40)
#define FIT_HDR_TYPE_MASK         ((FIT_UINT8) 0x0F)
#define FIT_MAX_LOCAL_MESGS       (FIT_HDR_TYPE_MASK + 1)

///////////////////////////////////////////////////////////////////////
// File Definitions
///////////////////////////////////////////////////////////////////////

typedef struct
{
   FIT_UINT32 def_file_offset;
   FIT_UINT32 data_file_offset;
   FIT_UINT16 num;
   FIT_UINT16 count;
   FIT_UINT16 mesg;
} FIT_FILE_MESG;

typedef struct
{
   FIT_UINT32 data_size;
   const FIT_FILE_MESG *mesgs;
   FIT_UINT16 mesg_count;
   FIT_UINT8 type;
   FIT_UINT8 count;
} FIT_FILE_DEF;


///////////////////////////////////////////////////////////////////////
// Message Definitions
///////////////////////////////////////////////////////////////////////

typedef struct
{
   FIT_UINT8 field_def_num;
   FIT_UINT8 size;
   FIT_UINT8 base_type;
} FIT_FIELD_DEF;

#define FIT_FIELD_DEF_SIZE        3

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_UINT16 global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[1];
} FIT_MESG_DEF;

#define FIT_MAX_MESG_SIZE         ((FIT_UINT8)255)

#define FIT_ARCH_ENDIAN_MASK      ((FIT_UINT8)0x01)
#define FIT_ARCH_ENDIAN_LITTLE    0
#define FIT_ARCH_ENDIAN_BIG       1


///////////////////////////////////////////////////////////////////////
// Field Definitions
///////////////////////////////////////////////////////////////////////

#define FIT_MAX_FIELD_SIZE             ((FIT_UINT8)255)
#define FIT_FIELD_NUM_INVALID          ((FIT_UINT8)0xFF)
#define FIT_FIELD_NUM_MESSAGE_INDEX    ((FIT_UINT8)254)
#define FIT_FIELD_NUM_TIMESTAMP        ((FIT_UINT8)253)

#define FIT_MESSAGE_INDEX_FIELD_NUM    FIT_FIELD_NUM_MESSAGE_INDEX // For reverse compatibility only.  Use FIT_FIELD_NUM_MESSAGE_INDEX instead.
#define FIT_TIMESTAMP_FIELD_NUM        FIT_FIELD_NUM_TIMESTAMP // For reverse compatibility only.  Use FIT_FIELD_NUM_TIMESTAMP instead.


///////////////////////////////////////////////////////////////////////
// Macros
///////////////////////////////////////////////////////////////////////

#define FIT_STRUCT_OFFSET(MEMBER, STRUCT_TYPE)                          ( ((FIT_UINT8 *) &(((STRUCT_TYPE *) FIT_NULL)->MEMBER)) - ((FIT_UINT8 *) (FIT_NULL)) ) // Computes the byte offset of a member in a file.  Compiles to a constant.

#define FIT_MESG_DEF_FIELD_OFFSET(FIELD_MEMBER, FIELD_INDEX)            (FIT_STRUCT_OFFSET(FIELD_MEMBER, FIT_FIELD_DEF) + FIT_FIELD_DEF_SIZE * FIELD_INDEX) // Computes the byte offset of a field definition member.  Compiles to a constant.

// Offset of message in file including file header.
#define FIT_MESG_OFFSET(MESG_MEMBER, MESG_INDEX, MESG_SIZE, FILE)       (FIT_STRUCT_OFFSET(MESG_MEMBER, FILE) + MESG_INDEX * (FIT_HDR_SIZE + MESG_SIZE) + FIT_HDR_SIZE) // Computes the byte offset of a message in a file structure.  Compiles to a constant.
#define FIT_MESG_DEF_OFFSET(MESG_DEF_MEMBER, FILE)                      (FIT_STRUCT_OFFSET(MESG_DEF_MEMBER, FILE) + FIT_HDR_SIZE) // Computes the byte offset of a message definition in a file structure.  Compiles to a constant.

// Below macros are obsolete because C file structures now include file header.  For reverse compatibility only.
#define FIT_FILE_MESG_OFFSET(MESG_MEMBER, MESG_INDEX, MESG_SIZE, FILE)  FIT_MESG_OFFSET(MESG_MEMBER, MESG_INDEX, MESG_SIZE, FILE)
#define FIT_FILE_MESG_DEF_OFFSET(MESG_DEF_MEMBER, FILE)                 FIT_MESG_DEF_OFFSET(MESG_DEF_MEMBER, FILE)
#define FIT_FILE_MESG_DEF_FIELD_OFFSET(FIELD_MEMBER, FIELD_INDEX)       FIT_MESG_DEF_FIELD_OFFSET(FIELD_MEMBER, FIELD_INDEX)


///////////////////////////////////////////////////////////////////////
// Public Constants
///////////////////////////////////////////////////////////////////////

const extern FIT_UINT8 fit_base_type_sizes[FIT_BASE_TYPES];
const extern FIT_CONST_UINT8_PTR fit_base_type_invalids[FIT_BASE_TYPES];


/**********
 * FIT SDK H
 **********/

#if !defined(FIT_EXAMPLE_H)
#define FIT_EXAMPLE_H

#if defined(__cplusplus)
   extern "C" {
#endif


///////////////////////////////////////////////////////////////////////
// Public Definitions
///////////////////////////////////////////////////////////////////////

#define FIT_ALIGNMENT                  4

///////////////////////////////////////////////////////////////////////
// Types
///////////////////////////////////////////////////////////////////////


typedef FIT_ENUM FIT_FILE;
#define FIT_FILE_INVALID                                                         FIT_ENUM_INVALID
#define FIT_FILE_DEVICE                                                          ((FIT_FILE)1) // Read only, single file. Must be in root directory.
#define FIT_FILE_SETTINGS                                                        ((FIT_FILE)2) // Read/write, single file. Directory=Settings
#define FIT_FILE_SPORT                                                           ((FIT_FILE)3) // Read/write, multiple files, file number = sport type. Directory=Sports
#define FIT_FILE_ACTIVITY                                                        ((FIT_FILE)4) // Read/erase, multiple files. Directory=Activities
#define FIT_FILE_WORKOUT                                                         ((FIT_FILE)5) // Read/write/erase, multiple files. Directory=Workouts
#define FIT_FILE_COURSE                                                          ((FIT_FILE)6) // Read/write/erase, multiple files. Directory=Courses
#define FIT_FILE_SCHEDULES                                                       ((FIT_FILE)7) // Read/write, single file. Directory=Schedules
#define FIT_FILE_WEIGHT                                                          ((FIT_FILE)9) // Read only, single file. Circular buffer. All message definitions at start of file. Directory=Weight
#define FIT_FILE_TOTALS                                                          ((FIT_FILE)10) // Read only, single file. Directory=Totals
#define FIT_FILE_GOALS                                                           ((FIT_FILE)11) // Read/write, single file. Directory=Goals
#define FIT_FILE_BLOOD_PRESSURE                                                  ((FIT_FILE)14) // Read only. Directory=Blood Pressure
#define FIT_FILE_MONITORING_A                                                    ((FIT_FILE)15) // Read only. Directory=Monitoring. File number=sub type.
#define FIT_FILE_ACTIVITY_SUMMARY                                                ((FIT_FILE)20) // Read/erase, multiple files. Directory=Activities
#define FIT_FILE_MONITORING_DAILY                                                ((FIT_FILE)28)
#define FIT_FILE_MONITORING_B                                                    ((FIT_FILE)32) // Read only. Directory=Monitoring. File number=identifier
#define FIT_FILE_COUNT                                                           15

typedef FIT_UINT16 FIT_MESG_NUM;
#define FIT_MESG_NUM_INVALID                                                     FIT_UINT16_INVALID
#define FIT_MESG_NUM_FILE_ID                                                     ((FIT_MESG_NUM)0)
#define FIT_MESG_NUM_CAPABILITIES                                                ((FIT_MESG_NUM)1)
#define FIT_MESG_NUM_DEVICE_SETTINGS                                             ((FIT_MESG_NUM)2)
#define FIT_MESG_NUM_USER_PROFILE                                                ((FIT_MESG_NUM)3)
#define FIT_MESG_NUM_HRM_PROFILE                                                 ((FIT_MESG_NUM)4)
#define FIT_MESG_NUM_SDM_PROFILE                                                 ((FIT_MESG_NUM)5)
#define FIT_MESG_NUM_BIKE_PROFILE                                                ((FIT_MESG_NUM)6)
#define FIT_MESG_NUM_ZONES_TARGET                                                ((FIT_MESG_NUM)7)
#define FIT_MESG_NUM_HR_ZONE                                                     ((FIT_MESG_NUM)8)
#define FIT_MESG_NUM_POWER_ZONE                                                  ((FIT_MESG_NUM)9)
#define FIT_MESG_NUM_MET_ZONE                                                    ((FIT_MESG_NUM)10)
#define FIT_MESG_NUM_SPORT                                                       ((FIT_MESG_NUM)12)
#define FIT_MESG_NUM_GOAL                                                        ((FIT_MESG_NUM)15)
#define FIT_MESG_NUM_SESSION                                                     ((FIT_MESG_NUM)18)
#define FIT_MESG_NUM_LAP                                                         ((FIT_MESG_NUM)19)
#define FIT_MESG_NUM_RECORD                                                      ((FIT_MESG_NUM)20)
#define FIT_MESG_NUM_EVENT                                                       ((FIT_MESG_NUM)21)
#define FIT_MESG_NUM_DEVICE_INFO                                                 ((FIT_MESG_NUM)23)
#define FIT_MESG_NUM_WORKOUT                                                     ((FIT_MESG_NUM)26)
#define FIT_MESG_NUM_WORKOUT_STEP                                                ((FIT_MESG_NUM)27)
#define FIT_MESG_NUM_SCHEDULE                                                    ((FIT_MESG_NUM)28)
#define FIT_MESG_NUM_WEIGHT_SCALE                                                ((FIT_MESG_NUM)30)
#define FIT_MESG_NUM_COURSE                                                      ((FIT_MESG_NUM)31)
#define FIT_MESG_NUM_COURSE_POINT                                                ((FIT_MESG_NUM)32)
#define FIT_MESG_NUM_TOTALS                                                      ((FIT_MESG_NUM)33)
#define FIT_MESG_NUM_ACTIVITY                                                    ((FIT_MESG_NUM)34)
#define FIT_MESG_NUM_SOFTWARE                                                    ((FIT_MESG_NUM)35)
#define FIT_MESG_NUM_FILE_CAPABILITIES                                           ((FIT_MESG_NUM)37)
#define FIT_MESG_NUM_MESG_CAPABILITIES                                           ((FIT_MESG_NUM)38)
#define FIT_MESG_NUM_FIELD_CAPABILITIES                                          ((FIT_MESG_NUM)39)
#define FIT_MESG_NUM_FILE_CREATOR                                                ((FIT_MESG_NUM)49)
#define FIT_MESG_NUM_BLOOD_PRESSURE                                              ((FIT_MESG_NUM)51)
#define FIT_MESG_NUM_SPEED_ZONE                                                  ((FIT_MESG_NUM)53)
#define FIT_MESG_NUM_MONITORING                                                  ((FIT_MESG_NUM)55)
#define FIT_MESG_NUM_HRV                                                         ((FIT_MESG_NUM)78)
#define FIT_MESG_NUM_LENGTH                                                      ((FIT_MESG_NUM)101)
#define FIT_MESG_NUM_MONITORING_INFO                                             ((FIT_MESG_NUM)103)
#define FIT_MESG_NUM_PAD                                                         ((FIT_MESG_NUM)105)
#define FIT_MESG_NUM_SLAVE_DEVICE                                                ((FIT_MESG_NUM)106)
#define FIT_MESG_NUM_CADENCE_ZONE                                                ((FIT_MESG_NUM)131)
#define FIT_MESG_NUM_MEMO_GLOB                                                   ((FIT_MESG_NUM)145)
#define FIT_MESG_NUM_MFG_RANGE_MIN                                               ((FIT_MESG_NUM)0xFF00) // 0xFF00 - 0xFFFE reserved for manufacturer specific messages
#define FIT_MESG_NUM_MFG_RANGE_MAX                                               ((FIT_MESG_NUM)0xFFFE) // 0xFF00 - 0xFFFE reserved for manufacturer specific messages
#define FIT_MESG_NUM_COUNT                                                       43

typedef FIT_UINT8 FIT_CHECKSUM;
#define FIT_CHECKSUM_INVALID                                                     FIT_UINT8_INVALID
#define FIT_CHECKSUM_CLEAR                                                       ((FIT_CHECKSUM)0) // Allows clear of checksum for flash memory where can only write 1 to 0 without erasing sector.
#define FIT_CHECKSUM_OK                                                          ((FIT_CHECKSUM)1) // Set to mark checksum as valid if computes to invalid values 0 or 0xFF.  Checksum can also be set to ok to save encoding computation time.
#define FIT_CHECKSUM_COUNT                                                       2

typedef FIT_UINT8Z FIT_FILE_FLAGS;
#define FIT_FILE_FLAGS_INVALID                                                   FIT_UINT8Z_INVALID
#define FIT_FILE_FLAGS_READ                                                      ((FIT_FILE_FLAGS)0x02)
#define FIT_FILE_FLAGS_WRITE                                                     ((FIT_FILE_FLAGS)0x04)
#define FIT_FILE_FLAGS_ERASE                                                     ((FIT_FILE_FLAGS)0x08)
#define FIT_FILE_FLAGS_COUNT                                                     3

typedef FIT_ENUM FIT_MESG_COUNT;
#define FIT_MESG_COUNT_INVALID                                                   FIT_ENUM_INVALID
#define FIT_MESG_COUNT_NUM_PER_FILE                                              ((FIT_MESG_COUNT)0)
#define FIT_MESG_COUNT_MAX_PER_FILE                                              ((FIT_MESG_COUNT)1)
#define FIT_MESG_COUNT_MAX_PER_FILE_TYPE                                         ((FIT_MESG_COUNT)2)
#define FIT_MESG_COUNT_COUNT                                                     3

typedef FIT_UINT32 FIT_DATE_TIME; // seconds since UTC 00:00 Dec 31 1989
#define FIT_DATE_TIME_INVALID                                                    FIT_UINT32_INVALID
#define FIT_DATE_TIME_MIN                                                        ((FIT_DATE_TIME)0x10000000) // if date_time is < 0x10000000 then it is system time (seconds from device power on)
#define FIT_DATE_TIME_COUNT                                                      1

typedef FIT_UINT32 FIT_LOCAL_DATE_TIME; // seconds since 00:00 Dec 31 1989 in local time zone
#define FIT_LOCAL_DATE_TIME_INVALID                                              FIT_UINT32_INVALID
#define FIT_LOCAL_DATE_TIME_MIN                                                  ((FIT_LOCAL_DATE_TIME)0x10000000) // if date_time is < 0x10000000 then it is system time (seconds from device power on)
#define FIT_LOCAL_DATE_TIME_COUNT                                                1

typedef FIT_UINT16 FIT_MESSAGE_INDEX;
#define FIT_MESSAGE_INDEX_INVALID                                                FIT_UINT16_INVALID
#define FIT_MESSAGE_INDEX_SELECTED                                               ((FIT_MESSAGE_INDEX)0x8000) // message is selected if set
#define FIT_MESSAGE_INDEX_RESERVED                                               ((FIT_MESSAGE_INDEX)0x7000) // reserved (default 0)
#define FIT_MESSAGE_INDEX_MASK                                                   ((FIT_MESSAGE_INDEX)0x0FFF) // index
#define FIT_MESSAGE_INDEX_COUNT                                                  3

typedef FIT_UINT8 FIT_DEVICE_INDEX;
#define FIT_DEVICE_INDEX_INVALID                                                 FIT_UINT8_INVALID
#define FIT_DEVICE_INDEX_CREATOR                                                 ((FIT_DEVICE_INDEX)0) // Creator of the file is always device index 0.
#define FIT_DEVICE_INDEX_COUNT                                                   1

typedef FIT_ENUM FIT_GENDER;
#define FIT_GENDER_INVALID                                                       FIT_ENUM_INVALID
#define FIT_GENDER_FEMALE                                                        ((FIT_GENDER)0)
#define FIT_GENDER_MALE                                                          ((FIT_GENDER)1)
#define FIT_GENDER_COUNT                                                         2

typedef FIT_ENUM FIT_LANGUAGE;
#define FIT_LANGUAGE_INVALID                                                     FIT_ENUM_INVALID
#define FIT_LANGUAGE_ENGLISH                                                     ((FIT_LANGUAGE)0)
#define FIT_LANGUAGE_FRENCH                                                      ((FIT_LANGUAGE)1)
#define FIT_LANGUAGE_ITALIAN                                                     ((FIT_LANGUAGE)2)
#define FIT_LANGUAGE_GERMAN                                                      ((FIT_LANGUAGE)3)
#define FIT_LANGUAGE_SPANISH                                                     ((FIT_LANGUAGE)4)
#define FIT_LANGUAGE_CROATIAN                                                    ((FIT_LANGUAGE)5)
#define FIT_LANGUAGE_CZECH                                                       ((FIT_LANGUAGE)6)
#define FIT_LANGUAGE_DANISH                                                      ((FIT_LANGUAGE)7)
#define FIT_LANGUAGE_DUTCH                                                       ((FIT_LANGUAGE)8)
#define FIT_LANGUAGE_FINNISH                                                     ((FIT_LANGUAGE)9)
#define FIT_LANGUAGE_GREEK                                                       ((FIT_LANGUAGE)10)
#define FIT_LANGUAGE_HUNGARIAN                                                   ((FIT_LANGUAGE)11)
#define FIT_LANGUAGE_NORWEGIAN                                                   ((FIT_LANGUAGE)12)
#define FIT_LANGUAGE_POLISH                                                      ((FIT_LANGUAGE)13)
#define FIT_LANGUAGE_PORTUGUESE                                                  ((FIT_LANGUAGE)14)
#define FIT_LANGUAGE_SLOVAKIAN                                                   ((FIT_LANGUAGE)15)
#define FIT_LANGUAGE_SLOVENIAN                                                   ((FIT_LANGUAGE)16)
#define FIT_LANGUAGE_SWEDISH                                                     ((FIT_LANGUAGE)17)
#define FIT_LANGUAGE_RUSSIAN                                                     ((FIT_LANGUAGE)18)
#define FIT_LANGUAGE_TURKISH                                                     ((FIT_LANGUAGE)19)
#define FIT_LANGUAGE_LATVIAN                                                     ((FIT_LANGUAGE)20)
#define FIT_LANGUAGE_UKRAINIAN                                                   ((FIT_LANGUAGE)21)
#define FIT_LANGUAGE_ARABIC                                                      ((FIT_LANGUAGE)22)
#define FIT_LANGUAGE_FARSI                                                       ((FIT_LANGUAGE)23)
#define FIT_LANGUAGE_BULGARIAN                                                   ((FIT_LANGUAGE)24)
#define FIT_LANGUAGE_ROMANIAN                                                    ((FIT_LANGUAGE)25)
#define FIT_LANGUAGE_CUSTOM                                                      ((FIT_LANGUAGE)254)
#define FIT_LANGUAGE_COUNT                                                       27

typedef FIT_ENUM FIT_DISPLAY_MEASURE;
#define FIT_DISPLAY_MEASURE_INVALID                                              FIT_ENUM_INVALID
#define FIT_DISPLAY_MEASURE_METRIC                                               ((FIT_DISPLAY_MEASURE)0)
#define FIT_DISPLAY_MEASURE_STATUTE                                              ((FIT_DISPLAY_MEASURE)1)
#define FIT_DISPLAY_MEASURE_COUNT                                                2

typedef FIT_ENUM FIT_DISPLAY_HEART;
#define FIT_DISPLAY_HEART_INVALID                                                FIT_ENUM_INVALID
#define FIT_DISPLAY_HEART_BPM                                                    ((FIT_DISPLAY_HEART)0)
#define FIT_DISPLAY_HEART_MAX                                                    ((FIT_DISPLAY_HEART)1)
#define FIT_DISPLAY_HEART_RESERVE                                                ((FIT_DISPLAY_HEART)2)
#define FIT_DISPLAY_HEART_COUNT                                                  3

typedef FIT_ENUM FIT_DISPLAY_POWER;
#define FIT_DISPLAY_POWER_INVALID                                                FIT_ENUM_INVALID
#define FIT_DISPLAY_POWER_WATTS                                                  ((FIT_DISPLAY_POWER)0)
#define FIT_DISPLAY_POWER_PERCENT_FTP                                            ((FIT_DISPLAY_POWER)1)
#define FIT_DISPLAY_POWER_COUNT                                                  2

typedef FIT_ENUM FIT_DISPLAY_POSITION;
#define FIT_DISPLAY_POSITION_INVALID                                             FIT_ENUM_INVALID
#define FIT_DISPLAY_POSITION_DEGREE                                              ((FIT_DISPLAY_POSITION)0) // dd.dddddd
#define FIT_DISPLAY_POSITION_DEGREE_MINUTE                                       ((FIT_DISPLAY_POSITION)1) // dddmm.mmm
#define FIT_DISPLAY_POSITION_DEGREE_MINUTE_SECOND                                ((FIT_DISPLAY_POSITION)2) // dddmmss
#define FIT_DISPLAY_POSITION_AUSTRIAN_GRID                                       ((FIT_DISPLAY_POSITION)3) // Austrian Grid (BMN)
#define FIT_DISPLAY_POSITION_BRITISH_GRID                                        ((FIT_DISPLAY_POSITION)4) // British National Grid
#define FIT_DISPLAY_POSITION_DUTCH_GRID                                          ((FIT_DISPLAY_POSITION)5) // Dutch grid system
#define FIT_DISPLAY_POSITION_HUNGARIAN_GRID                                      ((FIT_DISPLAY_POSITION)6) // Hungarian grid system
#define FIT_DISPLAY_POSITION_FINNISH_GRID                                        ((FIT_DISPLAY_POSITION)7) // Finnish grid system Zone3 KKJ27
#define FIT_DISPLAY_POSITION_GERMAN_GRID                                         ((FIT_DISPLAY_POSITION)8) // Gausss Krueger (German)
#define FIT_DISPLAY_POSITION_ICELANDIC_GRID                                      ((FIT_DISPLAY_POSITION)9) // Icelandic Grid
#define FIT_DISPLAY_POSITION_INDONESIAN_EQUATORIAL                               ((FIT_DISPLAY_POSITION)10) // Indonesian Equatorial LCO
#define FIT_DISPLAY_POSITION_INDONESIAN_IRIAN                                    ((FIT_DISPLAY_POSITION)11) // Indonesian Irian LCO
#define FIT_DISPLAY_POSITION_INDONESIAN_SOUTHERN                                 ((FIT_DISPLAY_POSITION)12) // Indonesian Southern LCO
#define FIT_DISPLAY_POSITION_INDIA_ZONE_0                                        ((FIT_DISPLAY_POSITION)13) // India zone 0
#define FIT_DISPLAY_POSITION_INDIA_ZONE_IA                                       ((FIT_DISPLAY_POSITION)14) // India zone IA
#define FIT_DISPLAY_POSITION_INDIA_ZONE_IB                                       ((FIT_DISPLAY_POSITION)15) // India zone IB
#define FIT_DISPLAY_POSITION_INDIA_ZONE_IIA                                      ((FIT_DISPLAY_POSITION)16) // India zone IIA
#define FIT_DISPLAY_POSITION_INDIA_ZONE_IIB                                      ((FIT_DISPLAY_POSITION)17) // India zone IIB
#define FIT_DISPLAY_POSITION_INDIA_ZONE_IIIA                                     ((FIT_DISPLAY_POSITION)18) // India zone IIIA
#define FIT_DISPLAY_POSITION_INDIA_ZONE_IIIB                                     ((FIT_DISPLAY_POSITION)19) // India zone IIIB
#define FIT_DISPLAY_POSITION_INDIA_ZONE_IVA                                      ((FIT_DISPLAY_POSITION)20) // India zone IVA
#define FIT_DISPLAY_POSITION_INDIA_ZONE_IVB                                      ((FIT_DISPLAY_POSITION)21) // India zone IVB
#define FIT_DISPLAY_POSITION_IRISH_TRANSVERSE                                    ((FIT_DISPLAY_POSITION)22) // Irish Transverse Mercator
#define FIT_DISPLAY_POSITION_IRISH_GRID                                          ((FIT_DISPLAY_POSITION)23) // Irish Grid
#define FIT_DISPLAY_POSITION_LORAN                                               ((FIT_DISPLAY_POSITION)24) // Loran TD
#define FIT_DISPLAY_POSITION_MAIDENHEAD_GRID                                     ((FIT_DISPLAY_POSITION)25) // Maidenhead grid system
#define FIT_DISPLAY_POSITION_MGRS_GRID                                           ((FIT_DISPLAY_POSITION)26) // MGRS grid system
#define FIT_DISPLAY_POSITION_NEW_ZEALAND_GRID                                    ((FIT_DISPLAY_POSITION)27) // New Zealand grid system
#define FIT_DISPLAY_POSITION_NEW_ZEALAND_TRANSVERSE                              ((FIT_DISPLAY_POSITION)28) // New Zealand Transverse Mercator
#define FIT_DISPLAY_POSITION_QATAR_GRID                                          ((FIT_DISPLAY_POSITION)29) // Qatar National Grid
#define FIT_DISPLAY_POSITION_MODIFIED_SWEDISH_GRID                               ((FIT_DISPLAY_POSITION)30) // Modified RT-90 (Sweden)
#define FIT_DISPLAY_POSITION_SWEDISH_GRID                                        ((FIT_DISPLAY_POSITION)31) // RT-90 (Sweden)
#define FIT_DISPLAY_POSITION_SOUTH_AFRICAN_GRID                                  ((FIT_DISPLAY_POSITION)32) // South African Grid
#define FIT_DISPLAY_POSITION_SWISS_GRID                                          ((FIT_DISPLAY_POSITION)33) // Swiss CH-1903 grid
#define FIT_DISPLAY_POSITION_TAIWAN_GRID                                         ((FIT_DISPLAY_POSITION)34) // Taiwan Grid
#define FIT_DISPLAY_POSITION_UNITED_STATES_GRID                                  ((FIT_DISPLAY_POSITION)35) // United States National Grid
#define FIT_DISPLAY_POSITION_UTM_UPS_GRID                                        ((FIT_DISPLAY_POSITION)36) // UTM/UPS grid system
#define FIT_DISPLAY_POSITION_WEST_MALAYAN                                        ((FIT_DISPLAY_POSITION)37) // West Malayan RSO
#define FIT_DISPLAY_POSITION_BORNEO_RSO                                          ((FIT_DISPLAY_POSITION)38) // Borneo RSO
#define FIT_DISPLAY_POSITION_ESTONIAN_GRID                                       ((FIT_DISPLAY_POSITION)39) // Estonian grid system
#define FIT_DISPLAY_POSITION_LATVIAN_GRID                                        ((FIT_DISPLAY_POSITION)40) // Latvian Transverse Mercator
#define FIT_DISPLAY_POSITION_SWEDISH_REF_99_GRID                                 ((FIT_DISPLAY_POSITION)41) // Reference Grid 99 TM (Swedish)
#define FIT_DISPLAY_POSITION_COUNT                                               42

typedef FIT_ENUM FIT_SPORT;
#define FIT_SPORT_INVALID                                                        FIT_ENUM_INVALID
#define FIT_SPORT_GENERIC                                                        ((FIT_SPORT)0)
#define FIT_SPORT_RUNNING                                                        ((FIT_SPORT)1)
#define FIT_SPORT_CYCLING                                                        ((FIT_SPORT)2)
#define FIT_SPORT_TRANSITION                                                     ((FIT_SPORT)3) // Mulitsport transition
#define FIT_SPORT_FITNESS_EQUIPMENT                                              ((FIT_SPORT)4)
#define FIT_SPORT_SWIMMING                                                       ((FIT_SPORT)5)
#define FIT_SPORT_BASKETBALL                                                     ((FIT_SPORT)6)
#define FIT_SPORT_SOCCER                                                         ((FIT_SPORT)7)
#define FIT_SPORT_TENNIS                                                         ((FIT_SPORT)8)
#define FIT_SPORT_AMERICAN_FOOTBALL                                              ((FIT_SPORT)9)
#define FIT_SPORT_TRAINING                                                       ((FIT_SPORT)10)
#define FIT_SPORT_WALKING                                                        ((FIT_SPORT)11)
#define FIT_SPORT_CROSS_COUNTRY_SKIING                                           ((FIT_SPORT)12)
#define FIT_SPORT_ALPINE_SKIING                                                  ((FIT_SPORT)13)
#define FIT_SPORT_SNOWBOARDING                                                   ((FIT_SPORT)14)
#define FIT_SPORT_ROWING                                                         ((FIT_SPORT)15)
#define FIT_SPORT_MOUNTAINEERING                                                 ((FIT_SPORT)16)
#define FIT_SPORT_HIKING                                                         ((FIT_SPORT)17)
#define FIT_SPORT_MULTISPORT                                                     ((FIT_SPORT)18)
#define FIT_SPORT_PADDLING                                                       ((FIT_SPORT)19)
#define FIT_SPORT_ALL                                                            ((FIT_SPORT)254) // All is for goals only to include all sports.
#define FIT_SPORT_COUNT                                                          21

typedef FIT_UINT8Z FIT_SPORT_BITS_0; // Bit field corresponding to sport enum type (1 << sport).
#define FIT_SPORT_BITS_0_INVALID                                                 FIT_UINT8Z_INVALID
#define FIT_SPORT_BITS_0_GENERIC                                                 ((FIT_SPORT_BITS_0)0x01)
#define FIT_SPORT_BITS_0_RUNNING                                                 ((FIT_SPORT_BITS_0)0x02)
#define FIT_SPORT_BITS_0_CYCLING                                                 ((FIT_SPORT_BITS_0)0x04)
#define FIT_SPORT_BITS_0_TRANSITION                                              ((FIT_SPORT_BITS_0)0x08) // Mulitsport transition
#define FIT_SPORT_BITS_0_FITNESS_EQUIPMENT                                       ((FIT_SPORT_BITS_0)0x10)
#define FIT_SPORT_BITS_0_SWIMMING                                                ((FIT_SPORT_BITS_0)0x20)
#define FIT_SPORT_BITS_0_BASKETBALL                                              ((FIT_SPORT_BITS_0)0x40)
#define FIT_SPORT_BITS_0_SOCCER                                                  ((FIT_SPORT_BITS_0)0x80)
#define FIT_SPORT_BITS_0_COUNT                                                   8

typedef FIT_UINT8Z FIT_SPORT_BITS_1; // Bit field corresponding to sport enum type (1 << (sport-8)).
#define FIT_SPORT_BITS_1_INVALID                                                 FIT_UINT8Z_INVALID
#define FIT_SPORT_BITS_1_TENNIS                                                  ((FIT_SPORT_BITS_1)0x01)
#define FIT_SPORT_BITS_1_AMERICAN_FOOTBALL                                       ((FIT_SPORT_BITS_1)0x02)
#define FIT_SPORT_BITS_1_TRAINING                                                ((FIT_SPORT_BITS_1)0x04)
#define FIT_SPORT_BITS_1_WALKING                                                 ((FIT_SPORT_BITS_1)0x08)
#define FIT_SPORT_BITS_1_CROSS_COUNTRY_SKIING                                    ((FIT_SPORT_BITS_1)0x10)
#define FIT_SPORT_BITS_1_ALPINE_SKIING                                           ((FIT_SPORT_BITS_1)0x20)
#define FIT_SPORT_BITS_1_SNOWBOARDING                                            ((FIT_SPORT_BITS_1)0x40)
#define FIT_SPORT_BITS_1_ROWING                                                  ((FIT_SPORT_BITS_1)0x80)
#define FIT_SPORT_BITS_1_COUNT                                                   8

typedef FIT_UINT8Z FIT_SPORT_BITS_2; // Bit field corresponding to sport enum type (1 << (sport-16)).
#define FIT_SPORT_BITS_2_INVALID                                                 FIT_UINT8Z_INVALID
#define FIT_SPORT_BITS_2_MOUNTAINEERING                                          ((FIT_SPORT_BITS_2)0x01)
#define FIT_SPORT_BITS_2_HIKING                                                  ((FIT_SPORT_BITS_2)0x02)
#define FIT_SPORT_BITS_2_MULTISPORT                                              ((FIT_SPORT_BITS_2)0x04)
#define FIT_SPORT_BITS_2_PADDLING                                                ((FIT_SPORT_BITS_2)0x08)
#define FIT_SPORT_BITS_2_COUNT                                                   4

typedef FIT_ENUM FIT_SUB_SPORT;
#define FIT_SUB_SPORT_INVALID                                                    FIT_ENUM_INVALID
#define FIT_SUB_SPORT_GENERIC                                                    ((FIT_SUB_SPORT)0)
#define FIT_SUB_SPORT_TREADMILL                                                  ((FIT_SUB_SPORT)1) // Run/Fitness Equipment
#define FIT_SUB_SPORT_STREET                                                     ((FIT_SUB_SPORT)2) // Run
#define FIT_SUB_SPORT_TRAIL                                                      ((FIT_SUB_SPORT)3) // Run
#define FIT_SUB_SPORT_TRACK                                                      ((FIT_SUB_SPORT)4) // Run
#define FIT_SUB_SPORT_SPIN                                                       ((FIT_SUB_SPORT)5) // Cycling
#define FIT_SUB_SPORT_INDOOR_CYCLING                                             ((FIT_SUB_SPORT)6) // Cycling/Fitness Equipment
#define FIT_SUB_SPORT_ROAD                                                       ((FIT_SUB_SPORT)7) // Cycling
#define FIT_SUB_SPORT_MOUNTAIN                                                   ((FIT_SUB_SPORT)8) // Cycling
#define FIT_SUB_SPORT_DOWNHILL                                                   ((FIT_SUB_SPORT)9) // Cycling
#define FIT_SUB_SPORT_RECUMBENT                                                  ((FIT_SUB_SPORT)10) // Cycling
#define FIT_SUB_SPORT_CYCLOCROSS                                                 ((FIT_SUB_SPORT)11) // Cycling
#define FIT_SUB_SPORT_HAND_CYCLING                                               ((FIT_SUB_SPORT)12) // Cycling
#define FIT_SUB_SPORT_TRACK_CYCLING                                              ((FIT_SUB_SPORT)13) // Cycling
#define FIT_SUB_SPORT_INDOOR_ROWING                                              ((FIT_SUB_SPORT)14) // Fitness Equipment
#define FIT_SUB_SPORT_ELLIPTICAL                                                 ((FIT_SUB_SPORT)15) // Fitness Equipment
#define FIT_SUB_SPORT_STAIR_CLIMBING                                             ((FIT_SUB_SPORT)16) // Fitness Equipment
#define FIT_SUB_SPORT_LAP_SWIMMING                                               ((FIT_SUB_SPORT)17) // Swimming
#define FIT_SUB_SPORT_OPEN_WATER                                                 ((FIT_SUB_SPORT)18) // Swimming
#define FIT_SUB_SPORT_FLEXIBILITY_TRAINING                                       ((FIT_SUB_SPORT)19) // Training
#define FIT_SUB_SPORT_STRENGTH_TRAINING                                          ((FIT_SUB_SPORT)20) // Training
#define FIT_SUB_SPORT_WARM_UP                                                    ((FIT_SUB_SPORT)21) // Tennis
#define FIT_SUB_SPORT_MATCH                                                      ((FIT_SUB_SPORT)22) // Tennis
#define FIT_SUB_SPORT_EXERCISE                                                   ((FIT_SUB_SPORT)23) // Tennis
#define FIT_SUB_SPORT_CHALLENGE                                                  ((FIT_SUB_SPORT)24) // Tennis
#define FIT_SUB_SPORT_INDOOR_SKIING                                              ((FIT_SUB_SPORT)25) // Fitness Equipment
#define FIT_SUB_SPORT_CARDIO_TRAINING                                            ((FIT_SUB_SPORT)26) // Training
#define FIT_SUB_SPORT_ALL                                                        ((FIT_SUB_SPORT)254)
#define FIT_SUB_SPORT_COUNT                                                      28

typedef FIT_ENUM FIT_ACTIVITY;
#define FIT_ACTIVITY_INVALID                                                     FIT_ENUM_INVALID
#define FIT_ACTIVITY_MANUAL                                                      ((FIT_ACTIVITY)0)
#define FIT_ACTIVITY_AUTO_MULTI_SPORT                                            ((FIT_ACTIVITY)1)
#define FIT_ACTIVITY_COUNT                                                       2

typedef FIT_ENUM FIT_INTENSITY;
#define FIT_INTENSITY_INVALID                                                    FIT_ENUM_INVALID
#define FIT_INTENSITY_ACTIVE                                                     ((FIT_INTENSITY)0)
#define FIT_INTENSITY_REST                                                       ((FIT_INTENSITY)1)
#define FIT_INTENSITY_WARMUP                                                     ((FIT_INTENSITY)2)
#define FIT_INTENSITY_COOLDOWN                                                   ((FIT_INTENSITY)3)
#define FIT_INTENSITY_COUNT                                                      4

typedef FIT_ENUM FIT_SESSION_TRIGGER;
#define FIT_SESSION_TRIGGER_INVALID                                              FIT_ENUM_INVALID
#define FIT_SESSION_TRIGGER_ACTIVITY_END                                         ((FIT_SESSION_TRIGGER)0)
#define FIT_SESSION_TRIGGER_MANUAL                                               ((FIT_SESSION_TRIGGER)1) // User changed sport.
#define FIT_SESSION_TRIGGER_AUTO_MULTI_SPORT                                     ((FIT_SESSION_TRIGGER)2) // Auto multi-sport feature is enabled and user pressed lap button to advance session.
#define FIT_SESSION_TRIGGER_FITNESS_EQUIPMENT                                    ((FIT_SESSION_TRIGGER)3) // Auto sport change caused by user linking to fitness equipment.
#define FIT_SESSION_TRIGGER_COUNT                                                4

typedef FIT_ENUM FIT_AUTOLAP_TRIGGER;
#define FIT_AUTOLAP_TRIGGER_INVALID                                              FIT_ENUM_INVALID
#define FIT_AUTOLAP_TRIGGER_TIME                                                 ((FIT_AUTOLAP_TRIGGER)0)
#define FIT_AUTOLAP_TRIGGER_DISTANCE                                             ((FIT_AUTOLAP_TRIGGER)1)
#define FIT_AUTOLAP_TRIGGER_POSITION_START                                       ((FIT_AUTOLAP_TRIGGER)2)
#define FIT_AUTOLAP_TRIGGER_POSITION_LAP                                         ((FIT_AUTOLAP_TRIGGER)3)
#define FIT_AUTOLAP_TRIGGER_POSITION_WAYPOINT                                    ((FIT_AUTOLAP_TRIGGER)4)
#define FIT_AUTOLAP_TRIGGER_POSITION_MARKED                                      ((FIT_AUTOLAP_TRIGGER)5)
#define FIT_AUTOLAP_TRIGGER_OFF                                                  ((FIT_AUTOLAP_TRIGGER)6)
#define FIT_AUTOLAP_TRIGGER_COUNT                                                7

typedef FIT_ENUM FIT_LAP_TRIGGER;
#define FIT_LAP_TRIGGER_INVALID                                                  FIT_ENUM_INVALID
#define FIT_LAP_TRIGGER_MANUAL                                                   ((FIT_LAP_TRIGGER)0)
#define FIT_LAP_TRIGGER_TIME                                                     ((FIT_LAP_TRIGGER)1)
#define FIT_LAP_TRIGGER_DISTANCE                                                 ((FIT_LAP_TRIGGER)2)
#define FIT_LAP_TRIGGER_POSITION_START                                           ((FIT_LAP_TRIGGER)3)
#define FIT_LAP_TRIGGER_POSITION_LAP                                             ((FIT_LAP_TRIGGER)4)
#define FIT_LAP_TRIGGER_POSITION_WAYPOINT                                        ((FIT_LAP_TRIGGER)5)
#define FIT_LAP_TRIGGER_POSITION_MARKED                                          ((FIT_LAP_TRIGGER)6)
#define FIT_LAP_TRIGGER_SESSION_END                                              ((FIT_LAP_TRIGGER)7)
#define FIT_LAP_TRIGGER_FITNESS_EQUIPMENT                                        ((FIT_LAP_TRIGGER)8)
#define FIT_LAP_TRIGGER_COUNT                                                    9

typedef FIT_ENUM FIT_EVENT;
#define FIT_EVENT_INVALID                                                        FIT_ENUM_INVALID
#define FIT_EVENT_TIMER                                                          ((FIT_EVENT)0) // Group 0.  Start / stop_all
#define FIT_EVENT_WORKOUT                                                        ((FIT_EVENT)3) // start / stop
#define FIT_EVENT_WORKOUT_STEP                                                   ((FIT_EVENT)4) // Start at beginning of workout.  Stop at end of each step.
#define FIT_EVENT_POWER_DOWN                                                     ((FIT_EVENT)5) // stop_all group 0
#define FIT_EVENT_POWER_UP                                                       ((FIT_EVENT)6) // stop_all group 0
#define FIT_EVENT_OFF_COURSE                                                     ((FIT_EVENT)7) // start / stop group 0
#define FIT_EVENT_SESSION                                                        ((FIT_EVENT)8) // Stop at end of each session.
#define FIT_EVENT_LAP                                                            ((FIT_EVENT)9) // Stop at end of each lap.
#define FIT_EVENT_COURSE_POINT                                                   ((FIT_EVENT)10) // marker
#define FIT_EVENT_BATTERY                                                        ((FIT_EVENT)11) // marker
#define FIT_EVENT_VIRTUAL_PARTNER_PACE                                           ((FIT_EVENT)12) // Group 1. Start at beginning of activity if VP enabled, when VP pace is changed during activity or VP enabled mid activity.  stop_disable when VP disabled.
#define FIT_EVENT_HR_HIGH_ALERT                                                  ((FIT_EVENT)13) // Group 0.  Start / stop when in alert condition.
#define FIT_EVENT_HR_LOW_ALERT                                                   ((FIT_EVENT)14) // Group 0.  Start / stop when in alert condition.
#define FIT_EVENT_SPEED_HIGH_ALERT                                               ((FIT_EVENT)15) // Group 0.  Start / stop when in alert condition.
#define FIT_EVENT_SPEED_LOW_ALERT                                                ((FIT_EVENT)16) // Group 0.  Start / stop when in alert condition.
#define FIT_EVENT_CAD_HIGH_ALERT                                                 ((FIT_EVENT)17) // Group 0.  Start / stop when in alert condition.
#define FIT_EVENT_CAD_LOW_ALERT                                                  ((FIT_EVENT)18) // Group 0.  Start / stop when in alert condition.
#define FIT_EVENT_POWER_HIGH_ALERT                                               ((FIT_EVENT)19) // Group 0.  Start / stop when in alert condition.
#define FIT_EVENT_POWER_LOW_ALERT                                                ((FIT_EVENT)20) // Group 0.  Start / stop when in alert condition.
#define FIT_EVENT_RECOVERY_HR                                                    ((FIT_EVENT)21) // marker
#define FIT_EVENT_BATTERY_LOW                                                    ((FIT_EVENT)22) // marker
#define FIT_EVENT_TIME_DURATION_ALERT                                            ((FIT_EVENT)23) // Group 1.  Start if enabled mid activity (not required at start of activity). Stop when duration is reached.  stop_disable if disabled.
#define FIT_EVENT_DISTANCE_DURATION_ALERT                                        ((FIT_EVENT)24) // Group 1.  Start if enabled mid activity (not required at start of activity). Stop when duration is reached.  stop_disable if disabled.
#define FIT_EVENT_CALORIE_DURATION_ALERT                                         ((FIT_EVENT)25) // Group 1.  Start if enabled mid activity (not required at start of activity). Stop when duration is reached.  stop_disable if disabled.
#define FIT_EVENT_ACTIVITY                                                       ((FIT_EVENT)26) // Group 1..  Stop at end of activity.
#define FIT_EVENT_FITNESS_EQUIPMENT                                              ((FIT_EVENT)27) // marker
#define FIT_EVENT_LENGTH                                                         ((FIT_EVENT)28) // Stop at end of each length.
#define FIT_EVENT_USER_MARKER                                                    ((FIT_EVENT)32) // marker
#define FIT_EVENT_SPORT_POINT                                                    ((FIT_EVENT)33) // marker
#define FIT_EVENT_CALIBRATION                                                    ((FIT_EVENT)36) // start/stop/marker
#define FIT_EVENT_COUNT                                                          30

typedef FIT_ENUM FIT_EVENT_TYPE;
#define FIT_EVENT_TYPE_INVALID                                                   FIT_ENUM_INVALID
#define FIT_EVENT_TYPE_START                                                     ((FIT_EVENT_TYPE)0)
#define FIT_EVENT_TYPE_STOP                                                      ((FIT_EVENT_TYPE)1)
#define FIT_EVENT_TYPE_CONSECUTIVE_DEPRECIATED                                   ((FIT_EVENT_TYPE)2)
#define FIT_EVENT_TYPE_MARKER                                                    ((FIT_EVENT_TYPE)3)
#define FIT_EVENT_TYPE_STOP_ALL                                                  ((FIT_EVENT_TYPE)4)
#define FIT_EVENT_TYPE_BEGIN_DEPRECIATED                                         ((FIT_EVENT_TYPE)5)
#define FIT_EVENT_TYPE_END_DEPRECIATED                                           ((FIT_EVENT_TYPE)6)
#define FIT_EVENT_TYPE_END_ALL_DEPRECIATED                                       ((FIT_EVENT_TYPE)7)
#define FIT_EVENT_TYPE_STOP_DISABLE                                              ((FIT_EVENT_TYPE)8)
#define FIT_EVENT_TYPE_STOP_DISABLE_ALL                                          ((FIT_EVENT_TYPE)9)
#define FIT_EVENT_TYPE_COUNT                                                     10

typedef FIT_ENUM FIT_TIMER_TRIGGER; // timer event data
#define FIT_TIMER_TRIGGER_INVALID                                                FIT_ENUM_INVALID
#define FIT_TIMER_TRIGGER_MANUAL                                                 ((FIT_TIMER_TRIGGER)0)
#define FIT_TIMER_TRIGGER_AUTO                                                   ((FIT_TIMER_TRIGGER)1)
#define FIT_TIMER_TRIGGER_FITNESS_EQUIPMENT                                      ((FIT_TIMER_TRIGGER)2)
#define FIT_TIMER_TRIGGER_COUNT                                                  3

typedef FIT_ENUM FIT_FITNESS_EQUIPMENT_STATE; // fitness equipment event data
#define FIT_FITNESS_EQUIPMENT_STATE_INVALID                                      FIT_ENUM_INVALID
#define FIT_FITNESS_EQUIPMENT_STATE_READY                                        ((FIT_FITNESS_EQUIPMENT_STATE)0)
#define FIT_FITNESS_EQUIPMENT_STATE_IN_USE                                       ((FIT_FITNESS_EQUIPMENT_STATE)1)
#define FIT_FITNESS_EQUIPMENT_STATE_PAUSED                                       ((FIT_FITNESS_EQUIPMENT_STATE)2)
#define FIT_FITNESS_EQUIPMENT_STATE_UNKNOWN                                      ((FIT_FITNESS_EQUIPMENT_STATE)3) // lost connection to fitness equipment
#define FIT_FITNESS_EQUIPMENT_STATE_COUNT                                        4

typedef FIT_ENUM FIT_ACTIVITY_CLASS;
#define FIT_ACTIVITY_CLASS_INVALID                                               FIT_ENUM_INVALID
#define FIT_ACTIVITY_CLASS_LEVEL                                                 ((FIT_ACTIVITY_CLASS)0x7F) // 0 to 100
#define FIT_ACTIVITY_CLASS_LEVEL_MAX                                             ((FIT_ACTIVITY_CLASS)100)
#define FIT_ACTIVITY_CLASS_ATHLETE                                               ((FIT_ACTIVITY_CLASS)0x80)
#define FIT_ACTIVITY_CLASS_COUNT                                                 3

typedef FIT_ENUM FIT_HR_ZONE_CALC;
#define FIT_HR_ZONE_CALC_INVALID                                                 FIT_ENUM_INVALID
#define FIT_HR_ZONE_CALC_CUSTOM                                                  ((FIT_HR_ZONE_CALC)0)
#define FIT_HR_ZONE_CALC_PERCENT_MAX_HR                                          ((FIT_HR_ZONE_CALC)1)
#define FIT_HR_ZONE_CALC_PERCENT_HRR                                             ((FIT_HR_ZONE_CALC)2)
#define FIT_HR_ZONE_CALC_COUNT                                                   3

typedef FIT_ENUM FIT_PWR_ZONE_CALC;
#define FIT_PWR_ZONE_CALC_INVALID                                                FIT_ENUM_INVALID
#define FIT_PWR_ZONE_CALC_CUSTOM                                                 ((FIT_PWR_ZONE_CALC)0)
#define FIT_PWR_ZONE_CALC_PERCENT_FTP                                            ((FIT_PWR_ZONE_CALC)1)
#define FIT_PWR_ZONE_CALC_COUNT                                                  2

typedef FIT_ENUM FIT_WKT_STEP_DURATION;
#define FIT_WKT_STEP_DURATION_INVALID                                            FIT_ENUM_INVALID
#define FIT_WKT_STEP_DURATION_TIME                                               ((FIT_WKT_STEP_DURATION)0)
#define FIT_WKT_STEP_DURATION_DISTANCE                                           ((FIT_WKT_STEP_DURATION)1)
#define FIT_WKT_STEP_DURATION_HR_LESS_THAN                                       ((FIT_WKT_STEP_DURATION)2)
#define FIT_WKT_STEP_DURATION_HR_GREATER_THAN                                    ((FIT_WKT_STEP_DURATION)3)
#define FIT_WKT_STEP_DURATION_CALORIES                                           ((FIT_WKT_STEP_DURATION)4)
#define FIT_WKT_STEP_DURATION_OPEN                                               ((FIT_WKT_STEP_DURATION)5)
#define FIT_WKT_STEP_DURATION_REPEAT_UNTIL_STEPS_CMPLT                           ((FIT_WKT_STEP_DURATION)6)
#define FIT_WKT_STEP_DURATION_REPEAT_UNTIL_TIME                                  ((FIT_WKT_STEP_DURATION)7)
#define FIT_WKT_STEP_DURATION_REPEAT_UNTIL_DISTANCE                              ((FIT_WKT_STEP_DURATION)8)
#define FIT_WKT_STEP_DURATION_REPEAT_UNTIL_CALORIES                              ((FIT_WKT_STEP_DURATION)9)
#define FIT_WKT_STEP_DURATION_REPEAT_UNTIL_HR_LESS_THAN                          ((FIT_WKT_STEP_DURATION)10)
#define FIT_WKT_STEP_DURATION_REPEAT_UNTIL_HR_GREATER_THAN                       ((FIT_WKT_STEP_DURATION)11)
#define FIT_WKT_STEP_DURATION_REPEAT_UNTIL_POWER_LESS_THAN                       ((FIT_WKT_STEP_DURATION)12)
#define FIT_WKT_STEP_DURATION_REPEAT_UNTIL_POWER_GREATER_THAN                    ((FIT_WKT_STEP_DURATION)13)
#define FIT_WKT_STEP_DURATION_POWER_LESS_THAN                                    ((FIT_WKT_STEP_DURATION)14)
#define FIT_WKT_STEP_DURATION_POWER_GREATER_THAN                                 ((FIT_WKT_STEP_DURATION)15)
#define FIT_WKT_STEP_DURATION_COUNT                                              16

typedef FIT_ENUM FIT_WKT_STEP_TARGET;
#define FIT_WKT_STEP_TARGET_INVALID                                              FIT_ENUM_INVALID
#define FIT_WKT_STEP_TARGET_SPEED                                                ((FIT_WKT_STEP_TARGET)0)
#define FIT_WKT_STEP_TARGET_HEART_RATE                                           ((FIT_WKT_STEP_TARGET)1)
#define FIT_WKT_STEP_TARGET_OPEN                                                 ((FIT_WKT_STEP_TARGET)2)
#define FIT_WKT_STEP_TARGET_CADENCE                                              ((FIT_WKT_STEP_TARGET)3)
#define FIT_WKT_STEP_TARGET_POWER                                                ((FIT_WKT_STEP_TARGET)4)
#define FIT_WKT_STEP_TARGET_GRADE                                                ((FIT_WKT_STEP_TARGET)5)
#define FIT_WKT_STEP_TARGET_RESISTANCE                                           ((FIT_WKT_STEP_TARGET)6)
#define FIT_WKT_STEP_TARGET_COUNT                                                7

typedef FIT_ENUM FIT_GOAL;
#define FIT_GOAL_INVALID                                                         FIT_ENUM_INVALID
#define FIT_GOAL_TIME                                                            ((FIT_GOAL)0)
#define FIT_GOAL_DISTANCE                                                        ((FIT_GOAL)1)
#define FIT_GOAL_CALORIES                                                        ((FIT_GOAL)2)
#define FIT_GOAL_FREQUENCY                                                       ((FIT_GOAL)3)
#define FIT_GOAL_STEPS                                                           ((FIT_GOAL)4)
#define FIT_GOAL_COUNT                                                           5

typedef FIT_ENUM FIT_GOAL_RECURRENCE;
#define FIT_GOAL_RECURRENCE_INVALID                                              FIT_ENUM_INVALID
#define FIT_GOAL_RECURRENCE_OFF                                                  ((FIT_GOAL_RECURRENCE)0)
#define FIT_GOAL_RECURRENCE_DAILY                                                ((FIT_GOAL_RECURRENCE)1)
#define FIT_GOAL_RECURRENCE_WEEKLY                                               ((FIT_GOAL_RECURRENCE)2)
#define FIT_GOAL_RECURRENCE_MONTHLY                                              ((FIT_GOAL_RECURRENCE)3)
#define FIT_GOAL_RECURRENCE_YEARLY                                               ((FIT_GOAL_RECURRENCE)4)
#define FIT_GOAL_RECURRENCE_CUSTOM                                               ((FIT_GOAL_RECURRENCE)5)
#define FIT_GOAL_RECURRENCE_COUNT                                                6

typedef FIT_ENUM FIT_SCHEDULE;
#define FIT_SCHEDULE_INVALID                                                     FIT_ENUM_INVALID
#define FIT_SCHEDULE_WORKOUT                                                     ((FIT_SCHEDULE)0)
#define FIT_SCHEDULE_COURSE                                                      ((FIT_SCHEDULE)1)
#define FIT_SCHEDULE_COUNT                                                       2

typedef FIT_ENUM FIT_COURSE_POINT;
#define FIT_COURSE_POINT_INVALID                                                 FIT_ENUM_INVALID
#define FIT_COURSE_POINT_GENERIC                                                 ((FIT_COURSE_POINT)0)
#define FIT_COURSE_POINT_SUMMIT                                                  ((FIT_COURSE_POINT)1)
#define FIT_COURSE_POINT_VALLEY                                                  ((FIT_COURSE_POINT)2)
#define FIT_COURSE_POINT_WATER                                                   ((FIT_COURSE_POINT)3)
#define FIT_COURSE_POINT_FOOD                                                    ((FIT_COURSE_POINT)4)
#define FIT_COURSE_POINT_DANGER                                                  ((FIT_COURSE_POINT)5)
#define FIT_COURSE_POINT_LEFT                                                    ((FIT_COURSE_POINT)6)
#define FIT_COURSE_POINT_RIGHT                                                   ((FIT_COURSE_POINT)7)
#define FIT_COURSE_POINT_STRAIGHT                                                ((FIT_COURSE_POINT)8)
#define FIT_COURSE_POINT_FIRST_AID                                               ((FIT_COURSE_POINT)9)
#define FIT_COURSE_POINT_FOURTH_CATEGORY                                         ((FIT_COURSE_POINT)10)
#define FIT_COURSE_POINT_THIRD_CATEGORY                                          ((FIT_COURSE_POINT)11)
#define FIT_COURSE_POINT_SECOND_CATEGORY                                         ((FIT_COURSE_POINT)12)
#define FIT_COURSE_POINT_FIRST_CATEGORY                                          ((FIT_COURSE_POINT)13)
#define FIT_COURSE_POINT_HORS_CATEGORY                                           ((FIT_COURSE_POINT)14)
#define FIT_COURSE_POINT_SPRINT                                                  ((FIT_COURSE_POINT)15)
#define FIT_COURSE_POINT_LEFT_FORK                                               ((FIT_COURSE_POINT)16)
#define FIT_COURSE_POINT_RIGHT_FORK                                              ((FIT_COURSE_POINT)17)
#define FIT_COURSE_POINT_MIDDLE_FORK                                             ((FIT_COURSE_POINT)18)
#define FIT_COURSE_POINT_SLIGHT_LEFT                                             ((FIT_COURSE_POINT)19)
#define FIT_COURSE_POINT_SHARP_LEFT                                              ((FIT_COURSE_POINT)20)
#define FIT_COURSE_POINT_SLIGHT_RIGHT                                            ((FIT_COURSE_POINT)21)
#define FIT_COURSE_POINT_SHARP_RIGHT                                             ((FIT_COURSE_POINT)22)
#define FIT_COURSE_POINT_U_TURN                                                  ((FIT_COURSE_POINT)23)
#define FIT_COURSE_POINT_COUNT                                                   24

typedef FIT_UINT16 FIT_MANUFACTURER;
#define FIT_MANUFACTURER_INVALID                                                 FIT_UINT16_INVALID
#define FIT_MANUFACTURER_GARMIN                                                  ((FIT_MANUFACTURER)1)
#define FIT_MANUFACTURER_GARMIN_FR405_ANTFS                                      ((FIT_MANUFACTURER)2) // Do not use.  Used by FR405 for ANTFS man id.
#define FIT_MANUFACTURER_ZEPHYR                                                  ((FIT_MANUFACTURER)3)
#define FIT_MANUFACTURER_DAYTON                                                  ((FIT_MANUFACTURER)4)
#define FIT_MANUFACTURER_IDT                                                     ((FIT_MANUFACTURER)5)
#define FIT_MANUFACTURER_SRM                                                     ((FIT_MANUFACTURER)6)
#define FIT_MANUFACTURER_QUARQ                                                   ((FIT_MANUFACTURER)7)
#define FIT_MANUFACTURER_IBIKE                                                   ((FIT_MANUFACTURER)8)
#define FIT_MANUFACTURER_SARIS                                                   ((FIT_MANUFACTURER)9)
#define FIT_MANUFACTURER_SPARK_HK                                                ((FIT_MANUFACTURER)10)
#define FIT_MANUFACTURER_TANITA                                                  ((FIT_MANUFACTURER)11)
#define FIT_MANUFACTURER_ECHOWELL                                                ((FIT_MANUFACTURER)12)
#define FIT_MANUFACTURER_DYNASTREAM_OEM                                          ((FIT_MANUFACTURER)13)
#define FIT_MANUFACTURER_NAUTILUS                                                ((FIT_MANUFACTURER)14)
#define FIT_MANUFACTURER_DYNASTREAM                                              ((FIT_MANUFACTURER)15)
#define FIT_MANUFACTURER_TIMEX                                                   ((FIT_MANUFACTURER)16)
#define FIT_MANUFACTURER_METRIGEAR                                               ((FIT_MANUFACTURER)17)
#define FIT_MANUFACTURER_XELIC                                                   ((FIT_MANUFACTURER)18)
#define FIT_MANUFACTURER_BEURER                                                  ((FIT_MANUFACTURER)19)
#define FIT_MANUFACTURER_CARDIOSPORT                                             ((FIT_MANUFACTURER)20)
#define FIT_MANUFACTURER_A_AND_D                                                 ((FIT_MANUFACTURER)21)
#define FIT_MANUFACTURER_HMM                                                     ((FIT_MANUFACTURER)22)
#define FIT_MANUFACTURER_SUUNTO                                                  ((FIT_MANUFACTURER)23)
#define FIT_MANUFACTURER_THITA_ELEKTRONIK                                        ((FIT_MANUFACTURER)24)
#define FIT_MANUFACTURER_GPULSE                                                  ((FIT_MANUFACTURER)25)
#define FIT_MANUFACTURER_CLEAN_MOBILE                                            ((FIT_MANUFACTURER)26)
#define FIT_MANUFACTURER_PEDAL_BRAIN                                             ((FIT_MANUFACTURER)27)
#define FIT_MANUFACTURER_PEAKSWARE                                               ((FIT_MANUFACTURER)28)
#define FIT_MANUFACTURER_SAXONAR                                                 ((FIT_MANUFACTURER)29)
#define FIT_MANUFACTURER_LEMOND_FITNESS                                          ((FIT_MANUFACTURER)30)
#define FIT_MANUFACTURER_DEXCOM                                                  ((FIT_MANUFACTURER)31)
#define FIT_MANUFACTURER_WAHOO_FITNESS                                           ((FIT_MANUFACTURER)32)
#define FIT_MANUFACTURER_OCTANE_FITNESS                                          ((FIT_MANUFACTURER)33)
#define FIT_MANUFACTURER_ARCHINOETICS                                            ((FIT_MANUFACTURER)34)
#define FIT_MANUFACTURER_THE_HURT_BOX                                            ((FIT_MANUFACTURER)35)
#define FIT_MANUFACTURER_CITIZEN_SYSTEMS                                         ((FIT_MANUFACTURER)36)
#define FIT_MANUFACTURER_MAGELLAN                                                ((FIT_MANUFACTURER)37)
#define FIT_MANUFACTURER_OSYNCE                                                  ((FIT_MANUFACTURER)38)
#define FIT_MANUFACTURER_HOLUX                                                   ((FIT_MANUFACTURER)39)
#define FIT_MANUFACTURER_CONCEPT2                                                ((FIT_MANUFACTURER)40)
#define FIT_MANUFACTURER_ONE_GIANT_LEAP                                          ((FIT_MANUFACTURER)42)
#define FIT_MANUFACTURER_ACE_SENSOR                                              ((FIT_MANUFACTURER)43)
#define FIT_MANUFACTURER_BRIM_BROTHERS                                           ((FIT_MANUFACTURER)44)
#define FIT_MANUFACTURER_XPLOVA                                                  ((FIT_MANUFACTURER)45)
#define FIT_MANUFACTURER_PERCEPTION_DIGITAL                                      ((FIT_MANUFACTURER)46)
#define FIT_MANUFACTURER_BF1SYSTEMS                                              ((FIT_MANUFACTURER)47)
#define FIT_MANUFACTURER_PIONEER                                                 ((FIT_MANUFACTURER)48)
#define FIT_MANUFACTURER_SPANTEC                                                 ((FIT_MANUFACTURER)49)
#define FIT_MANUFACTURER_METALOGICS                                              ((FIT_MANUFACTURER)50)
#define FIT_MANUFACTURER_4IIIIS                                                  ((FIT_MANUFACTURER)51)
#define FIT_MANUFACTURER_SEIKO_EPSON                                             ((FIT_MANUFACTURER)52)
#define FIT_MANUFACTURER_SEIKO_EPSON_OEM                                         ((FIT_MANUFACTURER)53)
#define FIT_MANUFACTURER_IFOR_POWELL                                             ((FIT_MANUFACTURER)54)
#define FIT_MANUFACTURER_MAXWELL_GUIDER                                          ((FIT_MANUFACTURER)55)
#define FIT_MANUFACTURER_STAR_TRAC                                               ((FIT_MANUFACTURER)56)
#define FIT_MANUFACTURER_BREAKAWAY                                               ((FIT_MANUFACTURER)57)
#define FIT_MANUFACTURER_ALATECH_TECHNOLOGY_LTD                                  ((FIT_MANUFACTURER)58)
#define FIT_MANUFACTURER_MIO_TECHNOLOGY_EUROPE                                   ((FIT_MANUFACTURER)59)
#define FIT_MANUFACTURER_ROTOR                                                   ((FIT_MANUFACTURER)60)
#define FIT_MANUFACTURER_GEONAUTE                                                ((FIT_MANUFACTURER)61)
#define FIT_MANUFACTURER_ID_BIKE                                                 ((FIT_MANUFACTURER)62)
#define FIT_MANUFACTURER_SPECIALIZED                                             ((FIT_MANUFACTURER)63)
#define FIT_MANUFACTURER_WTEK                                                    ((FIT_MANUFACTURER)64)
#define FIT_MANUFACTURER_PHYSICAL_ENTERPRISES                                    ((FIT_MANUFACTURER)65)
#define FIT_MANUFACTURER_NORTH_POLE_ENGINEERING                                  ((FIT_MANUFACTURER)66)
#define FIT_MANUFACTURER_BKOOL                                                   ((FIT_MANUFACTURER)67)
#define FIT_MANUFACTURER_CATEYE                                                  ((FIT_MANUFACTURER)68)
#define FIT_MANUFACTURER_STAGES_CYCLING                                          ((FIT_MANUFACTURER)69)
#define FIT_MANUFACTURER_SIGMASPORT                                              ((FIT_MANUFACTURER)70)
#define FIT_MANUFACTURER_TOMTOM                                                  ((FIT_MANUFACTURER)71)
#define FIT_MANUFACTURER_PERIPEDAL                                               ((FIT_MANUFACTURER)72)
#define FIT_MANUFACTURER_WATTBIKE                                                ((FIT_MANUFACTURER)73)
#define FIT_MANUFACTURER_MOXY                                                    ((FIT_MANUFACTURER)76)
#define FIT_MANUFACTURER_CICLOSPORT                                              ((FIT_MANUFACTURER)77)
#define FIT_MANUFACTURER_POWERBAHN                                               ((FIT_MANUFACTURER)78)
#define FIT_MANUFACTURER_ACORN_PROJECTS_APS                                      ((FIT_MANUFACTURER)79)
#define FIT_MANUFACTURER_LIFEBEAM                                                ((FIT_MANUFACTURER)80)
#define FIT_MANUFACTURER_BONTRAGER                                               ((FIT_MANUFACTURER)81)
#define FIT_MANUFACTURER_WELLGO                                                  ((FIT_MANUFACTURER)82)
#define FIT_MANUFACTURER_DEVELOPMENT                                             ((FIT_MANUFACTURER)255)
#define FIT_MANUFACTURER_ACTIGRAPHCORP                                           ((FIT_MANUFACTURER)5759)
#define FIT_MANUFACTURER_COUNT                                                   81

typedef FIT_UINT16 FIT_GARMIN_PRODUCT;
#define FIT_GARMIN_PRODUCT_INVALID                                               FIT_UINT16_INVALID
#define FIT_GARMIN_PRODUCT_HRM1                                                  ((FIT_GARMIN_PRODUCT)1)
#define FIT_GARMIN_PRODUCT_AXH01                                                 ((FIT_GARMIN_PRODUCT)2) // AXH01 HRM chipset
#define FIT_GARMIN_PRODUCT_AXB01                                                 ((FIT_GARMIN_PRODUCT)3)
#define FIT_GARMIN_PRODUCT_AXB02                                                 ((FIT_GARMIN_PRODUCT)4)
#define FIT_GARMIN_PRODUCT_HRM2SS                                                ((FIT_GARMIN_PRODUCT)5)
#define FIT_GARMIN_PRODUCT_DSI_ALF02                                             ((FIT_GARMIN_PRODUCT)6)
#define FIT_GARMIN_PRODUCT_HRM_RUN_SINGLE_BYTE_PRODUCT_ID                        ((FIT_GARMIN_PRODUCT)8) // hrm_run model for HRM ANT+ messaging
#define FIT_GARMIN_PRODUCT_FR301_CHINA                                           ((FIT_GARMIN_PRODUCT)473)
#define FIT_GARMIN_PRODUCT_FR301_JAPAN                                           ((FIT_GARMIN_PRODUCT)474)
#define FIT_GARMIN_PRODUCT_FR301_KOREA                                           ((FIT_GARMIN_PRODUCT)475)
#define FIT_GARMIN_PRODUCT_FR301_TAIWAN                                          ((FIT_GARMIN_PRODUCT)494)
#define FIT_GARMIN_PRODUCT_FR405                                                 ((FIT_GARMIN_PRODUCT)717) // Forerunner 405
#define FIT_GARMIN_PRODUCT_FR50                                                  ((FIT_GARMIN_PRODUCT)782) // Forerunner 50
#define FIT_GARMIN_PRODUCT_FR405_JAPAN                                           ((FIT_GARMIN_PRODUCT)987)
#define FIT_GARMIN_PRODUCT_FR60                                                  ((FIT_GARMIN_PRODUCT)988) // Forerunner 60
#define FIT_GARMIN_PRODUCT_DSI_ALF01                                             ((FIT_GARMIN_PRODUCT)1011)
#define FIT_GARMIN_PRODUCT_FR310XT                                               ((FIT_GARMIN_PRODUCT)1018) // Forerunner 310
#define FIT_GARMIN_PRODUCT_EDGE500                                               ((FIT_GARMIN_PRODUCT)1036)
#define FIT_GARMIN_PRODUCT_FR110                                                 ((FIT_GARMIN_PRODUCT)1124) // Forerunner 110
#define FIT_GARMIN_PRODUCT_EDGE800                                               ((FIT_GARMIN_PRODUCT)1169)
#define FIT_GARMIN_PRODUCT_EDGE500_TAIWAN                                        ((FIT_GARMIN_PRODUCT)1199)
#define FIT_GARMIN_PRODUCT_EDGE500_JAPAN                                         ((FIT_GARMIN_PRODUCT)1213)
#define FIT_GARMIN_PRODUCT_CHIRP                                                 ((FIT_GARMIN_PRODUCT)1253)
#define FIT_GARMIN_PRODUCT_FR110_JAPAN                                           ((FIT_GARMIN_PRODUCT)1274)
#define FIT_GARMIN_PRODUCT_EDGE200                                               ((FIT_GARMIN_PRODUCT)1325)
#define FIT_GARMIN_PRODUCT_FR910XT                                               ((FIT_GARMIN_PRODUCT)1328)
#define FIT_GARMIN_PRODUCT_EDGE800_TAIWAN                                        ((FIT_GARMIN_PRODUCT)1333)
#define FIT_GARMIN_PRODUCT_EDGE800_JAPAN                                         ((FIT_GARMIN_PRODUCT)1334)
#define FIT_GARMIN_PRODUCT_ALF04                                                 ((FIT_GARMIN_PRODUCT)1341)
#define FIT_GARMIN_PRODUCT_FR610                                                 ((FIT_GARMIN_PRODUCT)1345)
#define FIT_GARMIN_PRODUCT_FR210_JAPAN                                           ((FIT_GARMIN_PRODUCT)1360)
#define FIT_GARMIN_PRODUCT_VECTOR_SS                                             ((FIT_GARMIN_PRODUCT)1380)
#define FIT_GARMIN_PRODUCT_VECTOR_CP                                             ((FIT_GARMIN_PRODUCT)1381)
#define FIT_GARMIN_PRODUCT_EDGE800_CHINA                                         ((FIT_GARMIN_PRODUCT)1386)
#define FIT_GARMIN_PRODUCT_EDGE500_CHINA                                         ((FIT_GARMIN_PRODUCT)1387)
#define FIT_GARMIN_PRODUCT_FR610_JAPAN                                           ((FIT_GARMIN_PRODUCT)1410)
#define FIT_GARMIN_PRODUCT_EDGE500_KOREA                                         ((FIT_GARMIN_PRODUCT)1422)
#define FIT_GARMIN_PRODUCT_FR70                                                  ((FIT_GARMIN_PRODUCT)1436)
#define FIT_GARMIN_PRODUCT_FR310XT_4T                                            ((FIT_GARMIN_PRODUCT)1446)
#define FIT_GARMIN_PRODUCT_AMX                                                   ((FIT_GARMIN_PRODUCT)1461)
#define FIT_GARMIN_PRODUCT_FR10                                                  ((FIT_GARMIN_PRODUCT)1482)
#define FIT_GARMIN_PRODUCT_EDGE800_KOREA                                         ((FIT_GARMIN_PRODUCT)1497)
#define FIT_GARMIN_PRODUCT_SWIM                                                  ((FIT_GARMIN_PRODUCT)1499)
#define FIT_GARMIN_PRODUCT_FR910XT_CHINA                                         ((FIT_GARMIN_PRODUCT)1537)
#define FIT_GARMIN_PRODUCT_FENIX                                                 ((FIT_GARMIN_PRODUCT)1551)
#define FIT_GARMIN_PRODUCT_EDGE200_TAIWAN                                        ((FIT_GARMIN_PRODUCT)1555)
#define FIT_GARMIN_PRODUCT_EDGE510                                               ((FIT_GARMIN_PRODUCT)1561)
#define FIT_GARMIN_PRODUCT_EDGE810                                               ((FIT_GARMIN_PRODUCT)1567)
#define FIT_GARMIN_PRODUCT_TEMPE                                                 ((FIT_GARMIN_PRODUCT)1570)
#define FIT_GARMIN_PRODUCT_FR910XT_JAPAN                                         ((FIT_GARMIN_PRODUCT)1600)
#define FIT_GARMIN_PRODUCT_FR620                                                 ((FIT_GARMIN_PRODUCT)1623)
#define FIT_GARMIN_PRODUCT_FR220                                                 ((FIT_GARMIN_PRODUCT)1632)
#define FIT_GARMIN_PRODUCT_FR910XT_KOREA                                         ((FIT_GARMIN_PRODUCT)1664)
#define FIT_GARMIN_PRODUCT_FR10_JAPAN                                            ((FIT_GARMIN_PRODUCT)1688)
#define FIT_GARMIN_PRODUCT_EDGE810_JAPAN                                         ((FIT_GARMIN_PRODUCT)1721)
#define FIT_GARMIN_PRODUCT_VIRB_ELITE                                            ((FIT_GARMIN_PRODUCT)1735)
#define FIT_GARMIN_PRODUCT_EDGE_TOURING                                          ((FIT_GARMIN_PRODUCT)1736) // Also Edge Touring Plus
#define FIT_GARMIN_PRODUCT_EDGE510_JAPAN                                         ((FIT_GARMIN_PRODUCT)1742)
#define FIT_GARMIN_PRODUCT_HRM_RUN                                               ((FIT_GARMIN_PRODUCT)1752)
#define FIT_GARMIN_PRODUCT_EDGE510_ASIA                                          ((FIT_GARMIN_PRODUCT)1821)
#define FIT_GARMIN_PRODUCT_EDGE810_CHINA                                         ((FIT_GARMIN_PRODUCT)1822)
#define FIT_GARMIN_PRODUCT_EDGE810_TAIWAN                                        ((FIT_GARMIN_PRODUCT)1823)
#define FIT_GARMIN_PRODUCT_VIVO_FIT                                              ((FIT_GARMIN_PRODUCT)1837)
#define FIT_GARMIN_PRODUCT_VIRB_REMOTE                                           ((FIT_GARMIN_PRODUCT)1853)
#define FIT_GARMIN_PRODUCT_SDM4                                                  ((FIT_GARMIN_PRODUCT)10007) // SDM4 footpod
#define FIT_GARMIN_PRODUCT_TRAINING_CENTER                                       ((FIT_GARMIN_PRODUCT)20119)
#define FIT_GARMIN_PRODUCT_ANDROID_ANTPLUS_PLUGIN                                ((FIT_GARMIN_PRODUCT)65532)
#define FIT_GARMIN_PRODUCT_CONNECT                                               ((FIT_GARMIN_PRODUCT)65534) // Garmin Connect website
#define FIT_GARMIN_PRODUCT_COUNT                                                 68

typedef FIT_UINT8 FIT_ANTPLUS_DEVICE_TYPE;
#define FIT_ANTPLUS_DEVICE_TYPE_INVALID                                          FIT_UINT8_INVALID
#define FIT_ANTPLUS_DEVICE_TYPE_ANTFS                                            ((FIT_ANTPLUS_DEVICE_TYPE)1)
#define FIT_ANTPLUS_DEVICE_TYPE_BIKE_POWER                                       ((FIT_ANTPLUS_DEVICE_TYPE)11)
#define FIT_ANTPLUS_DEVICE_TYPE_ENVIRONMENT_SENSOR_LEGACY                        ((FIT_ANTPLUS_DEVICE_TYPE)12)
#define FIT_ANTPLUS_DEVICE_TYPE_MULTI_SPORT_SPEED_DISTANCE                       ((FIT_ANTPLUS_DEVICE_TYPE)15)
#define FIT_ANTPLUS_DEVICE_TYPE_CONTROL                                          ((FIT_ANTPLUS_DEVICE_TYPE)16)
#define FIT_ANTPLUS_DEVICE_TYPE_FITNESS_EQUIPMENT                                ((FIT_ANTPLUS_DEVICE_TYPE)17)
#define FIT_ANTPLUS_DEVICE_TYPE_BLOOD_PRESSURE                                   ((FIT_ANTPLUS_DEVICE_TYPE)18)
#define FIT_ANTPLUS_DEVICE_TYPE_GEOCACHE_NODE                                    ((FIT_ANTPLUS_DEVICE_TYPE)19)
#define FIT_ANTPLUS_DEVICE_TYPE_LIGHT_ELECTRIC_VEHICLE                           ((FIT_ANTPLUS_DEVICE_TYPE)20)
#define FIT_ANTPLUS_DEVICE_TYPE_ENV_SENSOR                                       ((FIT_ANTPLUS_DEVICE_TYPE)25)
#define FIT_ANTPLUS_DEVICE_TYPE_RACQUET                                          ((FIT_ANTPLUS_DEVICE_TYPE)26)
#define FIT_ANTPLUS_DEVICE_TYPE_WEIGHT_SCALE                                     ((FIT_ANTPLUS_DEVICE_TYPE)119)
#define FIT_ANTPLUS_DEVICE_TYPE_HEART_RATE                                       ((FIT_ANTPLUS_DEVICE_TYPE)120)
#define FIT_ANTPLUS_DEVICE_TYPE_BIKE_SPEED_CADENCE                               ((FIT_ANTPLUS_DEVICE_TYPE)121)
#define FIT_ANTPLUS_DEVICE_TYPE_BIKE_CADENCE                                     ((FIT_ANTPLUS_DEVICE_TYPE)122)
#define FIT_ANTPLUS_DEVICE_TYPE_BIKE_SPEED                                       ((FIT_ANTPLUS_DEVICE_TYPE)123)
#define FIT_ANTPLUS_DEVICE_TYPE_STRIDE_SPEED_DISTANCE                            ((FIT_ANTPLUS_DEVICE_TYPE)124)
#define FIT_ANTPLUS_DEVICE_TYPE_COUNT                                            17

typedef FIT_ENUM FIT_ANT_NETWORK;
#define FIT_ANT_NETWORK_INVALID                                                  FIT_ENUM_INVALID
#define FIT_ANT_NETWORK_PUBLIC                                                   ((FIT_ANT_NETWORK)0)
#define FIT_ANT_NETWORK_ANTPLUS                                                  ((FIT_ANT_NETWORK)1)
#define FIT_ANT_NETWORK_ANTFS                                                    ((FIT_ANT_NETWORK)2)
#define FIT_ANT_NETWORK_PRIVATE                                                  ((FIT_ANT_NETWORK)3)
#define FIT_ANT_NETWORK_COUNT                                                    4

typedef FIT_UINT32Z FIT_WORKOUT_CAPABILITIES;
#define FIT_WORKOUT_CAPABILITIES_INVALID                                         FIT_UINT32Z_INVALID
#define FIT_WORKOUT_CAPABILITIES_INTERVAL                                        ((FIT_WORKOUT_CAPABILITIES)0x00000001)
#define FIT_WORKOUT_CAPABILITIES_CUSTOM                                          ((FIT_WORKOUT_CAPABILITIES)0x00000002)
#define FIT_WORKOUT_CAPABILITIES_FITNESS_EQUIPMENT                               ((FIT_WORKOUT_CAPABILITIES)0x00000004)
#define FIT_WORKOUT_CAPABILITIES_FIRSTBEAT                                       ((FIT_WORKOUT_CAPABILITIES)0x00000008)
#define FIT_WORKOUT_CAPABILITIES_NEW_LEAF                                        ((FIT_WORKOUT_CAPABILITIES)0x00000010)
#define FIT_WORKOUT_CAPABILITIES_TCX                                             ((FIT_WORKOUT_CAPABILITIES)0x00000020) // For backwards compatibility.  Watch should add missing id fields then clear flag.
#define FIT_WORKOUT_CAPABILITIES_SPEED                                           ((FIT_WORKOUT_CAPABILITIES)0x00000080) // Speed source required for workout step.
#define FIT_WORKOUT_CAPABILITIES_HEART_RATE                                      ((FIT_WORKOUT_CAPABILITIES)0x00000100) // Heart rate source required for workout step.
#define FIT_WORKOUT_CAPABILITIES_DISTANCE                                        ((FIT_WORKOUT_CAPABILITIES)0x00000200) // Distance source required for workout step.
#define FIT_WORKOUT_CAPABILITIES_CADENCE                                         ((FIT_WORKOUT_CAPABILITIES)0x00000400) // Cadence source required for workout step.
#define FIT_WORKOUT_CAPABILITIES_POWER                                           ((FIT_WORKOUT_CAPABILITIES)0x00000800) // Power source required for workout step.
#define FIT_WORKOUT_CAPABILITIES_GRADE                                           ((FIT_WORKOUT_CAPABILITIES)0x00001000) // Grade source required for workout step.
#define FIT_WORKOUT_CAPABILITIES_RESISTANCE                                      ((FIT_WORKOUT_CAPABILITIES)0x00002000) // Resistance source required for workout step.
#define FIT_WORKOUT_CAPABILITIES_PROTECTED                                       ((FIT_WORKOUT_CAPABILITIES)0x00004000)
#define FIT_WORKOUT_CAPABILITIES_COUNT                                           14

typedef FIT_UINT8 FIT_BATTERY_STATUS;
#define FIT_BATTERY_STATUS_INVALID                                               FIT_UINT8_INVALID
#define FIT_BATTERY_STATUS_NEW                                                   ((FIT_BATTERY_STATUS)1)
#define FIT_BATTERY_STATUS_GOOD                                                  ((FIT_BATTERY_STATUS)2)
#define FIT_BATTERY_STATUS_OK                                                    ((FIT_BATTERY_STATUS)3)
#define FIT_BATTERY_STATUS_LOW                                                   ((FIT_BATTERY_STATUS)4)
#define FIT_BATTERY_STATUS_CRITICAL                                              ((FIT_BATTERY_STATUS)5)
#define FIT_BATTERY_STATUS_COUNT                                                 5

typedef FIT_ENUM FIT_HR_TYPE;
#define FIT_HR_TYPE_INVALID                                                      FIT_ENUM_INVALID
#define FIT_HR_TYPE_NORMAL                                                       ((FIT_HR_TYPE)0)
#define FIT_HR_TYPE_IRREGULAR                                                    ((FIT_HR_TYPE)1)
#define FIT_HR_TYPE_COUNT                                                        2

typedef FIT_UINT32Z FIT_COURSE_CAPABILITIES;
#define FIT_COURSE_CAPABILITIES_INVALID                                          FIT_UINT32Z_INVALID
#define FIT_COURSE_CAPABILITIES_PROCESSED                                        ((FIT_COURSE_CAPABILITIES)0x00000001)
#define FIT_COURSE_CAPABILITIES_VALID                                            ((FIT_COURSE_CAPABILITIES)0x00000002)
#define FIT_COURSE_CAPABILITIES_TIME                                             ((FIT_COURSE_CAPABILITIES)0x00000004)
#define FIT_COURSE_CAPABILITIES_DISTANCE                                         ((FIT_COURSE_CAPABILITIES)0x00000008)
#define FIT_COURSE_CAPABILITIES_POSITION                                         ((FIT_COURSE_CAPABILITIES)0x00000010)
#define FIT_COURSE_CAPABILITIES_HEART_RATE                                       ((FIT_COURSE_CAPABILITIES)0x00000020)
#define FIT_COURSE_CAPABILITIES_POWER                                            ((FIT_COURSE_CAPABILITIES)0x00000040)
#define FIT_COURSE_CAPABILITIES_CADENCE                                          ((FIT_COURSE_CAPABILITIES)0x00000080)
#define FIT_COURSE_CAPABILITIES_TRAINING                                         ((FIT_COURSE_CAPABILITIES)0x00000100)
#define FIT_COURSE_CAPABILITIES_NAVIGATION                                       ((FIT_COURSE_CAPABILITIES)0x00000200)
#define FIT_COURSE_CAPABILITIES_COUNT                                            10

typedef FIT_UINT16 FIT_WEIGHT;
#define FIT_WEIGHT_INVALID                                                       FIT_UINT16_INVALID
#define FIT_WEIGHT_CALCULATING                                                   ((FIT_WEIGHT)0xFFFE)
#define FIT_WEIGHT_COUNT                                                         1

typedef FIT_UINT32 FIT_WORKOUT_HR; // 0 - 100 indicates% of maz hr; >100 indicates bpm (255 max) plus 100
#define FIT_WORKOUT_HR_INVALID                                                   FIT_UINT32_INVALID
#define FIT_WORKOUT_HR_BPM_OFFSET                                                ((FIT_WORKOUT_HR)100)
#define FIT_WORKOUT_HR_COUNT                                                     1

typedef FIT_UINT32 FIT_WORKOUT_POWER; // 0 - 1000 indicates % of functional threshold power; >1000 indicates watts plus 1000.
#define FIT_WORKOUT_POWER_INVALID                                                FIT_UINT32_INVALID
#define FIT_WORKOUT_POWER_WATTS_OFFSET                                           ((FIT_WORKOUT_POWER)1000)
#define FIT_WORKOUT_POWER_COUNT                                                  1

typedef FIT_ENUM FIT_BP_STATUS;
#define FIT_BP_STATUS_INVALID                                                    FIT_ENUM_INVALID
#define FIT_BP_STATUS_NO_ERROR                                                   ((FIT_BP_STATUS)0)
#define FIT_BP_STATUS_ERROR_INCOMPLETE_DATA                                      ((FIT_BP_STATUS)1)
#define FIT_BP_STATUS_ERROR_NO_MEASUREMENT                                       ((FIT_BP_STATUS)2)
#define FIT_BP_STATUS_ERROR_DATA_OUT_OF_RANGE                                    ((FIT_BP_STATUS)3)
#define FIT_BP_STATUS_ERROR_IRREGULAR_HEART_RATE                                 ((FIT_BP_STATUS)4)
#define FIT_BP_STATUS_COUNT                                                      5

typedef FIT_UINT16 FIT_USER_LOCAL_ID;
#define FIT_USER_LOCAL_ID_INVALID                                                FIT_UINT16_INVALID
#define FIT_USER_LOCAL_ID_LOCAL_MIN                                              ((FIT_USER_LOCAL_ID)0x0000)
#define FIT_USER_LOCAL_ID_LOCAL_MAX                                              ((FIT_USER_LOCAL_ID)0x000F)
#define FIT_USER_LOCAL_ID_STATIONARY_MIN                                         ((FIT_USER_LOCAL_ID)0x0010)
#define FIT_USER_LOCAL_ID_STATIONARY_MAX                                         ((FIT_USER_LOCAL_ID)0x00FF)
#define FIT_USER_LOCAL_ID_PORTABLE_MIN                                           ((FIT_USER_LOCAL_ID)0x0100)
#define FIT_USER_LOCAL_ID_PORTABLE_MAX                                           ((FIT_USER_LOCAL_ID)0xFFFE)
#define FIT_USER_LOCAL_ID_COUNT                                                  6

typedef FIT_ENUM FIT_SWIM_STROKE;
#define FIT_SWIM_STROKE_INVALID                                                  FIT_ENUM_INVALID
#define FIT_SWIM_STROKE_FREESTYLE                                                ((FIT_SWIM_STROKE)0)
#define FIT_SWIM_STROKE_BACKSTROKE                                               ((FIT_SWIM_STROKE)1)
#define FIT_SWIM_STROKE_BREASTSTROKE                                             ((FIT_SWIM_STROKE)2)
#define FIT_SWIM_STROKE_BUTTERFLY                                                ((FIT_SWIM_STROKE)3)
#define FIT_SWIM_STROKE_DRILL                                                    ((FIT_SWIM_STROKE)4)
#define FIT_SWIM_STROKE_MIXED                                                    ((FIT_SWIM_STROKE)5)
#define FIT_SWIM_STROKE_IM                                                       ((FIT_SWIM_STROKE)6) // IM is a mixed interval containing the same number of lengths for each of: Butterfly, Backstroke, Breaststroke, Freestyle, swam in that order.
#define FIT_SWIM_STROKE_COUNT                                                    7

typedef FIT_ENUM FIT_ACTIVITY_TYPE;
#define FIT_ACTIVITY_TYPE_INVALID                                                FIT_ENUM_INVALID
#define FIT_ACTIVITY_TYPE_GENERIC                                                ((FIT_ACTIVITY_TYPE)0)
#define FIT_ACTIVITY_TYPE_RUNNING                                                ((FIT_ACTIVITY_TYPE)1)
#define FIT_ACTIVITY_TYPE_CYCLING                                                ((FIT_ACTIVITY_TYPE)2)
#define FIT_ACTIVITY_TYPE_TRANSITION                                             ((FIT_ACTIVITY_TYPE)3) // Mulitsport transition
#define FIT_ACTIVITY_TYPE_FITNESS_EQUIPMENT                                      ((FIT_ACTIVITY_TYPE)4)
#define FIT_ACTIVITY_TYPE_SWIMMING                                               ((FIT_ACTIVITY_TYPE)5)
#define FIT_ACTIVITY_TYPE_WALKING                                                ((FIT_ACTIVITY_TYPE)6)
#define FIT_ACTIVITY_TYPE_ALL                                                    ((FIT_ACTIVITY_TYPE)254) // All is for goals only to include all sports.
#define FIT_ACTIVITY_TYPE_COUNT                                                  8

typedef FIT_ENUM FIT_ACTIVITY_SUBTYPE;
#define FIT_ACTIVITY_SUBTYPE_INVALID                                             FIT_ENUM_INVALID
#define FIT_ACTIVITY_SUBTYPE_GENERIC                                             ((FIT_ACTIVITY_SUBTYPE)0)
#define FIT_ACTIVITY_SUBTYPE_TREADMILL                                           ((FIT_ACTIVITY_SUBTYPE)1) // Run
#define FIT_ACTIVITY_SUBTYPE_STREET                                              ((FIT_ACTIVITY_SUBTYPE)2) // Run
#define FIT_ACTIVITY_SUBTYPE_TRAIL                                               ((FIT_ACTIVITY_SUBTYPE)3) // Run
#define FIT_ACTIVITY_SUBTYPE_TRACK                                               ((FIT_ACTIVITY_SUBTYPE)4) // Run
#define FIT_ACTIVITY_SUBTYPE_SPIN                                                ((FIT_ACTIVITY_SUBTYPE)5) // Cycling
#define FIT_ACTIVITY_SUBTYPE_INDOOR_CYCLING                                      ((FIT_ACTIVITY_SUBTYPE)6) // Cycling
#define FIT_ACTIVITY_SUBTYPE_ROAD                                                ((FIT_ACTIVITY_SUBTYPE)7) // Cycling
#define FIT_ACTIVITY_SUBTYPE_MOUNTAIN                                            ((FIT_ACTIVITY_SUBTYPE)8) // Cycling
#define FIT_ACTIVITY_SUBTYPE_DOWNHILL                                            ((FIT_ACTIVITY_SUBTYPE)9) // Cycling
#define FIT_ACTIVITY_SUBTYPE_RECUMBENT                                           ((FIT_ACTIVITY_SUBTYPE)10) // Cycling
#define FIT_ACTIVITY_SUBTYPE_CYCLOCROSS                                          ((FIT_ACTIVITY_SUBTYPE)11) // Cycling
#define FIT_ACTIVITY_SUBTYPE_HAND_CYCLING                                        ((FIT_ACTIVITY_SUBTYPE)12) // Cycling
#define FIT_ACTIVITY_SUBTYPE_TRACK_CYCLING                                       ((FIT_ACTIVITY_SUBTYPE)13) // Cycling
#define FIT_ACTIVITY_SUBTYPE_INDOOR_ROWING                                       ((FIT_ACTIVITY_SUBTYPE)14) // Fitness Equipment
#define FIT_ACTIVITY_SUBTYPE_ELLIPTICAL                                          ((FIT_ACTIVITY_SUBTYPE)15) // Fitness Equipment
#define FIT_ACTIVITY_SUBTYPE_STAIR_CLIMBING                                      ((FIT_ACTIVITY_SUBTYPE)16) // Fitness Equipment
#define FIT_ACTIVITY_SUBTYPE_LAP_SWIMMING                                        ((FIT_ACTIVITY_SUBTYPE)17) // Swimming
#define FIT_ACTIVITY_SUBTYPE_OPEN_WATER                                          ((FIT_ACTIVITY_SUBTYPE)18) // Swimming
#define FIT_ACTIVITY_SUBTYPE_ALL                                                 ((FIT_ACTIVITY_SUBTYPE)254)
#define FIT_ACTIVITY_SUBTYPE_COUNT                                               20

typedef FIT_ENUM FIT_ACTIVITY_LEVEL;
#define FIT_ACTIVITY_LEVEL_INVALID                                               FIT_ENUM_INVALID
#define FIT_ACTIVITY_LEVEL_LOW                                                   ((FIT_ACTIVITY_LEVEL)0)
#define FIT_ACTIVITY_LEVEL_MEDIUM                                                ((FIT_ACTIVITY_LEVEL)1)
#define FIT_ACTIVITY_LEVEL_HIGH                                                  ((FIT_ACTIVITY_LEVEL)2)
#define FIT_ACTIVITY_LEVEL_COUNT                                                 3

typedef FIT_UINT8 FIT_LEFT_RIGHT_BALANCE;
#define FIT_LEFT_RIGHT_BALANCE_INVALID                                           FIT_UINT8_INVALID
#define FIT_LEFT_RIGHT_BALANCE_MASK                                              ((FIT_LEFT_RIGHT_BALANCE)0x7F) // % contribution
#define FIT_LEFT_RIGHT_BALANCE_RIGHT                                             ((FIT_LEFT_RIGHT_BALANCE)0x80) // data corresponds to right if set, otherwise unknown
#define FIT_LEFT_RIGHT_BALANCE_COUNT                                             2

typedef FIT_UINT16 FIT_LEFT_RIGHT_BALANCE_100;
#define FIT_LEFT_RIGHT_BALANCE_100_INVALID                                       FIT_UINT16_INVALID
#define FIT_LEFT_RIGHT_BALANCE_100_MASK                                          ((FIT_LEFT_RIGHT_BALANCE_100)0x3FFF) // % contribution scaled by 100
#define FIT_LEFT_RIGHT_BALANCE_100_RIGHT                                         ((FIT_LEFT_RIGHT_BALANCE_100)0x8000) // data corresponds to right if set, otherwise unknown
#define FIT_LEFT_RIGHT_BALANCE_100_COUNT                                         2

typedef FIT_ENUM FIT_LENGTH_TYPE;
#define FIT_LENGTH_TYPE_INVALID                                                  FIT_ENUM_INVALID
#define FIT_LENGTH_TYPE_IDLE                                                     ((FIT_LENGTH_TYPE)0) // Rest period. Length with no strokes
#define FIT_LENGTH_TYPE_ACTIVE                                                   ((FIT_LENGTH_TYPE)1) // Length with strokes.
#define FIT_LENGTH_TYPE_COUNT                                                    2

typedef FIT_UINT32Z FIT_CONNECTIVITY_CAPABILITIES;
#define FIT_CONNECTIVITY_CAPABILITIES_INVALID                                    FIT_UINT32Z_INVALID
#define FIT_CONNECTIVITY_CAPABILITIES_BLUETOOTH                                  ((FIT_CONNECTIVITY_CAPABILITIES)0x00000001)
#define FIT_CONNECTIVITY_CAPABILITIES_BLUETOOTH_LE                               ((FIT_CONNECTIVITY_CAPABILITIES)0x00000002)
#define FIT_CONNECTIVITY_CAPABILITIES_ANT                                        ((FIT_CONNECTIVITY_CAPABILITIES)0x00000004)
#define FIT_CONNECTIVITY_CAPABILITIES_ACTIVITY_UPLOAD                            ((FIT_CONNECTIVITY_CAPABILITIES)0x00000008)
#define FIT_CONNECTIVITY_CAPABILITIES_COURSE_DOWNLOAD                            ((FIT_CONNECTIVITY_CAPABILITIES)0x00000010)
#define FIT_CONNECTIVITY_CAPABILITIES_WORKOUT_DOWNLOAD                           ((FIT_CONNECTIVITY_CAPABILITIES)0x00000020)
#define FIT_CONNECTIVITY_CAPABILITIES_LIVE_TRACK                                 ((FIT_CONNECTIVITY_CAPABILITIES)0x00000040)
#define FIT_CONNECTIVITY_CAPABILITIES_WEATHER_CONDITIONS                         ((FIT_CONNECTIVITY_CAPABILITIES)0x00000080)
#define FIT_CONNECTIVITY_CAPABILITIES_WEATHER_ALERTS                             ((FIT_CONNECTIVITY_CAPABILITIES)0x00000100)
#define FIT_CONNECTIVITY_CAPABILITIES_GPS_EPHEMERIS_DOWNLOAD                     ((FIT_CONNECTIVITY_CAPABILITIES)0x00000200)
#define FIT_CONNECTIVITY_CAPABILITIES_EXPLICIT_ARCHIVE                           ((FIT_CONNECTIVITY_CAPABILITIES)0x00000400)
#define FIT_CONNECTIVITY_CAPABILITIES_SETUP_INCOMPLETE                           ((FIT_CONNECTIVITY_CAPABILITIES)0x00000800)
#define FIT_CONNECTIVITY_CAPABILITIES_COUNT                                      12

typedef FIT_ENUM FIT_STROKE_TYPE;
#define FIT_STROKE_TYPE_INVALID                                                  FIT_ENUM_INVALID
#define FIT_STROKE_TYPE_NO_EVENT                                                 ((FIT_STROKE_TYPE)0)
#define FIT_STROKE_TYPE_OTHER                                                    ((FIT_STROKE_TYPE)1) // stroke was detected but cannot be identified
#define FIT_STROKE_TYPE_SERVE                                                    ((FIT_STROKE_TYPE)2)
#define FIT_STROKE_TYPE_FOREHAND                                                 ((FIT_STROKE_TYPE)3)
#define FIT_STROKE_TYPE_BACKHAND                                                 ((FIT_STROKE_TYPE)4)
#define FIT_STROKE_TYPE_SMASH                                                    ((FIT_STROKE_TYPE)5)
#define FIT_STROKE_TYPE_COUNT                                                    6

typedef FIT_ENUM FIT_BODY_LOCATION;
#define FIT_BODY_LOCATION_INVALID                                                FIT_ENUM_INVALID
#define FIT_BODY_LOCATION_LEFT_LEG                                               ((FIT_BODY_LOCATION)0)
#define FIT_BODY_LOCATION_LEFT_CALF                                              ((FIT_BODY_LOCATION)1)
#define FIT_BODY_LOCATION_LEFT_SHIN                                              ((FIT_BODY_LOCATION)2)
#define FIT_BODY_LOCATION_LEFT_HAMSTRING                                         ((FIT_BODY_LOCATION)3)
#define FIT_BODY_LOCATION_LEFT_QUAD                                              ((FIT_BODY_LOCATION)4)
#define FIT_BODY_LOCATION_LEFT_GLUTE                                             ((FIT_BODY_LOCATION)5)
#define FIT_BODY_LOCATION_RIGHT_LEG                                              ((FIT_BODY_LOCATION)6)
#define FIT_BODY_LOCATION_RIGHT_CALF                                             ((FIT_BODY_LOCATION)7)
#define FIT_BODY_LOCATION_RIGHT_SHIN                                             ((FIT_BODY_LOCATION)8)
#define FIT_BODY_LOCATION_RIGHT_HAMSTRING                                        ((FIT_BODY_LOCATION)9)
#define FIT_BODY_LOCATION_RIGHT_QUAD                                             ((FIT_BODY_LOCATION)10)
#define FIT_BODY_LOCATION_RIGHT_GLUTE                                            ((FIT_BODY_LOCATION)11)
#define FIT_BODY_LOCATION_TORSO_BACK                                             ((FIT_BODY_LOCATION)12)
#define FIT_BODY_LOCATION_LEFT_LOWER_BACK                                        ((FIT_BODY_LOCATION)13)
#define FIT_BODY_LOCATION_LEFT_UPPER_BACK                                        ((FIT_BODY_LOCATION)14)
#define FIT_BODY_LOCATION_RIGHT_LOWER_BACK                                       ((FIT_BODY_LOCATION)15)
#define FIT_BODY_LOCATION_RIGHT_UPPER_BACK                                       ((FIT_BODY_LOCATION)16)
#define FIT_BODY_LOCATION_TORSO_FRONT                                            ((FIT_BODY_LOCATION)17)
#define FIT_BODY_LOCATION_LEFT_ABDOMEN                                           ((FIT_BODY_LOCATION)18)
#define FIT_BODY_LOCATION_LEFT_CHEST                                             ((FIT_BODY_LOCATION)19)
#define FIT_BODY_LOCATION_RIGHT_ABDOMEN                                          ((FIT_BODY_LOCATION)20)
#define FIT_BODY_LOCATION_RIGHT_CHEST                                            ((FIT_BODY_LOCATION)21)
#define FIT_BODY_LOCATION_LEFT_ARM                                               ((FIT_BODY_LOCATION)22)
#define FIT_BODY_LOCATION_LEFT_SHOULDER                                          ((FIT_BODY_LOCATION)23)
#define FIT_BODY_LOCATION_LEFT_BICEP                                             ((FIT_BODY_LOCATION)24)
#define FIT_BODY_LOCATION_LEFT_TRICEP                                            ((FIT_BODY_LOCATION)25)
#define FIT_BODY_LOCATION_LEFT_BRACHIORADIALIS                                   ((FIT_BODY_LOCATION)26) // Left anterior forearm
#define FIT_BODY_LOCATION_LEFT_FOREARM_EXTENSORS                                 ((FIT_BODY_LOCATION)27) // Left posterior forearm
#define FIT_BODY_LOCATION_RIGHT_ARM                                              ((FIT_BODY_LOCATION)28)
#define FIT_BODY_LOCATION_RIGHT_SHOULDER                                         ((FIT_BODY_LOCATION)29)
#define FIT_BODY_LOCATION_RIGHT_BICEP                                            ((FIT_BODY_LOCATION)30)
#define FIT_BODY_LOCATION_RIGHT_TRICEP                                           ((FIT_BODY_LOCATION)31)
#define FIT_BODY_LOCATION_RIGHT_BRACHIORADIALIS                                  ((FIT_BODY_LOCATION)32) // Right anterior forearm
#define FIT_BODY_LOCATION_RIGHT_FOREARM_EXTENSORS                                ((FIT_BODY_LOCATION)33) // Right posterior forearm
#define FIT_BODY_LOCATION_NECK                                                   ((FIT_BODY_LOCATION)34)
#define FIT_BODY_LOCATION_THROAT                                                 ((FIT_BODY_LOCATION)35)
#define FIT_BODY_LOCATION_COUNT                                                  36


///////////////////////////////////////////////////////////////////////
// Message Conversion Structures
///////////////////////////////////////////////////////////////////////

typedef struct
{
   FIT_UINT8 base_type;
   FIT_UINT8 offset_in;
   FIT_UINT8 offset_local;
   FIT_UINT8 size;
} FIT_FIELD_CONVERT;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_FIELD_CONVERT fields[81];
} FIT_MESG_CONVERT;


///////////////////////////////////////////////////////////////////////
// Messages
///////////////////////////////////////////////////////////////////////

#define FIT_MESG_SIZE       181
#define FIT_MESG_DEF_SIZE   248

// pad message

#define FIT_PAD_MESG_DEF_SIZE       5

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
} FIT_PAD_MESG_DEF;


// file_id message

#define FIT_FILE_ID_MESG_SIZE                                                   15
#define FIT_FILE_ID_MESG_DEF_SIZE                                               23

typedef struct
{
   FIT_UINT32Z serial_number; //
   FIT_DATE_TIME time_created; // Only set for files that are can be created/erased.
   FIT_MANUFACTURER manufacturer; //
   FIT_UINT16 product; //
   FIT_UINT16 number; // Only set for files that are not created/erased.
   FIT_FILE type; //
} FIT_FILE_ID_MESG;

typedef enum
{
   FIT_FILE_ID_FIELD_NUM_SERIAL_NUMBER = 3,
   FIT_FILE_ID_FIELD_NUM_TIME_CREATED = 4,
   FIT_FILE_ID_FIELD_NUM_MANUFACTURER = 1,
   FIT_FILE_ID_FIELD_NUM_PRODUCT = 2,
   FIT_FILE_ID_FIELD_NUM_NUMBER = 5,
   FIT_FILE_ID_FIELD_NUM_TYPE = 0
} FIT_FILE_ID_FIELD_NUM;

typedef enum
{
   FIT_FILE_ID_MESG_SERIAL_NUMBER,
   FIT_FILE_ID_MESG_TIME_CREATED,
   FIT_FILE_ID_MESG_MANUFACTURER,
   FIT_FILE_ID_MESG_PRODUCT,
   FIT_FILE_ID_MESG_NUMBER,
   FIT_FILE_ID_MESG_TYPE,
   FIT_FILE_ID_MESG_FIELDS
} FIT_FILE_ID_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_FILE_ID_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_FILE_ID_MESG_DEF;

// file_creator message

#define FIT_FILE_CREATOR_MESG_SIZE                                              3
#define FIT_FILE_CREATOR_MESG_DEF_SIZE                                          11

typedef struct
{
   FIT_UINT16 software_version; //
   FIT_UINT8 hardware_version; //
} FIT_FILE_CREATOR_MESG;

typedef enum
{
   FIT_FILE_CREATOR_FIELD_NUM_SOFTWARE_VERSION = 0,
   FIT_FILE_CREATOR_FIELD_NUM_HARDWARE_VERSION = 1
} FIT_FILE_CREATOR_FIELD_NUM;

typedef enum
{
   FIT_FILE_CREATOR_MESG_SOFTWARE_VERSION,
   FIT_FILE_CREATOR_MESG_HARDWARE_VERSION,
   FIT_FILE_CREATOR_MESG_FIELDS
} FIT_FILE_CREATOR_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_FILE_CREATOR_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_FILE_CREATOR_MESG_DEF;

// software message

#define FIT_SOFTWARE_MESG_SIZE                                                  20
#define FIT_SOFTWARE_MESG_DEF_SIZE                                              14
#define FIT_SOFTWARE_MESG_PART_NUMBER_COUNT                                     16

typedef struct
{
   FIT_STRING part_number[FIT_SOFTWARE_MESG_PART_NUMBER_COUNT]; //
   FIT_MESSAGE_INDEX message_index; //
   FIT_UINT16 version; //
} FIT_SOFTWARE_MESG;

typedef enum
{
   FIT_SOFTWARE_FIELD_NUM_PART_NUMBER = 5,
   FIT_SOFTWARE_FIELD_NUM_MESSAGE_INDEX = 254,
   FIT_SOFTWARE_FIELD_NUM_VERSION = 3
} FIT_SOFTWARE_FIELD_NUM;

typedef enum
{
   FIT_SOFTWARE_MESG_PART_NUMBER,
   FIT_SOFTWARE_MESG_MESSAGE_INDEX,
   FIT_SOFTWARE_MESG_VERSION,
   FIT_SOFTWARE_MESG_FIELDS
} FIT_SOFTWARE_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_SOFTWARE_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_SOFTWARE_MESG_DEF;

// slave_device message

#define FIT_SLAVE_DEVICE_MESG_SIZE                                              4
#define FIT_SLAVE_DEVICE_MESG_DEF_SIZE                                          11

typedef struct
{
   FIT_MANUFACTURER manufacturer; //
   FIT_UINT16 product; //
} FIT_SLAVE_DEVICE_MESG;

typedef enum
{
   FIT_SLAVE_DEVICE_FIELD_NUM_MANUFACTURER = 0,
   FIT_SLAVE_DEVICE_FIELD_NUM_PRODUCT = 1
} FIT_SLAVE_DEVICE_FIELD_NUM;

typedef enum
{
   FIT_SLAVE_DEVICE_MESG_MANUFACTURER,
   FIT_SLAVE_DEVICE_MESG_PRODUCT,
   FIT_SLAVE_DEVICE_MESG_FIELDS
} FIT_SLAVE_DEVICE_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_SLAVE_DEVICE_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_SLAVE_DEVICE_MESG_DEF;

// capabilities message

#define FIT_CAPABILITIES_MESG_SIZE                                              13
#define FIT_CAPABILITIES_MESG_DEF_SIZE                                          17
#define FIT_CAPABILITIES_MESG_LANGUAGES_COUNT                                   4
#define FIT_CAPABILITIES_MESG_SPORTS_COUNT                                      1

typedef struct
{
   FIT_UINT8Z languages[FIT_CAPABILITIES_MESG_LANGUAGES_COUNT]; // Use language_bits_x types where x is index of array.
   FIT_WORKOUT_CAPABILITIES workouts_supported; //
   FIT_CONNECTIVITY_CAPABILITIES connectivity_supported; //
   FIT_SPORT_BITS_0 sports[FIT_CAPABILITIES_MESG_SPORTS_COUNT]; // Use sport_bits_x types where x is index of array.
} FIT_CAPABILITIES_MESG;

typedef enum
{
   FIT_CAPABILITIES_FIELD_NUM_LANGUAGES = 0,
   FIT_CAPABILITIES_FIELD_NUM_WORKOUTS_SUPPORTED = 21,
   FIT_CAPABILITIES_FIELD_NUM_CONNECTIVITY_SUPPORTED = 23,
   FIT_CAPABILITIES_FIELD_NUM_SPORTS = 1
} FIT_CAPABILITIES_FIELD_NUM;

typedef enum
{
   FIT_CAPABILITIES_MESG_LANGUAGES,
   FIT_CAPABILITIES_MESG_WORKOUTS_SUPPORTED,
   FIT_CAPABILITIES_MESG_CONNECTIVITY_SUPPORTED,
   FIT_CAPABILITIES_MESG_SPORTS,
   FIT_CAPABILITIES_MESG_FIELDS
} FIT_CAPABILITIES_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_CAPABILITIES_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_CAPABILITIES_MESG_DEF;

// file_capabilities message

#define FIT_FILE_CAPABILITIES_MESG_SIZE                                         26
#define FIT_FILE_CAPABILITIES_MESG_DEF_SIZE                                     23
#define FIT_FILE_CAPABILITIES_MESG_DIRECTORY_COUNT                              16

typedef struct
{
   FIT_STRING directory[FIT_FILE_CAPABILITIES_MESG_DIRECTORY_COUNT]; //
   FIT_UINT32 max_size; // bytes,
   FIT_MESSAGE_INDEX message_index; //
   FIT_UINT16 max_count; //
   FIT_FILE type; //
   FIT_FILE_FLAGS flags; //
} FIT_FILE_CAPABILITIES_MESG;

typedef enum
{
   FIT_FILE_CAPABILITIES_FIELD_NUM_DIRECTORY = 2,
   FIT_FILE_CAPABILITIES_FIELD_NUM_MAX_SIZE = 4,
   FIT_FILE_CAPABILITIES_FIELD_NUM_MESSAGE_INDEX = 254,
   FIT_FILE_CAPABILITIES_FIELD_NUM_MAX_COUNT = 3,
   FIT_FILE_CAPABILITIES_FIELD_NUM_TYPE = 0,
   FIT_FILE_CAPABILITIES_FIELD_NUM_FLAGS = 1
} FIT_FILE_CAPABILITIES_FIELD_NUM;

typedef enum
{
   FIT_FILE_CAPABILITIES_MESG_DIRECTORY,
   FIT_FILE_CAPABILITIES_MESG_MAX_SIZE,
   FIT_FILE_CAPABILITIES_MESG_MESSAGE_INDEX,
   FIT_FILE_CAPABILITIES_MESG_MAX_COUNT,
   FIT_FILE_CAPABILITIES_MESG_TYPE,
   FIT_FILE_CAPABILITIES_MESG_FLAGS,
   FIT_FILE_CAPABILITIES_MESG_FIELDS
} FIT_FILE_CAPABILITIES_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_FILE_CAPABILITIES_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_FILE_CAPABILITIES_MESG_DEF;

// mesg_capabilities message

#define FIT_MESG_CAPABILITIES_MESG_SIZE                                         8
#define FIT_MESG_CAPABILITIES_MESG_DEF_SIZE                                     20

typedef struct
{
   FIT_MESSAGE_INDEX message_index; //
   FIT_MESG_NUM mesg_num; //
   FIT_UINT16 count; //
   FIT_FILE file; //
   FIT_MESG_COUNT count_type; //
} FIT_MESG_CAPABILITIES_MESG;

typedef enum
{
   FIT_MESG_CAPABILITIES_FIELD_NUM_MESSAGE_INDEX = 254,
   FIT_MESG_CAPABILITIES_FIELD_NUM_MESG_NUM = 1,
   FIT_MESG_CAPABILITIES_FIELD_NUM_COUNT = 3,
   FIT_MESG_CAPABILITIES_FIELD_NUM_FILE = 0,
   FIT_MESG_CAPABILITIES_FIELD_NUM_COUNT_TYPE = 2
} FIT_MESG_CAPABILITIES_FIELD_NUM;

typedef enum
{
   FIT_MESG_CAPABILITIES_MESG_MESSAGE_INDEX,
   FIT_MESG_CAPABILITIES_MESG_MESG_NUM,
   FIT_MESG_CAPABILITIES_MESG_COUNT,
   FIT_MESG_CAPABILITIES_MESG_FILE,
   FIT_MESG_CAPABILITIES_MESG_COUNT_TYPE,
   FIT_MESG_CAPABILITIES_MESG_FIELDS
} FIT_MESG_CAPABILITIES_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_MESG_CAPABILITIES_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_MESG_CAPABILITIES_MESG_DEF;

// field_capabilities message

#define FIT_FIELD_CAPABILITIES_MESG_SIZE                                        8
#define FIT_FIELD_CAPABILITIES_MESG_DEF_SIZE                                    20

typedef struct
{
   FIT_MESSAGE_INDEX message_index; //
   FIT_MESG_NUM mesg_num; //
   FIT_UINT16 count; //
   FIT_FILE file; //
   FIT_UINT8 field_num; //
} FIT_FIELD_CAPABILITIES_MESG;

typedef enum
{
   FIT_FIELD_CAPABILITIES_FIELD_NUM_MESSAGE_INDEX = 254,
   FIT_FIELD_CAPABILITIES_FIELD_NUM_MESG_NUM = 1,
   FIT_FIELD_CAPABILITIES_FIELD_NUM_COUNT = 3,
   FIT_FIELD_CAPABILITIES_FIELD_NUM_FILE = 0,
   FIT_FIELD_CAPABILITIES_FIELD_NUM_FIELD_NUM = 2
} FIT_FIELD_CAPABILITIES_FIELD_NUM;

typedef enum
{
   FIT_FIELD_CAPABILITIES_MESG_MESSAGE_INDEX,
   FIT_FIELD_CAPABILITIES_MESG_MESG_NUM,
   FIT_FIELD_CAPABILITIES_MESG_COUNT,
   FIT_FIELD_CAPABILITIES_MESG_FILE,
   FIT_FIELD_CAPABILITIES_MESG_FIELD_NUM,
   FIT_FIELD_CAPABILITIES_MESG_FIELDS
} FIT_FIELD_CAPABILITIES_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_FIELD_CAPABILITIES_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_FIELD_CAPABILITIES_MESG_DEF;

// device_settings message

#define FIT_DEVICE_SETTINGS_MESG_SIZE                                           4
#define FIT_DEVICE_SETTINGS_MESG_DEF_SIZE                                       8

typedef struct
{
   FIT_UINT32 utc_offset; // Offset from system time. Required to convert timestamp from system time to UTC.
} FIT_DEVICE_SETTINGS_MESG;

typedef enum
{
   FIT_DEVICE_SETTINGS_FIELD_NUM_UTC_OFFSET = 1
} FIT_DEVICE_SETTINGS_FIELD_NUM;

typedef enum
{
   FIT_DEVICE_SETTINGS_MESG_UTC_OFFSET,
   FIT_DEVICE_SETTINGS_MESG_FIELDS
} FIT_DEVICE_SETTINGS_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_DEVICE_SETTINGS_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_DEVICE_SETTINGS_MESG_DEF;

// user_profile message

#define FIT_USER_PROFILE_MESG_SIZE                                              46
#define FIT_USER_PROFILE_MESG_DEF_SIZE                                          74
#define FIT_USER_PROFILE_MESG_FRIENDLY_NAME_COUNT                               16
#define FIT_USER_PROFILE_MESG_GLOBAL_ID_COUNT                                   6

typedef struct
{
   FIT_STRING friendly_name[FIT_USER_PROFILE_MESG_FRIENDLY_NAME_COUNT]; //
   FIT_MESSAGE_INDEX message_index; //
   FIT_UINT16 weight; // 10 * kg,
   FIT_USER_LOCAL_ID local_id; //
   FIT_GENDER gender; //
   FIT_UINT8 age; // years,
   FIT_UINT8 height; // 100 * m,
   FIT_LANGUAGE language; //
   FIT_DISPLAY_MEASURE elev_setting; //
   FIT_DISPLAY_MEASURE weight_setting; //
   FIT_UINT8 resting_heart_rate; // bpm,
   FIT_UINT8 default_max_running_heart_rate; // bpm,
   FIT_UINT8 default_max_biking_heart_rate; // bpm,
   FIT_UINT8 default_max_heart_rate; // bpm,
   FIT_DISPLAY_HEART hr_setting; //
   FIT_DISPLAY_MEASURE speed_setting; //
   FIT_DISPLAY_MEASURE dist_setting; //
   FIT_DISPLAY_POWER power_setting; //
   FIT_ACTIVITY_CLASS activity_class; //
   FIT_DISPLAY_POSITION position_setting; //
   FIT_DISPLAY_MEASURE temperature_setting; //
   FIT_BYTE global_id[FIT_USER_PROFILE_MESG_GLOBAL_ID_COUNT]; //
   FIT_DISPLAY_MEASURE height_setting; //
} FIT_USER_PROFILE_MESG;

typedef enum
{
   FIT_USER_PROFILE_FIELD_NUM_FRIENDLY_NAME = 0,
   FIT_USER_PROFILE_FIELD_NUM_MESSAGE_INDEX = 254,
   FIT_USER_PROFILE_FIELD_NUM_WEIGHT = 4,
   FIT_USER_PROFILE_FIELD_NUM_LOCAL_ID = 22,
   FIT_USER_PROFILE_FIELD_NUM_GENDER = 1,
   FIT_USER_PROFILE_FIELD_NUM_AGE = 2,
   FIT_USER_PROFILE_FIELD_NUM_HEIGHT = 3,
   FIT_USER_PROFILE_FIELD_NUM_LANGUAGE = 5,
   FIT_USER_PROFILE_FIELD_NUM_ELEV_SETTING = 6,
   FIT_USER_PROFILE_FIELD_NUM_WEIGHT_SETTING = 7,
   FIT_USER_PROFILE_FIELD_NUM_RESTING_HEART_RATE = 8,
   FIT_USER_PROFILE_FIELD_NUM_DEFAULT_MAX_RUNNING_HEART_RATE = 9,
   FIT_USER_PROFILE_FIELD_NUM_DEFAULT_MAX_BIKING_HEART_RATE = 10,
   FIT_USER_PROFILE_FIELD_NUM_DEFAULT_MAX_HEART_RATE = 11,
   FIT_USER_PROFILE_FIELD_NUM_HR_SETTING = 12,
   FIT_USER_PROFILE_FIELD_NUM_SPEED_SETTING = 13,
   FIT_USER_PROFILE_FIELD_NUM_DIST_SETTING = 14,
   FIT_USER_PROFILE_FIELD_NUM_POWER_SETTING = 16,
   FIT_USER_PROFILE_FIELD_NUM_ACTIVITY_CLASS = 17,
   FIT_USER_PROFILE_FIELD_NUM_POSITION_SETTING = 18,
   FIT_USER_PROFILE_FIELD_NUM_TEMPERATURE_SETTING = 21,
   FIT_USER_PROFILE_FIELD_NUM_GLOBAL_ID = 23,
   FIT_USER_PROFILE_FIELD_NUM_HEIGHT_SETTING = 30
} FIT_USER_PROFILE_FIELD_NUM;

typedef enum
{
   FIT_USER_PROFILE_MESG_FRIENDLY_NAME,
   FIT_USER_PROFILE_MESG_MESSAGE_INDEX,
   FIT_USER_PROFILE_MESG_WEIGHT,
   FIT_USER_PROFILE_MESG_LOCAL_ID,
   FIT_USER_PROFILE_MESG_GENDER,
   FIT_USER_PROFILE_MESG_AGE,
   FIT_USER_PROFILE_MESG_HEIGHT,
   FIT_USER_PROFILE_MESG_LANGUAGE,
   FIT_USER_PROFILE_MESG_ELEV_SETTING,
   FIT_USER_PROFILE_MESG_WEIGHT_SETTING,
   FIT_USER_PROFILE_MESG_RESTING_HEART_RATE,
   FIT_USER_PROFILE_MESG_DEFAULT_MAX_RUNNING_HEART_RATE,
   FIT_USER_PROFILE_MESG_DEFAULT_MAX_BIKING_HEART_RATE,
   FIT_USER_PROFILE_MESG_DEFAULT_MAX_HEART_RATE,
   FIT_USER_PROFILE_MESG_HR_SETTING,
   FIT_USER_PROFILE_MESG_SPEED_SETTING,
   FIT_USER_PROFILE_MESG_DIST_SETTING,
   FIT_USER_PROFILE_MESG_POWER_SETTING,
   FIT_USER_PROFILE_MESG_ACTIVITY_CLASS,
   FIT_USER_PROFILE_MESG_POSITION_SETTING,
   FIT_USER_PROFILE_MESG_TEMPERATURE_SETTING,
   FIT_USER_PROFILE_MESG_GLOBAL_ID,
   FIT_USER_PROFILE_MESG_HEIGHT_SETTING,
   FIT_USER_PROFILE_MESG_FIELDS
} FIT_USER_PROFILE_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_USER_PROFILE_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_USER_PROFILE_MESG_DEF;

// hrm_profile message

#define FIT_HRM_PROFILE_MESG_SIZE                                               7
#define FIT_HRM_PROFILE_MESG_DEF_SIZE                                           20

typedef struct
{
   FIT_MESSAGE_INDEX message_index; //
   FIT_UINT16Z hrm_ant_id; //
   FIT_BOOL enabled; //
   FIT_BOOL log_hrv; //
   FIT_UINT8Z hrm_ant_id_trans_type; //
} FIT_HRM_PROFILE_MESG;

typedef enum
{
   FIT_HRM_PROFILE_FIELD_NUM_MESSAGE_INDEX = 254,
   FIT_HRM_PROFILE_FIELD_NUM_HRM_ANT_ID = 1,
   FIT_HRM_PROFILE_FIELD_NUM_ENABLED = 0,
   FIT_HRM_PROFILE_FIELD_NUM_LOG_HRV = 2,
   FIT_HRM_PROFILE_FIELD_NUM_HRM_ANT_ID_TRANS_TYPE = 3
} FIT_HRM_PROFILE_FIELD_NUM;

typedef enum
{
   FIT_HRM_PROFILE_MESG_MESSAGE_INDEX,
   FIT_HRM_PROFILE_MESG_HRM_ANT_ID,
   FIT_HRM_PROFILE_MESG_ENABLED,
   FIT_HRM_PROFILE_MESG_LOG_HRV,
   FIT_HRM_PROFILE_MESG_HRM_ANT_ID_TRANS_TYPE,
   FIT_HRM_PROFILE_MESG_FIELDS
} FIT_HRM_PROFILE_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_HRM_PROFILE_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_HRM_PROFILE_MESG_DEF;

// sdm_profile message

#define FIT_SDM_PROFILE_MESG_SIZE                                               14
#define FIT_SDM_PROFILE_MESG_DEF_SIZE                                           29

typedef struct
{
   FIT_UINT32 odometer; // 100 * m,
   FIT_MESSAGE_INDEX message_index; //
   FIT_UINT16Z sdm_ant_id; //
   FIT_UINT16 sdm_cal_factor; // 10 * %,
   FIT_BOOL enabled; //
   FIT_BOOL speed_source; // Use footpod for speed source instead of GPS
   FIT_UINT8Z sdm_ant_id_trans_type; //
   FIT_UINT8 odometer_rollover; // Rollover counter that can be used to extend the odometer
} FIT_SDM_PROFILE_MESG;

typedef enum
{
   FIT_SDM_PROFILE_FIELD_NUM_ODOMETER = 3,
   FIT_SDM_PROFILE_FIELD_NUM_MESSAGE_INDEX = 254,
   FIT_SDM_PROFILE_FIELD_NUM_SDM_ANT_ID = 1,
   FIT_SDM_PROFILE_FIELD_NUM_SDM_CAL_FACTOR = 2,
   FIT_SDM_PROFILE_FIELD_NUM_ENABLED = 0,
   FIT_SDM_PROFILE_FIELD_NUM_SPEED_SOURCE = 4,
   FIT_SDM_PROFILE_FIELD_NUM_SDM_ANT_ID_TRANS_TYPE = 5,
   FIT_SDM_PROFILE_FIELD_NUM_ODOMETER_ROLLOVER = 7
} FIT_SDM_PROFILE_FIELD_NUM;

typedef enum
{
   FIT_SDM_PROFILE_MESG_ODOMETER,
   FIT_SDM_PROFILE_MESG_MESSAGE_INDEX,
   FIT_SDM_PROFILE_MESG_SDM_ANT_ID,
   FIT_SDM_PROFILE_MESG_SDM_CAL_FACTOR,
   FIT_SDM_PROFILE_MESG_ENABLED,
   FIT_SDM_PROFILE_MESG_SPEED_SOURCE,
   FIT_SDM_PROFILE_MESG_SDM_ANT_ID_TRANS_TYPE,
   FIT_SDM_PROFILE_MESG_ODOMETER_ROLLOVER,
   FIT_SDM_PROFILE_MESG_FIELDS
} FIT_SDM_PROFILE_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_SDM_PROFILE_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_SDM_PROFILE_MESG_DEF;

// bike_profile message

#define FIT_BIKE_PROFILE_MESG_SIZE                                              54
#define FIT_BIKE_PROFILE_MESG_DEF_SIZE                                          86
#define FIT_BIKE_PROFILE_MESG_NAME_COUNT                                        16

typedef struct
{
   FIT_STRING name[FIT_BIKE_PROFILE_MESG_NAME_COUNT]; //
   FIT_UINT32 odometer; // 100 * m,
   FIT_MESSAGE_INDEX message_index; //
   FIT_UINT16Z bike_spd_ant_id; //
   FIT_UINT16Z bike_cad_ant_id; //
   FIT_UINT16Z bike_spdcad_ant_id; //
   FIT_UINT16Z bike_power_ant_id; //
   FIT_UINT16 custom_wheelsize; // 1000 * m,
   FIT_UINT16 auto_wheelsize; // 1000 * m,
   FIT_UINT16 bike_weight; // 10 * kg,
   FIT_UINT16 power_cal_factor; // 10 * %,
   FIT_SPORT sport; //
   FIT_SUB_SPORT sub_sport; //
   FIT_BOOL auto_wheel_cal; //
   FIT_BOOL auto_power_zero; //
   FIT_UINT8 id; //
   FIT_BOOL spd_enabled; //
   FIT_BOOL cad_enabled; //
   FIT_BOOL spdcad_enabled; //
   FIT_BOOL power_enabled; //
   FIT_UINT8 crank_length; // 2 * mm + -110,
   FIT_BOOL enabled; //
   FIT_UINT8Z bike_spd_ant_id_trans_type; //
   FIT_UINT8Z bike_cad_ant_id_trans_type; //
   FIT_UINT8Z bike_spdcad_ant_id_trans_type; //
   FIT_UINT8Z bike_power_ant_id_trans_type; //
   FIT_UINT8 odometer_rollover; // Rollover counter that can be used to extend the odometer
} FIT_BIKE_PROFILE_MESG;

typedef enum
{
   FIT_BIKE_PROFILE_FIELD_NUM_NAME = 0,
   FIT_BIKE_PROFILE_FIELD_NUM_ODOMETER = 3,
   FIT_BIKE_PROFILE_FIELD_NUM_MESSAGE_INDEX = 254,
   FIT_BIKE_PROFILE_FIELD_NUM_BIKE_SPD_ANT_ID = 4,
   FIT_BIKE_PROFILE_FIELD_NUM_BIKE_CAD_ANT_ID = 5,
   FIT_BIKE_PROFILE_FIELD_NUM_BIKE_SPDCAD_ANT_ID = 6,
   FIT_BIKE_PROFILE_FIELD_NUM_BIKE_POWER_ANT_ID = 7,
   FIT_BIKE_PROFILE_FIELD_NUM_CUSTOM_WHEELSIZE = 8,
   FIT_BIKE_PROFILE_FIELD_NUM_AUTO_WHEELSIZE = 9,
   FIT_BIKE_PROFILE_FIELD_NUM_BIKE_WEIGHT = 10,
   FIT_BIKE_PROFILE_FIELD_NUM_POWER_CAL_FACTOR = 11,
   FIT_BIKE_PROFILE_FIELD_NUM_SPORT = 1,
   FIT_BIKE_PROFILE_FIELD_NUM_SUB_SPORT = 2,
   FIT_BIKE_PROFILE_FIELD_NUM_AUTO_WHEEL_CAL = 12,
   FIT_BIKE_PROFILE_FIELD_NUM_AUTO_POWER_ZERO = 13,
   FIT_BIKE_PROFILE_FIELD_NUM_ID = 14,
   FIT_BIKE_PROFILE_FIELD_NUM_SPD_ENABLED = 15,
   FIT_BIKE_PROFILE_FIELD_NUM_CAD_ENABLED = 16,
   FIT_BIKE_PROFILE_FIELD_NUM_SPDCAD_ENABLED = 17,
   FIT_BIKE_PROFILE_FIELD_NUM_POWER_ENABLED = 18,
   FIT_BIKE_PROFILE_FIELD_NUM_CRANK_LENGTH = 19,
   FIT_BIKE_PROFILE_FIELD_NUM_ENABLED = 20,
   FIT_BIKE_PROFILE_FIELD_NUM_BIKE_SPD_ANT_ID_TRANS_TYPE = 21,
   FIT_BIKE_PROFILE_FIELD_NUM_BIKE_CAD_ANT_ID_TRANS_TYPE = 22,
   FIT_BIKE_PROFILE_FIELD_NUM_BIKE_SPDCAD_ANT_ID_TRANS_TYPE = 23,
   FIT_BIKE_PROFILE_FIELD_NUM_BIKE_POWER_ANT_ID_TRANS_TYPE = 24,
   FIT_BIKE_PROFILE_FIELD_NUM_ODOMETER_ROLLOVER = 37
} FIT_BIKE_PROFILE_FIELD_NUM;

typedef enum
{
   FIT_BIKE_PROFILE_MESG_NAME,
   FIT_BIKE_PROFILE_MESG_ODOMETER,
   FIT_BIKE_PROFILE_MESG_MESSAGE_INDEX,
   FIT_BIKE_PROFILE_MESG_BIKE_SPD_ANT_ID,
   FIT_BIKE_PROFILE_MESG_BIKE_CAD_ANT_ID,
   FIT_BIKE_PROFILE_MESG_BIKE_SPDCAD_ANT_ID,
   FIT_BIKE_PROFILE_MESG_BIKE_POWER_ANT_ID,
   FIT_BIKE_PROFILE_MESG_CUSTOM_WHEELSIZE,
   FIT_BIKE_PROFILE_MESG_AUTO_WHEELSIZE,
   FIT_BIKE_PROFILE_MESG_BIKE_WEIGHT,
   FIT_BIKE_PROFILE_MESG_POWER_CAL_FACTOR,
   FIT_BIKE_PROFILE_MESG_SPORT,
   FIT_BIKE_PROFILE_MESG_SUB_SPORT,
   FIT_BIKE_PROFILE_MESG_AUTO_WHEEL_CAL,
   FIT_BIKE_PROFILE_MESG_AUTO_POWER_ZERO,
   FIT_BIKE_PROFILE_MESG_ID,
   FIT_BIKE_PROFILE_MESG_SPD_ENABLED,
   FIT_BIKE_PROFILE_MESG_CAD_ENABLED,
   FIT_BIKE_PROFILE_MESG_SPDCAD_ENABLED,
   FIT_BIKE_PROFILE_MESG_POWER_ENABLED,
   FIT_BIKE_PROFILE_MESG_CRANK_LENGTH,
   FIT_BIKE_PROFILE_MESG_ENABLED,
   FIT_BIKE_PROFILE_MESG_BIKE_SPD_ANT_ID_TRANS_TYPE,
   FIT_BIKE_PROFILE_MESG_BIKE_CAD_ANT_ID_TRANS_TYPE,
   FIT_BIKE_PROFILE_MESG_BIKE_SPDCAD_ANT_ID_TRANS_TYPE,
   FIT_BIKE_PROFILE_MESG_BIKE_POWER_ANT_ID_TRANS_TYPE,
   FIT_BIKE_PROFILE_MESG_ODOMETER_ROLLOVER,
   FIT_BIKE_PROFILE_MESG_FIELDS
} FIT_BIKE_PROFILE_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_BIKE_PROFILE_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_BIKE_PROFILE_MESG_DEF;

// zones_target message

#define FIT_ZONES_TARGET_MESG_SIZE                                              6
#define FIT_ZONES_TARGET_MESG_DEF_SIZE                                          20

typedef struct
{
   FIT_UINT16 functional_threshold_power; //
   FIT_UINT8 max_heart_rate; //
   FIT_UINT8 threshold_heart_rate; //
   FIT_HR_ZONE_CALC hr_calc_type; //
   FIT_PWR_ZONE_CALC pwr_calc_type; //
} FIT_ZONES_TARGET_MESG;

typedef enum
{
   FIT_ZONES_TARGET_FIELD_NUM_FUNCTIONAL_THRESHOLD_POWER = 3,
   FIT_ZONES_TARGET_FIELD_NUM_MAX_HEART_RATE = 1,
   FIT_ZONES_TARGET_FIELD_NUM_THRESHOLD_HEART_RATE = 2,
   FIT_ZONES_TARGET_FIELD_NUM_HR_CALC_TYPE = 5,
   FIT_ZONES_TARGET_FIELD_NUM_PWR_CALC_TYPE = 7
} FIT_ZONES_TARGET_FIELD_NUM;

typedef enum
{
   FIT_ZONES_TARGET_MESG_FUNCTIONAL_THRESHOLD_POWER,
   FIT_ZONES_TARGET_MESG_MAX_HEART_RATE,
   FIT_ZONES_TARGET_MESG_THRESHOLD_HEART_RATE,
   FIT_ZONES_TARGET_MESG_HR_CALC_TYPE,
   FIT_ZONES_TARGET_MESG_PWR_CALC_TYPE,
   FIT_ZONES_TARGET_MESG_FIELDS
} FIT_ZONES_TARGET_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_ZONES_TARGET_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_ZONES_TARGET_MESG_DEF;

// sport message

#define FIT_SPORT_MESG_SIZE                                                     18
#define FIT_SPORT_MESG_DEF_SIZE                                                 14
#define FIT_SPORT_MESG_NAME_COUNT                                               16

typedef struct
{
   FIT_STRING name[FIT_SPORT_MESG_NAME_COUNT]; //
   FIT_SPORT sport; //
   FIT_SUB_SPORT sub_sport; //
} FIT_SPORT_MESG;

typedef enum
{
   FIT_SPORT_FIELD_NUM_NAME = 3,
   FIT_SPORT_FIELD_NUM_SPORT = 0,
   FIT_SPORT_FIELD_NUM_SUB_SPORT = 1
} FIT_SPORT_FIELD_NUM;

typedef enum
{
   FIT_SPORT_MESG_NAME,
   FIT_SPORT_MESG_SPORT,
   FIT_SPORT_MESG_SUB_SPORT,
   FIT_SPORT_MESG_FIELDS
} FIT_SPORT_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_SPORT_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_SPORT_MESG_DEF;

// hr_zone message

#define FIT_HR_ZONE_MESG_SIZE                                                   19
#define FIT_HR_ZONE_MESG_DEF_SIZE                                               14
#define FIT_HR_ZONE_MESG_NAME_COUNT                                             16

typedef struct
{
   FIT_STRING name[FIT_HR_ZONE_MESG_NAME_COUNT]; //
   FIT_MESSAGE_INDEX message_index; //
   FIT_UINT8 high_bpm; // bpm,
} FIT_HR_ZONE_MESG;

typedef enum
{
   FIT_HR_ZONE_FIELD_NUM_NAME = 2,
   FIT_HR_ZONE_FIELD_NUM_MESSAGE_INDEX = 254,
   FIT_HR_ZONE_FIELD_NUM_HIGH_BPM = 1
} FIT_HR_ZONE_FIELD_NUM;

typedef enum
{
   FIT_HR_ZONE_MESG_NAME,
   FIT_HR_ZONE_MESG_MESSAGE_INDEX,
   FIT_HR_ZONE_MESG_HIGH_BPM,
   FIT_HR_ZONE_MESG_FIELDS
} FIT_HR_ZONE_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_HR_ZONE_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_HR_ZONE_MESG_DEF;

// speed_zone message

#define FIT_SPEED_ZONE_MESG_SIZE                                                20
#define FIT_SPEED_ZONE_MESG_DEF_SIZE                                            14
#define FIT_SPEED_ZONE_MESG_NAME_COUNT                                          16

typedef struct
{
   FIT_STRING name[FIT_SPEED_ZONE_MESG_NAME_COUNT]; //
   FIT_MESSAGE_INDEX message_index; //
   FIT_UINT16 high_value; // 1000 * m/s,
} FIT_SPEED_ZONE_MESG;

typedef enum
{
   FIT_SPEED_ZONE_FIELD_NUM_NAME = 1,
   FIT_SPEED_ZONE_FIELD_NUM_MESSAGE_INDEX = 254,
   FIT_SPEED_ZONE_FIELD_NUM_HIGH_VALUE = 0
} FIT_SPEED_ZONE_FIELD_NUM;

typedef enum
{
   FIT_SPEED_ZONE_MESG_NAME,
   FIT_SPEED_ZONE_MESG_MESSAGE_INDEX,
   FIT_SPEED_ZONE_MESG_HIGH_VALUE,
   FIT_SPEED_ZONE_MESG_FIELDS
} FIT_SPEED_ZONE_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_SPEED_ZONE_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_SPEED_ZONE_MESG_DEF;

// cadence_zone message

#define FIT_CADENCE_ZONE_MESG_SIZE                                              19
#define FIT_CADENCE_ZONE_MESG_DEF_SIZE                                          14
#define FIT_CADENCE_ZONE_MESG_NAME_COUNT                                        16

typedef struct
{
   FIT_STRING name[FIT_CADENCE_ZONE_MESG_NAME_COUNT]; //
   FIT_MESSAGE_INDEX message_index; //
   FIT_UINT8 high_value; // rpm,
} FIT_CADENCE_ZONE_MESG;

typedef enum
{
   FIT_CADENCE_ZONE_FIELD_NUM_NAME = 1,
   FIT_CADENCE_ZONE_FIELD_NUM_MESSAGE_INDEX = 254,
   FIT_CADENCE_ZONE_FIELD_NUM_HIGH_VALUE = 0
} FIT_CADENCE_ZONE_FIELD_NUM;

typedef enum
{
   FIT_CADENCE_ZONE_MESG_NAME,
   FIT_CADENCE_ZONE_MESG_MESSAGE_INDEX,
   FIT_CADENCE_ZONE_MESG_HIGH_VALUE,
   FIT_CADENCE_ZONE_MESG_FIELDS
} FIT_CADENCE_ZONE_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_CADENCE_ZONE_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_CADENCE_ZONE_MESG_DEF;

// power_zone message

#define FIT_POWER_ZONE_MESG_SIZE                                                20
#define FIT_POWER_ZONE_MESG_DEF_SIZE                                            14
#define FIT_POWER_ZONE_MESG_NAME_COUNT                                          16

typedef struct
{
   FIT_STRING name[FIT_POWER_ZONE_MESG_NAME_COUNT]; //
   FIT_MESSAGE_INDEX message_index; //
   FIT_UINT16 high_value; // watts,
} FIT_POWER_ZONE_MESG;

typedef enum
{
   FIT_POWER_ZONE_FIELD_NUM_NAME = 2,
   FIT_POWER_ZONE_FIELD_NUM_MESSAGE_INDEX = 254,
   FIT_POWER_ZONE_FIELD_NUM_HIGH_VALUE = 1
} FIT_POWER_ZONE_FIELD_NUM;

typedef enum
{
   FIT_POWER_ZONE_MESG_NAME,
   FIT_POWER_ZONE_MESG_MESSAGE_INDEX,
   FIT_POWER_ZONE_MESG_HIGH_VALUE,
   FIT_POWER_ZONE_MESG_FIELDS
} FIT_POWER_ZONE_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_POWER_ZONE_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_POWER_ZONE_MESG_DEF;

// met_zone message

#define FIT_MET_ZONE_MESG_SIZE                                                  6
#define FIT_MET_ZONE_MESG_DEF_SIZE                                              17

typedef struct
{
   FIT_MESSAGE_INDEX message_index; //
   FIT_UINT16 calories; // 10 * kcal / min,
   FIT_UINT8 high_bpm; //
   FIT_UINT8 fat_calories; // 10 * kcal / min,
} FIT_MET_ZONE_MESG;

typedef enum
{
   FIT_MET_ZONE_FIELD_NUM_MESSAGE_INDEX = 254,
   FIT_MET_ZONE_FIELD_NUM_CALORIES = 2,
   FIT_MET_ZONE_FIELD_NUM_HIGH_BPM = 1,
   FIT_MET_ZONE_FIELD_NUM_FAT_CALORIES = 3
} FIT_MET_ZONE_FIELD_NUM;

typedef enum
{
   FIT_MET_ZONE_MESG_MESSAGE_INDEX,
   FIT_MET_ZONE_MESG_CALORIES,
   FIT_MET_ZONE_MESG_HIGH_BPM,
   FIT_MET_ZONE_MESG_FAT_CALORIES,
   FIT_MET_ZONE_MESG_FIELDS
} FIT_MET_ZONE_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_MET_ZONE_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_MET_ZONE_MESG_DEF;

// goal message

#define FIT_GOAL_MESG_SIZE                                                      26
#define FIT_GOAL_MESG_DEF_SIZE                                                  41

typedef struct
{
   FIT_DATE_TIME start_date; //
   FIT_DATE_TIME end_date; //
   FIT_UINT32 value; //
   FIT_UINT32 target_value; //
   FIT_MESSAGE_INDEX message_index; //
   FIT_UINT16 recurrence_value; //
   FIT_SPORT sport; //
   FIT_SUB_SPORT sub_sport; //
   FIT_GOAL type; //
   FIT_BOOL repeat; //
   FIT_GOAL_RECURRENCE recurrence; //
   FIT_BOOL enabled; //
} FIT_GOAL_MESG;

typedef enum
{
   FIT_GOAL_FIELD_NUM_START_DATE = 2,
   FIT_GOAL_FIELD_NUM_END_DATE = 3,
   FIT_GOAL_FIELD_NUM_VALUE = 5,
   FIT_GOAL_FIELD_NUM_TARGET_VALUE = 7,
   FIT_GOAL_FIELD_NUM_MESSAGE_INDEX = 254,
   FIT_GOAL_FIELD_NUM_RECURRENCE_VALUE = 9,
   FIT_GOAL_FIELD_NUM_SPORT = 0,
   FIT_GOAL_FIELD_NUM_SUB_SPORT = 1,
   FIT_GOAL_FIELD_NUM_TYPE = 4,
   FIT_GOAL_FIELD_NUM_REPEAT = 6,
   FIT_GOAL_FIELD_NUM_RECURRENCE = 8,
   FIT_GOAL_FIELD_NUM_ENABLED = 10
} FIT_GOAL_FIELD_NUM;

typedef enum
{
   FIT_GOAL_MESG_START_DATE,
   FIT_GOAL_MESG_END_DATE,
   FIT_GOAL_MESG_VALUE,
   FIT_GOAL_MESG_TARGET_VALUE,
   FIT_GOAL_MESG_MESSAGE_INDEX,
   FIT_GOAL_MESG_RECURRENCE_VALUE,
   FIT_GOAL_MESG_SPORT,
   FIT_GOAL_MESG_SUB_SPORT,
   FIT_GOAL_MESG_TYPE,
   FIT_GOAL_MESG_REPEAT,
   FIT_GOAL_MESG_RECURRENCE,
   FIT_GOAL_MESG_ENABLED,
   FIT_GOAL_MESG_FIELDS
} FIT_GOAL_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_GOAL_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_GOAL_MESG_DEF;

// activity message

#define FIT_ACTIVITY_MESG_SIZE                                                  18
#define FIT_ACTIVITY_MESG_DEF_SIZE                                              29

typedef struct
{
   FIT_DATE_TIME timestamp; //
   FIT_UINT32 total_timer_time; // 1000 * s,Exclude pauses
   FIT_LOCAL_DATE_TIME local_timestamp; // timestamp epoch expressed in local time, used to convert activity timestamps to local time
   FIT_UINT16 num_sessions; //
   FIT_ACTIVITY type; //
   FIT_EVENT event; //
   FIT_EVENT_TYPE event_type; //
   FIT_UINT8 event_group; //
} FIT_ACTIVITY_MESG;

typedef enum
{
   FIT_ACTIVITY_FIELD_NUM_TIMESTAMP = 253,
   FIT_ACTIVITY_FIELD_NUM_TOTAL_TIMER_TIME = 0,
   FIT_ACTIVITY_FIELD_NUM_LOCAL_TIMESTAMP = 5,
   FIT_ACTIVITY_FIELD_NUM_NUM_SESSIONS = 1,
   FIT_ACTIVITY_FIELD_NUM_TYPE = 2,
   FIT_ACTIVITY_FIELD_NUM_EVENT = 3,
   FIT_ACTIVITY_FIELD_NUM_EVENT_TYPE = 4,
   FIT_ACTIVITY_FIELD_NUM_EVENT_GROUP = 6
} FIT_ACTIVITY_FIELD_NUM;

typedef enum
{
   FIT_ACTIVITY_MESG_TIMESTAMP,
   FIT_ACTIVITY_MESG_TOTAL_TIMER_TIME,
   FIT_ACTIVITY_MESG_LOCAL_TIMESTAMP,
   FIT_ACTIVITY_MESG_NUM_SESSIONS,
   FIT_ACTIVITY_MESG_TYPE,
   FIT_ACTIVITY_MESG_EVENT,
   FIT_ACTIVITY_MESG_EVENT_TYPE,
   FIT_ACTIVITY_MESG_EVENT_GROUP,
   FIT_ACTIVITY_MESG_FIELDS
} FIT_ACTIVITY_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_ACTIVITY_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_ACTIVITY_MESG_DEF;

// session message

#define FIT_SESSION_MESG_SIZE                                                   181
#define FIT_SESSION_MESG_DEF_SIZE                                               248
#define FIT_SESSION_MESG_TIME_IN_HR_ZONE_COUNT                                  1
#define FIT_SESSION_MESG_TIME_IN_SPEED_ZONE_COUNT                               1
#define FIT_SESSION_MESG_TIME_IN_CADENCE_ZONE_COUNT                             1
#define FIT_SESSION_MESG_TIME_IN_POWER_ZONE_COUNT                               1
#define FIT_SESSION_MESG_STROKE_COUNT_COUNT                                     1
#define FIT_SESSION_MESG_ZONE_COUNT_COUNT                                       1
#define FIT_SESSION_MESG_OPPONENT_NAME_COUNT                                    1

typedef struct
{
   FIT_DATE_TIME timestamp; // s,Sesson end time.
   FIT_DATE_TIME start_time; //
   FIT_SINT32 start_position_lat; // semicircles,
   FIT_SINT32 start_position_long; // semicircles,
   FIT_UINT32 total_elapsed_time; // 1000 * s,Time (includes pauses)
   FIT_UINT32 total_timer_time; // 1000 * s,Timer Time (excludes pauses)
   FIT_UINT32 total_distance; // 100 * m,
   FIT_UINT32 total_cycles; // cycles,
   FIT_SINT32 nec_lat; // semicircles,
   FIT_SINT32 nec_long; // semicircles,
   FIT_SINT32 swc_lat; // semicircles,
   FIT_SINT32 swc_long; // semicircles,
   FIT_UINT32 avg_stroke_count; // 10 * strokes/lap,
   FIT_UINT32 total_work; // J,
   FIT_UINT32 total_moving_time; // 1000 * s,
   FIT_UINT32 time_in_hr_zone[FIT_SESSION_MESG_TIME_IN_HR_ZONE_COUNT]; // 1000 * s,
   FIT_UINT32 time_in_speed_zone[FIT_SESSION_MESG_TIME_IN_SPEED_ZONE_COUNT]; // 1000 * s,
   FIT_UINT32 time_in_cadence_zone[FIT_SESSION_MESG_TIME_IN_CADENCE_ZONE_COUNT]; // 1000 * s,
   FIT_UINT32 time_in_power_zone[FIT_SESSION_MESG_TIME_IN_POWER_ZONE_COUNT]; // 1000 * s,
   FIT_UINT32 avg_lap_time; // 1000 * s,
   FIT_MESSAGE_INDEX message_index; // Selected bit is set for the current session.
   FIT_UINT16 total_calories; // kcal,
   FIT_UINT16 total_fat_calories; // kcal,
   FIT_UINT16 avg_speed; // 1000 * m/s,total_distance / total_timer_time
   FIT_UINT16 max_speed; // 1000 * m/s,
   FIT_UINT16 avg_power; // watts,total_power / total_timer_time if non_zero_avg_power otherwise total_power / total_elapsed_time
   FIT_UINT16 max_power; // watts,
   FIT_UINT16 total_ascent; // m,
   FIT_UINT16 total_descent; // m,
   FIT_UINT16 first_lap_index; //
   FIT_UINT16 num_laps; //
   FIT_UINT16 normalized_power; // watts,
   FIT_UINT16 training_stress_score; // 10 * tss,
   FIT_UINT16 intensity_factor; // 1000 * if,
   FIT_LEFT_RIGHT_BALANCE_100 left_right_balance; //
   FIT_UINT16 avg_stroke_distance; // 100 * m,
   FIT_UINT16 pool_length; // 100 * m,
   FIT_UINT16 num_active_lengths; // lengths,# of active lengths of swim pool
   FIT_UINT16 avg_altitude; // 5 * m + 500,
   FIT_UINT16 max_altitude; // 5 * m + 500,
   FIT_SINT16 avg_grade; // 100 * %,
   FIT_SINT16 avg_pos_grade; // 100 * %,
   FIT_SINT16 avg_neg_grade; // 100 * %,
   FIT_SINT16 max_pos_grade; // 100 * %,
   FIT_SINT16 max_neg_grade; // 100 * %,
   FIT_SINT16 avg_pos_vertical_speed; // 1000 * m/s,
   FIT_SINT16 avg_neg_vertical_speed; // 1000 * m/s,
   FIT_SINT16 max_pos_vertical_speed; // 1000 * m/s,
   FIT_SINT16 max_neg_vertical_speed; // 1000 * m/s,
   FIT_UINT16 best_lap_index; //
   FIT_UINT16 min_altitude; // 5 * m + 500,
   FIT_UINT16 player_score; //
   FIT_UINT16 opponent_score; //
   FIT_UINT16 stroke_count[FIT_SESSION_MESG_STROKE_COUNT_COUNT]; // counts,stroke_type enum used as the index
   FIT_UINT16 zone_count[FIT_SESSION_MESG_ZONE_COUNT_COUNT]; // counts,zone number used as the index
   FIT_UINT16 max_ball_speed; // 100 * m/s,
   FIT_UINT16 avg_ball_speed; // 100 * m/s,
   FIT_UINT16 avg_vertical_oscillation; // 10 * mm,
   FIT_UINT16 avg_stance_time_percent; // 100 * percent,
   FIT_UINT16 avg_stance_time; // 10 * ms,
   FIT_EVENT event; // session
   FIT_EVENT_TYPE event_type; // stop
   FIT_SPORT sport; //
   FIT_SUB_SPORT sub_sport; //
   FIT_UINT8 avg_heart_rate; // bpm,average heart rate (excludes pause time)
   FIT_UINT8 max_heart_rate; // bpm,
   FIT_UINT8 avg_cadence; // rpm,total_cycles / total_timer_time if non_zero_avg_cadence otherwise total_cycles / total_elapsed_time
   FIT_UINT8 max_cadence; // rpm,
   FIT_UINT8 total_training_effect; //
   FIT_UINT8 event_group; //
   FIT_SESSION_TRIGGER trigger; //
   FIT_SWIM_STROKE swim_stroke; // swim_stroke,
   FIT_DISPLAY_MEASURE pool_length_unit; //
   FIT_UINT8 gps_accuracy; // m,
   FIT_SINT8 avg_temperature; // C,
   FIT_SINT8 max_temperature; // C,
   FIT_UINT8 min_heart_rate; // bpm,
   FIT_STRING opponent_name[FIT_SESSION_MESG_OPPONENT_NAME_COUNT]; //
   FIT_UINT8 avg_fractional_cadence; // 128 * rpm,fractional part of the avg_cadence
   FIT_UINT8 max_fractional_cadence; // 128 * rpm,fractional part of the max_cadence
   FIT_UINT8 total_fractional_cycles; // 128 * cycles,fractional part of the total_cycles
} FIT_SESSION_MESG;

typedef enum
{
   FIT_SESSION_FIELD_NUM_TIMESTAMP = 253,
   FIT_SESSION_FIELD_NUM_START_TIME = 2,
   FIT_SESSION_FIELD_NUM_START_POSITION_LAT = 3,
   FIT_SESSION_FIELD_NUM_START_POSITION_LONG = 4,
   FIT_SESSION_FIELD_NUM_TOTAL_ELAPSED_TIME = 7,
   FIT_SESSION_FIELD_NUM_TOTAL_TIMER_TIME = 8,
   FIT_SESSION_FIELD_NUM_TOTAL_DISTANCE = 9,
   FIT_SESSION_FIELD_NUM_TOTAL_CYCLES = 10,
   FIT_SESSION_FIELD_NUM_NEC_LAT = 29,
   FIT_SESSION_FIELD_NUM_NEC_LONG = 30,
   FIT_SESSION_FIELD_NUM_SWC_LAT = 31,
   FIT_SESSION_FIELD_NUM_SWC_LONG = 32,
   FIT_SESSION_FIELD_NUM_AVG_STROKE_COUNT = 41,
   FIT_SESSION_FIELD_NUM_TOTAL_WORK = 48,
   FIT_SESSION_FIELD_NUM_TOTAL_MOVING_TIME = 59,
   FIT_SESSION_FIELD_NUM_TIME_IN_HR_ZONE = 65,
   FIT_SESSION_FIELD_NUM_TIME_IN_SPEED_ZONE = 66,
   FIT_SESSION_FIELD_NUM_TIME_IN_CADENCE_ZONE = 67,
   FIT_SESSION_FIELD_NUM_TIME_IN_POWER_ZONE = 68,
   FIT_SESSION_FIELD_NUM_AVG_LAP_TIME = 69,
   FIT_SESSION_FIELD_NUM_MESSAGE_INDEX = 254,
   FIT_SESSION_FIELD_NUM_TOTAL_CALORIES = 11,
   FIT_SESSION_FIELD_NUM_TOTAL_FAT_CALORIES = 13,
   FIT_SESSION_FIELD_NUM_AVG_SPEED = 14,
   FIT_SESSION_FIELD_NUM_MAX_SPEED = 15,
   FIT_SESSION_FIELD_NUM_AVG_POWER = 20,
   FIT_SESSION_FIELD_NUM_MAX_POWER = 21,
   FIT_SESSION_FIELD_NUM_TOTAL_ASCENT = 22,
   FIT_SESSION_FIELD_NUM_TOTAL_DESCENT = 23,
   FIT_SESSION_FIELD_NUM_FIRST_LAP_INDEX = 25,
   FIT_SESSION_FIELD_NUM_NUM_LAPS = 26,
   FIT_SESSION_FIELD_NUM_NORMALIZED_POWER = 34,
   FIT_SESSION_FIELD_NUM_TRAINING_STRESS_SCORE = 35,
   FIT_SESSION_FIELD_NUM_INTENSITY_FACTOR = 36,
   FIT_SESSION_FIELD_NUM_LEFT_RIGHT_BALANCE = 37,
   FIT_SESSION_FIELD_NUM_AVG_STROKE_DISTANCE = 42,
   FIT_SESSION_FIELD_NUM_POOL_LENGTH = 44,
   FIT_SESSION_FIELD_NUM_NUM_ACTIVE_LENGTHS = 47,
   FIT_SESSION_FIELD_NUM_AVG_ALTITUDE = 49,
   FIT_SESSION_FIELD_NUM_MAX_ALTITUDE = 50,
   FIT_SESSION_FIELD_NUM_AVG_GRADE = 52,
   FIT_SESSION_FIELD_NUM_AVG_POS_GRADE = 53,
   FIT_SESSION_FIELD_NUM_AVG_NEG_GRADE = 54,
   FIT_SESSION_FIELD_NUM_MAX_POS_GRADE = 55,
   FIT_SESSION_FIELD_NUM_MAX_NEG_GRADE = 56,
   FIT_SESSION_FIELD_NUM_AVG_POS_VERTICAL_SPEED = 60,
   FIT_SESSION_FIELD_NUM_AVG_NEG_VERTICAL_SPEED = 61,
   FIT_SESSION_FIELD_NUM_MAX_POS_VERTICAL_SPEED = 62,
   FIT_SESSION_FIELD_NUM_MAX_NEG_VERTICAL_SPEED = 63,
   FIT_SESSION_FIELD_NUM_BEST_LAP_INDEX = 70,
   FIT_SESSION_FIELD_NUM_MIN_ALTITUDE = 71,
   FIT_SESSION_FIELD_NUM_PLAYER_SCORE = 82,
   FIT_SESSION_FIELD_NUM_OPPONENT_SCORE = 83,
   FIT_SESSION_FIELD_NUM_STROKE_COUNT = 85,
   FIT_SESSION_FIELD_NUM_ZONE_COUNT = 86,
   FIT_SESSION_FIELD_NUM_MAX_BALL_SPEED = 87,
   FIT_SESSION_FIELD_NUM_AVG_BALL_SPEED = 88,
   FIT_SESSION_FIELD_NUM_AVG_VERTICAL_OSCILLATION = 89,
   FIT_SESSION_FIELD_NUM_AVG_STANCE_TIME_PERCENT = 90,
   FIT_SESSION_FIELD_NUM_AVG_STANCE_TIME = 91,
   FIT_SESSION_FIELD_NUM_EVENT = 0,
   FIT_SESSION_FIELD_NUM_EVENT_TYPE = 1,
   FIT_SESSION_FIELD_NUM_SPORT = 5,
   FIT_SESSION_FIELD_NUM_SUB_SPORT = 6,
   FIT_SESSION_FIELD_NUM_AVG_HEART_RATE = 16,
   FIT_SESSION_FIELD_NUM_MAX_HEART_RATE = 17,
   FIT_SESSION_FIELD_NUM_AVG_CADENCE = 18,
   FIT_SESSION_FIELD_NUM_MAX_CADENCE = 19,
   FIT_SESSION_FIELD_NUM_TOTAL_TRAINING_EFFECT = 24,
   FIT_SESSION_FIELD_NUM_EVENT_GROUP = 27,
   FIT_SESSION_FIELD_NUM_TRIGGER = 28,
   FIT_SESSION_FIELD_NUM_SWIM_STROKE = 43,
   FIT_SESSION_FIELD_NUM_POOL_LENGTH_UNIT = 46,
   FIT_SESSION_FIELD_NUM_GPS_ACCURACY = 51,
   FIT_SESSION_FIELD_NUM_AVG_TEMPERATURE = 57,
   FIT_SESSION_FIELD_NUM_MAX_TEMPERATURE = 58,
   FIT_SESSION_FIELD_NUM_MIN_HEART_RATE = 64,
   FIT_SESSION_FIELD_NUM_OPPONENT_NAME = 84,
   FIT_SESSION_FIELD_NUM_AVG_FRACTIONAL_CADENCE = 92,
   FIT_SESSION_FIELD_NUM_MAX_FRACTIONAL_CADENCE = 93,
   FIT_SESSION_FIELD_NUM_TOTAL_FRACTIONAL_CYCLES = 94
} FIT_SESSION_FIELD_NUM;

typedef enum
{
   FIT_SESSION_MESG_TIMESTAMP,
   FIT_SESSION_MESG_START_TIME,
   FIT_SESSION_MESG_START_POSITION_LAT,
   FIT_SESSION_MESG_START_POSITION_LONG,
   FIT_SESSION_MESG_TOTAL_ELAPSED_TIME,
   FIT_SESSION_MESG_TOTAL_TIMER_TIME,
   FIT_SESSION_MESG_TOTAL_DISTANCE,
   FIT_SESSION_MESG_TOTAL_CYCLES,
   FIT_SESSION_MESG_NEC_LAT,
   FIT_SESSION_MESG_NEC_LONG,
   FIT_SESSION_MESG_SWC_LAT,
   FIT_SESSION_MESG_SWC_LONG,
   FIT_SESSION_MESG_AVG_STROKE_COUNT,
   FIT_SESSION_MESG_TOTAL_WORK,
   FIT_SESSION_MESG_TOTAL_MOVING_TIME,
   FIT_SESSION_MESG_TIME_IN_HR_ZONE,
   FIT_SESSION_MESG_TIME_IN_SPEED_ZONE,
   FIT_SESSION_MESG_TIME_IN_CADENCE_ZONE,
   FIT_SESSION_MESG_TIME_IN_POWER_ZONE,
   FIT_SESSION_MESG_AVG_LAP_TIME,
   FIT_SESSION_MESG_MESSAGE_INDEX,
   FIT_SESSION_MESG_TOTAL_CALORIES,
   FIT_SESSION_MESG_TOTAL_FAT_CALORIES,
   FIT_SESSION_MESG_AVG_SPEED,
   FIT_SESSION_MESG_MAX_SPEED,
   FIT_SESSION_MESG_AVG_POWER,
   FIT_SESSION_MESG_MAX_POWER,
   FIT_SESSION_MESG_TOTAL_ASCENT,
   FIT_SESSION_MESG_TOTAL_DESCENT,
   FIT_SESSION_MESG_FIRST_LAP_INDEX,
   FIT_SESSION_MESG_NUM_LAPS,
   FIT_SESSION_MESG_NORMALIZED_POWER,
   FIT_SESSION_MESG_TRAINING_STRESS_SCORE,
   FIT_SESSION_MESG_INTENSITY_FACTOR,
   FIT_SESSION_MESG_LEFT_RIGHT_BALANCE,
   FIT_SESSION_MESG_AVG_STROKE_DISTANCE,
   FIT_SESSION_MESG_POOL_LENGTH,
   FIT_SESSION_MESG_NUM_ACTIVE_LENGTHS,
   FIT_SESSION_MESG_AVG_ALTITUDE,
   FIT_SESSION_MESG_MAX_ALTITUDE,
   FIT_SESSION_MESG_AVG_GRADE,
   FIT_SESSION_MESG_AVG_POS_GRADE,
   FIT_SESSION_MESG_AVG_NEG_GRADE,
   FIT_SESSION_MESG_MAX_POS_GRADE,
   FIT_SESSION_MESG_MAX_NEG_GRADE,
   FIT_SESSION_MESG_AVG_POS_VERTICAL_SPEED,
   FIT_SESSION_MESG_AVG_NEG_VERTICAL_SPEED,
   FIT_SESSION_MESG_MAX_POS_VERTICAL_SPEED,
   FIT_SESSION_MESG_MAX_NEG_VERTICAL_SPEED,
   FIT_SESSION_MESG_BEST_LAP_INDEX,
   FIT_SESSION_MESG_MIN_ALTITUDE,
   FIT_SESSION_MESG_PLAYER_SCORE,
   FIT_SESSION_MESG_OPPONENT_SCORE,
   FIT_SESSION_MESG_STROKE_COUNT,
   FIT_SESSION_MESG_ZONE_COUNT,
   FIT_SESSION_MESG_MAX_BALL_SPEED,
   FIT_SESSION_MESG_AVG_BALL_SPEED,
   FIT_SESSION_MESG_AVG_VERTICAL_OSCILLATION,
   FIT_SESSION_MESG_AVG_STANCE_TIME_PERCENT,
   FIT_SESSION_MESG_AVG_STANCE_TIME,
   FIT_SESSION_MESG_EVENT,
   FIT_SESSION_MESG_EVENT_TYPE,
   FIT_SESSION_MESG_SPORT,
   FIT_SESSION_MESG_SUB_SPORT,
   FIT_SESSION_MESG_AVG_HEART_RATE,
   FIT_SESSION_MESG_MAX_HEART_RATE,
   FIT_SESSION_MESG_AVG_CADENCE,
   FIT_SESSION_MESG_MAX_CADENCE,
   FIT_SESSION_MESG_TOTAL_TRAINING_EFFECT,
   FIT_SESSION_MESG_EVENT_GROUP,
   FIT_SESSION_MESG_TRIGGER,
   FIT_SESSION_MESG_SWIM_STROKE,
   FIT_SESSION_MESG_POOL_LENGTH_UNIT,
   FIT_SESSION_MESG_GPS_ACCURACY,
   FIT_SESSION_MESG_AVG_TEMPERATURE,
   FIT_SESSION_MESG_MAX_TEMPERATURE,
   FIT_SESSION_MESG_MIN_HEART_RATE,
   FIT_SESSION_MESG_OPPONENT_NAME,
   FIT_SESSION_MESG_AVG_FRACTIONAL_CADENCE,
   FIT_SESSION_MESG_MAX_FRACTIONAL_CADENCE,
   FIT_SESSION_MESG_TOTAL_FRACTIONAL_CYCLES,
   FIT_SESSION_MESG_FIELDS
} FIT_SESSION_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_SESSION_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_SESSION_MESG_DEF;

// lap message

#define FIT_LAP_MESG_SIZE                                                       167
#define FIT_LAP_MESG_DEF_SIZE                                                   236
#define FIT_LAP_MESG_TIME_IN_HR_ZONE_COUNT                                      1
#define FIT_LAP_MESG_TIME_IN_SPEED_ZONE_COUNT                                   1
#define FIT_LAP_MESG_TIME_IN_CADENCE_ZONE_COUNT                                 1
#define FIT_LAP_MESG_TIME_IN_POWER_ZONE_COUNT                                   1
#define FIT_LAP_MESG_STROKE_COUNT_COUNT                                         1
#define FIT_LAP_MESG_ZONE_COUNT_COUNT                                           1
#define FIT_LAP_MESG_AVG_TOTAL_HEMOGLOBIN_CONC_COUNT                            1
#define FIT_LAP_MESG_MIN_TOTAL_HEMOGLOBIN_CONC_COUNT                            1
#define FIT_LAP_MESG_MAX_TOTAL_HEMOGLOBIN_CONC_COUNT                            1
#define FIT_LAP_MESG_AVG_SATURATED_HEMOGLOBIN_PERCENT_COUNT                     1
#define FIT_LAP_MESG_MIN_SATURATED_HEMOGLOBIN_PERCENT_COUNT                     1
#define FIT_LAP_MESG_MAX_SATURATED_HEMOGLOBIN_PERCENT_COUNT                     1

typedef struct
{
   FIT_DATE_TIME timestamp; // s,Lap end time.
   FIT_DATE_TIME start_time; //
   FIT_SINT32 start_position_lat; // semicircles,
   FIT_SINT32 start_position_long; // semicircles,
   FIT_SINT32 end_position_lat; // semicircles,
   FIT_SINT32 end_position_long; // semicircles,
   FIT_UINT32 total_elapsed_time; // 1000 * s,Time (includes pauses)
   FIT_UINT32 total_timer_time; // 1000 * s,Timer Time (excludes pauses)
   FIT_UINT32 total_distance; // 100 * m,
   FIT_UINT32 total_cycles; // cycles,
   FIT_UINT32 total_work; // J,
   FIT_UINT32 total_moving_time; // 1000 * s,
   FIT_UINT32 time_in_hr_zone[FIT_LAP_MESG_TIME_IN_HR_ZONE_COUNT]; // 1000 * s,
   FIT_UINT32 time_in_speed_zone[FIT_LAP_MESG_TIME_IN_SPEED_ZONE_COUNT]; // 1000 * s,
   FIT_UINT32 time_in_cadence_zone[FIT_LAP_MESG_TIME_IN_CADENCE_ZONE_COUNT]; // 1000 * s,
   FIT_UINT32 time_in_power_zone[FIT_LAP_MESG_TIME_IN_POWER_ZONE_COUNT]; // 1000 * s,
   FIT_MESSAGE_INDEX message_index; //
   FIT_UINT16 total_calories; // kcal,
   FIT_UINT16 total_fat_calories; // kcal,If New Leaf
   FIT_UINT16 avg_speed; // 1000 * m/s,
   FIT_UINT16 max_speed; // 1000 * m/s,
   FIT_UINT16 avg_power; // watts,total_power / total_timer_time if non_zero_avg_power otherwise total_power / total_elapsed_time
   FIT_UINT16 max_power; // watts,
   FIT_UINT16 total_ascent; // m,
   FIT_UINT16 total_descent; // m,
   FIT_UINT16 num_lengths; // lengths,# of lengths of swim pool
   FIT_UINT16 normalized_power; // watts,
   FIT_LEFT_RIGHT_BALANCE_100 left_right_balance; //
   FIT_UINT16 first_length_index; //
   FIT_UINT16 avg_stroke_distance; // 100 * m,
   FIT_UINT16 num_active_lengths; // lengths,# of active lengths of swim pool
   FIT_UINT16 avg_altitude; // 5 * m + 500,
   FIT_UINT16 max_altitude; // 5 * m + 500,
   FIT_SINT16 avg_grade; // 100 * %,
   FIT_SINT16 avg_pos_grade; // 100 * %,
   FIT_SINT16 avg_neg_grade; // 100 * %,
   FIT_SINT16 max_pos_grade; // 100 * %,
   FIT_SINT16 max_neg_grade; // 100 * %,
   FIT_SINT16 avg_pos_vertical_speed; // 1000 * m/s,
   FIT_SINT16 avg_neg_vertical_speed; // 1000 * m/s,
   FIT_SINT16 max_pos_vertical_speed; // 1000 * m/s,
   FIT_SINT16 max_neg_vertical_speed; // 1000 * m/s,
   FIT_UINT16 repetition_num; //
   FIT_UINT16 min_altitude; // 5 * m + 500,
   FIT_MESSAGE_INDEX wkt_step_index; //
   FIT_UINT16 opponent_score; //
   FIT_UINT16 stroke_count[FIT_LAP_MESG_STROKE_COUNT_COUNT]; // counts,stroke_type enum used as the index
   FIT_UINT16 zone_count[FIT_LAP_MESG_ZONE_COUNT_COUNT]; // counts,zone number used as the index
   FIT_UINT16 avg_vertical_oscillation; // 10 * mm,
   FIT_UINT16 avg_stance_time_percent; // 100 * percent,
   FIT_UINT16 avg_stance_time; // 10 * ms,
   FIT_UINT16 player_score; //
   FIT_UINT16 avg_total_hemoglobin_conc[FIT_LAP_MESG_AVG_TOTAL_HEMOGLOBIN_CONC_COUNT]; // 100 * g/dL,Avg saturated and unsaturated hemoglobin
   FIT_UINT16 min_total_hemoglobin_conc[FIT_LAP_MESG_MIN_TOTAL_HEMOGLOBIN_CONC_COUNT]; // 100 * g/dL,Min saturated and unsaturated hemoglobin
   FIT_UINT16 max_total_hemoglobin_conc[FIT_LAP_MESG_MAX_TOTAL_HEMOGLOBIN_CONC_COUNT]; // 100 * g/dL,Max saturated and unsaturated hemoglobin
   FIT_UINT16 avg_saturated_hemoglobin_percent[FIT_LAP_MESG_AVG_SATURATED_HEMOGLOBIN_PERCENT_COUNT]; // 10 * %,Avg percentage of hemoglobin saturated with oxygen
   FIT_UINT16 min_saturated_hemoglobin_percent[FIT_LAP_MESG_MIN_SATURATED_HEMOGLOBIN_PERCENT_COUNT]; // 10 * %,Min percentage of hemoglobin saturated with oxygen
   FIT_UINT16 max_saturated_hemoglobin_percent[FIT_LAP_MESG_MAX_SATURATED_HEMOGLOBIN_PERCENT_COUNT]; // 10 * %,Max percentage of hemoglobin saturated with oxygen
   FIT_EVENT event; //
   FIT_EVENT_TYPE event_type; //
   FIT_UINT8 avg_heart_rate; // bpm,
   FIT_UINT8 max_heart_rate; // bpm,
   FIT_UINT8 avg_cadence; // rpm,total_cycles / total_timer_time if non_zero_avg_cadence otherwise total_cycles / total_elapsed_time
   FIT_UINT8 max_cadence; // rpm,
   FIT_INTENSITY intensity; //
   FIT_LAP_TRIGGER lap_trigger; //
   FIT_SPORT sport; //
   FIT_UINT8 event_group; //
   FIT_SWIM_STROKE swim_stroke; //
   FIT_SUB_SPORT sub_sport; //
   FIT_UINT8 gps_accuracy; // m,
   FIT_SINT8 avg_temperature; // C,
   FIT_SINT8 max_temperature; // C,
   FIT_UINT8 min_heart_rate; // bpm,
   FIT_UINT8 avg_fractional_cadence; // 128 * rpm,fractional part of the avg_cadence
   FIT_UINT8 max_fractional_cadence; // 128 * rpm,fractional part of the max_cadence
   FIT_UINT8 total_fractional_cycles; // 128 * cycles,fractional part of the total_cycles
} FIT_LAP_MESG;

typedef enum
{
   FIT_LAP_FIELD_NUM_TIMESTAMP = 253,
   FIT_LAP_FIELD_NUM_START_TIME = 2,
   FIT_LAP_FIELD_NUM_START_POSITION_LAT = 3,
   FIT_LAP_FIELD_NUM_START_POSITION_LONG = 4,
   FIT_LAP_FIELD_NUM_END_POSITION_LAT = 5,
   FIT_LAP_FIELD_NUM_END_POSITION_LONG = 6,
   FIT_LAP_FIELD_NUM_TOTAL_ELAPSED_TIME = 7,
   FIT_LAP_FIELD_NUM_TOTAL_TIMER_TIME = 8,
   FIT_LAP_FIELD_NUM_TOTAL_DISTANCE = 9,
   FIT_LAP_FIELD_NUM_TOTAL_CYCLES = 10,
   FIT_LAP_FIELD_NUM_TOTAL_WORK = 41,
   FIT_LAP_FIELD_NUM_TOTAL_MOVING_TIME = 52,
   FIT_LAP_FIELD_NUM_TIME_IN_HR_ZONE = 57,
   FIT_LAP_FIELD_NUM_TIME_IN_SPEED_ZONE = 58,
   FIT_LAP_FIELD_NUM_TIME_IN_CADENCE_ZONE = 59,
   FIT_LAP_FIELD_NUM_TIME_IN_POWER_ZONE = 60,
   FIT_LAP_FIELD_NUM_MESSAGE_INDEX = 254,
   FIT_LAP_FIELD_NUM_TOTAL_CALORIES = 11,
   FIT_LAP_FIELD_NUM_TOTAL_FAT_CALORIES = 12,
   FIT_LAP_FIELD_NUM_AVG_SPEED = 13,
   FIT_LAP_FIELD_NUM_MAX_SPEED = 14,
   FIT_LAP_FIELD_NUM_AVG_POWER = 19,
   FIT_LAP_FIELD_NUM_MAX_POWER = 20,
   FIT_LAP_FIELD_NUM_TOTAL_ASCENT = 21,
   FIT_LAP_FIELD_NUM_TOTAL_DESCENT = 22,
   FIT_LAP_FIELD_NUM_NUM_LENGTHS = 32,
   FIT_LAP_FIELD_NUM_NORMALIZED_POWER = 33,
   FIT_LAP_FIELD_NUM_LEFT_RIGHT_BALANCE = 34,
   FIT_LAP_FIELD_NUM_FIRST_LENGTH_INDEX = 35,
   FIT_LAP_FIELD_NUM_AVG_STROKE_DISTANCE = 37,
   FIT_LAP_FIELD_NUM_NUM_ACTIVE_LENGTHS = 40,
   FIT_LAP_FIELD_NUM_AVG_ALTITUDE = 42,
   FIT_LAP_FIELD_NUM_MAX_ALTITUDE = 43,
   FIT_LAP_FIELD_NUM_AVG_GRADE = 45,
   FIT_LAP_FIELD_NUM_AVG_POS_GRADE = 46,
   FIT_LAP_FIELD_NUM_AVG_NEG_GRADE = 47,
   FIT_LAP_FIELD_NUM_MAX_POS_GRADE = 48,
   FIT_LAP_FIELD_NUM_MAX_NEG_GRADE = 49,
   FIT_LAP_FIELD_NUM_AVG_POS_VERTICAL_SPEED = 53,
   FIT_LAP_FIELD_NUM_AVG_NEG_VERTICAL_SPEED = 54,
   FIT_LAP_FIELD_NUM_MAX_POS_VERTICAL_SPEED = 55,
   FIT_LAP_FIELD_NUM_MAX_NEG_VERTICAL_SPEED = 56,
   FIT_LAP_FIELD_NUM_REPETITION_NUM = 61,
   FIT_LAP_FIELD_NUM_MIN_ALTITUDE = 62,
   FIT_LAP_FIELD_NUM_WKT_STEP_INDEX = 71,
   FIT_LAP_FIELD_NUM_OPPONENT_SCORE = 74,
   FIT_LAP_FIELD_NUM_STROKE_COUNT = 75,
   FIT_LAP_FIELD_NUM_ZONE_COUNT = 76,
   FIT_LAP_FIELD_NUM_AVG_VERTICAL_OSCILLATION = 77,
   FIT_LAP_FIELD_NUM_AVG_STANCE_TIME_PERCENT = 78,
   FIT_LAP_FIELD_NUM_AVG_STANCE_TIME = 79,
   FIT_LAP_FIELD_NUM_PLAYER_SCORE = 83,
   FIT_LAP_FIELD_NUM_AVG_TOTAL_HEMOGLOBIN_CONC = 84,
   FIT_LAP_FIELD_NUM_MIN_TOTAL_HEMOGLOBIN_CONC = 85,
   FIT_LAP_FIELD_NUM_MAX_TOTAL_HEMOGLOBIN_CONC = 86,
   FIT_LAP_FIELD_NUM_AVG_SATURATED_HEMOGLOBIN_PERCENT = 87,
   FIT_LAP_FIELD_NUM_MIN_SATURATED_HEMOGLOBIN_PERCENT = 88,
   FIT_LAP_FIELD_NUM_MAX_SATURATED_HEMOGLOBIN_PERCENT = 89,
   FIT_LAP_FIELD_NUM_EVENT = 0,
   FIT_LAP_FIELD_NUM_EVENT_TYPE = 1,
   FIT_LAP_FIELD_NUM_AVG_HEART_RATE = 15,
   FIT_LAP_FIELD_NUM_MAX_HEART_RATE = 16,
   FIT_LAP_FIELD_NUM_AVG_CADENCE = 17,
   FIT_LAP_FIELD_NUM_MAX_CADENCE = 18,
   FIT_LAP_FIELD_NUM_INTENSITY = 23,
   FIT_LAP_FIELD_NUM_LAP_TRIGGER = 24,
   FIT_LAP_FIELD_NUM_SPORT = 25,
   FIT_LAP_FIELD_NUM_EVENT_GROUP = 26,
   FIT_LAP_FIELD_NUM_SWIM_STROKE = 38,
   FIT_LAP_FIELD_NUM_SUB_SPORT = 39,
   FIT_LAP_FIELD_NUM_GPS_ACCURACY = 44,
   FIT_LAP_FIELD_NUM_AVG_TEMPERATURE = 50,
   FIT_LAP_FIELD_NUM_MAX_TEMPERATURE = 51,
   FIT_LAP_FIELD_NUM_MIN_HEART_RATE = 63,
   FIT_LAP_FIELD_NUM_AVG_FRACTIONAL_CADENCE = 80,
   FIT_LAP_FIELD_NUM_MAX_FRACTIONAL_CADENCE = 81,
   FIT_LAP_FIELD_NUM_TOTAL_FRACTIONAL_CYCLES = 82
} FIT_LAP_FIELD_NUM;

typedef enum
{
   FIT_LAP_MESG_TIMESTAMP,
   FIT_LAP_MESG_START_TIME,
   FIT_LAP_MESG_START_POSITION_LAT,
   FIT_LAP_MESG_START_POSITION_LONG,
   FIT_LAP_MESG_END_POSITION_LAT,
   FIT_LAP_MESG_END_POSITION_LONG,
   FIT_LAP_MESG_TOTAL_ELAPSED_TIME,
   FIT_LAP_MESG_TOTAL_TIMER_TIME,
   FIT_LAP_MESG_TOTAL_DISTANCE,
   FIT_LAP_MESG_TOTAL_CYCLES,
   FIT_LAP_MESG_TOTAL_WORK,
   FIT_LAP_MESG_TOTAL_MOVING_TIME,
   FIT_LAP_MESG_TIME_IN_HR_ZONE,
   FIT_LAP_MESG_TIME_IN_SPEED_ZONE,
   FIT_LAP_MESG_TIME_IN_CADENCE_ZONE,
   FIT_LAP_MESG_TIME_IN_POWER_ZONE,
   FIT_LAP_MESG_MESSAGE_INDEX,
   FIT_LAP_MESG_TOTAL_CALORIES,
   FIT_LAP_MESG_TOTAL_FAT_CALORIES,
   FIT_LAP_MESG_AVG_SPEED,
   FIT_LAP_MESG_MAX_SPEED,
   FIT_LAP_MESG_AVG_POWER,
   FIT_LAP_MESG_MAX_POWER,
   FIT_LAP_MESG_TOTAL_ASCENT,
   FIT_LAP_MESG_TOTAL_DESCENT,
   FIT_LAP_MESG_NUM_LENGTHS,
   FIT_LAP_MESG_NORMALIZED_POWER,
   FIT_LAP_MESG_LEFT_RIGHT_BALANCE,
   FIT_LAP_MESG_FIRST_LENGTH_INDEX,
   FIT_LAP_MESG_AVG_STROKE_DISTANCE,
   FIT_LAP_MESG_NUM_ACTIVE_LENGTHS,
   FIT_LAP_MESG_AVG_ALTITUDE,
   FIT_LAP_MESG_MAX_ALTITUDE,
   FIT_LAP_MESG_AVG_GRADE,
   FIT_LAP_MESG_AVG_POS_GRADE,
   FIT_LAP_MESG_AVG_NEG_GRADE,
   FIT_LAP_MESG_MAX_POS_GRADE,
   FIT_LAP_MESG_MAX_NEG_GRADE,
   FIT_LAP_MESG_AVG_POS_VERTICAL_SPEED,
   FIT_LAP_MESG_AVG_NEG_VERTICAL_SPEED,
   FIT_LAP_MESG_MAX_POS_VERTICAL_SPEED,
   FIT_LAP_MESG_MAX_NEG_VERTICAL_SPEED,
   FIT_LAP_MESG_REPETITION_NUM,
   FIT_LAP_MESG_MIN_ALTITUDE,
   FIT_LAP_MESG_WKT_STEP_INDEX,
   FIT_LAP_MESG_OPPONENT_SCORE,
   FIT_LAP_MESG_STROKE_COUNT,
   FIT_LAP_MESG_ZONE_COUNT,
   FIT_LAP_MESG_AVG_VERTICAL_OSCILLATION,
   FIT_LAP_MESG_AVG_STANCE_TIME_PERCENT,
   FIT_LAP_MESG_AVG_STANCE_TIME,
   FIT_LAP_MESG_PLAYER_SCORE,
   FIT_LAP_MESG_AVG_TOTAL_HEMOGLOBIN_CONC,
   FIT_LAP_MESG_MIN_TOTAL_HEMOGLOBIN_CONC,
   FIT_LAP_MESG_MAX_TOTAL_HEMOGLOBIN_CONC,
   FIT_LAP_MESG_AVG_SATURATED_HEMOGLOBIN_PERCENT,
   FIT_LAP_MESG_MIN_SATURATED_HEMOGLOBIN_PERCENT,
   FIT_LAP_MESG_MAX_SATURATED_HEMOGLOBIN_PERCENT,
   FIT_LAP_MESG_EVENT,
   FIT_LAP_MESG_EVENT_TYPE,
   FIT_LAP_MESG_AVG_HEART_RATE,
   FIT_LAP_MESG_MAX_HEART_RATE,
   FIT_LAP_MESG_AVG_CADENCE,
   FIT_LAP_MESG_MAX_CADENCE,
   FIT_LAP_MESG_INTENSITY,
   FIT_LAP_MESG_LAP_TRIGGER,
   FIT_LAP_MESG_SPORT,
   FIT_LAP_MESG_EVENT_GROUP,
   FIT_LAP_MESG_SWIM_STROKE,
   FIT_LAP_MESG_SUB_SPORT,
   FIT_LAP_MESG_GPS_ACCURACY,
   FIT_LAP_MESG_AVG_TEMPERATURE,
   FIT_LAP_MESG_MAX_TEMPERATURE,
   FIT_LAP_MESG_MIN_HEART_RATE,
   FIT_LAP_MESG_AVG_FRACTIONAL_CADENCE,
   FIT_LAP_MESG_MAX_FRACTIONAL_CADENCE,
   FIT_LAP_MESG_TOTAL_FRACTIONAL_CYCLES,
   FIT_LAP_MESG_FIELDS
} FIT_LAP_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_LAP_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_LAP_MESG_DEF;

// length message

#define FIT_LENGTH_MESG_SIZE                                                    38
#define FIT_LENGTH_MESG_DEF_SIZE                                                59
#define FIT_LENGTH_MESG_STROKE_COUNT_COUNT                                      1
#define FIT_LENGTH_MESG_ZONE_COUNT_COUNT                                        1

typedef struct
{
   FIT_DATE_TIME timestamp; //
   FIT_DATE_TIME start_time; //
   FIT_UINT32 total_elapsed_time; // 1000 * s,
   FIT_UINT32 total_timer_time; // 1000 * s,
   FIT_MESSAGE_INDEX message_index; //
   FIT_UINT16 total_strokes; // strokes,
   FIT_UINT16 avg_speed; // 1000 * m/s,
   FIT_UINT16 total_calories; // kcal,
   FIT_UINT16 player_score; //
   FIT_UINT16 opponent_score; //
   FIT_UINT16 stroke_count[FIT_LENGTH_MESG_STROKE_COUNT_COUNT]; // counts,stroke_type enum used as the index
   FIT_UINT16 zone_count[FIT_LENGTH_MESG_ZONE_COUNT_COUNT]; // counts,zone number used as the index
   FIT_EVENT event; //
   FIT_EVENT_TYPE event_type; //
   FIT_SWIM_STROKE swim_stroke; // swim_stroke,
   FIT_UINT8 avg_swimming_cadence; // strokes/min,
   FIT_UINT8 event_group; //
   FIT_LENGTH_TYPE length_type; //
} FIT_LENGTH_MESG;

typedef enum
{
   FIT_LENGTH_FIELD_NUM_TIMESTAMP = 253,
   FIT_LENGTH_FIELD_NUM_START_TIME = 2,
   FIT_LENGTH_FIELD_NUM_TOTAL_ELAPSED_TIME = 3,
   FIT_LENGTH_FIELD_NUM_TOTAL_TIMER_TIME = 4,
   FIT_LENGTH_FIELD_NUM_MESSAGE_INDEX = 254,
   FIT_LENGTH_FIELD_NUM_TOTAL_STROKES = 5,
   FIT_LENGTH_FIELD_NUM_AVG_SPEED = 6,
   FIT_LENGTH_FIELD_NUM_TOTAL_CALORIES = 11,
   FIT_LENGTH_FIELD_NUM_PLAYER_SCORE = 18,
   FIT_LENGTH_FIELD_NUM_OPPONENT_SCORE = 19,
   FIT_LENGTH_FIELD_NUM_STROKE_COUNT = 20,
   FIT_LENGTH_FIELD_NUM_ZONE_COUNT = 21,
   FIT_LENGTH_FIELD_NUM_EVENT = 0,
   FIT_LENGTH_FIELD_NUM_EVENT_TYPE = 1,
   FIT_LENGTH_FIELD_NUM_SWIM_STROKE = 7,
   FIT_LENGTH_FIELD_NUM_AVG_SWIMMING_CADENCE = 9,
   FIT_LENGTH_FIELD_NUM_EVENT_GROUP = 10,
   FIT_LENGTH_FIELD_NUM_LENGTH_TYPE = 12
} FIT_LENGTH_FIELD_NUM;

typedef enum
{
   FIT_LENGTH_MESG_TIMESTAMP,
   FIT_LENGTH_MESG_START_TIME,
   FIT_LENGTH_MESG_TOTAL_ELAPSED_TIME,
   FIT_LENGTH_MESG_TOTAL_TIMER_TIME,
   FIT_LENGTH_MESG_MESSAGE_INDEX,
   FIT_LENGTH_MESG_TOTAL_STROKES,
   FIT_LENGTH_MESG_AVG_SPEED,
   FIT_LENGTH_MESG_TOTAL_CALORIES,
   FIT_LENGTH_MESG_PLAYER_SCORE,
   FIT_LENGTH_MESG_OPPONENT_SCORE,
   FIT_LENGTH_MESG_STROKE_COUNT,
   FIT_LENGTH_MESG_ZONE_COUNT,
   FIT_LENGTH_MESG_EVENT,
   FIT_LENGTH_MESG_EVENT_TYPE,
   FIT_LENGTH_MESG_SWIM_STROKE,
   FIT_LENGTH_MESG_AVG_SWIMMING_CADENCE,
   FIT_LENGTH_MESG_EVENT_GROUP,
   FIT_LENGTH_MESG_LENGTH_TYPE,
   FIT_LENGTH_MESG_FIELDS
} FIT_LENGTH_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_LENGTH_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_LENGTH_MESG_DEF;

// record message

#define FIT_RECORD_MESG_SIZE                                                    90
#define FIT_RECORD_MESG_DEF_SIZE                                                140
#define FIT_RECORD_MESG_COMPRESSED_SPEED_DISTANCE_COUNT                         3
#define FIT_RECORD_MESG_SPEED_1S_COUNT                                          5

typedef struct
{
   FIT_DATE_TIME timestamp; // s,
   FIT_SINT32 position_lat; // semicircles,
   FIT_SINT32 position_long; // semicircles,
   FIT_UINT32 distance; // 100 * m,
   FIT_SINT32 time_from_course; // 1000 * s,
   FIT_UINT32 total_cycles; // cycles,
   FIT_UINT32 accumulated_power; // watts,
   FIT_UINT16 altitude; // 5 * m + 500,
   FIT_UINT16 speed; // 1000 * m/s,
   FIT_UINT16 power; // watts,
   FIT_SINT16 grade; // 100 * %,
   FIT_UINT16 compressed_accumulated_power; //
   FIT_SINT16 vertical_speed; // 1000 * m/s,
   FIT_UINT16 calories; // kcal,
   FIT_UINT16 vertical_oscillation; // 10 * mm,
   FIT_UINT16 stance_time_percent; // 100 * percent,
   FIT_UINT16 stance_time; // 10 * ms,
   FIT_UINT16 ball_speed; // 100 * m/s,
   FIT_UINT16 cadence256; // 256 * rpm,Log cadence and fractional cadence for backwards compatability
   FIT_UINT16 total_hemoglobin_conc; // 100 * g/dL,Total saturated and unsaturated hemoglobin
   FIT_UINT16 total_hemoglobin_conc_min; // 100 * g/dL,Min saturated and unsaturated hemoglobin
   FIT_UINT16 total_hemoglobin_conc_max; // 100 * g/dL,Max saturated and unsaturated hemoglobin
   FIT_UINT16 saturated_hemoglobin_percent; // 10 * %,Percentage of hemoglobin saturated with oxygen
   FIT_UINT16 saturated_hemoglobin_percent_min; // 10 * %,Min percentage of hemoglobin saturated with oxygen
   FIT_UINT16 saturated_hemoglobin_percent_max; // 10 * %,Max percentage of hemoglobin saturated with oxygen
   FIT_UINT8 heart_rate; // bpm,
   FIT_UINT8 cadence; // rpm,
   FIT_BYTE compressed_speed_distance[FIT_RECORD_MESG_COMPRESSED_SPEED_DISTANCE_COUNT]; //
   FIT_UINT8 resistance; // Relative. 0 is none  254 is Max.
   FIT_UINT8 cycle_length; // 100 * m,
   FIT_SINT8 temperature; // C,
   FIT_UINT8 speed_1s[FIT_RECORD_MESG_SPEED_1S_COUNT]; // 16 * m/s,Speed at 1s intervals.  Timestamp field indicates time of last array element.
   FIT_UINT8 cycles; //
   FIT_LEFT_RIGHT_BALANCE left_right_balance; //
   FIT_UINT8 gps_accuracy; // m,
   FIT_ACTIVITY_TYPE activity_type; //
   FIT_UINT8 left_torque_effectiveness; // 2 * percent,
   FIT_UINT8 right_torque_effectiveness; // 2 * percent,
   FIT_UINT8 left_pedal_smoothness; // 2 * percent,
   FIT_UINT8 right_pedal_smoothness; // 2 * percent,
   FIT_UINT8 combined_pedal_smoothness; // 2 * percent,
   FIT_UINT8 time128; // 128 * s,
   FIT_STROKE_TYPE stroke_type; //
   FIT_UINT8 zone; //
   FIT_DEVICE_INDEX device_index; //
} FIT_RECORD_MESG;

typedef enum
{
   FIT_RECORD_FIELD_NUM_TIMESTAMP = 253,
   FIT_RECORD_FIELD_NUM_POSITION_LAT = 0,
   FIT_RECORD_FIELD_NUM_POSITION_LONG = 1,
   FIT_RECORD_FIELD_NUM_DISTANCE = 5,
   FIT_RECORD_FIELD_NUM_TIME_FROM_COURSE = 11,
   FIT_RECORD_FIELD_NUM_TOTAL_CYCLES = 19,
   FIT_RECORD_FIELD_NUM_ACCUMULATED_POWER = 29,
   FIT_RECORD_FIELD_NUM_ALTITUDE = 2,
   FIT_RECORD_FIELD_NUM_SPEED = 6,
   FIT_RECORD_FIELD_NUM_POWER = 7,
   FIT_RECORD_FIELD_NUM_GRADE = 9,
   FIT_RECORD_FIELD_NUM_COMPRESSED_ACCUMULATED_POWER = 28,
   FIT_RECORD_FIELD_NUM_VERTICAL_SPEED = 32,
   FIT_RECORD_FIELD_NUM_CALORIES = 33,
   FIT_RECORD_FIELD_NUM_VERTICAL_OSCILLATION = 39,
   FIT_RECORD_FIELD_NUM_STANCE_TIME_PERCENT = 40,
   FIT_RECORD_FIELD_NUM_STANCE_TIME = 41,
   FIT_RECORD_FIELD_NUM_BALL_SPEED = 51,
   FIT_RECORD_FIELD_NUM_CADENCE256 = 52,
   FIT_RECORD_FIELD_NUM_TOTAL_HEMOGLOBIN_CONC = 54,
   FIT_RECORD_FIELD_NUM_TOTAL_HEMOGLOBIN_CONC_MIN = 55,
   FIT_RECORD_FIELD_NUM_TOTAL_HEMOGLOBIN_CONC_MAX = 56,
   FIT_RECORD_FIELD_NUM_SATURATED_HEMOGLOBIN_PERCENT = 57,
   FIT_RECORD_FIELD_NUM_SATURATED_HEMOGLOBIN_PERCENT_MIN = 58,
   FIT_RECORD_FIELD_NUM_SATURATED_HEMOGLOBIN_PERCENT_MAX = 59,
   FIT_RECORD_FIELD_NUM_HEART_RATE = 3,
   FIT_RECORD_FIELD_NUM_CADENCE = 4,
   FIT_RECORD_FIELD_NUM_COMPRESSED_SPEED_DISTANCE = 8,
   FIT_RECORD_FIELD_NUM_RESISTANCE = 10,
   FIT_RECORD_FIELD_NUM_CYCLE_LENGTH = 12,
   FIT_RECORD_FIELD_NUM_TEMPERATURE = 13,
   FIT_RECORD_FIELD_NUM_SPEED_1S = 17,
   FIT_RECORD_FIELD_NUM_CYCLES = 18,
   FIT_RECORD_FIELD_NUM_LEFT_RIGHT_BALANCE = 30,
   FIT_RECORD_FIELD_NUM_GPS_ACCURACY = 31,
   FIT_RECORD_FIELD_NUM_ACTIVITY_TYPE = 42,
   FIT_RECORD_FIELD_NUM_LEFT_TORQUE_EFFECTIVENESS = 43,
   FIT_RECORD_FIELD_NUM_RIGHT_TORQUE_EFFECTIVENESS = 44,
   FIT_RECORD_FIELD_NUM_LEFT_PEDAL_SMOOTHNESS = 45,
   FIT_RECORD_FIELD_NUM_RIGHT_PEDAL_SMOOTHNESS = 46,
   FIT_RECORD_FIELD_NUM_COMBINED_PEDAL_SMOOTHNESS = 47,
   FIT_RECORD_FIELD_NUM_TIME128 = 48,
   FIT_RECORD_FIELD_NUM_STROKE_TYPE = 49,
   FIT_RECORD_FIELD_NUM_ZONE = 50,
   FIT_RECORD_FIELD_NUM_DEVICE_INDEX = 62
} FIT_RECORD_FIELD_NUM;

typedef enum
{
   FIT_RECORD_MESG_TIMESTAMP,
   FIT_RECORD_MESG_POSITION_LAT,
   FIT_RECORD_MESG_POSITION_LONG,
   FIT_RECORD_MESG_DISTANCE,
   FIT_RECORD_MESG_TIME_FROM_COURSE,
   FIT_RECORD_MESG_TOTAL_CYCLES,
   FIT_RECORD_MESG_ACCUMULATED_POWER,
   FIT_RECORD_MESG_ALTITUDE,
   FIT_RECORD_MESG_SPEED,
   FIT_RECORD_MESG_POWER,
   FIT_RECORD_MESG_GRADE,
   FIT_RECORD_MESG_COMPRESSED_ACCUMULATED_POWER,
   FIT_RECORD_MESG_VERTICAL_SPEED,
   FIT_RECORD_MESG_CALORIES,
   FIT_RECORD_MESG_VERTICAL_OSCILLATION,
   FIT_RECORD_MESG_STANCE_TIME_PERCENT,
   FIT_RECORD_MESG_STANCE_TIME,
   FIT_RECORD_MESG_BALL_SPEED,
   FIT_RECORD_MESG_CADENCE256,
   FIT_RECORD_MESG_TOTAL_HEMOGLOBIN_CONC,
   FIT_RECORD_MESG_TOTAL_HEMOGLOBIN_CONC_MIN,
   FIT_RECORD_MESG_TOTAL_HEMOGLOBIN_CONC_MAX,
   FIT_RECORD_MESG_SATURATED_HEMOGLOBIN_PERCENT,
   FIT_RECORD_MESG_SATURATED_HEMOGLOBIN_PERCENT_MIN,
   FIT_RECORD_MESG_SATURATED_HEMOGLOBIN_PERCENT_MAX,
   FIT_RECORD_MESG_HEART_RATE,
   FIT_RECORD_MESG_CADENCE,
   FIT_RECORD_MESG_COMPRESSED_SPEED_DISTANCE,
   FIT_RECORD_MESG_RESISTANCE,
   FIT_RECORD_MESG_CYCLE_LENGTH,
   FIT_RECORD_MESG_TEMPERATURE,
   FIT_RECORD_MESG_SPEED_1S,
   FIT_RECORD_MESG_CYCLES,
   FIT_RECORD_MESG_LEFT_RIGHT_BALANCE,
   FIT_RECORD_MESG_GPS_ACCURACY,
   FIT_RECORD_MESG_ACTIVITY_TYPE,
   FIT_RECORD_MESG_LEFT_TORQUE_EFFECTIVENESS,
   FIT_RECORD_MESG_RIGHT_TORQUE_EFFECTIVENESS,
   FIT_RECORD_MESG_LEFT_PEDAL_SMOOTHNESS,
   FIT_RECORD_MESG_RIGHT_PEDAL_SMOOTHNESS,
   FIT_RECORD_MESG_COMBINED_PEDAL_SMOOTHNESS,
   FIT_RECORD_MESG_TIME128,
   FIT_RECORD_MESG_STROKE_TYPE,
   FIT_RECORD_MESG_ZONE,
   FIT_RECORD_MESG_DEVICE_INDEX,
   FIT_RECORD_MESG_FIELDS
} FIT_RECORD_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_RECORD_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_RECORD_MESG_DEF;

// event message

#define FIT_EVENT_MESG_SIZE                                                     17
#define FIT_EVENT_MESG_DEF_SIZE                                                 29

typedef struct
{
   FIT_DATE_TIME timestamp; // s,
   FIT_UINT32 data; //
   FIT_UINT16 data16; //
   FIT_UINT16 score; // Do not use.  Placeholder for sport_point subfield components
   FIT_UINT16 opponent_score; // Do not use.  Placeholder for sport_point subfield components
   FIT_EVENT event; //
   FIT_EVENT_TYPE event_type; //
   FIT_UINT8 event_group; //
} FIT_EVENT_MESG;

typedef enum
{
   FIT_EVENT_FIELD_NUM_TIMESTAMP = 253,
   FIT_EVENT_FIELD_NUM_DATA = 3,
   FIT_EVENT_FIELD_NUM_DATA16 = 2,
   FIT_EVENT_FIELD_NUM_SCORE = 7,
   FIT_EVENT_FIELD_NUM_OPPONENT_SCORE = 8,
   FIT_EVENT_FIELD_NUM_EVENT = 0,
   FIT_EVENT_FIELD_NUM_EVENT_TYPE = 1,
   FIT_EVENT_FIELD_NUM_EVENT_GROUP = 4
} FIT_EVENT_FIELD_NUM;

typedef enum
{
   FIT_EVENT_MESG_TIMESTAMP,
   FIT_EVENT_MESG_DATA,
   FIT_EVENT_MESG_DATA16,
   FIT_EVENT_MESG_SCORE,
   FIT_EVENT_MESG_OPPONENT_SCORE,
   FIT_EVENT_MESG_EVENT,
   FIT_EVENT_MESG_EVENT_TYPE,
   FIT_EVENT_MESG_EVENT_GROUP,
   FIT_EVENT_MESG_FIELDS
} FIT_EVENT_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_EVENT_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_EVENT_MESG_DEF;

// device_info message

#define FIT_DEVICE_INFO_MESG_SIZE                                               30
#define FIT_DEVICE_INFO_MESG_DEF_SIZE                                           53
#define FIT_DEVICE_INFO_MESG_DESCRIPTOR_COUNT                                   1

typedef struct
{
   FIT_DATE_TIME timestamp; // s,
   FIT_UINT32Z serial_number; //
   FIT_UINT32 cum_operating_time; // s,Reset by new battery or charge.
   FIT_MANUFACTURER manufacturer; //
   FIT_UINT16 product; //
   FIT_UINT16 software_version; //
   FIT_UINT16 battery_voltage; // 256 * V,
   FIT_UINT16Z ant_device_number; //
   FIT_DEVICE_INDEX device_index; //
   FIT_UINT8 ant_device_type; //
   FIT_UINT8 hardware_version; //
   FIT_BATTERY_STATUS battery_status; //
   FIT_BODY_LOCATION sensor_position; // Indicates the location of the sensor
   FIT_STRING descriptor[FIT_DEVICE_INFO_MESG_DESCRIPTOR_COUNT]; // Used to describe the sensor or location
   FIT_UINT8Z ant_transmission_type; //
   FIT_ANT_NETWORK ant_network; //
} FIT_DEVICE_INFO_MESG;

typedef enum
{
   FIT_DEVICE_INFO_FIELD_NUM_TIMESTAMP = 253,
   FIT_DEVICE_INFO_FIELD_NUM_SERIAL_NUMBER = 3,
   FIT_DEVICE_INFO_FIELD_NUM_CUM_OPERATING_TIME = 7,
   FIT_DEVICE_INFO_FIELD_NUM_MANUFACTURER = 2,
   FIT_DEVICE_INFO_FIELD_NUM_PRODUCT = 4,
   FIT_DEVICE_INFO_FIELD_NUM_SOFTWARE_VERSION = 5,
   FIT_DEVICE_INFO_FIELD_NUM_BATTERY_VOLTAGE = 10,
   FIT_DEVICE_INFO_FIELD_NUM_ANT_DEVICE_NUMBER = 21,
   FIT_DEVICE_INFO_FIELD_NUM_DEVICE_INDEX = 0,
   FIT_DEVICE_INFO_FIELD_NUM_ANT_DEVICE_TYPE = 1,
   FIT_DEVICE_INFO_FIELD_NUM_HARDWARE_VERSION = 6,
   FIT_DEVICE_INFO_FIELD_NUM_BATTERY_STATUS = 11,
   FIT_DEVICE_INFO_FIELD_NUM_SENSOR_POSITION = 18,
   FIT_DEVICE_INFO_FIELD_NUM_DESCRIPTOR = 19,
   FIT_DEVICE_INFO_FIELD_NUM_ANT_TRANSMISSION_TYPE = 20,
   FIT_DEVICE_INFO_FIELD_NUM_ANT_NETWORK = 22
} FIT_DEVICE_INFO_FIELD_NUM;

typedef enum
{
   FIT_DEVICE_INFO_MESG_TIMESTAMP,
   FIT_DEVICE_INFO_MESG_SERIAL_NUMBER,
   FIT_DEVICE_INFO_MESG_CUM_OPERATING_TIME,
   FIT_DEVICE_INFO_MESG_MANUFACTURER,
   FIT_DEVICE_INFO_MESG_PRODUCT,
   FIT_DEVICE_INFO_MESG_SOFTWARE_VERSION,
   FIT_DEVICE_INFO_MESG_BATTERY_VOLTAGE,
   FIT_DEVICE_INFO_MESG_ANT_DEVICE_NUMBER,
   FIT_DEVICE_INFO_MESG_DEVICE_INDEX,
   FIT_DEVICE_INFO_MESG_ANT_DEVICE_TYPE,
   FIT_DEVICE_INFO_MESG_HARDWARE_VERSION,
   FIT_DEVICE_INFO_MESG_BATTERY_STATUS,
   FIT_DEVICE_INFO_MESG_SENSOR_POSITION,
   FIT_DEVICE_INFO_MESG_DESCRIPTOR,
   FIT_DEVICE_INFO_MESG_ANT_TRANSMISSION_TYPE,
   FIT_DEVICE_INFO_MESG_ANT_NETWORK,
   FIT_DEVICE_INFO_MESG_FIELDS
} FIT_DEVICE_INFO_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_DEVICE_INFO_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_DEVICE_INFO_MESG_DEF;

// hrv message

#define FIT_HRV_MESG_SIZE                                                       2
#define FIT_HRV_MESG_DEF_SIZE                                                   8
#define FIT_HRV_MESG_TIME_COUNT                                                 1

typedef struct
{
   FIT_UINT16 time[FIT_HRV_MESG_TIME_COUNT]; // 1000 * s,Time between beats
} FIT_HRV_MESG;

typedef enum
{
   FIT_HRV_FIELD_NUM_TIME = 0
} FIT_HRV_FIELD_NUM;

typedef enum
{
   FIT_HRV_MESG_TIME,
   FIT_HRV_MESG_FIELDS
} FIT_HRV_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_HRV_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_HRV_MESG_DEF;

// course message

#define FIT_COURSE_MESG_SIZE                                                    21
#define FIT_COURSE_MESG_DEF_SIZE                                                14
#define FIT_COURSE_MESG_NAME_COUNT                                              16

typedef struct
{
   FIT_STRING name[FIT_COURSE_MESG_NAME_COUNT]; //
   FIT_COURSE_CAPABILITIES capabilities; //
   FIT_SPORT sport; //
} FIT_COURSE_MESG;

typedef enum
{
   FIT_COURSE_FIELD_NUM_NAME = 5,
   FIT_COURSE_FIELD_NUM_CAPABILITIES = 6,
   FIT_COURSE_FIELD_NUM_SPORT = 4
} FIT_COURSE_FIELD_NUM;

typedef enum
{
   FIT_COURSE_MESG_NAME,
   FIT_COURSE_MESG_CAPABILITIES,
   FIT_COURSE_MESG_SPORT,
   FIT_COURSE_MESG_FIELDS
} FIT_COURSE_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_COURSE_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_COURSE_MESG_DEF;

// course_point message

#define FIT_COURSE_POINT_MESG_SIZE                                              35
#define FIT_COURSE_POINT_MESG_DEF_SIZE                                          26
#define FIT_COURSE_POINT_MESG_NAME_COUNT                                        16

typedef struct
{
   FIT_DATE_TIME timestamp; //
   FIT_SINT32 position_lat; // semicircles,
   FIT_SINT32 position_long; // semicircles,
   FIT_UINT32 distance; // 100 * m,
   FIT_STRING name[FIT_COURSE_POINT_MESG_NAME_COUNT]; //
   FIT_MESSAGE_INDEX message_index; //
   FIT_COURSE_POINT type; //
} FIT_COURSE_POINT_MESG;

typedef enum
{
   FIT_COURSE_POINT_FIELD_NUM_TIMESTAMP = 1,
   FIT_COURSE_POINT_FIELD_NUM_POSITION_LAT = 2,
   FIT_COURSE_POINT_FIELD_NUM_POSITION_LONG = 3,
   FIT_COURSE_POINT_FIELD_NUM_DISTANCE = 4,
   FIT_COURSE_POINT_FIELD_NUM_NAME = 6,
   FIT_COURSE_POINT_FIELD_NUM_MESSAGE_INDEX = 254,
   FIT_COURSE_POINT_FIELD_NUM_TYPE = 5
} FIT_COURSE_POINT_FIELD_NUM;

typedef enum
{
   FIT_COURSE_POINT_MESG_TIMESTAMP,
   FIT_COURSE_POINT_MESG_POSITION_LAT,
   FIT_COURSE_POINT_MESG_POSITION_LONG,
   FIT_COURSE_POINT_MESG_DISTANCE,
   FIT_COURSE_POINT_MESG_NAME,
   FIT_COURSE_POINT_MESG_MESSAGE_INDEX,
   FIT_COURSE_POINT_MESG_TYPE,
   FIT_COURSE_POINT_MESG_FIELDS
} FIT_COURSE_POINT_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_COURSE_POINT_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_COURSE_POINT_MESG_DEF;

// workout message

#define FIT_WORKOUT_MESG_SIZE                                                   23
#define FIT_WORKOUT_MESG_DEF_SIZE                                               17
#define FIT_WORKOUT_MESG_WKT_NAME_COUNT                                         16

typedef struct
{
   FIT_WORKOUT_CAPABILITIES capabilities; //
   FIT_STRING wkt_name[FIT_WORKOUT_MESG_WKT_NAME_COUNT]; //
   FIT_UINT16 num_valid_steps; // number of valid steps
   FIT_SPORT sport; //
} FIT_WORKOUT_MESG;

typedef enum
{
   FIT_WORKOUT_FIELD_NUM_CAPABILITIES = 5,
   FIT_WORKOUT_FIELD_NUM_WKT_NAME = 8,
   FIT_WORKOUT_FIELD_NUM_NUM_VALID_STEPS = 6,
   FIT_WORKOUT_FIELD_NUM_SPORT = 4
} FIT_WORKOUT_FIELD_NUM;

typedef enum
{
   FIT_WORKOUT_MESG_CAPABILITIES,
   FIT_WORKOUT_MESG_WKT_NAME,
   FIT_WORKOUT_MESG_NUM_VALID_STEPS,
   FIT_WORKOUT_MESG_SPORT,
   FIT_WORKOUT_MESG_FIELDS
} FIT_WORKOUT_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_WORKOUT_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_WORKOUT_MESG_DEF;

// workout_step message

#define FIT_WORKOUT_STEP_MESG_SIZE                                              37
#define FIT_WORKOUT_STEP_MESG_DEF_SIZE                                          32
#define FIT_WORKOUT_STEP_MESG_WKT_STEP_NAME_COUNT                               16

typedef struct
{
   FIT_STRING wkt_step_name[FIT_WORKOUT_STEP_MESG_WKT_STEP_NAME_COUNT]; //
   FIT_UINT32 duration_value; //
   FIT_UINT32 target_value; //
   FIT_UINT32 custom_target_value_low; //
   FIT_UINT32 custom_target_value_high; //
   FIT_MESSAGE_INDEX message_index; //
   FIT_WKT_STEP_DURATION duration_type; //
   FIT_WKT_STEP_TARGET target_type; //
   FIT_INTENSITY intensity; //
} FIT_WORKOUT_STEP_MESG;

typedef enum
{
   FIT_WORKOUT_STEP_FIELD_NUM_WKT_STEP_NAME = 0,
   FIT_WORKOUT_STEP_FIELD_NUM_DURATION_VALUE = 2,
   FIT_WORKOUT_STEP_FIELD_NUM_TARGET_VALUE = 4,
   FIT_WORKOUT_STEP_FIELD_NUM_CUSTOM_TARGET_VALUE_LOW = 5,
   FIT_WORKOUT_STEP_FIELD_NUM_CUSTOM_TARGET_VALUE_HIGH = 6,
   FIT_WORKOUT_STEP_FIELD_NUM_MESSAGE_INDEX = 254,
   FIT_WORKOUT_STEP_FIELD_NUM_DURATION_TYPE = 1,
   FIT_WORKOUT_STEP_FIELD_NUM_TARGET_TYPE = 3,
   FIT_WORKOUT_STEP_FIELD_NUM_INTENSITY = 7
} FIT_WORKOUT_STEP_FIELD_NUM;

typedef enum
{
   FIT_WORKOUT_STEP_MESG_WKT_STEP_NAME,
   FIT_WORKOUT_STEP_MESG_DURATION_VALUE,
   FIT_WORKOUT_STEP_MESG_TARGET_VALUE,
   FIT_WORKOUT_STEP_MESG_CUSTOM_TARGET_VALUE_LOW,
   FIT_WORKOUT_STEP_MESG_CUSTOM_TARGET_VALUE_HIGH,
   FIT_WORKOUT_STEP_MESG_MESSAGE_INDEX,
   FIT_WORKOUT_STEP_MESG_DURATION_TYPE,
   FIT_WORKOUT_STEP_MESG_TARGET_TYPE,
   FIT_WORKOUT_STEP_MESG_INTENSITY,
   FIT_WORKOUT_STEP_MESG_FIELDS
} FIT_WORKOUT_STEP_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_WORKOUT_STEP_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_WORKOUT_STEP_MESG_DEF;

// schedule message

#define FIT_SCHEDULE_MESG_SIZE                                                  18
#define FIT_SCHEDULE_MESG_DEF_SIZE                                              26

typedef struct
{
   FIT_UINT32Z serial_number; // Corresponds to file_id of scheduled workout / course.
   FIT_DATE_TIME time_created; // Corresponds to file_id of scheduled workout / course.
   FIT_LOCAL_DATE_TIME scheduled_time; //
   FIT_MANUFACTURER manufacturer; // Corresponds to file_id of scheduled workout / course.
   FIT_UINT16 product; // Corresponds to file_id of scheduled workout / course.
   FIT_BOOL completed; // TRUE if this activity has been started
   FIT_SCHEDULE type; //
} FIT_SCHEDULE_MESG;

typedef enum
{
   FIT_SCHEDULE_FIELD_NUM_SERIAL_NUMBER = 2,
   FIT_SCHEDULE_FIELD_NUM_TIME_CREATED = 3,
   FIT_SCHEDULE_FIELD_NUM_SCHEDULED_TIME = 6,
   FIT_SCHEDULE_FIELD_NUM_MANUFACTURER = 0,
   FIT_SCHEDULE_FIELD_NUM_PRODUCT = 1,
   FIT_SCHEDULE_FIELD_NUM_COMPLETED = 4,
   FIT_SCHEDULE_FIELD_NUM_TYPE = 5
} FIT_SCHEDULE_FIELD_NUM;

typedef enum
{
   FIT_SCHEDULE_MESG_SERIAL_NUMBER,
   FIT_SCHEDULE_MESG_TIME_CREATED,
   FIT_SCHEDULE_MESG_SCHEDULED_TIME,
   FIT_SCHEDULE_MESG_MANUFACTURER,
   FIT_SCHEDULE_MESG_PRODUCT,
   FIT_SCHEDULE_MESG_COMPLETED,
   FIT_SCHEDULE_MESG_TYPE,
   FIT_SCHEDULE_MESG_FIELDS
} FIT_SCHEDULE_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_SCHEDULE_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_SCHEDULE_MESG_DEF;

// totals message

#define FIT_TOTALS_MESG_SIZE                                                    29
#define FIT_TOTALS_MESG_DEF_SIZE                                                32

typedef struct
{
   FIT_DATE_TIME timestamp; // s,
   FIT_UINT32 timer_time; // s,Excludes pauses
   FIT_UINT32 distance; // m,
   FIT_UINT32 calories; // kcal,
   FIT_UINT32 elapsed_time; // s,Includes pauses
   FIT_UINT32 active_time; // s,
   FIT_MESSAGE_INDEX message_index; //
   FIT_UINT16 sessions; //
   FIT_SPORT sport; //
} FIT_TOTALS_MESG;

typedef enum
{
   FIT_TOTALS_FIELD_NUM_TIMESTAMP = 253,
   FIT_TOTALS_FIELD_NUM_TIMER_TIME = 0,
   FIT_TOTALS_FIELD_NUM_DISTANCE = 1,
   FIT_TOTALS_FIELD_NUM_CALORIES = 2,
   FIT_TOTALS_FIELD_NUM_ELAPSED_TIME = 4,
   FIT_TOTALS_FIELD_NUM_ACTIVE_TIME = 6,
   FIT_TOTALS_FIELD_NUM_MESSAGE_INDEX = 254,
   FIT_TOTALS_FIELD_NUM_SESSIONS = 5,
   FIT_TOTALS_FIELD_NUM_SPORT = 3
} FIT_TOTALS_FIELD_NUM;

typedef enum
{
   FIT_TOTALS_MESG_TIMESTAMP,
   FIT_TOTALS_MESG_TIMER_TIME,
   FIT_TOTALS_MESG_DISTANCE,
   FIT_TOTALS_MESG_CALORIES,
   FIT_TOTALS_MESG_ELAPSED_TIME,
   FIT_TOTALS_MESG_ACTIVE_TIME,
   FIT_TOTALS_MESG_MESSAGE_INDEX,
   FIT_TOTALS_MESG_SESSIONS,
   FIT_TOTALS_MESG_SPORT,
   FIT_TOTALS_MESG_FIELDS
} FIT_TOTALS_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_TOTALS_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_TOTALS_MESG_DEF;

// weight_scale message

#define FIT_WEIGHT_SCALE_MESG_SIZE                                              25
#define FIT_WEIGHT_SCALE_MESG_DEF_SIZE                                          44

typedef struct
{
   FIT_DATE_TIME timestamp; // s,
   FIT_WEIGHT weight; // 100 * kg,
   FIT_UINT16 percent_fat; // 100 * %,
   FIT_UINT16 percent_hydration; // 100 * %,
   FIT_UINT16 visceral_fat_mass; // 100 * kg,
   FIT_UINT16 bone_mass; // 100 * kg,
   FIT_UINT16 muscle_mass; // 100 * kg,
   FIT_UINT16 basal_met; // 4 * kcal/day,
   FIT_UINT16 active_met; // 4 * kcal/day,~4kJ per kcal, 0.25 allows max 16384 kcal
   FIT_MESSAGE_INDEX user_profile_index; // Associates this weight scale message to a user.  This corresponds to the index of the user profile message in the weight scale file.
   FIT_UINT8 physique_rating; //
   FIT_UINT8 metabolic_age; // years,
   FIT_UINT8 visceral_fat_rating; //
} FIT_WEIGHT_SCALE_MESG;

typedef enum
{
   FIT_WEIGHT_SCALE_FIELD_NUM_TIMESTAMP = 253,
   FIT_WEIGHT_SCALE_FIELD_NUM_WEIGHT = 0,
   FIT_WEIGHT_SCALE_FIELD_NUM_PERCENT_FAT = 1,
   FIT_WEIGHT_SCALE_FIELD_NUM_PERCENT_HYDRATION = 2,
   FIT_WEIGHT_SCALE_FIELD_NUM_VISCERAL_FAT_MASS = 3,
   FIT_WEIGHT_SCALE_FIELD_NUM_BONE_MASS = 4,
   FIT_WEIGHT_SCALE_FIELD_NUM_MUSCLE_MASS = 5,
   FIT_WEIGHT_SCALE_FIELD_NUM_BASAL_MET = 7,
   FIT_WEIGHT_SCALE_FIELD_NUM_ACTIVE_MET = 9,
   FIT_WEIGHT_SCALE_FIELD_NUM_USER_PROFILE_INDEX = 12,
   FIT_WEIGHT_SCALE_FIELD_NUM_PHYSIQUE_RATING = 8,
   FIT_WEIGHT_SCALE_FIELD_NUM_METABOLIC_AGE = 10,
   FIT_WEIGHT_SCALE_FIELD_NUM_VISCERAL_FAT_RATING = 11
} FIT_WEIGHT_SCALE_FIELD_NUM;

typedef enum
{
   FIT_WEIGHT_SCALE_MESG_TIMESTAMP,
   FIT_WEIGHT_SCALE_MESG_WEIGHT,
   FIT_WEIGHT_SCALE_MESG_PERCENT_FAT,
   FIT_WEIGHT_SCALE_MESG_PERCENT_HYDRATION,
   FIT_WEIGHT_SCALE_MESG_VISCERAL_FAT_MASS,
   FIT_WEIGHT_SCALE_MESG_BONE_MASS,
   FIT_WEIGHT_SCALE_MESG_MUSCLE_MASS,
   FIT_WEIGHT_SCALE_MESG_BASAL_MET,
   FIT_WEIGHT_SCALE_MESG_ACTIVE_MET,
   FIT_WEIGHT_SCALE_MESG_USER_PROFILE_INDEX,
   FIT_WEIGHT_SCALE_MESG_PHYSIQUE_RATING,
   FIT_WEIGHT_SCALE_MESG_METABOLIC_AGE,
   FIT_WEIGHT_SCALE_MESG_VISCERAL_FAT_RATING,
   FIT_WEIGHT_SCALE_MESG_FIELDS
} FIT_WEIGHT_SCALE_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_WEIGHT_SCALE_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_WEIGHT_SCALE_MESG_DEF;

// blood_pressure message

#define FIT_BLOOD_PRESSURE_MESG_SIZE                                            21
#define FIT_BLOOD_PRESSURE_MESG_DEF_SIZE                                        38

typedef struct
{
   FIT_DATE_TIME timestamp; // s,
   FIT_UINT16 systolic_pressure; // mmHg,
   FIT_UINT16 diastolic_pressure; // mmHg,
   FIT_UINT16 mean_arterial_pressure; // mmHg,
   FIT_UINT16 map_3_sample_mean; // mmHg,
   FIT_UINT16 map_morning_values; // mmHg,
   FIT_UINT16 map_evening_values; // mmHg,
   FIT_MESSAGE_INDEX user_profile_index; // Associates this blood pressure message to a user.  This corresponds to the index of the user profile message in the blood pressure file.
   FIT_UINT8 heart_rate; // bpm,
   FIT_HR_TYPE heart_rate_type; //
   FIT_BP_STATUS status; //
} FIT_BLOOD_PRESSURE_MESG;

typedef enum
{
   FIT_BLOOD_PRESSURE_FIELD_NUM_TIMESTAMP = 253,
   FIT_BLOOD_PRESSURE_FIELD_NUM_SYSTOLIC_PRESSURE = 0,
   FIT_BLOOD_PRESSURE_FIELD_NUM_DIASTOLIC_PRESSURE = 1,
   FIT_BLOOD_PRESSURE_FIELD_NUM_MEAN_ARTERIAL_PRESSURE = 2,
   FIT_BLOOD_PRESSURE_FIELD_NUM_MAP_3_SAMPLE_MEAN = 3,
   FIT_BLOOD_PRESSURE_FIELD_NUM_MAP_MORNING_VALUES = 4,
   FIT_BLOOD_PRESSURE_FIELD_NUM_MAP_EVENING_VALUES = 5,
   FIT_BLOOD_PRESSURE_FIELD_NUM_USER_PROFILE_INDEX = 9,
   FIT_BLOOD_PRESSURE_FIELD_NUM_HEART_RATE = 6,
   FIT_BLOOD_PRESSURE_FIELD_NUM_HEART_RATE_TYPE = 7,
   FIT_BLOOD_PRESSURE_FIELD_NUM_STATUS = 8
} FIT_BLOOD_PRESSURE_FIELD_NUM;

typedef enum
{
   FIT_BLOOD_PRESSURE_MESG_TIMESTAMP,
   FIT_BLOOD_PRESSURE_MESG_SYSTOLIC_PRESSURE,
   FIT_BLOOD_PRESSURE_MESG_DIASTOLIC_PRESSURE,
   FIT_BLOOD_PRESSURE_MESG_MEAN_ARTERIAL_PRESSURE,
   FIT_BLOOD_PRESSURE_MESG_MAP_3_SAMPLE_MEAN,
   FIT_BLOOD_PRESSURE_MESG_MAP_MORNING_VALUES,
   FIT_BLOOD_PRESSURE_MESG_MAP_EVENING_VALUES,
   FIT_BLOOD_PRESSURE_MESG_USER_PROFILE_INDEX,
   FIT_BLOOD_PRESSURE_MESG_HEART_RATE,
   FIT_BLOOD_PRESSURE_MESG_HEART_RATE_TYPE,
   FIT_BLOOD_PRESSURE_MESG_STATUS,
   FIT_BLOOD_PRESSURE_MESG_FIELDS
} FIT_BLOOD_PRESSURE_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_BLOOD_PRESSURE_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_BLOOD_PRESSURE_MESG_DEF;

// monitoring_info message

#define FIT_MONITORING_INFO_MESG_SIZE                                           8
#define FIT_MONITORING_INFO_MESG_DEF_SIZE                                       11

typedef struct
{
   FIT_DATE_TIME timestamp; //
   FIT_LOCAL_DATE_TIME local_timestamp; // Use to convert activity timestamps to local time if device does not support time zone and daylight savings time correction.
} FIT_MONITORING_INFO_MESG;

typedef enum
{
   FIT_MONITORING_INFO_FIELD_NUM_TIMESTAMP = 253,
   FIT_MONITORING_INFO_FIELD_NUM_LOCAL_TIMESTAMP = 0
} FIT_MONITORING_INFO_FIELD_NUM;

typedef enum
{
   FIT_MONITORING_INFO_MESG_TIMESTAMP,
   FIT_MONITORING_INFO_MESG_LOCAL_TIMESTAMP,
   FIT_MONITORING_INFO_MESG_FIELDS
} FIT_MONITORING_INFO_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_MONITORING_INFO_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_MONITORING_INFO_MESG_DEF;

// monitoring message

#define FIT_MONITORING_MESG_SIZE                                                31
#define FIT_MONITORING_MESG_DEF_SIZE                                            41

typedef struct
{
   FIT_DATE_TIME timestamp; // s,Must align to logging interval, for example, time must be 00:00:00 for daily log.
   FIT_UINT32 distance; // 100 * m,
   FIT_UINT32 cycles; // 2 * cycles,
   FIT_UINT32 active_time; // 1000 * s,
   FIT_LOCAL_DATE_TIME local_timestamp; // Must align to logging interval, for example, time must be 00:00:00 for daily log.
   FIT_UINT16 calories; // kcal,total calories
   FIT_UINT16 distance_16; // 100 * m,
   FIT_UINT16 cycles_16; // 2 * cycles (steps),
   FIT_UINT16 active_time_16; // s,
   FIT_DEVICE_INDEX device_index; // Associates this data to device_info message.  Not required for file with single device (sensor).
   FIT_ACTIVITY_TYPE activity_type; //
   FIT_ACTIVITY_SUBTYPE activity_subtype; //
} FIT_MONITORING_MESG;

typedef enum
{
   FIT_MONITORING_FIELD_NUM_TIMESTAMP = 253,
   FIT_MONITORING_FIELD_NUM_DISTANCE = 2,
   FIT_MONITORING_FIELD_NUM_CYCLES = 3,
   FIT_MONITORING_FIELD_NUM_ACTIVE_TIME = 4,
   FIT_MONITORING_FIELD_NUM_LOCAL_TIMESTAMP = 11,
   FIT_MONITORING_FIELD_NUM_CALORIES = 1,
   FIT_MONITORING_FIELD_NUM_DISTANCE_16 = 8,
   FIT_MONITORING_FIELD_NUM_CYCLES_16 = 9,
   FIT_MONITORING_FIELD_NUM_ACTIVE_TIME_16 = 10,
   FIT_MONITORING_FIELD_NUM_DEVICE_INDEX = 0,
   FIT_MONITORING_FIELD_NUM_ACTIVITY_TYPE = 5,
   FIT_MONITORING_FIELD_NUM_ACTIVITY_SUBTYPE = 6
} FIT_MONITORING_FIELD_NUM;

typedef enum
{
   FIT_MONITORING_MESG_TIMESTAMP,
   FIT_MONITORING_MESG_DISTANCE,
   FIT_MONITORING_MESG_CYCLES,
   FIT_MONITORING_MESG_ACTIVE_TIME,
   FIT_MONITORING_MESG_LOCAL_TIMESTAMP,
   FIT_MONITORING_MESG_CALORIES,
   FIT_MONITORING_MESG_DISTANCE_16,
   FIT_MONITORING_MESG_CYCLES_16,
   FIT_MONITORING_MESG_ACTIVE_TIME_16,
   FIT_MONITORING_MESG_DEVICE_INDEX,
   FIT_MONITORING_MESG_ACTIVITY_TYPE,
   FIT_MONITORING_MESG_ACTIVITY_SUBTYPE,
   FIT_MONITORING_MESG_FIELDS
} FIT_MONITORING_MESG_FIELD;

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_MESG_NUM global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[FIT_MONITORING_MESG_FIELDS * FIT_FIELD_DEF_SIZE];
} FIT_MONITORING_MESG_DEF;

typedef enum {
   FIT_MESG_PAD,
   FIT_MESG_FILE_ID,
   FIT_MESG_FILE_CREATOR,
   FIT_MESG_SOFTWARE,
   FIT_MESG_SLAVE_DEVICE,
   FIT_MESG_CAPABILITIES,
   FIT_MESG_FILE_CAPABILITIES,
   FIT_MESG_MESG_CAPABILITIES,
   FIT_MESG_FIELD_CAPABILITIES,
   FIT_MESG_DEVICE_SETTINGS,
   FIT_MESG_USER_PROFILE,
   FIT_MESG_HRM_PROFILE,
   FIT_MESG_SDM_PROFILE,
   FIT_MESG_BIKE_PROFILE,
   FIT_MESG_ZONES_TARGET,
   FIT_MESG_SPORT,
   FIT_MESG_HR_ZONE,
   FIT_MESG_SPEED_ZONE,
   FIT_MESG_CADENCE_ZONE,
   FIT_MESG_POWER_ZONE,
   FIT_MESG_MET_ZONE,
   FIT_MESG_GOAL,
   FIT_MESG_ACTIVITY,
   FIT_MESG_SESSION,
   FIT_MESG_LAP,
   FIT_MESG_LENGTH,
   FIT_MESG_RECORD,
   FIT_MESG_EVENT,
   FIT_MESG_DEVICE_INFO,
   FIT_MESG_HRV,
   FIT_MESG_COURSE,
   FIT_MESG_COURSE_POINT,
   FIT_MESG_WORKOUT,
   FIT_MESG_WORKOUT_STEP,
   FIT_MESG_SCHEDULE,
   FIT_MESG_TOTALS,
   FIT_MESG_WEIGHT_SCALE,
   FIT_MESG_BLOOD_PRESSURE,
   FIT_MESG_MONITORING_INFO,
   FIT_MESG_MONITORING,
   FIT_MESGS
} FIT_MESG;

typedef const FIT_MESG_DEF * FIT_CONST_MESG_DEF_PTR;
const extern FIT_CONST_MESG_DEF_PTR fit_mesg_defs[FIT_MESGS];

#if defined(__cplusplus)
   }
#endif

#endif // !defined(FIT_EXAMPLE_H)

