/* Copyright 2026 Jake Ireland <jakewilliami@icloud.com>
 *
 * This keymap is MIT-licensed for the source code itself.
 *
 * When compiled with QMK/OpenAnnePro software, the resulting firmware
 * is subject to the GPL-2.0 license of that software.
 *
 * See also:
 *   <qmk.fm/licence>
 *   <github.com/qmk/qmk_firmware/blob/e391793f/keyboards/annepro2/annepro2.c#L1-L15>
 */

#include QMK_KEYBOARD_H

enum anne_pro_layers {
    BASE,
    FN1,
    FN2,
};

// clang-format off
// Key symbols are based on QMK. Use them to remap your keyboard
/*
* Layer BASE
* ,-----------------------------------------------------------------------------------------.
* | esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  |  w  |  f  |  p  |  b  |  j  |  l  |  u  |  y  |  ;  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* | Ctrl    |  a  |  r  |  s  |  t  |  g  |  m  |  n  |  e  |  i  |  o  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  x  |  c  |  d  |  v  |  z  |  k  |  h  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
* Layer TAP in BASE
* ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
* |-----------------------------------------------------------------------------------------+
* |         |     |     |     |     |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |            |     |     |     |     |     |     |     |     |     |     |       UP       |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |                                 |       |  LEFT | DOWN  | RIGHT |
* \-----------------------------------------------------------------------------------------/
*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [BASE] = LAYOUT_60_ansi( /* Base */
    KC_ESC,           KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6,   KC_7, KC_8, KC_9,    KC_0,             KC_MINS,          KC_EQL,        KC_BSPC,
    KC_TAB,           KC_Q,    KC_W,    KC_F, KC_P, KC_B, KC_J,   KC_L, KC_U, KC_Y,    KC_SCLN,          KC_LBRC,          KC_RBRC,       KC_BSLS,
    LT(FN1, KC_LCTL), KC_A,    KC_R,    KC_S, KC_T, KC_G, KC_M,   KC_N, KC_E, KC_I,    KC_O,             KC_QUOT,          KC_ENT,
    KC_LSFT,                   KC_X,    KC_C, KC_D, KC_V, KC_Z,   KC_K, KC_H, KC_COMM, KC_DOT,           KC_SLSH,          RSFT_T(KC_UP),
    KC_LCTL,          KC_LGUI, KC_LALT,                   KC_SPC,             KC_RALT, LT(FN1, KC_LEFT), LT(FN2, KC_DOWN), RCTL_T(KC_RGHT)
),
  /*
  * Layer FN1
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  | UP  |  f  | PS  |  b  |  j  |  l  |  u  |  y  | PGUP|HOME | END |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |LEFT |DOWN |RIGHT|  t  |  g  |  m  |  n  |  e  |  i  |  o  |PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  x  |  c  |  d  |  v  |  z  |  k  |  h  |  ,  |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
  /*
   *NOTE: x, c, and d were formerly respectively vol up, vol down, and mute.  However, these did not work, so I never
   *    got used to using them, so I have removed them from this layer.
   *
   *    Additionally, I have moved most of the FN1 layer functions to where those keys are on the new layout, for the
   *    visual queue, but I have kept the arrow pad in the Minecraft position.
   */
 [FN1] = LAYOUT_60_ansi( /* FN1 */
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    _______, _______, KC_UP,   _______, KC_PSCR, _______, _______, _______, _______, _______, KC_PGUP, KC_HOME, KC_END,  _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, KC_PGDN, _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, KC_INS,  KC_DEL,  _______,
    _______, _______, _______,                            _______,                   _______, _______, MO(FN2), _______
),
  /*
  * Layer FN2
  * ,-----------------------------------------------------------------------------------------.
  * |  ~  | BT1 | BT2 | BT3 | BT4 |  F5 |  F6 | F7 | F8 | MOD | TOG | BRI- | BRI+ |    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  | UP  |  f  | PS  |  b  |  j  |  l  |  u  |  y  | PGUP|HOME | END |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [FN2] = LAYOUT_60_ansi( /* FN2 */
    _______, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, _______, _______, _______, _______, KC_AP_RGB_MOD, KC_AP_RGB_TOG, KC_AP_RGB_VAD, KC_AP_RGB_VAI, _______,
    _______, _______,    KC_UP,      _______,    KC_PSCR,    _______, _______, _______, _______, _______,       KC_PGUP,       KC_HOME,       KC_END,        _______,
    _______, KC_LEFT,    KC_DOWN,    KC_RGHT,    _______,    _______, _______, _______, _______, _______,       _______,       KC_PGDN,       _______,
    _______,             _______,    _______,    _______,    _______, _______, _______, _______, _______,       KC_INS,        KC_DEL,        _______,
    _______, _______,    _______,                                     _______,                   _______,       _______,       _______,       _______
 ),
};
// clang-format on
