/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define KC_CTSC RCTL_T(KC_SCLN)
#define KC_CTLA LCTL_T(KC_A)
#define KC_LSHZ LSFT_T(KC_Z)
#define KC_RLSH RSFT_T(KC_SLSH)
#define KC_GUTA GUI_T(KC_TAB)
#define KC_CLGV CTL_T(KC_GRV)
#define ALT_Z LALT_T(KC_Z)

#define G_GRV   LGUI(KC_GRV)
#define SftEnt  SFT_T(KC_ENT)

//Norwegian letters, EurKeys layout
#define AA   LALT(KC_W)
#define AE   LALT(KC_Q)
#define OE   LALT(KC_L)

#define SFT_A LSFT_T(KC_A)
#define SFT_O RSFT_T(KC_O)


#define SftSpc LSFT_T(KC_SPC)

#define LSPACE LT(_LEFTTHUMB,KC_SPACE)
#define FUNCBSPC LT(_FUNC, KC_BSPC) 
#define RBSPC LT(_RTHUMB, KC_BSPC) 
#define MEHSPTL MEH_T(LCMD(KC_SPC))
#define CTRLGRV LCTL_T(KC_GRV)
#define LTAB LT(_RTHUMB, KC_TAB) 


enum crkbd_layers {
    _COLEMAK,
    _RTHUMB,
    _LEFTTHUMB,    
    _FUNC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC ,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_MINS, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LTAB   ,    SFT_A,    KC_R,    KC_S,    KC_T,   KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,  SFT_O, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CTRLGRV,    ALT_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                  KC_MEH  ,KC_LCMD, LSPACE,                     RBSPC,FUNCBSPC, _______
                                      //`--------------------------'  `--------------------------'

  ),

    [_LEFTTHUMB] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_EXLM ,  KC_AT , KC_HASH, KC_DLR , KC_PERC,                     _______,_______ ,_______ , _______ , _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_CIRC ,  AE    , OE   ,    AA    , KC_PIPE,                     _______,KC_LEFT,KC_DOWN, KC_UP  , KC_RGHT, _______, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_TILDE, KC_AMPR,KC_PAST,KC_BSLS  ,_______,                      _______,KC_HOME,KC_PGDN, KC_PGUP, KC_END, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     _______, _______  , _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_RTHUMB] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______, KC_PAST ,  KC_7  ,  KC_8  ,  KC_9  ,KC_PLUS ,                      KC_RBRC ,KC_RPRN ,KC_RCBR ,KC_QUOT , KC_MINS, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_PSLS ,  KC_4  ,  KC_5  ,  KC_6  ,KC_MINS ,                      KC_LBRC , KC_LPRN,KC_LCBR , KC_DQT , KC_UNDS,  _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_COMM ,  KC_1 ,   KC_2  ,  KC_3  ,KC_EQL  ,                      KC_COLN , KC_SCLN, KC_LT  , KC_GT  , KC_QUES, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, KC_0,  KC_ENT,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
    [_FUNC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______, _______ ,  KC_F7  ,  KC_F8  ,  KC_F9  ,    KC_F12 ,                      _______ ,_______ ,_______ ,_______ , _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______ ,  KC_F4  ,  KC_F5  ,  KC_F6  ,    KC_F11 ,                      _______ , _______,_______ , _______ , _______,  _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______ ,  KC_F1 ,   KC_F2  ,  KC_F3  ,    KC_F10  ,                      _______ , _______, _______  , _______  , _______, QK_BOOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};