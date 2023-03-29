#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "types.h"
#include "utils.h"

int main(int argc, char** argv) {
	int result = 0;

	if (argc < 3) {
		printf("Usage: %s input.pvr output.png\n", argv[0]);
		result = 1; goto end;
	}

	FILE* f = fopen(argv[1], "rb");

	if (f == NULL) {
		printf("failed to open input PVR: '%s'\n", argv[1]);
		result = 1; goto end;
	}

	char gbixMagic[5] = "0000";
	fread(&gbixMagic, 4, 1, f);
	if (strncmp(gbixMagic, "GBIX", 4) == 0) {
		int gbixHeaderLen = -1;
		fread(&gbixHeaderLen, 4, 1, f);
		assert(gbixHeaderLen > 0);
		fseek(f, gbixHeaderLen, SEEK_CUR);
	} else if (strncmp(gbixMagic, "PVRT", 4) == 0) {
		fseek(f, -4, SEEK_CUR);
	}

	char pvrMagic[5] = "0000";
	fread(&pvrMagic, 4, 1, f);

	if (strncmp(pvrMagic, "PVRT", 4) != 0) {
		printf("Invalid PVR Magic: '%s'\n", pvrMagic);
		result = 1; goto end;
	} else {
		printf("- PVR Magic: Valid\n");
	}

	int32_t pvrRestFileLen = -1;
	fread(&pvrRestFileLen, 4, 1, f);
	assert(pvrRestFileLen > 0);
	printf("- PVR Rest File Len: %d\n", pvrRestFileLen);

	uint8_t pvrPixelFormat = 0;
	fread(&pvrPixelFormat, 1, 1, f);
	assert(pvrPixelFormat <= 0x06);
	printf("- PVR Pixel Format: %s\n", pvrPixelFormatToReadable(pvrPixelFormat));

	uint8_t pvrImageDataType = 0;
	fread(&pvrImageDataType, 1, 1, f);
	assert(IS_IMAGE_DATA_TYPE_VALID(pvrImageDataType));
	if (pvrImageDataType == 0x12) { pvrImageDataType = IDT_SQUARE_TWIDDLED_AND_MIPMAP; } // special case where 0x02 & 0x12 both are same thing
	printf("- PVR Image Data Format: %s\n", pvrImgDataTypeToReadable(pvrImageDataType));

	fseek(f, 2, SEEK_CUR); // move 2 bytes forward from current position as they don't contain any information.

	uint16_t pvrWidth = 0;
	fread(&pvrWidth, 2, 1, f);
	assert(pvrWidth > 0);

	uint16_t pvrHeight = 0;
	fread(&pvrHeight, 2, 1, f);
	assert(pvrHeight > 0);
	pvrWidth *= 256;
	pvrHeight *= 256;

	printf("- PVR Image Resolution: %ux%u\n", (unsigned int)pvrWidth, (unsigned int)pvrHeight);

end:
	if (f) fclose(f);
	f = NULL;
	return result;
}

