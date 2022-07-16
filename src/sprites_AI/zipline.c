#include "zipline.h"
#include "../samus.h"
#include "../sprite_util.h"
#include "../event.h"
#include "../globals.h"

void ZiplineCheckColliding(void)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition - 0x20;
    xPosition = gCurrentSprite.xPosition;

    if (gCurrentSprite.pose == 0x0)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition, xPosition + 0x2C);
        if (gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_STOP_ENEMY_BLOCK_SOLID)
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition, xPosition - 0x2C);
            if (gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_STOP_ENEMY_BLOCK_SOLID)
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            SpriteUtilCheckCollisionAtPosition(yPosition, xPosition + 0x2C);
        else
            SpriteUtilCheckCollisionAtPosition(yPosition, xPosition - 0x2C);
    }
}

u8 ZiplineMoving(void)
{
    u8 releasing;
    u16 velocity;
    u8 samus_grabbing;

    releasing = FALSE;
    samus_grabbing = FALSE;
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        samus_grabbing = TRUE;
        velocity = 0xC;
    }
    else
        velocity = 0x10;

    ZiplineCheckColliding();
    if (gCurrentAffectingClipdata.hazard == CLIPDATA_MOVEMENT_STOP_ENEMY_BLOCK_SOLID)
    {
        releasing++;
        gCurrentSprite.xPosition = (gCurrentSprite.xPosition & 0xFFC0) + 0x20;
        if (samus_grabbing)
            gSamusData.xPosition = gCurrentSprite.xPosition;
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            gCurrentSprite.xPosition += velocity;
            if (samus_grabbing)
                gSamusData.xPosition += velocity;
        }
        else
        {
            gCurrentSprite.xPosition -= velocity;
            if (samus_grabbing)
                gSamusData.xPosition -= velocity;
        }
    }

    if (releasing && samus_grabbing)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
        gCurrentSprite.ignore_samus_collision_timer = 0xF;
        SamusSetPose(SPOSE_UPDATE_JUMP_VELOCITY_REQUEST);
    }

    return releasing;
}

void ZiplineGFXUpdate(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
        {
            switch (gCurrentSprite.workVariable)
            {
                case 0x0:
                    gCurrentSprite.oam_pointer = zipline_oam_2ce9b0;
                    gCurrentSprite.animationDuratoinCounter = 0x0;
                    gCurrentSprite.currentAnimationFrame = 0x0;
                    gCurrentSprite.workVariable = 0x1;
                    break;

                case 0x1:
                    if (SpriteUtillCheckEndCurrentSpriteAnim())
                    {
                        gCurrentSprite.oam_pointer = zipline_oam_2ce9d0;
                        gCurrentSprite.animationDuratoinCounter = 0x0;
                        gCurrentSprite.currentAnimationFrame = 0x0;
                        gCurrentSprite.workVariable = 0x2;
                        gCurrentSprite.health = 0x2;
                    }
                    break;

                case 0x3:
                    if (SpriteUtillCheckEndCurrentSpriteAnim())
                    {
                        gCurrentSprite.oam_pointer = zipline_oam_2ce9d0;
                        gCurrentSprite.animationDuratoinCounter = 0x0;
                        gCurrentSprite.currentAnimationFrame = 0x0;
                        gCurrentSprite.workVariable = 0x2;
                    }
                    break;

                case 0x2:
                    if (gCurrentSprite.oam_pointer != zipline_oam_2ce9d0)
                    {
                        gCurrentSprite.oam_pointer = zipline_oam_2ce9d0;
                        gCurrentSprite.animationDuratoinCounter = 0x0;
                        gCurrentSprite.currentAnimationFrame = 0x0;
                    }
            }
        }
        else
        {
            switch (gCurrentSprite.workVariable)
            {
                case 0x0:
                    gCurrentSprite.oam_pointer = zipline_oam_2ce928;
                    gCurrentSprite.animationDuratoinCounter = 0x0;
                    gCurrentSprite.currentAnimationFrame = 0x0;
                    gCurrentSprite.workVariable = 0x1;
                    break;

                case 0x1:
                case 0x3:
                    if (SpriteUtill0x0EndCurrentSpriteAnim())
                    {
                        gCurrentSprite.oam_pointer = zipline_oam_2cd948;
                        gCurrentSprite.animationDuratoinCounter = 0x0;
                        gCurrentSprite.currentAnimationFrame = 0x0;
                        gCurrentSprite.workVariable = 0x2;
                    }
                    break;

                case 0x2:
                    if (gCurrentSprite.oam_pointer != zipline_oam_2ce948)
                    {
                        gCurrentSprite.oam_pointer = zipline_oam_2ce948;
                        gCurrentSprite.animationDuratoinCounter = 0x0;
                        gCurrentSprite.currentAnimationFrame = 0x0;
                    }
            }
        }
    }
    else
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
        {
            switch (gCurrentSprite.workVariable)
            {
                case 0x2:
                    gCurrentSprite.oam_pointer = zipline_oam_2cea08;
                    gCurrentSprite.animationDuratoinCounter = 0x0;
                    gCurrentSprite.currentAnimationFrame = 0x0;
                    gCurrentSprite.workVariable = 0x3;
                    break;

                case 0x1:
                case 0x3:
                    if (SpriteUtillCheckEndCurrentSpriteAnim())
                    {
                        gCurrentSprite.oam_pointer = zipline_oam_activated_2ce978;
                        gCurrentSprite.currentAnimationFrame = 0x0;
                        gCurrentSprite.animationDuratoinCounter = 0x0;
                        gCurrentSprite.workVariable = 0x0;
                    }
                    break;

                case 0x0:
                    if (gCurrentSprite.oam_pointer != zipline_oam_activated_2ce978)
                    {
                        gCurrentSprite.oam_pointer = zipline_oam_activated_2ce978;
                        gCurrentSprite.animationDuratoinCounter = 0x0;
                        gCurrentSprite.currentAnimationFrame = 0x0;
                    }
            }
        }
        else
        {
            switch (gCurrentSprite.workVariable)
            {
                case 0x2:
                    gCurrentSprite.oam_pointer = zipline_oam_2ce958;
                    gCurrentSprite.animationDuratoinCounter = 0x0;
                    gCurrentSprite.currentAnimationFrame = 0x0;
                    gCurrentSprite.workVariable = 0x3;
                    break;

                case 0x1:
                case 0x3:
                    if (SpriteUtillCheckEndCurrentSpriteAnim())
                    {
                        gCurrentSprite.oam_pointer = zipline_oam_deactivated_2ce918;
                        gCurrentSprite.animationDuratoinCounter = 0x0;
                        gCurrentSprite.currentAnimationFrame = 0x0;
                        gCurrentSprite.workVariable = 0x0;
                    }
                    break;

                case 0x0:
                    if (gCurrentSprite.oam_pointer != zipline_oam_deactivated_2ce918)
                    {
                        gCurrentSprite.oam_pointer = zipline_oam_activated_2ce978;
                        gCurrentSprite.animationDuratoinCounter = 0x0;
                        gCurrentSprite.currentAnimationFrame = 0x0;
                    }
            }
        }
    }
}

void ZiplineInit(void)
{
    gCurrentSprite.hitboxTopOffset = -0x40;
    gCurrentSprite.hitboxBottomOffset = 0x10;
    gCurrentSprite.hitboxLeftOffset = -0x4;
    gCurrentSprite.hitboxRightOffset = 0x4;
    gCurrentSprite.drawDistanceTopOffset = 0x10;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.draw_distance_horizontal_offset = 0x8;
    gCurrentSprite.samus_collision = SSC_ZIPLINE;
    gCurrentSprite.health = 0x1;
    gCurrentSprite.properties |= SP_SOLID_FOR_PROJECTILES;
    gCurrentSprite.draw_order = 0x3;
    gCurrentSprite.bg_priority = 0x1;
    gCurrentSprite.animationDuratoinCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.timer1 = 0x0;
    gCurrentSprite.workVariable = 0x0;
    ZiplineCheckColliding();
    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
        gCurrentSprite.oam_pointer = zipline_oam_activated_2ce978;
    else
        gCurrentSprite.oam_pointer = zipline_oam_deactivated_2ce918;
    gCurrentSprite.pose = 0x9;
}

void ZiplineMoving(void)
{
    if (!SpriteUtilCheckOnZipline() && gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
        gCurrentSprite.ignore_samus_collision_timer = 0xF;
    }

    ZiplineGFXUpdate();
    if (gCurrentSprite.health == 0x2)
    {
        if ((gCurrentSprite.timer1 & 0xF) == 0x0)
            SoundPlay(0x110);
        gCurrentSprite.timer1++;
        if (ZiplineMoving() << 0x18)
        {
            gCurrentSprite.health = 0x1;
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.timer1 = 0x0;
            unk_2c80(0x110, 0x4);
        }
    }
}

void ZiplineButtonInit(void)
{
    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
        gCurrentSprite.oam_pointer = zipline_button_oam_activated_2cea38;
    else
        gCurrentSprite.oam_pointer = zipline_button_oam_deactivated_2cea28;

    gCurrentSprite.yPosition -= 0x80;
    gCurrentSprite.drawDistanceTopOffset = 0x0;
    gCurrentSprite.drawDistanceBottomOffset = 0x18;
    gCurrentSprite.draw_distance_horizontal_offset = 0x8;
    gCurrentSprite.hitboxTopOffset = 0x0;
    gCurrentSprite.hitboxBottomOffset = 0x50;
    gCurrentSprite.hitboxLeftOffset = -0x14;
    gCurrentSprite.hitboxRightOffset = 0x14;
    gCurrentSprite.animationDuratoinCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.samus_collision = SSC_NONE;
    gCurrentSprite.health = 0x1;
    gCurrentSprite.properties |= SP_SOLID_FOR_PROJECTILES;
    gCurrentSprite.pose = 0x1;
    gCurrentSprite.draw_order = 0x3;
    gCurrentSprite.bg_priority = 0x1;
}

void ZiplineButtonActivatedGFXInit(void)
{
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.animationDuratoinCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.oam_pointer = zipline_button_oam_activated_2cea38;
}

void ZiplineButtonSpawn(void)
{
    u8 slot;

    slot = SpriteUtilFindPrimary(PSPRITE_ZIPLINE);
    if (slot == 0xFF)
        gCurrentSprite.status = 0x0;
    else
    {
        gCurrentSprite.workVariable = slot;
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
            ZiplineButtonActivatedGFXInit();
        else
            gCurrentSprite.pose = 0xF;
    }
}

void ZiplineButtonCheckZiplinesActivated(void)
{
    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
        ZiplineButtonActivatedGFXInit();
}

void ZiplineButtonIdle(void)
{
    u8 moving;
    u8 slot;

    moving = FALSE;
    slot = gCurrentSprite.workVariable;
    if (gCurrentSprite.invicibility_stun_flash_timer & 0x7F)
    {
        gSpriteData[slot].health = 0x2;
        moving = TRUE;
        SoundPlay(0x111);
    }
    else if (gSpriteData[slot].health == 0x2)
        moving = TRUE;

    if (moving)
    {
        gCurrentSprite.pose = 0x23;
        gCurrentSprite.animationDuratoinCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.oam_pointer = zipline_button_oam_2cea70;
    }
}

void ZiplineButtonZiplineMoving(void)
{
    u8 slot;

    slot = gCurrentSprite.workVariable;

    if (gSpriteData[slot].health == 0x1)
        ZiplineButtonActivatedGFXInit();
}

void Zipline"void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ZiplineInit();
            break;
        case 0x9:
            ZiplineMoving();
    }
}

void ZiplineButton(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ZiplineButtonInit();
            break;
        case 0x1:
            ZiplineButtonSpawn();
            break;
        case 0x9:
            ZiplineButtonIdle();
            break;
        case 0x23:
            ZiplineButtonZiplineMoving();
            break;
        case 0xF:
            ZiplineButtonCheckZiplinesActivated();
    }
}