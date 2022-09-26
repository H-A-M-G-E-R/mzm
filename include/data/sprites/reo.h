#ifndef REO_DATA_H
#define REO_DATA_H

#include "types.h"
#include "macros.h"
#include "oam.h"

static const i16 sReoIdleYMovement[65] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1,
    1, 2, 2, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, 0, -1,
    0, 1, 0, -1, 1, -1, -2, 2, -1, -1, 1, 0,
    -1, 0, -1, 0, 1, 0, -1, 0, 0, 0, 0, SHORT_MAX
};

static const i16 sReoIdleXMovement[81] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1,
    1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1,
    0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, -1, 0, -1, 0, -1, 0, -1, 0, -1, -1,
    -1, -1, -1, -1, -2, -2, -2, -2, -1, -1,
    -1, -1, -1, -1, 0, -1, 0, -1, 0, -1, 0,
    -1, 0, 0, 0, 0, SHORT_MAX
};

static const u32 sReoGreenWingsGFX[277] = INCBIN_U32("data/sprites/ReoGreenWings.gfx.lz");
static const u16 sReoGrrenWingsPAL[16] = INCBIN_U16("data/sprites/ReoGreenWings.pal");
static const u32 sReoPurpleWingsGFX[277] = INCBIN_U32("data/sprites/ReoPurpleWings.gfx.lz");
static const u16 sReoPurpleWingsPAL[16] = INCBIN_U16("data/sprites/ReoPurpleWings.pal");

static const u16 sReoOAM_Idle_Frame0[10] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sReoOAM_Idle_Frame1[13] = {
    0x4,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    0xee, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x204,
    0xee, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sReoOAM_Idle_Frame2[13] = {
    0x4,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1ea, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sReoOAM_Moving_Unused_Frame0[10] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sReoOAM_Moving_Unused_Frame1[13] = {
    0x4,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    0xee, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x204,
    0xee, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sReoOAM_Moving_Unused_Frame2[13] = {
    0x4,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1eb, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x5, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sReoOAM_UnusedFrame[13] = {
    0x4,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1eb, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x5, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sReoOAM_Idle_Unused_Frame0[10] = {
    0x3,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xee, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200
};

static const u16 sReoOAM_Idle_Unused_Frame1[13] = {
    0x4,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xef, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x204,
    0xef, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sReoOAM_Idle_Unused_Frame2[13] = {
    0x4,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1ea, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sReoOAM_Idle_Unused_Frame4[10] = {
    0x3,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xed, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x218
};

static const u16 sReoOAM_Idle_Unused_Frame5[13] = {
    0x4,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xef, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x204,
    0xef, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x218
};

static const u16 sReoOAM_Idle_Unused_Frame6[13] = {
    0x4,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1ea, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x218
};

static const u16 sReoOAM_Moving_Frame0[13] = {
    0x4,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    0xfe, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x210,
    0xfe, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x210
};

static const u16 sReoOAM_Moving_Frame1[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xee, OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x204,
    0xee, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x204,
    0xfd, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x210,
    0xfd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x210
};

static const u16 sReoOAM_Moving_Frame2[16] = {
    0x5,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1e9, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x226,
    0xfd, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x210,
    0xfd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x210
};

static const u16 sReoOAM_Moving_Frame4[10] = {
    0x3,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x214
};

static const u16 sReoOAM_Moving_Frame5[13] = {
    0x4,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xf0, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x204,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x214
};

static const u16 sReoOAM_Moving_Frame6[13] = {
    0x4,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1ea, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x214
};

static const struct FrameData sReoOAM_Unused1[5] = {
    sReoOAM_Idle_Frame0,
    0x6,
    sReoOAM_Idle_Frame1,
    0x2,
    sReoOAM_Idle_Frame2,
    0x2,
    sReoOAM_Idle_Frame1,
    0x2,
    NULL,
    0x0
};

static const struct FrameData sReoOAM_Idle[5] = {
    sReoOAM_Idle_Frame0,
    0x4,
    sReoOAM_Idle_Frame1,
    0x2,
    sReoOAM_Idle_Frame2,
    0x2,
    sReoOAM_Idle_Frame1,
    0x2,
    NULL,
    0x0
};

static const struct FrameData sReoOAM_Idle_Unused[9] = {
    sReoOAM_Idle_Unused_Frame0,
    0x2,
    sReoOAM_Idle_Unused_Frame1,
    0x2,
    sReoOAM_Idle_Unused_Frame2,
    0x2,
    sReoOAM_Idle_Unused_Frame1,
    0x2,
    sReoOAM_Idle_Unused_Frame4,
    0x2,
    sReoOAM_Idle_Unused_Frame5,
    0x1,
    sReoOAM_Idle_Unused_Frame6,
    0x1,
    sReoOAM_Idle_Unused_Frame5,
    0x1,
    NULL,
    0x0
};

static const struct FrameData sReoOAM_Moving[13] = {
    sReoOAM_Moving_Frame0,
    0x2,
    sReoOAM_Moving_Frame1,
    0x2,
    sReoOAM_Moving_Frame2,
    0x2,
    sReoOAM_Moving_Frame1,
    0x2,
    sReoOAM_Moving_Frame4,
    0x2,
    sReoOAM_Moving_Frame5,
    0x1,
    sReoOAM_Moving_Frame6,
    0x1,
    sReoOAM_Moving_Frame5,
    0x1,
    sReoOAM_Moving_Frame4,
    0x2,
    sReoOAM_Moving_Frame5,
    0x1,
    sReoOAM_Moving_Frame6,
    0x1,
    sReoOAM_Moving_Frame5,
    0x1,
    NULL,
    0x0
};

static const struct FrameData sReoOAM_Unused2[21] = {
    sReoOAM_Moving_Frame4,
    0x2,
    sReoOAM_Moving_Frame5,
    0x1,
    sReoOAM_Moving_Frame6,
    0x1,
    sReoOAM_Moving_Frame5,
    0x1,
    sReoOAM_Moving_Frame4,
    0x2,
    sReoOAM_Moving_Frame5,
    0x1,
    sReoOAM_Moving_Frame6,
    0x1,
    sReoOAM_Moving_Frame5,
    0x1,
    sReoOAM_Moving_Frame4,
    0x2,
    sReoOAM_Moving_Frame5,
    0x1,
    sReoOAM_Moving_Frame6,
    0x1,
    sReoOAM_Moving_Frame5,
    0x1,
    sReoOAM_Moving_Frame4,
    0x2,
    sReoOAM_Moving_Frame6,
    0x1,
    sReoOAM_Moving_Frame5,
    0x1,
    sReoOAM_Moving_Frame0,
    0x2,
    sReoOAM_Moving_Frame1,
    0x2,
    sReoOAM_Moving_Frame2,
    0x2,
    sReoOAM_Moving_Frame1,
    0x2,
    NULL,
    0x0
};

static const struct FrameData sReoOAM_Unused3[9] = {
    sReoOAM_Idle_Unused_Frame4,
    0x2,
    sReoOAM_Idle_Unused_Frame5,
    0x1,
    sReoOAM_Idle_Unused_Frame6,
    0x1,
    sReoOAM_Idle_Unused_Frame5,
    0x1,
    sReoOAM_Idle_Unused_Frame0,
    0x2,
    sReoOAM_Idle_Unused_Frame1,
    0x2,
    sReoOAM_Idle_Unused_Frame2,
    0x2,
    sReoOAM_Idle_Unused_Frame1,
    0x2,
    NULL,
    0x0
};

static const struct FrameData sReoOAM_Moving_Unused[5] = {
    sReoOAM_Moving_Unused_Frame0,
    0x4,
    sReoOAM_Moving_Unused_Frame1,
    0x2,
    sReoOAM_Moving_Unused_Frame2,
    0x2,
    sReoOAM_Moving_Unused_Frame1,
    0x2,
    NULL,
    0x0
};

#endif