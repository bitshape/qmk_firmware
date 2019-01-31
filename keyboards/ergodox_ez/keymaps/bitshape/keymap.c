#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD
};

// Tap dance declarations
enum {
  TD_RBRACKET = 0,
  TD_LBRACKET,
  TD_MINUSEQL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc/` |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   - =  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  Cmd |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           | Space|------+------+------+------+------+--------|
 * |  Ctrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   |    '   |
 * |--------+------+------+------+------+------|  MO1 |           | Alt  |------+------+------+------+------+--------|
 * | Shift (|   Z  |   X  |   C  |   V  |   B  |      |           | Space|   N  |   M  |   ,  |   .  |  /   | Shift )|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      | Alt  |  Cmd | Left | Right|                                       | Down |  Up  |  [{  |  ]}  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |  Del |      |       | CmdK |   Alt  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | Space|Bcksp |------|       |------|  Cmd   | Enter|
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_GESC,          KC_1,    KC_2,    KC_3,     KC_4,        KC_5,      KC_TRNS,
  KC_TAB,           KC_Q,    KC_W,    KC_E,     KC_R,        KC_T,      TG(1),
  KC_LCTRL,         KC_A,    KC_S,    KC_D,     KC_F,        KC_G,
  KC_LSPO,          KC_Z,    KC_X,    KC_C,     KC_V,        KC_B,      MO(1),
  KC_TRNS,          KC_LALT, KC_LGUI, KC_LEFT,  KC_RIGHT,
                                                             KC_DELETE, KC_TRNS,
                                                                        KC_TRNS,
                                                KC_SPC,      KC_BSPC,   KC_TRNS,
  // right hand
  KC_TRNS,          KC_6,    KC_7,    KC_8,     KC_9,            KC_0,            TD(TD_MINUSEQL),
  LGUI(KC_SPACE),   KC_Y,    KC_U,    KC_I,     KC_O,            KC_P,            KC_BSLASH,
                    KC_H,    KC_J,    KC_K,     KC_L,            KC_SCOLON,       KC_QUOTE,
  LALT(KC_SPACE),   KC_N,    KC_M,    KC_COMMA, KC_DOT,          KC_SLASH,        KC_RSPC,
                             KC_DOWN, KC_UP,    TD(TD_LBRACKET), TD(TD_RBRACKET), KC_TRNS,
  LGUI(KC_K),       KC_LALT,
  KC_TRNS,
  KC_TRNS,          KC_LGUI, KC_ENTER
),
/* Keymap 1: Symbol layer
*
* ,--------------------------------------------------.           ,--------------------------------------------------.
* |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |        |
* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
* |        |      | PgUp |      |      |      |      |           |      |      |      |      |      |      |        |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |        | Home | PgDn |  End |      |      |------|           |------| Left | Down |  Up  | Right|      |        |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
*   |      |      |      | Prev | Next |                                       |VolDwn|VolUp | Mute |      |      |
*   `----------------------------------'                                       `----------------------------------'
*                                        ,-------------.       ,---------------.
*                                        |      |      |       |      |        |
*                                 ,------|------|------|       |------+--------+------.
*                                 |      |      |      |       |      |        |      |
*                                 |      |      |------|       |------|        |      |
*                                 |      |      |      |       |      |        |      |
*                                 `--------------------'       `----------------------'
*/
[SYMB] = LAYOUT_ergodox(
  // left hand
  KC_TRANSPARENT, KC_F1,          KC_F2,             KC_F3,               KC_F4,               KC_F5,          KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_PGUP,           KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_HOME,        KC_PGDOWN,         KC_END,              KC_TRANSPARENT,      KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,    KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,    KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK,
                                                                                               KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                               KC_TRANSPARENT,
                                                                          KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT,
  // right hand
  KC_TRANSPARENT, KC_F6,          KC_F7,             KC_F8,               KC_F9,               KC_F10,         KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,    KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT,
                  KC_LEFT,        KC_DOWN,           KC_UP,               KC_RIGHT,      KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,    KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT,
                                  KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP,     KC_AUDIO_MUTE,       KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT,KC_TRANSPARENT),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_RBRACKET] = ACTION_TAP_DANCE_DOUBLE(KC_RBRACKET, LSFT(KC_RBRACKET)),
  [TD_LBRACKET] = ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, LSFT(KC_LBRACKET)),
  [TD_MINUSEQL] = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_EQUAL)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
