#ifndef _PVR2PNG_UTILS_H_INCLUDED
#define _PVR2PNG_UTILS_H_INCLUDED 1
#pragma once

#include "types.h"

// returned string SHOULD'NT BE FREE-D
const char* pvrPixelFormatToReadable(PVR_PIXEL_FORMAT t);

// returned string SHOULD'NT BE FREE-D
const char* pvrImgDataTypeToReadable(PVR_IMAGE_DATA_TYPE t);

#endif // _PVR2PNG_UTILS_H_INCLUDED

