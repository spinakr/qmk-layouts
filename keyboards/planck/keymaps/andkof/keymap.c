/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif


#define SftEnt SFT_T(KC_ENT)   // Shift when held, Enter when tapped
#define BSCTL  LCTL_T(KC_BSPC) // Ctrl when held, Backspace when tapped
#define CTAB   LCTL(KC_TAB)
#define ATAB   LALT(KC_TAB)
#define CMDTAB   LGUI(KC_TAB)
#define SS LSG(KC_4)

//aliases for Navigation layer
#define WDBSPC LALT(KC_BSPC)  // delete whole word
#define C_CL   LCTL(KC_LEFT) // move cursor one word back
#define C_CR   LCTL(KC_RGHT) // move cursor one word forward
#define CUT   LCMD(KC_X)
#define COPY   LCMD(KC_C)
#define PASTE   LCMD(KC_V)
#define UNDO   LCMD(KC_Z)
#define REDO   LSG(KC_Z)
#define CMDW   LCMD(KC_W)
#define CMDT   LCMD(KC_T)
#define CMDA   LCMD(KC_A)
#define CMDS   LCMD(KC_S)
#define CMDC   LCMD(KC_C)
#define CMDV   LCMD(KC_V)
#define CMDZ   LCMD(KC_Z)
#define CMDF   LCMD(KC_F)


#define G_GRV   LGUI(KC_GRV)
#define SftEnt  SFT_T(KC_ENT)

//Norwegian letters, EurKeys layout
#define AA   LALT(KC_W)
#define AE   LALT(KC_Q)
#define OE   LALT(KC_L)

#define SftSpc LSFT_T(KC_SPC)
// Left-hand home row mods
#define SYM_S LT(_RIGHTSYM,KC_S)
#define NAV_T LT(_NAV,KC_T)
#define ALT_C LALT_T(KC_C)
#define CTL_X LCTL_T(KC_X)
#define SFT_A LSFT_T(KC_A)
#define CMD_D CMD_T(KC_D)


// Right-hand home row mods
#define NUM_E LT(_NUM,KC_E)
#define SYM_N LT(_LEFTSYM,KC_N)
#define ALT_E LALT_T(KC_E)
#define CTL_I RCTL_T(KC_I)
#define SFT_O RSFT_T(KC_O)
#define CMD_H CMD_T(KC_H)

enum planck_layers {
    _COLEMAK,
    _RTHUMB,
    _LEFTTHUMB,    
    _ALW
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  BACKLIT,
  EXT_PLV
};

#define LSPACE LT(_LEFTTHUMB,KC_SPACE)
#define RBSPC LT(_RTHUMB, KC_BSPC) 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,   _______, _______, KC_J,   KC_L,    KC_U,    KC_Y,    KC_MINS,
    SFT_A,   KC_R,    KC_S,    KC_T,    KC_G,   _______, _______, KC_M,   KC_N,    KC_E,    KC_I,    SFT_O, 
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,   _______, _______, KC_K,   KC_H,    KC_COMM, KC_DOT,  KC_SLSH, 
    _______, _______, _______, KC_MEH,  LSPACE, _______, _______, RBSPC,  KC_LCMD, _______, _______,   _______
),

[_LEFTTHUMB] = LAYOUT_planck_grid(
    KC_EXLM ,  KC_AT , KC_HASH, KC_DLR , KC_PERC,  _______, _______, KC_ESC,_______ ,_______ , _______ , QK_BOOT,
    KC_CIRC ,  AE    , OE   ,    AA    , KC_PIPE,  _______, _______, KC_TAB,KC_LEFT,KC_DOWN, KC_UP  , KC_RGHT, 
    KC_TILDE,KC_AMPR,KC_PAST,KC_BSLS   , _______,  _______, _______, KC_GRV,KC_HOME,KC_PGDN, KC_PGUP, KC_END, 
    _______, _______, _______, _______,  _______,  _______, _______, _______,  _______, _______, _______,   _______
),

[_RTHUMB] = LAYOUT_planck_grid(
    KC_PAST ,  KC_7  ,  KC_8  ,  KC_9  ,KC_PLUS ,   _______, _______, KC_RBRC ,KC_RPRN ,KC_RCBR ,KC_QUOT , KC_MINS,
    KC_PSLS ,  KC_4  ,  KC_5  ,  KC_6  ,KC_MINS ,   _______, _______, KC_LBRC , KC_LPRN,KC_LCBR , KC_DQT , KC_UNDS, 
    KC_COMM ,  KC_1 ,   KC_2  ,  KC_3  ,KC_EQL  ,   _______, _______, KC_COLN , KC_SCLN, KC_LT  , KC_GT  , KC_QUES, 
    _______, _______, _______ ,  KC_0, KC_ENT   ,   _______, _______, _______,  _______, _______, _______,   _______
),

};

