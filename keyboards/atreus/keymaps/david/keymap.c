// This is the personal keymap of David Janssen (@p-implies-q).

#include "atreus.h"

// Name the layers for readability

#define COLE 0
#define L    1
#define LL   2
#define LR   3
#define R    4
#define RL   5
#define GAME 6
#define GNUM 7
#define GFN  8

// * Name particular key-combos to keep the keymaps clean

#define ML    MO(L)              // L:     Switch to the Left layer
#define MR    MO(R)              // R:     Switch to the Right layer

// Mod-tap
#define MT_GE   GUI_T(KC_ENT)    // G/E:   Gui when help, enter when pressed
#define MT_CB   CTL_T(KC_BSPC)   // C/B:   Control when held, backspace when pressed
#define MT_CESC CTL_T(KC_ESC)    // C/esc: Control when held, escape when pressed
#define MT_ST   SFT_T(KC_TAB)    // S/T:   Shift when held, tab when pressed
#define MT_AE   ALT_T(KC_ESC)    // A/E:   Alt when held, esc when pressed

// Layer-switch-tap
#define LT_L_T  LT(L, KC_TAB)    // L/T:   Switch to left layer when held, tab when pressed
#define LS_LR   MO(LR)           // toLR:  Switch to left-right layer
#define LT_R_E  LT(R, KC_ESC)    // R/E:   Switch to right layer when held, esc when pressed
#define LS_RL   MO(RL)           // toRL:  Switch to right-left
#define GN_SPC  LT(GNUM, KC_SPC) // G#/S:  Activate gaming num overlay, space when pressed
#define GF_RET  LT(GFN, KC_ENT)  // GF/Rt: Activate gaming Fkey overlay, ret when pressed

// Modified keys
#define M_P     LALT(KC_P)       // M-p:   Alt-p
#define M_N     LALT(KC_N)       // M-n:   Alt-n
#define M_PERC  LALT(KC_PERC)    // M-%:   Alt-%

// Syntactic sugar
#define _       KC_NO

// Define my custom macros
/* #define CX      SS_LCTL("x")    // C-x, used in defining emacs macros */
#define CX(C)      SEND_STRING(SS_LCTRL("x")C)

enum custom_keycodes {
  // Haskell operators
  LARR = SAFE_RANGE,   // ->
  RARR,                // <-
  FARR,                // =>
  BIND,                // >>=
  FMAP,                // <$>
  APP,                 // <*>
  RAPP,                // *>
  LAPP,                // <*
  ALTV,                // <|>

  // Emacs shortcuts
  CXO,                 // C-x o
  CX0,                 // C-x 0
  CX1,                 // C-x 1
  CX2,                 // C-x 2
  CX3,                 // C-x 3
  CXB,                 // C-x b

};

/* Template:
 *   .     .     .     .     .         ||          .     .     .     .     .
 *   .     .     .     .     .         ||          .     .     .     .     .
 *   .     .     .     .     .         ||          .     .     .     .     .
 *   .     .     .     .     .         ||          .     .     .     .     .
 *   .     .     .     .     .     .   ||   .      .     .     .     .     .
 */

/*
[] = LAYOUT (
  _,       _,      _,       _,       _,                          _,       _,       _,       _,       _,
  _,       _,      _,       _,       _,                          _,       _,       _,       _,       _,
  _,       _,      _,       _,       _,                          _,       _,       _,       _,       _,
  _,       _,      _,       _,       _,       _,       _,        _,       _,       _,       _,       _,
  ),
*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* COLEMAK
   *
   *   q     w     f     p     g         ||        j     l     u     y     ;
   *   a     r     s     t     d         ||        h     n     e     i     o
   *   z     x     c     v     b         ||        k     m     ,    dot    /
   *  tab   alt    R   shift  ctl    L   ||   esc spc   gui    -   bkspc  ret
   */
  [COLE] = LAYOUT (
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                       KC_H,    KC_N,    KC_E,    KC_I,    KC_O,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                       KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    KC_TAB,  KC_LALT, MO(R),   KC_LSFT, KC_LCTL, ML,      KC_ESC,   KC_SPC,  KC_LGUI, KC_MINS, KC_BSPC, KC_ENT
  ),

  /* LEFT: Symbol / Numeric
   *   .     `     ~     [     ]         ||        .     7     8     9     /
   * shift   "     _     (     )         ||        .     4     5     6     *
   *  ctl    '     |     {     }         ||        =     1     2     3     -
   *   .     .     .     <     >     .   || toLR  spc    0     .    dot    +
   */
  [L] = LAYOUT (
    _,       KC_GRV,  KC_TILD, KC_LBRC, KC_RBRC,                    _,       KC_7,    KC_8,    KC_9,    KC_SLSH,
    MO(LL),  KC_DQT,  KC_UNDS, KC_LPRN, KC_RPRN,                    _,       KC_4,    KC_5,    KC_6,    KC_ASTR,
    KC_LCTL, KC_QUOT, KC_PIPE, KC_LCBR, KC_RCBR,                    KC_EQL,  KC_1,    KC_2,    KC_3,    KC_MINS,
    _,       _,       _,       KC_LT,   KC_GT,   _,       LS_LR,    KC_SPC,  KC_0,    _,       KC_DOT,  KC_PLUS
  ),

  /* LEFT-LEFT: Secondary symbols
  *    .    ->    <$>   <|>    .       ||        .     &     *     =     .
  *    .    <-    <*>    .     .       ||        .     $     %     ^     .
  *    .    =>     *>    .     .       ||        .     !     @     #     .
  *    .   >>=    <*     .     .  toRL ||  .     .     .     .     .     .
  */
  [LL] = LAYOUT (
    _,       RARR,    FMAP,    ALTV,    _,                          _,       KC_AMPR, KC_ASTR, KC_EQL,  _,
    _,       LARR,    APP,     _,       _,                          _,       KC_DLR,  KC_PERC, KC_CIRC, _,
    _,       FARR,    RAPP,    _,       _,                          _,       KC_EXLM, KC_AT,   KC_HASH, _,
    _,       BIND,    LAPP,    _,       _,       _,       LS_LR,    KC_SPC,  _,       _,       _,       _
  ),


  /* LEFT-RIGHT: Function keys
   * reset   .     .     .     .        ||             F7    F8    F9    F10
   * game    .     .     .     .        ||             F4    F5    F6    F11
   *   .     .     .     .     .        ||             F1    F2    F3    F12
   *   .     .     .     .     .     .  ||  .     .     .     .     .     .
   */
  [LR] = LAYOUT (
    RESET,   _,       _,       _,       _,                          _,       KC_F7,   KC_F8,   KC_F9,   KC_F10,
    DF(GAME),_,       _,       _,       _,                          _,       KC_F4,   KC_F5,   KC_F6,   KC_F11,
    _,       _,       _,       _,       _,                          _,       KC_F1,   KC_F2,   KC_F3,   KC_F12,
    _,       _,       _,       _,       _,      _,       _,         _,       _,       _,       _,       _
  ),

  /* RIGHT: Arrow and media keys
   *   .     .     .     .   volup       ||          .   pgup   up   pgdwn   .
   *   .     .     .     .   voldn       ||          .   left  down  right   .
   *   .     .     .     .   mute        ||          .     .     .     .     .
   *   .     .     .     .     .         ||          .     .     .     .     .
   *   .     .     .     .     .     .   ||   .      .     .     .     .     .
   */

  [R] = LAYOUT (
    _,       _,      _,       _,       KC_VOLU,                    _,       KC_PGDN, KC_UP,   KC_PGUP, _,
    _,       _,      _,       _,       KC_VOLD,                    _,       KC_LEFT, KC_DOWN, KC_RGHT, _,
    _,       _,      _,       _,       KC_MUTE,                    _,       _,       _,       _,       _,
    _,       _,      _,       _,       _,       _,       _,        _,       _,       _,       _,       _
  ),



  /* RIGHT-LEFT: Motion keys / Media Keys
   *   .   pgup   up   pgdwn   .        ||      volup   .     .     .   game
   *   .   left  down  right   .        ||      voldw   .     .     .     .
   *   .     .     .     .     .        ||      mute    .     .     .     .
   * reset   .     .     .     .     .  ||  .     .     .     .     .     .
   */
  [RL] = LAYOUT (
    _,       KC_PGDN, KC_UP,   KC_PGUP, _,                          KC_VOLU, _,       _,       _,       DF(GAME),
    _,       KC_LEFT, KC_DOWN, KC_RGHT, _,                          KC_VOLD, _,       _,       _,       _,
    _,       _,       _,       _,       _,                          KC_MUTE, _,       _,       _,       _,
    RESET,   _,       _,       _,       _,      _,       _,         _,       _,       _,       _,       _
  ),

  /* Gaming base
   *
   *  esc    q     w     e     r        ||        .     .     .     .   cole
   *  ctl    a     s     d     f        ||        .     .     .     .     .
   * shift   z     x     c     v        ||        .     .     .     .     .
   *  tab   alt    m   GF/Rt  G#/S   .  ||  .     .     .     .     .     .
   */
  [GAME] = LAYOUT (
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,                       _,       _,       _,       _,       DF(COLE),
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,                       _,       _,       _,       _,       _,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,                       _,       _,       _,       _,       _,
    KC_TAB,  KC_LALT, KC_M,    GF_RET,  GN_SPC,  _,       _,        _,       _,       _,       _,       _
  ),

  /* Gaming num
   *
   *   .     7     8     9     0        ||        .     .     .     .     .
   *   .     4     5     6     .        ||        .     .     .     .     .
   *   .     1     2     3     .        ||        .     .     .     .     .
   *   .     .     .     .     .     .  ||  .     .     .     .     .     .
   */
  [GNUM] = LAYOUT (
    _,       KC_7,    KC_8,    KC_9,    KC_0,                       _,       _,       _,       _,       _,
    _,       KC_4,    KC_5,    KC_6,    _,                          _,       _,       _,       _,       _,
    _,       KC_1,    KC_2,    KC_3,    _,                          _,       _,       _,       _,       _,
    _,       _,       _,       _,       _,       _,       _,        _,       _,       _,       _,       _
  ),

  /* Gaming fnum
   *
   *   .    f7    f8    f9     .        ||        .     .     .     .     .
   *   .    f4    f5    f6     .        ||        .     .     .     .     .
   *   .    f1    f2    f3     .        ||        .     .     .     .     .
   *   .     .     .     .     .     .  ||  .     .     .     .     .     .
   */
  [GFN] = LAYOUT (
    _,       KC_F7,   KC_F8,   KC_F9,   _,                          _,       _,       _,       _,       _,
    _,       KC_F4,   KC_F5,   KC_F6,   _,                          _,       _,       _,       _,       _,
    _,       KC_F1,   KC_F2,   KC_F3,   _,                          _,       _,       _,       _,       _,
    _,       _,       _,       _,       _,       _,       _,        _,       _,       _,       _,       _
  )





};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (record->event.pressed) {
    switch(keycode) {

    // Haskell operators
    case RARR:
      SEND_STRING("->");
      return false;

    case LARR:
      SEND_STRING("<-");
      return false;

    case FARR:
      SEND_STRING("=>");
      return false;

    case BIND:
      SEND_STRING(">>=");
      return false;

    case FMAP:
      SEND_STRING("<$>");
      return false;

    case APP:
      SEND_STRING("<*>");
      return false;

    case LAPP:
      SEND_STRING("<*");
      return false;

    case RAPP:
      SEND_STRING("*>");
      return false;

    case ALTV:
      SEND_STRING("<|>");
      return false;

    // Emacs Shortcuts
    case CXO:
      CX("o");
      return false;

    case CX0:
      CX("0");
      return false;

    case CX1:
      CX("1");
      return false;

    case CX2:
      CX("2");
      return false;

    case CX3:
      CX("3");
      return false;

    case CXB:
      CX("b");
      return false;
    }
  }

  return true;
}
