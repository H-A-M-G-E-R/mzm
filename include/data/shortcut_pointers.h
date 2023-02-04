#ifndef SHORTCUT_POINTERS_H
#define SHORTCUT_POINTERS_H

#include "types.h"
#include "temp_globals.h"

extern void* sEwramPointer;
extern void* sBgPalramPointer;
extern void* sObjPalramPointer;
extern u32** sVisitedMinimapTilesPointer;
extern union NonGameplayRAM* sNonGameplayRamPointer;
extern void* sSramEwramPointer;
extern void* sSramFlashPointer;

#endif /* SHORTCUT_POINTERS_H */
