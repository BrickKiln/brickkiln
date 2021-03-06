// BrickKiln Layout. More thumbs. More palms. More Convenience.

#include "planck.h"
#include "action_layer.h"
#include "config.h"
#include "version.h"


extern keymap_config_t keymap_config;

// Naming layers for readability
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _NAV 3
#define _ADJUST 16

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER = LT(_LOWER, KC_BSPC),
  RAISE = LT(_RAISE, KC_ENT),
  NAV,
  BACKLIT
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift(|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |)Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Nav | Ctrl | Alt  | GUI  | Bksp |    Space    | Enter| Spot |LSpace|RSpace|  Nav |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC},
  {MO(_NAV), KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC,  KC_SPC, RAISE, LGUI(KC_SPC), LCTL(KC_LEFT), LCTL(KC_RGHT),   MO(_NAV)}
},

 /* Lower
  * ,-----------------------------------------------------------------------------------.
  * |   ~  |      |      |      |   [  |   +  |   -  |   ]  |      |      |      | Bksp |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Del  |   !  |   @  |   #  |   $  |   %  |   ^  |   =  |   &  |   _  |   \  |  |   |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |      |      |   {  |   *  |   /  |   }  |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |             |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
[_LOWER] = {
  {KC_TILD, _______, _______, _______, KC_LBRC, KC_PLUS, KC_MINS, KC_RBRC, _______, _______, _______, KC_BSPC},
  {KC_DEL,  KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC,  KC_EQL, KC_AMPR, KC_UNDS, KC_BSLS, KC_PIPE},
  {_______, _______, _______, _______, KC_LCBR, KC_ASTR, KC_SLSH, KC_RCBR, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},


 /* Raise
  * ,-----------------------------------------------------------------------------------.
  * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Bksp |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Del  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |  F11 |  F12 |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19 |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |             |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
[_RAISE] = {
  {KC_GRV,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_BSPC},
  {KC_DEL,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______},
  {_______,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Navigation Layer
 * ,-----------------------------------------------------------------------------------.
 * |      |      | LWord|  Up  | RWord| Prev | Next | LWord|  Up  | RWord| PgUp |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | Left | Down | Right| Vol- | Vol+ | Left | Down | Right| PgDn |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      | Enter| Mute | Play | Bksp |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = {
 {_______, KC_PGUP, LALT(KC_LEFT), KC_UP, LALT(KC_RGHT), KC_MPRV, KC_MNXT, LALT(KC_LEFT), KC_UP, LALT(KC_RGHT), KC_PGUP, _______},
 {_______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_VOLU, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______},
 {_______, _______, _______, _______, KC_ENT, KC_MUTE, KC_MPLY, KC_BSPC, _______, _______, _______, _______},
 {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |Brite |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, BACKLIT},
  {_______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
          breathing_speed_set(2);
          breathing_pulse();
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      //return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        breathing_speed_set(2);
        breathing_pulse();
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      //return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
  }
  return true;
}
