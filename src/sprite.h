#ifndef SPRITE_H
#define SPRITE_H

#include "types.h"
#include "oam.h"

// Globals

#define MAX_AMOUNT_OF_SPRITES 24

extern u16 gAlarmTimer;
extern struct SpriteData gSpriteData[MAX_AMOUNT_OF_SPRITES];
extern u8 gSpritesetSpritesID[15];
extern u8 gSpritesetGFXSlots[15];
extern struct SubSpriteData gSubSpriteData1;
extern struct SubSpriteData gSubSpriteData2;
extern u8 gParasiteRelated;
extern struct SpriteData gCurrentSprite;
extern struct SpriteDebris gSpriteDebris[8];
extern u8 gPreviousVerticalCollisionCheck;
extern u8 gPreviousCollisionCheck;
extern u8 gIgnoreSamusAndSpriteCollision;
extern u8 gSpriteDrawOrder[MAX_AMOUNT_OF_SPRITES];
extern struct BossWork gBossWork;
extern u8 gSpriteRNG;

// Defines

#define SPRITE_STATUS_NONE 0x0
#define SPRITE_STATUS_EXISTS 0x1
#define SPRITE_STATUS_ONSCREEN 0x2
#define SPRITE_STATUS_NOT_DRAWN 0x4
#define SPRITE_STATUS_ROTATION_SCALING 0x8
#define SPRITE_STATUS_UNKNOWN 0x10
#define SPRITE_STATUS_MOSAIC 0x20
#define SPRITE_STATUS_XFLIP 0x40
#define SPRITE_STATUS_YFLIP 0x80
#define SPRITE_STATUS_FACING_DOWN 0x100
#define SPRITE_STATUS_FACING_RIGHT 0x200
#define SPRITE_STATUS_UNKNOWN2 0x400
#define SPRITE_STATUS_SAMUS_COLLIDING 0x800
#define SPRITE_STATUS_SAMUS_ON_TOP 0x1000
#define SPRITE_STATUS_ALPHA_BLENDING 0x2000
#define SPRITE_STATUS_DOUBLE_SIZE 0x4000
#define SPRITE_STATUS_IGNORE_PROJECTILES 0x8000

#define PSPRITE_UNUSED0 0x0
#define PSPRITE_UNUSED1 0x1
#define PSPRITE_UNUSED2 0x3
#define PSPRITE_UNUSED3 0x3
#define PSPRITE_UNUSED4 0x4
#define PSPRITE_UNUSED5 0x5
#define PSPRITE_UNUSED6 0x6
#define PSPRITE_UNUSED7 0x7
#define PSPRITE_UNUSED8 0x8
#define PSPRITE_UNUSED9 0x9
#define PSPRITE_UNUSED10 0xA
#define PSPRITE_UNUSED11 0xB
#define PSPRITE_UNUSED12 0xC
#define PSPRITE_UNUSED13 0xD
#define PSPRITE_UNUSED14 0xE
#define PSPRITE_UNUSED15 0xF
#define PSPRITE_UNUSED16 0x10
#define PSPRITE_ITEM_BANNER 0x11
#define PSPRITE_ZOOMER_YELLOW 0x12
#define PSPRITE_ZOOMER_RED 0x13
#define PSPRITE_ZEELA 0x14
#define PSPRITE_ZEELA_RED 0x15
#define PSPRITE_RIPPER_BROWN 0x16
#define PSPRITE_RIPPER_PURPLE 0x17
#define PSPRITE_ZEB 0x18
#define PSPRITE_ZEB_BLUE 0x19
#define PSPRITE_LARGE_ENERGY_DROP 0x1A
#define PSPRITE_SMALL_ENERGY_DROP 0x1B
#define PSPRITE_MISSILE_DROP 0x1C
#define PSPRITE_SUPER_MISSILE_DROP 0x1D
#define PSPRITE_POWER_BOMB_DROP 0x1E
#define PSPRITE_SKREE_GREEN 0x1F
#define PSPRITE_SKREE_BLUE 0x20
#define PSPRITE_MORPH_BALL 0x21
#define PSPRITE_CHOZO_STATUE_LONG_HINT 0x22
#define PSPRITE_CHOZO_STATUE_LONG 0x23
#define PSPRITE_CHOZO_STATUE_ICE_HINT 0x24
#define PSPRITE_CHOZO_STATUE_ICE 0x25
#define PSPRITE_CHOZO_STATUE_WAVE_HINT 0x26
#define PSPRITE_CHOZO_STATUE_WAVE 0x27
#define PSPRITE_CHOZO_STATUE_BOMB_HINT 0x28
#define PSPRITE_CHOZO_STATUE_BOMB 0x29
#define PSPRITE_CHOZO_STATUE_SPEEDBOOSTER_HINT 0x2A
#define PSPRITE_CHOZO_STATUE_SPEEDBOOSTER 0x2B
#define PSPRITE_CHOZO_STATUE_HIGH_JUMP_HINT 0x2C
#define PSPRITE_CHOZO_STATUE_HIGH_JUMP 0x2D
#define PSPRITE_CHOZO_STATUE_SCREW_HINT 0x2E
#define PSPRITE_CHOZO_STATUE_SCREW 0x2F
#define PSPRITE_CHOZO_STATUE_VARIA_HINT 0x30
#define PSPRITE_CHOZO_STATUE_VARIA 0x31
#define PSPRITE_SOVA_PURPLE 0x32
#define PSPRITE_SOVA_ORANGE 0x33
#define PSPRITE_MULTIVIOLA 0x34
#define PSPRITE_MULTIPLE_LARGE_ENERGY 0x35
#define PSPRITE_GERUTA_RED 0x36
#define PSPRITE_GERUTA_GREEN 0x37
#define PSPRITE_SQUEEPT 0x38
#define PSPRITE_SQUEEPT_UNUSED 0x39
#define PSPRITE_MAP_STATION 0x3A
#define PSPRITE_DRAGON 0x3B
#define PSPRITE_DRAGON_UNUSED 0x3C
#define PSPRITE_ZIPLINE 0x3D
#define PSPRITE_ZIPLINE_BUTTON 0x3E
#define PSPRITE_REO_GREEN_WINGS 0x3F
#define PSPRITE_REO_PURPLE_WINGS 0x40
#define PSPRITE_GUNSHIP 0x41
#define PSPRITE_DEOREM 0x42
#define PSPRITE_DEOREM_SECOND_LOCATION 0x43
#define PSPRITE_CHARGE_BEAM 0x44
#define PSPRITE_SKULTERA 0x45
#define PSPRITE_DESSGEEGA 0x46
#define PSPRITE_DESSGEEGA_AFTER_LONG_BEAM 0x47
#define PSPRITE_WAVER 0x48
#define PSPRITE_WAVER_UNUSED 0x49
#define PSPRITE_MELLOW 0x4A
#define PSPRITE_HIVE 0x4B
#define PSPRITE_POWER_GRIP 0x4C
#define PSPRITE_IMAGO_LARVA_RIGHT 0x4D
#define PSPRITE_MORPH_BALL_LAUNCHER 0x4E
#define PSPRITE_IMAGO_COCOON 0x4F
#define PSPRITE_ELEVATOR_PAD 0x50
#define PSPRITE_SPACE_PIRATE 0x51
#define PSPRITE_SPACE_PIRATE_WAITING1 0x52
#define PSPRITE_SPACE_PIRATE_WAITING2 0x53
#define PSPRITE_SPACE_PIRATE_WAITING3 0x54
#define PSPRITE_SPACE_PIRATE2 0x55
#define PSPRITE_GAMET_BLUE_SINGLE 0x56
#define PSPRITE_GAMET_RED_SINGLE 0x57
#define PSPRITE_CHOZO_STATUE_GRAVITY 0x58
#define PSPRITE_CHOZO_STATUE_SPACE_JUMP 0x59
#define PSPRITE_SECURITY_GATE_DEFAULT_OPEN 0x5A
#define PSPRITE_ZEBBO_GREEN 0x5B
#define PSPRITE_ZEBBO_YELLOW 0x5C
#define PSPRITE_WORKER_ROBOT 0x5D
#define PSPRITE_PARASITE_MULTIPLE 0x5E
#define PSPRITE_PARASITE 0x5F
#define PSPRITE_PISTON 0x60
#define PSPRITE_RIDLEY 0x61
#define PSPRITE_SECURITY_GATE_DEFAULT_CLOSED 0x62
#define PSPRITE_ZIPLINE_GENERATOR 0x63
#define PSPRITE_METROID 0x64
#define PSPRITE_FROZEN_METROID 0x65
#define PSPRITE_RINKA_ORANGE 0x66
#define PSPRITE_POLYP 0x67
#define PSPRITE_VIOLA_BLUE 0x68
#define PSPRITE_VIOLA_ORANGE 0x69
#define PSPRITE_GERON_NORFAIR 0x6A
#define PSPRITE_HOLTZ 0x6B
#define PSPRITE_GEKITAI_MACHINE 0x6C
#define PSPRITE_RUINS_TEST 0x6D
#define PSPRITE_SAVE_PLATFORM 0x6E
#define PSPRITE_KRAID 0x6F
#define PSPRITE_IMAGO_COCOON_AFTER_FIGHT 0x70
#define PSPRITE_RIPPERII 0x71
#define PSPRITE_MELLA 0x72
#define PSPRITE_ATOMIC 0x73
#define PSPRITE_AREA_BANNER 0x74
#define PSPRITE_MOTHER_BRAIN 0x75
#define PSPRITE_FAKE_POWER_BOMB_EVENT_TRIGGER 0x76
#define PSPRITE_ACID_WORM 0x77
#define PSPRITE_ESCAPE_SHIP 0x78
#define PSPRITE_SIDEHOPPER 0x79
#define PSPRITE_GEEGA 0x7A
#define PSPRITE_GEEGA_WHITE 0x7B
#define PSPRITE_RINKA_MOTHER_BRAIN 0x7C
#define PSPRITE_ZEBETITE_ONE_AND_THREE 0x7D
#define PSPRITE_CANNON 0x7E
#define PSPRITE_IMAGO_LARVA_RIGHT_SIDE 0x7F
#define PSPRITE_TANGLE_VINE_TALL 0x80
#define PSPRITE_TANGLE_VINE_MEDIUM 0x81
#define PSPRITE_TANGLE_VINE_CURVED 0x82
#define PSPRITE_TANGLE_VINE_SHORT 0x83
#define PSPRITE_MELLOW_SWARM 0x84
#define PSPRITE_MELLOW_SWARM_HEALTH_BASED 0x85
#define PSPRITE_IMAGO 0x86
#define PSPRITE_ZEBITITE_TWO_AND_FOUR 0x87
#define PSPRITE_CANNON2 0x88
#define PSPRITE_CANNON3 0x89
#define PSPRITE_CROCOMIRE 0x8A
#define PSPRITE_IMAGO_LARVA_LFT 0x8B
#define PSPRITE_GERON_BRINSTAR_ROOM_15 0x8C
#define PSPRITE_GERON_BRINSTAR_ROOM_1C 0x8D
#define PSPRITE_GERON_VARIA1 0x8E
#define PSPRITE_GERON_VARIA2 0x8F
#define PSPRITE_GERON_VARIA3 0x90
#define PSPRITE_GLASS_TUBE 0x91
#define PSPRITE_SAVE_PLATFORM_CHOZODIA 0x92
#define PSPRITE_BARISTUTE 0x93
#define PSPRITE_CHOZO_STATUE_PLASMA_BEAM 0x94
#define PSPRITE_KRAID_ELEVATOR_STATUE 0x95
#define PSPRITE_RIDLEY_ELEVATOR_STATUE 0x96
#define PSPRITE_RISING_CHOZO_PILLAR 0x97
#define PSPRITE_SECURITY_LASER_VERTICAL 0x98
#define PSPRITE_SECURITY_LASER_HORIZONTAL 0x99
#define PSPRITE_SECURITY_LASER_VERTICAL2 0x9A
#define PSPRITE_SECURITY_LASER_HORIZONTAL2 0x9B
#define PSPRITE_LOCK_UNLOCK_METROID_DOORS_UNUSED 0x9C
#define PSPRITE_GAMET_BLUE_LEADER 0x9D
#define PSPRITE_GAMET_BLUE_FOLLOWER 0x9E
#define PSPRITE_GEEGA_LEADER 0x9F
#define PSPRITE_GEEGA_FOLLOWER 0xA0
#define PSPRITE_ZEBBO_GREEN_LEADER 0xA1
#define PSPRITE_ZEBBO_GREEN_FOLLOWER 0xA2
#define PSPRITE_KRAID_STATUE 0xA3
#define PSPRITE_RIDLEY_STATUE 0xA4
#define PSPRITE_RINKA_GREEN 0xA5
#define PSPRITE_SEARCHLIGHT_EYE 0xA6
#define PSPRITE_SEARCHLIGHT_EYE2 0xA7
#define PSPRITE_STEAM_LARGE 0xA8
#define PSPRITE_STEAM_SMALL 0xA9
#define PSPRITE_PLASMA_BEAM_BLOCK 0xAA
#define PSPRITE_GRAVITY_SUIT_BLOCK 0xAB
#define PSPRITE_SPACE_JUMP_BLOCK 0xAC
#define PSPRITE_GADORA_KRAID 0xAD
#define PSPRITE_GADORA_RIDLEY 0xAE
#define PSPRITE_SEARCHLIGHT 0xAF
#define PSPRITE_SEARCHLIGHT2 0xB0
#define PSPRITE_SEARCHLIGHT3 0xB1
#define PSPRITE_SEARCHLIGHT4 0xB2
#define PSPRITE_MAYBE_SEARCHLIGHT_TRIGGER 0xB3
#define PSPRITE_DISCOVERED_IMAGO_PASSAGE_EVENT_TRIGGER 0xB4
#define PSPRITE_FAKE_POWER_BOMB 0xB5
#define PSPRITE_SPACE_PIRATE_CARRYING_POWER_BOMB 0xB6
#define PSPRITE_TANGLE_VINE_RED_GARUTA 0xB7
#define PSPRITE_TANGLE_VINE_GERUTA 0xB8
#define PSPRITE_TANGLE_VINE_LARVA_RIGHT 0xB9
#define PSPRITE_TANGLE_VINE_LARVA_LEFT 0xBA
#define PSPRITE_WATER_DROP 0xBB
#define PSPRITE_FALLING_CHOZO_PILLAR 0xBC
#define PSPRITE_MECHA_RIDLEY 0xBD
#define PSPRITE_EXPLOSION_ZEBES_ESCAPE 0xBE
#define PSPRITE_STEAM_LARGE_DIAGONAL_UP 0xBF
#define PSPRITE_STEAM_SMALL_DIAGONAL_UP 0xC0
#define PSPRITE_STEAM_LARGE_DIAGONAL_DOWN 0xC1
#define PSPRITE_STEAM_SMALL_DIAGONAL_DOWN 0xC2
#define PSPRITE_BARISTUTE_KRAID_UPPER 0xC3
#define PSPRITE_ESCAPE_GATE1 0xC4
#define PSPRITE_ESCAPE_GATE2 0xC5
#define PSPRITE_BLACK_SPACE_PIRATE 0xC6
#define PSPRITE_ESCAPE_SHIP_SPACE_PIRATE 0xC7
#define PSPRITE_BARISTUTE_KRAID_LOWER 0xC8
#define PSPRITE_RINKA_MOTHER_BRAIN2 0xC9
#define PSPRITE_RINKA_MOTHER_BRAIN3 0xCA
#define PSPRITE_RINKA_MOTHER_BRAIN4 0xCB
#define PSPRITE_RINKA_MOTHER_BRAIN5 0xCC
#define PSPRITE_RINKA_MOTHER_BRAIN6 0xCD

#define SSPRITE_CHOZO_BALL 0x0
#define SSPRITE_CHOZO_STATUE_BODY 0x1
#define SSPRITE_CHOZO_STATUE_REFILL 0x2
#define SSPRITE_KRAID_PART 0x3
#define SSPRITE_CHOZO_STATUE_MOVEMENT 0x4
#define SSPRITE_CHARGE_BEAM_GLOW 0x5
#define SSPRITE_WINGED_RIPPER 0x6
#define SSPRITE_MULTIVIOLA_UNUSED 0x7
#define SSPRITE_DRAGON_FIREBALL 0x8
#define SSPRITE_DEOREM_SEGMENT 0x9
#define SSPRITE_DEOREM_EYE 0xA
#define SSPRITE_DEOREM_THORN 0xB
#define SSPRITE_SKREE_EXPLOSION 0xC
#define SSPRITE_SAVE_PLATFORM_TOP 0xD
#define SSPRITE_SAVE_YES_NO_CURSOR 0xE
#define SSPRITE_BLUE_SKREE_EXPLOSION 0xF
#define SSPRITE_ZEELA_EYES 0x10
#define SSPRITE_HIVE_ROOTS 0x11
#define SSPRITE_IMAGO_LARVA_OUTSIDE 0x12
#define SSPRITE_MORPH_BALL_OUTSIDE 0x13
#define SSPRITE_IMAGO_COCOON_VINE 0x14
#define SSPRITE_IMAGO_COCOON_SPORE 0x15
#define SSPRITE_SPACE_PIRATE_LASER 0x16
#define SSPRITE_RIDLEY_BODY 0x17
#define SSPRITE_RIDLEY_TAIL 0x18
#define SSPRITE_SEARCHLIGHT_EYE_BEAM 0x19
#define SSPRITE_METROID_SHELL 0x1A
#define SSPRITE_POLYP_PROJECTILE 0x1B
#define SSPRITE_KRAID_SPIKE 0x1C
#define SSPRITE_KRAID_NAIL 0x1D
#define SSPRITE_ZIPLINE_BUTTON_INITIALIZE_MORPH_SYMBOL 0x1E
#define SSPRITE_ATOMIC_ELECTRICITY 0x1F
#define SSPRITE_MOTHER_BRAIN_PART 0x20
#define SSPRITE_RIDLEY_FIREBALL 0x21
#define SSPRITE_UNKNOWN_ITEM_CHOZO_STATUE_BODY 0x22
#define SSPRITE_UNKNOWN_ITEM_CHOZO_STATUE_REFILL 0x23
#define SSPRITE_MORPH_BALL_LAUNCHER_PART 0x24
#define SSPRITE_ACID_WORM_BODY 0x25
#define SSPRITE_ACID_WORM_SPIT 0x26
#define SSPRITE_CANNON_BULLET 0x27
#define SSPRITE_CROCOMIRE_BODY 0x28
#define SSPRITE_IMAGO_PART 0x29
#define SSPRITE_DEFEATED_IMAGO_COCOON 0x2A
#define SSPRITE_IMAGO_CEILING_VINE 0x2B
#define SSPRITE_SEARCHLIGHT_EYE_BEAM2 0x2C
#define SSPRITE_GERUTA_TANGLE_VINE 0x2D
#define SSPRITE_CHOZODIA_SAVE_PLATFORM_TOP 0x2E
#define SSPRITE_IMAGO_NEEDLE 0x2F
#define SSPRITE_ELEVATOR_STATUE_DEBRIS 0x30
#define SSPRITE_IMAGO_DAMAGED_STINGER 0x31
#define SSPRITE_GUNSHIP_PART 0x32
#define SSPRITE_IMAGO_EGG 0x33
#define SSPRITE_MAP_STATION_SCREEN 0x34
#define SSPRITE_CHOZO_PILLAR_PLATFORM 0x35
#define SSPRITE_GADORA_EYE 0x36
#define SSPRITE_GADORA_BEAM 0x37
#define SSPRITE_UNKNOWN_ITEM_BLOCK_LIGHT 0x38
#define SSPRITE_SEARCHLIGHT_EYE_PROJECTILE 0x39
#define SSPRITE_CHOZO_PILLAR_PLATFORM_SHADOW 0x3A
#define SSPRITE_RUINS_TEST_SYMBOL 0x3B
#define SSPRITE_RUINS_TEST_SAMUS_REFLECTION_START 0x3C
#define SSPRITE_RUINS_TEST_REFLECTION_COVER 0x3D
#define SSPRITE_RUINS_TEST_GHOST_OUTLINE 0x3E
#define SSPRITE_RUINS_TEST_GHOST 0x3F
#define SSPRITE_RUINS_TEST_SHOOTABLE_SYMBOL 0x40
#define SSPRITE_RUINS_TEST_SAMUS_REFLECTION_END 0x41
#define SSPRITE_RUINS_TEST_LIGHTNING 0x42
#define SSPRITE_RIDLEY_BIG_FIREBALL 0x43
#define SSPRITE_MECHA_RIDLEY_PART 0x44
#define SSPRITE_ESCAPE_SHIP_PART 0x45
#define SSPRITE_POWER_GRIP_GLOW 0x46
#define SSPRITE_MECHA_RIDLEY_LASER 0x47
#define SSPRITE_MECHA_RIDLEY_MISSILE 0x48
#define SSPRITE_MECHA_RIDLEY_FIREBALL 0x49
#define SSPRITE_MOTHER_BRAIN_BEAM 0x4A
#define SSPRITE_MOTHER_BRAIN_BLOCK 0x4B
#define SSPRITE_MOTHER_BRAIN_GLASS_BREAKING 0x4C

#define SSC_NONE 0x0
#define SSC_SOLID 0x1
#define SSC_ESCAPE_SHIP 0x2
#define SSC_HURTS_SAMUS_CAN_STAND_ON_TOP 0x3
#define SSC_HURTS_SAMUS 0x4
#define SSC_ATOMIC_DISCHARGE 0x5
#define SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT 0x6
#define SSC_KNOCKS_BACK_SAMUS 0x7
#define SSC_HURTS_SAMUS_NO_KNOCKBACK 0x9
#define SSC_KRAID 0xA
#define SSC_HURTS_SAMUS_NO_PASS_THROUGH 0xB
#define SSC_ZEBETITE 0xC
#define SSC_IMAGO_STINGER 0xD
#define SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT_BIG_KNOCKBACK 0xE
#define SSC_MOTHER_BRAIN_BEAM 0xF
#define SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT_NO_KNOCKBACK 0x10
#define SSC_HURTS_SAMUS_NO_KNOCKBACK_NO_CONTACT_DAMAGE 0x11
#define SSC_MELLOW 0x12
#define SSC_SPACE_PIRATE_LASER 0x13
#define SSC_SPACE_PIRATE 0x14
#define SSC_ACID_WORM 0x15
#define SSC_ACID_WORM_MOUTH 0x16
#define SSC_BUG 0x17
#define SSC_METROID 0x18
#define SSC_KRAID_SPIKE 0x19
#define SSC_ZIPLINE 0x1A
#define SSC_IMAGO_EGG 0x1B
#define SSC_RIDLEY_CLAW 0x1C
#define SSC_MECHA_RIDLEY 0x1D
#define SSC_ABILITY_LASER_SEARCHLIGHT 0x1E
#define SSC_SMALL_ENERGY_DROP 0x1F
#define SSC_LARGE_ENERGY_DROP 0x20
#define SSC_MISSILE_DROP 0x21
#define SSC_SUPER_MISSILE_DROP 0x22
#define SSC_POWER_BOMB_DROP 0x23
#define SSC_MULTIPLE_LARGE_ENERGY_DROP 0x24

#define SP_NONE 0x0
#define SP_ALWAYS_ACTIVE 0x1
#define SP_DAMAGED 0x2
#define SP_KILL_OFF_SCREEN 0x4
#define SP_SOLID_FOR_PROJECTILES 0x8
#define SP_DESTROYED 0x10
#define SP_ABSOLUTE_POSITION 0x20
#define SP_IMMUNE_TO_PROJECTILES 0x40
#define SP_SECONDARY_SPRITE 0x80

#define WEAKNESS_NONE 0x0
#define WEAKNESS_CHARGE_BEAM_PISTOL 0x1
#define WEAKNESS_BEAM_BOMBS 0x2
#define WEAKNESS_SUPER_MISSILES 0x4
#define WEAKNESS_MISSILES 0x8
#define WEAKNESS_POWER_BOMB 0x10
#define WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK 0x20
#define WEAKNESS_CAN_BE_FROZEN 0x40


#define SPRITE_ARRAY_TERMINATOR 0x7FFF

// Structs

struct __attribute__((packed)) EnemyRoomData {
    u8 yPosition;
    u8 xPosition;
    u8 spritesetSlot;
};

struct SubSpriteData {
    const struct FrameData* pMultiOam;
    u16 currentAnimationFrame;
    u16 yPosition;
    u16 xPosition;
    u16 health;
    u8 animationDurationCounter;
    u8 workVariable1;
    u8 workVariable2;
    u8 workVariable3;
    u8 workVariable4;
    u8 workVariable5;
    u8 workVariable6;
    u8 workVariable7;
};

struct SpriteData {
    u16 status;
    u16 yPosition;
    u16 xPosition;
    u16 yPositionSpawn;
    u16 xPositionSpawn;
    i16 hitboxTopOffset;
    i16 hitboxBottomOffset;
    i16 hitboxLeftOffset;
    i16 hitboxRightOffset;
    u16 oamScaling;
    u16 health;
    u16 currentAnimationFrame;
    const struct FrameData* pOam;
    u8 animationDurationCounter;
    u8 spriteID;
    u8 roomSlot;
    u8 spritesetGFXSlot;
    u8 paletteRow;
    u8 bgPriority;
    u8 drawOrder;
    u8 primarySpriteRAMSlot;
    u8 pose;
    u8 samusCollision;
    u8 ignoreSamusCollisionTimer;
    u8 drawDistanceTopOffset;
    u8 drawDistanceBottomOffset;
    u8 drawDistanceHorizontalOffset;
    u8 oamRotation;
    u8 invicibilityStunFlashTimer;
    u8 timer;
    u8 workVariable;
    u8 workVariable2;
    u8 arrayOffset;
    u8 freezeTimer;
    u8 standingOnSprite;
    u8 properties;
    u8 frozenPaletteRowOffset;
    u8 absolutePaletteRow;
};

struct BossWork {
    u16 work1; // Usually spawn Y
    u16 work2; // Usually spawn X
    u16 work3;
    u16 work4; // Usually health
    u16 work5;
    u16 work6;
    u16 work7;
    u16 work8;
    u16 work9;
    u16 work10;
    u16 work11; // Completion percentage, only used by mecha ridley
    u16 work12;
    u16 work13;
    u16 work14;
    u16 work15;
    u16 work16;
    u16 work17;
    u16 work18;
    u16 work19;
    u16 work20;
    u16 work21;
    u16 work22;
    u16 work23;
    u16 work24;
};

// Functions

void SpriteUpdate(void);
void SpriteUpdateAnimation(struct SpriteData* pSprite);
void SpriteDrawAll_2(void);
void SpriteDrawAll(void);
void SpriteDrawAll_3(void);
void SpriteDraw(struct SpriteData* pSprite, u32 slot);
void SpriteCheckOnScreen(struct SpriteData* pSprite);
void SpriteLoadAllData(void);
void SpriteLoadSpriteset(void);
void SpriteLoadGFX(u8 spriteID, u8 gfx_row);
void SpriteLoadPAL(u8 spriteID, u8 row, u8 len);
void SpriteClearData(void);
void SpriteLoadRoomSprites(void);
void SpriteInitPrimary(u8 spritesetSlot, u16 yPosition, u16 xPosition, u8 roomSlot);
u8 SpriteSpawnSecondary(u8 spriteID, u8 roomSlot, u8 gfxSlot, u8 ramSlot, u16 yPosition, u16 xPosition, u16 statusToAdd);
u8 SpriteSpawnPrimary(u8 spriteID, u8 roomSlot, u8 gfxSlot, u16 yPosition, u16 xPosition, u16 statusToAdd);
u8 SpriteSpawnDropFollowers(u8 spriteID, u8 roomSlot, u8 gfxSlot, u8 ramSlot, u16 yPosition, u16 xPosition, u16 statusToAdd);

#endif /* SPRITE_H */