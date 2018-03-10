#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* describe device */
#define VENDOR_ID       0x1209
#define PRODUCT_ID      0xA1E5
#define DEVICE_VER      0x0008
#define MANUFACTURER    Technomancy
#define PRODUCT         Atreus
#define DESCRIPTION     q.m.k. keyboard firmware for Atreus

/* define wiring */
#define MATRIX_ROWS 4
#define MATRIX_COLS 11
#define MATRIX_ROW_PINS { D0, D1, D3, D2 }
#define MATRIX_COL_PINS { B7, D6, F7, F6, B6, D4, E6, B4, B5, C6, D7 }
#define UNUSED_PINS
#define DIODE_DIRECTION COL2ROW

/* tweak key-detection settings */
#define DEBOUNCING_DELAY 5

/* tweak keyboard behavior */
#define TAPPING_TERM 100
#define PERMISSIVE_HOLD
#define PREVENT_STUCK_MODIFIERS
#define IGNORE_MOD_TAP_INTERRUPT

/* key combination for command */
#define IS_COMMAND() (                                                  \
     keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
 )


#endif
