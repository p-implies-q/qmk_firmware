// This is the personal keymap of David Janssen (@p-implies-q).

#include "atreus.h"

// Name the layers for readability

#define COLE 0
#define L    1
#define LR   2
#define R    3
#define RL   4

// * Name particular key-combos to keep the keymaps clean

// Mod-tap
#define MT_GE GUI_T(KC_ENT)     // G/E: Gui when help, enter when pressed
#define MT_CB CTL_T(KC_BSPC)    // C/B: Control when held, backspace when pressed
#define MT_ST SFT_T(KC_TAB)     // S/T: Shift when held, tab when pressed
#define MT_AE ALT_T(KC_ESC)     // A/E: Alt when held, esc when pressed

// Layer-switch-tap
#define LT_L_T  LT(L, KC_TAB)   // L/T:  Switch to left layer when held, tab when pressed
#define LS_LR MO(LR)            // toLR: Switch to left-right layer
#define LT_R_E LT(R, KC_ESC)    // R/E:  Switch to right layer when held, esc when pressed
#define LS_RL MO(RL)            // toRL: Switch to right-left

// Define my custom macros
enum custom_keycodes {
    ARRL = SAFE_RANGE

};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* COLEMAK
   *
   *   q     w     f     p     g        ||        j     l     u     y     ;
   *   a     r     s     t     d        ||        h     n     e     i     o
   *   z     x     c     v     b        ||        k     m     ,     .     /
   *  R/E   alt   gui  shift  C/B   L/T || R/E   spc  enter   -     '    L/T
   */
  [COLE] = KEYMAP (
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                       KC_H,    KC_N,    KC_E,    KC_I,    KC_O,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                       KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    LT_R_E,  KC_LALT, KC_LGUI, KC_LSFT, MT_CB,   LT_L_T,  LT_R_E,   KC_SPC,  KC_ENT,  KC_MINS, KC_QUOT, LT_L_T
  ),

  /* LEFT: Numeric
   *               [     ]              ||              7     8     9     /
   *               (     )              ||        ,     4     5     6     *
   *  SFT          {     }              ||              1     2     3     -
   *               <     >              || toLR  spc    0     .     =     +
   */
  [L] = KEYMAP (
    KC_NO,   KC_NO,   KC_LBRC, KC_RBRC, KC_NO,                      KC_NO,   KC_7,   KC_8,   KC_9,   KC_SLSH,
    KC_NO,   KC_NO,   KC_LPRN, KC_RPRN, KC_NO,                      KC_COMM, KC_4,   KC_5,   KC_6,   KC_ASTR,
    KC_LSFT, KC_NO,   KC_LCBR, KC_RCBR, KC_NO,                      KC_NO,   KC_1,   KC_2,   KC_3,   KC_MINS,
    KC_NO,   KC_NO,   KC_LT,   KC_GT,   KC_NO,   KC_NO,   LS_LR,    KC_SPC,  KC_0,   KC_DOT, KC_EQL, KC_PLUS
  ),

  /* LEFT-RIGHT: Function keys
   *                                    ||             F7    F8    F9    F10
   *                                    ||             F4    F5    F6    F11
   *                                    ||             F1    F2    F3    F12
   *                                    ||
   */
  [LR] = KEYMAP (
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_F4,   KC_F5,   KC_F6,   KC_F11,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
  ),

  /* RIGHT: Symbol keys
   *               [     ]    ->        ||        ~     &     *     =     `
   *               (     )              ||        |     $     %     ^     "
   *               {     }              ||        _     !     @     #     '
   *               <     >         toRL ||
   */
  [R] = KEYMAP (
    KC_NO,   KC_NO,   KC_LBRC, KC_RBRC, ARRL,                       KC_TILD, KC_AMPR, KC_ASTR, KC_EQL,  KC_GRV,
    KC_NO,   KC_NO,   KC_LPRN, KC_RPRN, KC_NO,                      KC_PIPE, KC_DLR,  KC_PERC, KC_CIRC, KC_DQT,
    KC_NO,   KC_NO,   KC_LCBR, KC_RCBR, KC_NO,                      KC_UNDS, KC_EXLM, KC_AT,   KC_HASH, KC_QUOT,
    KC_NO,   KC_NO,   KC_LT,   KC_GT,   KC_NO,  LS_RL,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
  ),

  /* RIGHT-LEFT: Motion keys / Media Keys
   *       pgup   up   pgdwn            ||      volup
   *       left  down  right            ||      voldw
   *                                    ||      mute
   * reset                              ||
   */
  [RL] = KEYMAP (
    KC_NO,   KC_PGDN, KC_UP,   KC_PGUP, KC_NO,                      KC_VOLU, KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,                      KC_VOLD, KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_MUTE, KC_NO,   KC_NO,   KC_NO,   KC_NO,
    RESET,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (record->event.pressed) {
    switch(keycode) {
        case ARRL:
          SEND_STRING("->");
          return false;
    }
  }

  return true;
}
