#ifndef GLOBALS_H
#define GLOBALS_H

#include "callbacks.h"
#include "types.h"

extern u8 softreset_disabled;
extern u16 game_mode;
extern u16 button_input;
extern u16 button_input_old;
extern u16 buttons_changed;
extern void *sp_sys;
extern void *sp_irq;
extern void *intr_vector; // TODO: proper type
extern u16 intr_code[0x100];
extern u16 (*intr_code_ptr)[0x100];
extern i8 cleared_every_frame;
extern u16 vblank_request_flag;
extern u16 unk_03007ff8;
extern callback_t vblank_callback;
extern callback_t hblank_callback;
extern callback_t vcount_callback;
extern callback_t serial_callback;
extern callback_t timer3_callback;

#endif /* GLOBALS_H */
