#ifndef UNSORTED_C
#define UNSORTED_C

#include "types.h"
#include "minimap.h"

// 754bc0
static u32* sVisitedMinimapTilesPointer[1] = {
    gVisitedMinimapTiles
};

// 760218
static const u32 sExploredMinimapBitFlags[32] = {
    0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200, 0x400, 0x800,
    0x1000, 0x2000, 0x4000, 0x8000, 0x10000, 0x20000, 0x40000, 0x80000,
    0x100000, 0x200000, 0x400000, 0x800000, 0x1000000, 0x2000000, 0x4000000,
    0x8000000, 0x10000000, 0x20000000, 0x40000000, 0x80000000
};

// 760298
static const MinimapFunc_T sMinimapTilesCopyGFXFunctionPointers[4] = {
    MinimapCopyTileGFX,
    MinimapCopyTileXFlippedGFX,
    MinimapCopyTileYFlippedGFX,
    MinimapCopyTileXYFlippedGFX,
};

#endif