#include "data/cutscenes/before_charlie_data.h"
#include "gba.h"
#include "macros.h"

const struct CutscenePageData sBeforeCharliePageData[9] = {
    [0] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1E,
        .priority = 3,
        .bg = DCNT_BG3,
        .screenSize = 0x4000
    },
    [1] = {
        .graphicsPage = 2,
        .tiletablePage = 0x1C,
        .priority = 2,
        .bg = DCNT_BG2,
        .screenSize = 0x4000
    },
    [2] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1F,
        .priority = 3,
        .bg = DCNT_BG3,
        .screenSize = 0
    },
    [3] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1E,
        .priority = 2,
        .bg = DCNT_BG2,
        .screenSize = 0
    },
    [4] = {
        .graphicsPage = 2,
        .tiletablePage = 0x1C,
        .priority = 1,
        .bg = DCNT_BG1,
        .screenSize = 0x4000
    },
    [5] = {
        .graphicsPage = 2,
        .tiletablePage = 0x1F,
        .priority = 0,
        .bg = DCNT_BG0,
        .screenSize = 0
    },
    [6] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1E,
        .priority = 3,
        .bg = DCNT_BG3,
        .screenSize = 0
    },
    [7] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1C,
        .priority = 1,
        .bg = DCNT_BG1,
        .screenSize = 0
    },
    [8] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1D,
        .priority = 2,
        .bg = DCNT_BG2,
        .screenSize = 0
    },
};

const u16 sBeforeCharlieChozoWallSidesPAL[10 * 16] = INCBIN_U16("data/cutscenes/BeforeCharlie/ChozoWallSides.pal");
const u16 sBeforeCharlieChozoWallPAL[8 * 16] = INCBIN_U16("data/cutscenes/BeforeCharlie/ChozoWall.pal");
const u16 sBeforeCharlieSamusCloseUpPAL[16 * 16] = INCBIN_U16("data/cutscenes/BeforeCharlie/SamusCloseUp.pal");

const u32 sBeforeCharlieLeftSideOfChozoWallGFX[4049] = INCBIN_U32("data/cutscenes/BeforeCharlie/LeftSideChozoWall.gfx.lz");
const u32 sBeforeCharlieRightSideOfChozoWallGFX[3987] = INCBIN_U32("data/cutscenes/BeforeCharlie/RightSideChozoWall.gfx.lz");
const u32 sBeforeCharlieChozoWallBackgroundGFX[6446] = INCBIN_U32("data/cutscenes/BeforeCharlie/ChozoWallBackground.gfx.lz");
const u32 sBeforeCharlieYoungSamusAndGreyVoiceGFX[1792] = INCBIN_U32("data/cutscenes/BeforeCharlie/YoungSamusAndGreyVoice.gfx.lz");
const u32 sBeforeCharlieYoungSamusAndGreyVoiceCloseUpGFX[3818] = INCBIN_U32("data/cutscenes/BeforeCharlie/YoungSamusAndGreyVoiceCloseUp.gfx.lz");
const u32 sBeforeCharlieYoungSamusCloseUpGFX[2979] = INCBIN_U32("data/cutscenes/BeforeCharlie/YoungSamusCloseUp.gfx.lz");
const u32 sBeforeCharlieSamusCloseUpGFX[5285] = INCBIN_U32("data/cutscenes/BeforeCharlie/SamusCloseUp.gfx.lz");

const u32 sBeforeCharlieLeftSideOfChozoWallTileTable[368] = INCBIN_U32("data/cutscenes/BeforeCharlie/LeftSideChozoWall.tt");
const u32 sBeforeCharlieRightSideOfChozoWallTileTable[369] = INCBIN_U32("data/cutscenes/BeforeCharlie/RightSideChozoWall.tt");
const u32 sBeforeCharlieChozoWallBackgroundTileTable[551] = INCBIN_U32("data/cutscenes/BeforeCharlie/ChozoWallBackground.tt");
const u32 sBeforeCharlieYoungSamusAndGreyVoiceTileTable[185] = INCBIN_U32("data/cutscenes/BeforeCharlie/YoungSamusAndGreyVoice.tt");
const u32 sBeforeCharlieYoungSamusAndGreyVoiceCloseuUpTileTable[452] = INCBIN_U32("data/cutscenes/BeforeCharlie/YoungSamusAndGreyVoiceCloseUp.tt");
const u32 sBeforeCharlieYoungSamusCloseUpTileTable[368] = INCBIN_U32("data/cutscenes/BeforeCharlie/YoungSamusCloseUp.tt");
const u32 sBeforeCharlieSamusCloseUpEyesClosedTileTable[251] = INCBIN_U32("data/cutscenes/BeforeCharlie/SamusCloseUpEyesClosed.tt");
const u32 sBeforeCharlieSamusCloseUpEyesOpenedTileTable[232] = INCBIN_U32("data/cutscenes/BeforeCharlie/SamusCloseUpEyesOpened.tt");
const u32 sBeforeCharlieSamusCloseUpOutlineTileTable[333] = INCBIN_U32("data/cutscenes/BeforeCharlie/SamusCloseUpOutline.tt");

const u8 sTempArray_3ed498[0x71fc4] = INCBIN_U8("data/Blob_3ed498_45f45c.bin");