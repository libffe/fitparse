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


#if !defined(FIT_CRC_H)
#define FIT_CRC_H

#include "fit.h"


//////////////////////////////////////////////////////////////////////////////////
// Public Function Prototypes
//////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
   extern "C" {
#endif

FIT_UINT16 FitCRC_Get16(FIT_UINT16 crc, FIT_UINT8 byte);
FIT_UINT16 FitCRC_Update16(FIT_UINT16 crc, const volatile void *data, FIT_UINT8 size);
FIT_UINT16 FitCRC_Calc16(const volatile void *data, FIT_UINT8 size);

#if defined(__cplusplus)
   }
#endif

#endif // !defined(FIT_CRC_H)
