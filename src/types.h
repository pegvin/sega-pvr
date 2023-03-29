#ifndef _PVR2PNG_TYPES_H_INCLUDED
#define _PVR2PNG_TYPES_H_INCLUDED 1
#pragma once

// Common Types Used In PVR File Format

// PVR Pixel Format
typedef enum {
	PF_ARGB1555 = 0x00, // bilevel translucent alpha 0,255
	PF_RGB565   = 0x01, // no translucent
	PF_ARGB4444 = 0x02, // translucent alpha 0-255
	PF_YUV442   = 0x03,
	PF_BUMP     = 0x04,
	PF_4_BIT    = 0x05,
	PF_8_BIT    = 0x06,
	PF_INVALID
} PVR_PIXEL_FORMAT;

// PVR Image Data Type
typedef enum {
	IDT_SQUARE_TWIDDLED = 0x01,
	IDT_SQUARE_TWIDDLED_AND_MIPMAP = 0x02, // 0x12 is also this value
	IDT_VQ = 0x03,
	IDT_VQ_AND_MIPMAP = 0x04,
	IDT_8_BIT_CLUT_TWIDDLED = 0x05,
	IDT_4_BIT_CLUT_TWIDDLED = 0x06,
	IDT_8_BIT_DIRECT_TWIDDLED = 0x07,
	IDT_4_BIT_DIRECT_TWIDDLED = 0x08,
	IDT_RECTANGLE = 0x09,
	IDT_RECTANGULAR_STRIDE = 0x0B,
	IDT_RECTANGULAR_TWIDDLED = 0x0D,
	IDT_SMALL_VQ = 0x10,
	IDT_SMALL_VQ_AND_MIPMAP = 0x11
} PVR_IMAGE_DATA_TYPE;

/* use this macro to see if your PVR_IMAGE_DATA_TYPE is valid
   because there are multiple in-between enum entries which aren't valid */
#define IS_IMAGE_DATA_TYPE_VALID(t) (t != 0x00 || t != 0x0A || t != 0x0C || t != 0x0E || t != 0x0F)

#endif // _PVR2PNG_TYPES_H_INCLUDED

