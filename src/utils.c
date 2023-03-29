#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

const char* pvrPixelFormatReadable[7] = {
	"ARGB1555 (bilevel translucent alpha 0, 255)",
	"RGB565 (no translucent)",
	"ARGB4444 (translucent alpha 0-255)",
	"YUV442",
	"BUMP",
	"4-BIT",
	"8-BIT"
};

const char* pvrPixelFormatToReadable(PVR_PIXEL_FORMAT t) {
	switch (t) {
	case PF_ARGB1555: return pvrPixelFormatReadable[0]; break;
	case PF_RGB565:   return pvrPixelFormatReadable[1]; break;
	case PF_ARGB4444: return pvrPixelFormatReadable[2]; break;
	case PF_YUV442:   return pvrPixelFormatReadable[3]; break;
	case PF_BUMP:     return pvrPixelFormatReadable[4]; break;
	case PF_4_BIT:    return pvrPixelFormatReadable[5]; break;
	case PF_8_BIT:    return pvrPixelFormatReadable[6]; break;
	default: return NULL; break;
	}
}

const char* pvrImgDataTypeReadable[13] = {
	"SQUARE TWIDDLED",
	"SQUARE TWIDDLED & MIPMAP",
	"VQ",
	"VQ & MIPMAP",
	"8-BIT CLUT TWIDDLED",
	"4-BIT CLUT TWIDDLED",
	"8-BIT DIRECT TWIDDLED",
	"4-BIT DIRECT TWIDDLED",
	"RECTANGLE",
	"RECTANGULAR STRIDE",
	"RECTANGULAR TWIDDLED",
	"SMALL VQ",
	"SMALL VQ & MIPMAP"
};

const char* pvrImgDataTypeToReadable(PVR_IMAGE_DATA_TYPE t) {
	switch (t) {
	case IDT_SQUARE_TWIDDLED:            return pvrImgDataTypeReadable[0]; break;
	case IDT_SQUARE_TWIDDLED_AND_MIPMAP: return pvrImgDataTypeReadable[1]; break;
	case IDT_VQ:                         return pvrImgDataTypeReadable[2]; break;
	case IDT_VQ_AND_MIPMAP:              return pvrImgDataTypeReadable[3]; break;
	case IDT_8_BIT_CLUT_TWIDDLED:        return pvrImgDataTypeReadable[4]; break;
	case IDT_4_BIT_CLUT_TWIDDLED:        return pvrImgDataTypeReadable[5]; break;
	case IDT_8_BIT_DIRECT_TWIDDLED:      return pvrImgDataTypeReadable[6]; break;
	case IDT_4_BIT_DIRECT_TWIDDLED:      return pvrImgDataTypeReadable[7]; break;
	case IDT_RECTANGLE:                  return pvrImgDataTypeReadable[8]; break;
	case IDT_RECTANGULAR_STRIDE:         return pvrImgDataTypeReadable[9]; break;
	case IDT_RECTANGULAR_TWIDDLED:       return pvrImgDataTypeReadable[10]; break;
	case IDT_SMALL_VQ:                   return pvrImgDataTypeReadable[11]; break;
	case IDT_SMALL_VQ_AND_MIPMAP:        return pvrImgDataTypeReadable[12]; break;
	default: return NULL; break;
	}
}

