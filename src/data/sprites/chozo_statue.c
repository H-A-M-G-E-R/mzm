#include "data/sprites/chozo_statue.h"
#include "sprites_AI/chozo_statue.h"
#include "macros.h"

static const s16 sChozoStatueMultiSpriteData_Standing_Frame0[CHOZO_STATUE_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [CHOZO_STATUE_PART_ARM] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_ARM_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(BLOCK_SIZE + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE)
    },
    [CHOZO_STATUE_PART_GLOW] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_REFILL_GLOW_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 3),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE)
    },
    [CHOZO_STATUE_PART_EYE] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_EYE_OPENED,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 4 + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(BLOCK_SIZE + HALF_BLOCK_SIZE)
    },
    [CHOZO_STATUE_PART_LEG] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_LEG_STANDING,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [CHOZO_STATUE_PART_HEAD] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 4),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(BLOCK_SIZE - QUARTER_BLOCK_SIZE - PIXEL_SIZE)
    }
};

static const s16 sChozoStatueMultiSpriteData_Sitting_Frame0[CHOZO_STATUE_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [CHOZO_STATUE_PART_ARM] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_ARM_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(BLOCK_SIZE + HALF_BLOCK_SIZE + PIXEL_SIZE)
    },
    [CHOZO_STATUE_PART_GLOW] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_REFILL_GLOW_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 3 - EIGHTH_BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE - PIXEL_SIZE)
    },
    [CHOZO_STATUE_PART_EYE] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_EYE_OPENED,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 4 + HALF_BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(BLOCK_SIZE + HALF_BLOCK_SIZE - PIXEL_SIZE)
    },
    [CHOZO_STATUE_PART_LEG] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_LEG_SITTING,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [CHOZO_STATUE_PART_HEAD] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 4 - EIGHTH_BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE)
    }
};

static const s16 sChozoStatueMultiSpriteData_Sitting_Frame1[CHOZO_STATUE_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [CHOZO_STATUE_PART_ARM] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_ARM_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(BLOCK_SIZE + HALF_BLOCK_SIZE)
    },
    [CHOZO_STATUE_PART_GLOW] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_REFILL_GLOW_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE)
    },
    [CHOZO_STATUE_PART_EYE] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_EYE_OPENED,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 4 + QUARTER_BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(BLOCK_SIZE + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE)
    },
    [CHOZO_STATUE_PART_LEG] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_LEG_SITTING,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = PIXEL_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [CHOZO_STATUE_PART_HEAD] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(HALF_BLOCK_SIZE + PIXEL_SIZE)
    }
};

static const s16 sChozoStatueMultiSpriteData_Sitting_Frame2[CHOZO_STATUE_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [CHOZO_STATUE_PART_ARM] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_ARM_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 2 - PIXEL_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(BLOCK_SIZE + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE)
    },
    [CHOZO_STATUE_PART_GLOW] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_REFILL_GLOW_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE - PIXEL_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE)
    },
    [CHOZO_STATUE_PART_EYE] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_EYE_OPENED,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 4 - QUARTER_BLOCK_SIZE + PIXEL_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(BLOCK_SIZE + QUARTER_BLOCK_SIZE)
    },
    [CHOZO_STATUE_PART_LEG] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_LEG_SITTING,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = PIXEL_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [CHOZO_STATUE_PART_HEAD] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE - PIXEL_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(HALF_BLOCK_SIZE - PIXEL_SIZE)
    }
};

static const s16 sChozoStatueMultiSpriteData_Sitting_Frame3[CHOZO_STATUE_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [CHOZO_STATUE_PART_ARM] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_ARM_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 2 - EIGHTH_BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(BLOCK_SIZE + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE)
    },
    [CHOZO_STATUE_PART_GLOW] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_REFILL_GLOW_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 2 + EIGHTH_BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE)
    },
    [CHOZO_STATUE_PART_EYE] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_EYE_OPENED,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 4 - QUARTER_BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(BLOCK_SIZE + QUARTER_BLOCK_SIZE)
    },
    [CHOZO_STATUE_PART_LEG] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_LEG_SITTING,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = PIXEL_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [CHOZO_STATUE_PART_HEAD] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 3 + EIGHTH_BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(HALF_BLOCK_SIZE - PIXEL_SIZE)
    }
};

static const s16 sChozoStatueMultiSpriteData_Sitting_Frame5[CHOZO_STATUE_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [CHOZO_STATUE_PART_ARM] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_ARM_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE + PIXEL_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(BLOCK_SIZE - QUARTER_BLOCK_SIZE + PIXEL_SIZE)
    },
    [CHOZO_STATUE_PART_GLOW] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_REFILL_GLOW_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 2 + PIXEL_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE - PIXEL_SIZE)
    },
    [CHOZO_STATUE_PART_EYE] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_EYE_OPENED,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 4 - QUARTER_BLOCK_SIZE - PIXEL_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE - PIXEL_SIZE)
    },
    [CHOZO_STATUE_PART_LEG] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_LEG_SITTING,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = PIXEL_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [CHOZO_STATUE_PART_HEAD] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 3 + PIXEL_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 8
    }
};

static const s16 sChozoStatueMultiSpriteData_Sitting_Frame6[CHOZO_STATUE_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [CHOZO_STATUE_PART_ARM] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_ARM_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE + HALF_BLOCK_SIZE - PIXEL_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(QUARTER_BLOCK_SIZE - PIXEL_SIZE)
    },
    [CHOZO_STATUE_PART_GLOW] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_REFILL_GLOW_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE - PIXEL_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(BLOCK_SIZE + PIXEL_SIZE)
    },
    [CHOZO_STATUE_PART_EYE] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_EYE_OPENED,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE + PIXEL_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(PIXEL_SIZE)
    },
    [CHOZO_STATUE_PART_LEG] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_LEG_SITTING,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = PIXEL_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [CHOZO_STATUE_PART_HEAD] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE - PIXEL_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = (BLOCK_SIZE - QUARTER_BLOCK_SIZE)
    }
};

static const s16 sChozoStatueMultiSpriteData_Sitting_Frame7[CHOZO_STATUE_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [CHOZO_STATUE_PART_ARM] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_ARM_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -PIXEL_SIZE
    },
    [CHOZO_STATUE_PART_GLOW] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_REFILL_GLOW_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE + QUARTER_BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(BLOCK_SIZE - PIXEL_SIZE)
    },
    [CHOZO_STATUE_PART_EYE] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_EYE_OPENED,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 3 - EIGHTH_BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = PIXEL_SIZE
    },
    [CHOZO_STATUE_PART_LEG] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_LEG_SITTING,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = PIXEL_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [CHOZO_STATUE_PART_HEAD] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = (BLOCK_SIZE - EIGHTH_BLOCK_SIZE)
    }
};

static const s16 sChozoStatueMultiSpriteData_Sitting_Frame8[CHOZO_STATUE_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [CHOZO_STATUE_PART_ARM] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_ARM_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -PIXEL_SIZE
    },
    [CHOZO_STATUE_PART_GLOW] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_REFILL_GLOW_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE - EIGHTH_BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(BLOCK_SIZE - PIXEL_SIZE)
    },
    [CHOZO_STATUE_PART_EYE] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_EYE_OPENED,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = PIXEL_SIZE
    },
    [CHOZO_STATUE_PART_LEG] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_LEG_SITTING,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = PIXEL_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [CHOZO_STATUE_PART_HEAD] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 2 - EIGHTH_BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = (BLOCK_SIZE - EIGHTH_BLOCK_SIZE)
    }
};

static const s16 sChozoStatueMultiSpriteData_Sitting_Frame9[CHOZO_STATUE_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [CHOZO_STATUE_PART_ARM] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_ARM_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE - PIXEL_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [CHOZO_STATUE_PART_GLOW] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_REFILL_GLOW_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE - PIXEL_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(BLOCK_SIZE - EIGHTH_BLOCK_SIZE)
    },
    [CHOZO_STATUE_PART_EYE] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_EYE_OPENED,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + PIXEL_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 8
    },
    [CHOZO_STATUE_PART_LEG] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_LEG_SEATED,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = PIXEL_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [CHOZO_STATUE_PART_HEAD] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 2 - PIXEL_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = (BLOCK_SIZE - PIXEL_SIZE)
    }
};

static const s16 sChozoStatueMultiSpriteData_Seated_Frame0[CHOZO_STATUE_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [CHOZO_STATUE_PART_ARM] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_ARM_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE - QUARTER_BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [CHOZO_STATUE_PART_GLOW] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_REFILL_GLOW_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -(BLOCK_SIZE - EIGHTH_BLOCK_SIZE)
    },
    [CHOZO_STATUE_PART_EYE] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_EYE_OPENED,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = EIGHTH_BLOCK_SIZE
    },
    [CHOZO_STATUE_PART_LEG] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_LEG_SEATED,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = PIXEL_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [CHOZO_STATUE_PART_HEAD] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = CHOZO_STATUE_OAM_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 2),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = (BLOCK_SIZE - PIXEL_SIZE)
    }
};

const struct MultiSpriteData sChozoStatueMultiSpriteData_Standing[2] = {
    [0] = {
        .pData = sChozoStatueMultiSpriteData_Standing_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sChozoStatueMultiSpriteData_Sitting[11] = {
    [0] = {
        .pData = sChozoStatueMultiSpriteData_Sitting_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pData = sChozoStatueMultiSpriteData_Sitting_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [2] = {
        .pData = sChozoStatueMultiSpriteData_Sitting_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pData = sChozoStatueMultiSpriteData_Sitting_Frame3,
        .timer = CONVERT_SECONDS(5.f / 60)
    },
    [4] = {
        .pData = sChozoStatueMultiSpriteData_Sitting_Frame2,
        .timer = CONVERT_SECONDS(.5f)
    },
    [5] = {
        .pData = sChozoStatueMultiSpriteData_Sitting_Frame5,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [6] = {
        .pData = sChozoStatueMultiSpriteData_Sitting_Frame6,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [7] = {
        .pData = sChozoStatueMultiSpriteData_Sitting_Frame7,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [8] = {
        .pData = sChozoStatueMultiSpriteData_Sitting_Frame8,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [9] = {
        .pData = sChozoStatueMultiSpriteData_Sitting_Frame9,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [10] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sChozoStatueMultiSpriteData_Seated[2] = {
    [0] = {
        .pData = sChozoStatueMultiSpriteData_Seated_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = MULTI_SPRITE_DATA_TERMINATOR
};

const u8 sChozoStatueFlashingPaletteRows[4] = {
    1, 2, 3, 2
};

const u32 sChozoStatueLongBeamGfx[1335] = INCBIN_U32("data/sprites/ChozoStatueLongBeam.gfx.lz");
const u16 sChozoStatueLongBeamPal[80] = INCBIN_U16("data/sprites/ChozoStatueLongBeam.pal");


static const u16 sChozoStatuePartOam_LegStanding_Frame0[16] = {
    0x5,
    0xe0, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x127d,
    0xe8, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x129e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e6, OBJ_SPRITE_OAM | 0x126a,
    0xd0, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x120b,
    0xd8, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x122a
};

static const u16 sChozoStatuePartOam_LegSitting_Frame0[16] = {
    0x5,
    0xe0, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x127d,
    0xe8, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x129e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e6, OBJ_SPRITE_OAM | 0x126a,
    0xd1, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x120b,
    0xd9, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x122a
};

static const u16 sChozoStatuePartOam_LegSitting_Frame1[16] = {
    0x5,
    0xe0, OBJ_SIZE_16x16 | 0x1e3, OBJ_SPRITE_OAM | 0x127a,
    0xe8, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x129b,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e6, OBJ_SPRITE_OAM | 0x126a,
    0xd4, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x120e,
    0xdc, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x122d
};

static const u16 sChozoStatuePartOam_LegSitting_Frame2[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xe1, 0x1e3, OBJ_SPRITE_OAM | 0x1277,
    0xe9, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x1298,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e6, OBJ_SPRITE_OAM | 0x126a,
    0xdc, OBJ_SIZE_16x16 | 0x1e7, OBJ_SPRITE_OAM | 0x1210,
    OBJ_SHAPE_VERTICAL | 0xdc, 0x1f7, OBJ_SPRITE_OAM | 0x1212
};

static const u16 sChozoStatuePartOam_LegSitting_Frame3[16] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xe2, 0x1e3, OBJ_SPRITE_OAM | 0x1277,
    0xea, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x1298,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e6, OBJ_SPRITE_OAM | 0x126a,
    0xdd, OBJ_SIZE_16x16 | 0x1e7, OBJ_SPRITE_OAM | 0x1210,
    OBJ_SHAPE_VERTICAL | 0xdd, 0x1f7, OBJ_SPRITE_OAM | 0x1212
};

static const u16 sChozoStatuePartOam_LegSitting_Frame5[13] = {
    0x4,
    0xe0, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x1275,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1f1, OBJ_SPRITE_OAM | 0x12b6,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e7, OBJ_SPRITE_OAM | 0x126a,
    OBJ_SHAPE_HORIZONTAL | 0xdd, OBJ_SIZE_32x16 | 0x1ea, OBJ_SPRITE_OAM | 0x1213
};

static const u16 sChozoStatuePartOam_LegSitting_Frame6[16] = {
    0x5,
    0xe0, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x1273,
    0xf0, 0x1f6, OBJ_SPRITE_OAM | 0x12b3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e8, OBJ_SPRITE_OAM | 0x126a,
    0xde, OBJ_SIZE_16x16 | 0x1fc, OBJ_SPRITE_OAM | 0x1217,
    0xe6, OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x1238
};

static const u16 sChozoStatuePartOam_LegSitting_Frame7[16] = {
    0x5,
    0xe1, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x1271,
    0xf1, 0x1f7, OBJ_SPRITE_OAM | 0x12b1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e7, OBJ_SPRITE_OAM | 0x126a,
    0xe3, OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x121d,
    0xeb, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x123e
};

static const u16 sChozoStatuePartOam_LegSitting_Frame8[16] = {
    0x5,
    0xe4, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x126f,
    0xf4, 0x1f4, OBJ_SPRITE_OAM | 0x12af,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e4, OBJ_SPRITE_OAM | 0x126a,
    0xe8, OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x121d,
    0xf0, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x123e
};

static const u16 sChozoStatuePartOam_LegSeated_Frame0[19] = {
    0x6,
    0xe0, 0x1fb, OBJ_SPRITE_OAM | 0x126e,
    0xe8, OBJ_SIZE_16x16 | 0x1f3, OBJ_SPRITE_OAM | 0x128d,
    0xf0, 0x1eb, OBJ_SPRITE_OAM | 0x12ac,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e2, OBJ_SPRITE_OAM | 0x126a,
    0xe9, OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x121a,
    0xf1, OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x123b
};

static const u16 sChozoStatueOam_Idle_Frame0[13] = {
    0x4,
    0xe8, OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x1200,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_SIZE_8x32 | 0x8, OBJ_SPRITE_OAM | 0x1204,
    0x8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x1282,
    0x8, 0x1f0, OBJ_SPRITE_OAM | 0x1281
};

static const u16 sChozoStatuePartOam_EyeClosing_Frame0[4] = {
    0x1,
    0xfc, 0x1fa, OBJ_SPRITE_OAM | 0x1280
};

static const u16 sChozoStatuePartOam_EyeClosing_Frame1[4] = {
    0x1,
    0xfc, 0x1fa, OBJ_SPRITE_OAM | 0x12a0
};

static const u16 sChozoStatuePartOam_EyeClosed_Frame0[4] = {
    0x1,
    0xfc, 0x1fa, OBJ_SPRITE_OAM | 0x12a1
};

static const u16 sChozoStatuePartOam_ArmIdle_Frame0[13] = {
    0x4,
    0xe6, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x1205,
    0xf6, OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x1245,
    0xf6, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x1207,
    OBJ_SHAPE_VERTICAL | 0xf6, 0x1f6, OBJ_SPRITE_OAM | 0x1209
};

static const u16 sChozoStatuePartOam_ArmGlow_Frame1[19] = {
    0x6,
    0xe6, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x1205,
    0xf6, OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x1245,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1e6, OBJ_SPRITE_OAM | 0x1300,
    0xf6, 0x1f6, OBJ_SPRITE_OAM | 0x1302,
    OBJ_SHAPE_HORIZONTAL | 0xfe, 0x1e6, OBJ_SPRITE_OAM | 0x1227,
    0xfe, 0x1f6, OBJ_SPRITE_OAM | 0x1229
};

static const u16 sChozoStatuePartOam_ArmGlow_Frame2[19] = {
    0x6,
    0xe6, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x1205,
    0xf6, OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x1245,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1e6, OBJ_SPRITE_OAM | 0x1320,
    0xf6, 0x1f6, OBJ_SPRITE_OAM | 0x1322,
    OBJ_SHAPE_HORIZONTAL | 0xfe, 0x1e6, OBJ_SPRITE_OAM | 0x1227,
    0xfe, 0x1f6, OBJ_SPRITE_OAM | 0x1229
};

static const u16 sChozoStatuePartOam_ArmGlow_Frame3[19] = {
    0x6,
    0xe6, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x1205,
    0xf6, OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x1245,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1e6, OBJ_SPRITE_OAM | 0x1303,
    0xf6, 0x1f6, OBJ_SPRITE_OAM | 0x1305,
    OBJ_SHAPE_HORIZONTAL | 0xfe, 0x1e6, OBJ_SPRITE_OAM | 0x1227,
    0xfe, 0x1f6, OBJ_SPRITE_OAM | 0x1229
};

static const u16 sChozoStatuePartOam_ArmGlow_Frame4[19] = {
    0x6,
    0xe6, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x1205,
    0xf6, OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x1245,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1e6, OBJ_SPRITE_OAM | 0x1323,
    0xf6, 0x1f6, OBJ_SPRITE_OAM | 0x1325,
    OBJ_SHAPE_HORIZONTAL | 0xfe, 0x1e6, OBJ_SPRITE_OAM | 0x1227,
    0xfe, 0x1f6, OBJ_SPRITE_OAM | 0x1229
};

static const u16 sChozoStatuePartOam_ArmSamusGrabbed_Frame0[13] = {
    0x4,
    0xe6, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x1205,
    0xf6, OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x1245,
    0xf6, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x1247,
    OBJ_SHAPE_VERTICAL | 0xf6, 0x1f6, OBJ_SPRITE_OAM | 0x1249
};

static const u16 sChozoBallOam_NormalClosed_Frame0[10] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x1307,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x7, OBJ_SPRITE_OAM | 0x1309,
    OBJ_SHAPE_HORIZONTAL | 0x7, 0x1f7, OBJ_SPRITE_OAM | 0x1310
};

static const u16 sChozoBallOam_NormalClosed_Frame1[10] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x130a,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x7, OBJ_SPRITE_OAM | 0x130c,
    OBJ_SHAPE_HORIZONTAL | 0x7, 0x1f7, OBJ_SPRITE_OAM | 0x1330
};

static const u16 sChozoBallOam_NormalClosed_Frame3[10] = {
    0x3,
    0xf7, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x130d,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x7, OBJ_SPRITE_OAM | 0x130f,
    OBJ_SHAPE_HORIZONTAL | 0x7, 0x1f7, OBJ_SPRITE_OAM | 0x1312
};

static const u16 sChozoBallOam_NormalRevealing_Frame0[16] = {
    0x5,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x1315,
    OBJ_SHAPE_VERTICAL | 0xf4, 0x4, OBJ_SPRITE_OAM | 0x1317,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1f4, OBJ_SPRITE_OAM | 0x1332,
    0x4, 0x4, OBJ_SPRITE_OAM | 0x1334,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x284
};

static const u16 sChozoBallOam_NormalRevealing_Frame1[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f4, OBJ_SPRITE_OAM | 0x1319,
    OBJ_SHAPE_VERTICAL | 0xf4, 0x4, OBJ_SPRITE_OAM | 0x131b,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x1f4, OBJ_SPRITE_OAM | 0x1318,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1fc, OBJ_SPRITE_OAM | 0x1339,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x284
};

static const u16 sChozoBallOam_NormalRevealing_Frame2[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f4, OBJ_SPRITE_OAM | 0x131d,
    OBJ_SHAPE_VERTICAL | 0xf4, 0x4, OBJ_SPRITE_OAM | 0x131f,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x1f4, OBJ_SPRITE_OAM | 0x131c,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1fc, OBJ_SPRITE_OAM | 0x133d,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x284
};

static const u16 sChozoBallOam_NormalRevealed_Frame0[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x284,
    0x8, 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

static const u16 sChozoBallOam_NormalRevealed_Frame1[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x286,
    0x8, 0x1f8, OBJ_SPRITE_OAM | 0x24c
};

static const u16 sChozoBallOam_NormalRevealed_Frame2[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x288,
    0x8, 0x1f8, OBJ_SPRITE_OAM | 0x20d
};

static const u16 sChozoStatueRefillOam_Frame0[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12cc,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12cc,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12cc,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12cc
};

static const u16 sChozoStatueRefillOam_Frame2[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12ce,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12ce,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12ce,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12ce
};

static const u16 sChozoStatueRefillOam_Frame4[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d0,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d0,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d0,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d0
};

static const u16 sChozoStatueRefillOam_Frame10[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d2,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d2,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d2,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d2
};

static const u16 sChozoStatueRefillOam_Frame12[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d4,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d4,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d4,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d4
};

static const u16 sChozoStatueRefillOam_Frame18[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d6,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d6,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d6,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d6
};

static const u16 sChozoStatueRefillOam_Frame20[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d8,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d8,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12d8,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12d8
};

static const u16 sChozoStatueRefillOam_Frame26[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12da,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12da,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12da,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12da
};

static const u16 sChozoStatueRefillOam_Frame28[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12dc,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12dc,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12dc,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12dc
};

static const u16 sChozoStatueRefillOam_Frame34[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12de,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12de,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x12de,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x12de
};

static const u16 sChozoStatuePartOam_EyeOpened_Frame0[4] = {
    0x1,
    0xfc, 0x1fa, OBJ_SPRITE_OAM | 0x1314
};

static const u16 sChozoStatuePartOam_GlowIdle_Frame0[7] = {
    0x2,
    0xf8, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x12c0
};

static const u16 sChozoStatuePartOam_GlowIdle_Frame4[13] = {
    0x4,
    0xf8, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x12e0,
    0xf7, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c1,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1f9, OBJ_SPRITE_OAM | 0x12c0
};

static const u16 sChozoStatuePartOam_GlowIdle_Frame8[19] = {
    0x6,
    0xf8, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x12c2,
    0xf7, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e1,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1f9, OBJ_SPRITE_OAM | 0x12e0,
    0xf6, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c1,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1f9, OBJ_SPRITE_OAM | 0x12c0
};

static const u16 sChozoStatuePartOam_GlowIdle_Frame12[25] = {
    0x8,
    0xf8, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x12e2,
    0xf7, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c3,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1f9, OBJ_SPRITE_OAM | 0x12c2,
    0xf5, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e1,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f9, OBJ_SPRITE_OAM | 0x12e0,
    0xf5, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c9,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f9, OBJ_SPRITE_OAM | 0x12c8
};

static const u16 sChozoStatuePartOam_GlowIdle_Frame16[31] = {
    0xa,
    0xf8, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c5,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x12c4,
    0xf7, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e3,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1f9, OBJ_SPRITE_OAM | 0x12e2,
    0xf5, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c3,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f9, OBJ_SPRITE_OAM | 0x12c2,
    0xf3, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e1,
    OBJ_SHAPE_HORIZONTAL | 0xf3, 0x1f9, OBJ_SPRITE_OAM | 0x12e0,
    0xf5, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c7,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f9, OBJ_SPRITE_OAM | 0x12c6
};

static const u16 sChozoStatuePartOam_GlowIdle_Frame20[37] = {
    0xc,
    0xf8, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e5,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x12e4,
    0xf7, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c5,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1f9, OBJ_SPRITE_OAM | 0x12c4,
    0xf5, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e3,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f9, OBJ_SPRITE_OAM | 0x12e2,
    0xf3, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c3,
    OBJ_SHAPE_HORIZONTAL | 0xf3, 0x1f9, OBJ_SPRITE_OAM | 0x12c2,
    0xf1, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e1,
    OBJ_SHAPE_HORIZONTAL | 0xf1, 0x1f9, OBJ_SPRITE_OAM | 0x12e0,
    0xf0, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e7,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1f9, OBJ_SPRITE_OAM | 0x12e6
};

static const u16 sChozoStatuePartOam_GlowIdle_Frame24[37] = {
    0xc,
    0xf8, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c5,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x12c4,
    0xf7, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e3,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1f9, OBJ_SPRITE_OAM | 0x12e2,
    0xf5, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c3,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f9, OBJ_SPRITE_OAM | 0x12c2,
    0xf3, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e1,
    OBJ_SHAPE_HORIZONTAL | 0xf3, 0x1f9, OBJ_SPRITE_OAM | 0x12e0,
    0xf1, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e7,
    OBJ_SHAPE_HORIZONTAL | 0xf1, 0x1f9, OBJ_SPRITE_OAM | 0x12e6,
    0xee, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e7,
    OBJ_SHAPE_HORIZONTAL | 0xee, 0x1f9, OBJ_SPRITE_OAM | 0x12e6
};

static const u16 sChozoStatuePartOam_GlowIdle_Frame28[31] = {
    0xa,
    0xf9, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e3,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f9, OBJ_SPRITE_OAM | 0x12e2,
    0xf7, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c3,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1f9, OBJ_SPRITE_OAM | 0x12c2,
    0xf5, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e1,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f9, OBJ_SPRITE_OAM | 0x12e0,
    0xf3, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e7,
    OBJ_SHAPE_HORIZONTAL | 0xf3, 0x1f9, OBJ_SPRITE_OAM | 0x12e6,
    0xef, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e7,
    OBJ_SHAPE_HORIZONTAL | 0xef, 0x1f9, OBJ_SPRITE_OAM | 0x12e6
};

static const u16 sChozoStatuePartOam_GlowIdle_Frame32[25] = {
    0x8,
    0xf9, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c3,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f9, OBJ_SPRITE_OAM | 0x12c2,
    0xf7, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e1,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1f9, OBJ_SPRITE_OAM | 0x12e0,
    0xf5, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e7,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f9, OBJ_SPRITE_OAM | 0x12e6,
    0xf4, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c7,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f9, OBJ_SPRITE_OAM | 0x12c6
};

static const u16 sChozoStatuePartOam_GlowIdle_Frame36[13] = {
    0x4,
    0xf8, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12e1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x12e0,
    0xf6, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x12c9,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1f9, OBJ_SPRITE_OAM | 0x12c8
};

const struct FrameData sChozoStatuePartOam_LegStanding[2] = {
    sChozoStatuePartOam_LegStanding_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sChozoStatuePartOam_LegSitting[10] = {
    sChozoStatuePartOam_LegSitting_Frame0,
    10,
    sChozoStatuePartOam_LegSitting_Frame1,
    10,
    sChozoStatuePartOam_LegSitting_Frame2,
    10,
    sChozoStatuePartOam_LegSitting_Frame3,
    5,
    sChozoStatuePartOam_LegSitting_Frame2,
    30,
    sChozoStatuePartOam_LegSitting_Frame5,
    10,
    sChozoStatuePartOam_LegSitting_Frame6,
    10,
    sChozoStatuePartOam_LegSitting_Frame7,
    10,
    sChozoStatuePartOam_LegSitting_Frame8,
    20,
    NULL,
    0x0
};

const struct FrameData sChozoStatuePartOam_LegSeated[2] = {
    sChozoStatuePartOam_LegSeated_Frame0,
    UCHAR_MAX,
    NULL,
    0x0
};

const struct FrameData sChozoStatueOam_Idle[2] = {
    sChozoStatueOam_Idle_Frame0,
    UCHAR_MAX,
    NULL,
    0x0
};

const struct FrameData sChozoStatuePartOam_EyeOpened[2] = {
    sChozoStatuePartOam_EyeOpened_Frame0,
    UCHAR_MAX,
    NULL,
    0x0
};

const struct FrameData sChozoStatuePartOam_EyeClosing[3] = {
    sChozoStatuePartOam_EyeClosing_Frame0,
    10,
    sChozoStatuePartOam_EyeClosing_Frame1,
    10,
    NULL,
    0x0
};

const struct FrameData sChozoStatuePartOam_EyeOpening[3] = {
    sChozoStatuePartOam_EyeClosing_Frame1,
    10,
    sChozoStatuePartOam_EyeClosing_Frame0,
    10,
    NULL,
    0x0
};

const struct FrameData sChozoStatuePartOam_EyeClosed[2] = {
    sChozoStatuePartOam_EyeClosed_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sChozoStatuePartOam_ArmIdle[2] = {
    sChozoStatuePartOam_ArmIdle_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sChozoStatuePartOam_ArmGlow[9] = {
    sChozoStatuePartOam_ArmIdle_Frame0,
    10,
    sChozoStatuePartOam_ArmGlow_Frame1,
    10,
    sChozoStatuePartOam_ArmGlow_Frame2,
    10,
    sChozoStatuePartOam_ArmGlow_Frame3,
    10,
    sChozoStatuePartOam_ArmGlow_Frame4,
    10,
    sChozoStatuePartOam_ArmGlow_Frame3,
    10,
    sChozoStatuePartOam_ArmGlow_Frame2,
    10,
    sChozoStatuePartOam_ArmGlow_Frame1,
    10,
    NULL,
    0x0
};

const struct FrameData sChozoStatuePartOam_ArmSamusGrabbed[2] = {
    sChozoStatuePartOam_ArmSamusGrabbed_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sChozoBallOam_NormalClosed[5] = {
    sChozoBallOam_NormalClosed_Frame0,
    0xE,
    sChozoBallOam_NormalClosed_Frame1,
    0xE,
    sChozoBallOam_NormalClosed_Frame0,
    0xE,
    sChozoBallOam_NormalClosed_Frame3,
    0xE,
    NULL,
    0x0
};

const struct FrameData sChozoBallOam_NormalRevealing[4] = {
    sChozoBallOam_NormalRevealing_Frame0,
    0x2,
    sChozoBallOam_NormalRevealing_Frame1,
    0x2,
    sChozoBallOam_NormalRevealing_Frame2,
    0x2,
    NULL,
    0x0
};

const struct FrameData sChozoBallOam_NormalRevealed[5] = {
    sChozoBallOam_NormalRevealed_Frame0,
    10,
    sChozoBallOam_NormalRevealed_Frame1,
    10,
    sChozoBallOam_NormalRevealed_Frame2,
    10,
    sChozoBallOam_NormalRevealed_Frame1,
    10,
    NULL,
    0x0
};

const struct FrameData sChozoStatueRefillOam[41] = {
    sChozoStatueRefillOam_Frame0,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOam_Frame2,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOam_Frame4,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOam_Frame2,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOam_Frame4,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOam_Frame10,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOam_Frame12,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOam_Frame10,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOam_Frame12,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOam_Frame18,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOam_Frame20,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOam_Frame18,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOam_Frame20,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOam_Frame26,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOam_Frame28,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOam_Frame26,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOam_Frame28,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOam_Frame34,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOam_Frame0,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatueRefillOam_Frame34,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    NULL,
    0x0
};

const struct FrameData sChozoStatuePartOam_GlowIdle[41] = {
    sChozoStatuePartOam_GlowIdle_Frame0,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOam_GlowIdle_Frame0,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOam_GlowIdle_Frame4,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOam_GlowIdle_Frame4,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOam_GlowIdle_Frame8,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOam_GlowIdle_Frame8,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOam_GlowIdle_Frame12,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOam_GlowIdle_Frame12,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOam_GlowIdle_Frame16,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOam_GlowIdle_Frame16,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOam_GlowIdle_Frame20,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOam_GlowIdle_Frame20,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOam_GlowIdle_Frame24,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOam_GlowIdle_Frame24,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOam_GlowIdle_Frame28,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOam_GlowIdle_Frame28,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOam_GlowIdle_Frame32,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOam_GlowIdle_Frame32,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOam_GlowIdle_Frame36,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    sChozoStatuePartOam_GlowIdle_Frame36,
    0x2,
    sChozoStatuePartOam_EyeOpened_Frame0,
    0x2,
    NULL,
    0x0
};

const u32 sChozoStatueIceBeamGfx[1335] = INCBIN_U32("data/sprites/ChozoStatueIceBeam.gfx.lz");
const u16 sChozoStatueIceBeamPal[80] = INCBIN_U16("data/sprites/ChozoStatueIceBeam.pal");

const u32 sChozoStatueWaveBeamGfx[1335] = INCBIN_U32("data/sprites/ChozoStatueWaveBeam.gfx.lz");
const u16 sChozoStatueWaveBeamPal[80] = INCBIN_U16("data/sprites/ChozoStatueWaveBeam.pal");

const u32 sChozoStatueBombsGfx[1339] = INCBIN_U32("data/sprites/ChozoStatueBomb.gfx.lz");
const u16 sChozoStatueBombsPal[80] = INCBIN_U16("data/sprites/ChozoStatueBomb.pal");

const u32 sChozoStatueSpeedboosterGfx[1342] = INCBIN_U32("data/sprites/ChozoStatueSpeedbooster.gfx.lz");
const u16 sChozoStatueSpeedboosterPal[80] = INCBIN_U16("data/sprites/ChozoStatueSpeedbooster.pal");

const u32 sChozoStatueHighJumpGfx[1372] = INCBIN_U32("data/sprites/ChozoStatueHighJump.gfx.lz");
const u16 sChozoStatueHighJumpPal[80] = INCBIN_U16("data/sprites/ChozoStatueHighJump.pal");

const u32 sChozoStatueScrewAttackGfx[1378] = INCBIN_U32("data/sprites/ChozoStatueScrewAttack.gfx.lz");
const u16 sChozoStatueScrewAttackPal[80] = INCBIN_U16("data/sprites/ChozoStatueScrewAttack.pal");

const u32 sChozoStatueVariaGfx[1348] = INCBIN_U32("data/sprites/ChozoStatueVariaSuit.gfx.lz");
const u16 sChozoStatueVariaPal[80] = INCBIN_U16("data/sprites/ChozoStatueVariaSuit.pal");
