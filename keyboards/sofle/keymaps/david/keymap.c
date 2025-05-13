// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _COLEMAK,
    _ACCENTS,
    _NUM,
    _LOWER,
    _RAISE,
    _ADJUST,
    _QWERTY,
};

enum custom_keycodes {
    KC_PRVWD = QK_USER,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    INV_QUES,
    INV_EXCLM,
};

enum unicode_name {
    A_ACUTE,
    E_ACUTE,
    I_ACUTE,
    O_ACUTE,
    U_ACUTE,
    A_ACUTE_CAP,
    E_ACUTE_CAP,
    I_ACUTE_CAP,
    O_ACUTE_CAP,
    U_ACUTE_CAP,
    N_TILDE,
    N_TILDE_CAP
};

const uint32_t PROGMEM unicode_map[] = {
    [A_ACUTE] = 0x00E1, // á
    [E_ACUTE] = 0x00E9, // é
    [I_ACUTE] = 0x00ED, // í
    [O_ACUTE] = 0x00F3, // ó
    [U_ACUTE] = 0x00FA, // ú
    [A_ACUTE_CAP] = 0x00C1, // Á
    [E_ACUTE_CAP] = 0x00C9, // É
    [I_ACUTE_CAP] = 0x00CD, // Í
    [O_ACUTE_CAP] = 0x00D3, // Ó
    [U_ACUTE_CAP] = 0x00DA,  // Ú
    [N_TILDE]      = 0x00F1, // ñ
    [N_TILDE_CAP]  = 0x00D1  // Ñ
};

#define KC_COLEMAK PDF(_COLEMAK)
#define KC_QWERTY PDF(_QWERTY)

#define A_ACUTE_KEY UP(A_ACUTE, A_ACUTE_CAP)
#define E_ACUTE_KEY UP(E_ACUTE, E_ACUTE_CAP)
#define I_ACUTE_KEY UP(I_ACUTE, I_ACUTE_CAP)
#define O_ACUTE_KEY UP(O_ACUTE, O_ACUTE_CAP)
#define U_ACUTE_KEY UP(U_ACUTE, U_ACUTE_CAP)
#define N_TILDE_KEY UP(N_TILDE, N_TILDE_CAP)

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_COLEMAK] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_NUM] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_ACCENTS] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_QWERTY] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_LOWER] = { ENCODER_CCW_CW(UG_VALD, UG_VALU),  ENCODER_CCW_CW(UG_HUED, UG_HUEU)  },
    [_RAISE] = { ENCODER_CCW_CW(UG_SATD, UG_SATU),  ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [_ADJUST] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
* COLEMAK
* ,-----------------------------------------.                    ,-----------------------------------------.
* |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   -  |
* |------+------+------+------+------+------|                    |------+------+------+------+------+------|
* | ESC  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
* |------+------+------+------+------+------|                    |------+------+------+------+------+------|
* | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
* |------+------+------+------+------+------|  PLAY |    | MUTE  |------+------+------+------+------+------|
* |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
* `-----------------------------------------/       /     \      \-----------------------------------------'
*            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Space \  |Enter | RCTR | RAlt | RGUI |
*            |      |      |      |      |/ACCENTS/         \      \ |RAISE |      |      |      |
*            `----------------------------------'           '------''---------------------------'
*/
[_COLEMAK] = LAYOUT(
    KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
    HYPR_T(KC_ESC),   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_BSPC,
    LT(_NUM, KC_TAB),  KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,    KC_E,    KC_I,    KC_O,  KC_QUOT,
            KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MPLY,    KC_MUTE, KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
        KC_LGUI, KC_LALT, KC_LCTL, TL_LOWR, LT(_ACCENTS, KC_SPC),              KC_SPC, LT(TL_UPPR, KC_ENT), KC_RCTL, KC_RALT, KC_RGUI
),
/*
* ACCENTS
* ,-----------------------------------------.                    ,-----------------------------------------.
* |      |      |      |      |      |      |                    |      |      |      |      |      |      |
* |------+------+------+------+------+------|                    |------+------+------+------+------+------|
* |      |      |      |      |      |      |                    |      |      |   ú  |      |      | Bspc |
* |------+------+------+------+------+------|                    |------+------+------+------+------+------|
* | TAB  |   á  |      |      |LShift|      |-------.    ,-------|      |   ñ  |   é  |   í  |   ó  |  '   |
* |------+------+------+------+------+------|  PLAY |    | MUTE  |------+------+------+------+------+------|
* |LShift|      |      |      |      |      |-------|    |-------|      |      |      |      |      |RShift|
* `-----------------------------------------/       /     \      \-----------------------------------------'
*            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
*            |      |      |      |      |/       /         \      \ |      |      |      |      |
*            `----------------------------------'           '------''---------------------------'
*/
[_ACCENTS] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, U_ACUTE_KEY, _______, _______, _______,
    KC_TAB, A_ACUTE_KEY, _______, _______, KC_LSFT, _______,                _______, N_TILDE_KEY, E_ACUTE_KEY, I_ACUTE_KEY, O_ACUTE_KEY,  KC_QUOT,
    KC_LSFT, _______, _______, _______, _______ , _______, _______,      _______, _______, _______, _______, _______, _______, KC_RSFT,
                    KC_LGUI,KC_LALT,KC_LCTL,TL_LOWR, KC_ENT,                KC_SPC,  TL_UPPR, KC_RCTL, KC_RALT, KC_RGUI
),
/*
* NUM
* ,-----------------------------------------.                    ,-----------------------------------------.
* |      |      |      |      |      |      |                    |      |      |      |      |      |      |
* |------+------+------+------+------+------|                    |------+------+------+------+------+------|
* |      |      |      |      |      |      |                    |   -  |   7  |   8  |   9  |   .  | Bspc |
* |------+------+------+------+------+------|                    |------+------+------+------+------+------|
* | TAB  |      |      |      |LShift|      |-------.    ,-------|   +  |   4  |   5  |   6  |   0  |   ^  |
* |------+------+------+------+------+------|  PLAY |    | MUTE  |------+------+------+------+------+------|
* |LShift|      |      |      |      |      |-------|    |-------|   *  |   1  |   2  |   3  |   /  |   ,  |
* `-----------------------------------------/       /     \      \-----------------------------------------'
*            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |LLOCK | RCTR | RAlt | RGUI |
*            |      |      |      |      |/       /         \      \ |      |      |      |      |
*            `----------------------------------'           '------''---------------------------'
*/
[_NUM] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                        KC_SLSH, _______, _______, _______, KC_PLUS, _______,
    _______, _______, _______, _______, QK_LLCK, _______,                        KC_MINS,    KC_7,    KC_8,    KC_9,  KC_DOT, KC_BSPC,
    LT(_NUM, KC_TAB), _______, _______, _______, KC_LSFT, _______,               KC_PLUS,    KC_4,    KC_5,    KC_6,    KC_0, KC_CIRC,
    KC_LSFT, _______, _______, _______, _______, _______, _______,      _______, KC_ASTR,    KC_1,    KC_2,    KC_3, KC_SLSH, KC_COMM,
                KC_LGUI,KC_LALT,KC_LCTL,TL_LOWR, KC_ENT,                    KC_SPC,  TL_UPPR, KC_RCTL, KC_RALT, KC_RGUI
),
/* LOWER
 * ,----------------------------------------.                      ,-----------------------------------------.
 * |      |      |      |      |      |      |                     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu | LLCK | Caps |                     |  PUP | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift| MEH  | HYPR |-------.     ,-------|  PDW | Left | Down | Rigth|  Del | LLCK |
 * |------+------+------+------+------+------|  MUTE |     |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|     |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /      \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /        \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /          \      \ |      |      |      |      |
 *            `----------------------------------'             '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                       _______,  _______  , _______,  _______ ,  _______ ,_______,
  _______,  KC_INS,  KC_PSCR,   KC_APP,  QK_LLCK, KC_CAPS,                        QK_LLCK, KC_PRVWD,   KC_UP, KC_NXTWD,C(KC_BSPC), KC_BSPC,
  _______, KC_LALT,  KC_LCTL,  KC_LSFT,  KC_MEH, KC_HYPR,                        XXXXXXX,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, QK_LLCK,
  _______, KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX,  _______,       _______,  XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND,   XXXXXXX, _______,
                    KC_LGUI,KC_LALT,KC_LCTL,TL_LOWR, KC_ENT,                 KC_SPC,  TL_UPPR, KC_RCTL, KC_RALT, KC_RGUI
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LLOCK|   #  |   @  |   +  |   (  |  )   |                    |   -  |   "  |   |  |   $  |  ;   | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   ¿  |   ?  |   =  |   [  |  ]   |-------.    ,-------|   +  |   '  |   _  |   ~  |   :  |   ^  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|   ¡  |   !  |   -  |   {  |   }  |-------|    |-------|   *  |   `  |   &  |   %  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
    KC_F1,   KC_F2,     KC_F3,   KC_F4,   KC_F5,   KC_F6,                             KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
    QK_LLCK, KC_HASH,   KC_AT, KC_PLUS, KC_LPRN, KC_RPRN,                           KC_MINS, KC_DQUO, KC_PIPE,  KC_DLR, KC_SCLN, KC_BSPC,
    _______, INV_QUES, KC_QUES, KC_EQL, KC_LBRC, KC_RBRC,                           KC_PLUS, KC_QUOT, KC_UNDS, KC_TILD, KC_COLN, KC_CIRC,
    _______, INV_EXCLM, KC_EXLM, KC_MINS, KC_LCBR, KC_RCBR, _______,       _______, KC_ASTR,  KC_GRV, KC_AMPR, KC_PERC, KC_BSLS, _______,
                    _______, _______, _______, _______, KC_ENT,            KC_SPC, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      | RGB  |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | BOOT |      |QWERTY|COLEMA| LLCK |      |                    |      |  VAL |  SAT | HUE  | BRIU |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      | Shift|      |-------.    ,-------|      | VOLDO| MUTE | VOLUP| BRID |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_ADJUST] = LAYOUT(
  XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, UG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  QK_BOOT , XXXXXXX, KC_QWERTY, KC_COLEMAK, QK_LLCK,XXXXXXX,                     XXXXXXX, UG_VALU, UG_SATU, UG_HUEU, KC_BRIU, XXXXXXX,
  XXXXXXX , XXXXXXX, CG_TOGG, XXXXXXX,    KC_LSFT,  XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, KC_BRID, XXXXXXX,
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                   KC_LGUI,KC_LALT,KC_LCTL,TL_LOWR, KC_ENT,                    KC_SPC,  TL_UPPR, KC_RCTL, KC_RALT, KC_RGUI
),
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  PLAY |    | MUTE  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_QWERTY] = LAYOUT(
    KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
    KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
    KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MPLY,    KC_MUTE,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                   KC_LGUI,KC_LALT,KC_LCTL, TL_LOWR, KC_ENT,      KC_SPC,  TL_UPPR, KC_RCTL, KC_RALT, KC_RGUI
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case INV_QUES:
            send_unicode_string("¿");
            return false;
        case INV_EXCLM:
            send_unicode_string("¡");
            return false;
    }
    return true;
}


layer_state_t layer_state_set_user(layer_state_t state) {
    // Obtener saturación y valor actuales
    uint8_t current_sat = rgblight_get_sat();
    uint8_t current_val = rgblight_get_val();
    uint8_t new_hue = 0;

    switch (get_highest_layer(state)) {        
        case _COLEMAK:
            new_hue = 250;  // white
            break;
        case _NUM:
            new_hue = 128;  // cyan
            break;
        case _ACCENTS:
            new_hue = 85;   // green
            break;
        case _LOWER:
            new_hue = 32;   // orange (rojo + un poco de amarillo)
            break;
        case _RAISE:
            new_hue = 192;  // purple
            break;
        case _ADJUST:
            new_hue = 0;    // red
            break;
        case _QWERTY:
            new_hue = 0;    // sin color (o usa sat = 0)
            current_sat = 0;
            break;
        default:
            return state;
    }

    rgblight_sethsv_noeeprom(new_hue, current_sat, current_val);
    return state;
}


#ifdef OLED_ENABLE

// --- Logo para la pantalla OLED del lado no maestro ---
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 
        0x00
    };
    oled_write_P(qmk_logo, false);
}

// --- Inicializa rotación del OLED ---
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return is_keyboard_master() ? rotation : OLED_ROTATION_180;
}

// --- Renderizado de capa y LEDs ---
bool render_status(void) {
    // Capa activa
    oled_write_P(PSTR("David\n Key \n \n =] \n \n"), false);
    oled_write_P(PSTR("Layer:\n"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
            oled_write_ln_P(PSTR("Col\n"), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("Num\n"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("Raise\n"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adjus\n"), false);
            break;
        case _ACCENTS:
            oled_write_ln_P(PSTR("Accen\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef\n"), false);
    }

    // Mostrar solo estado de Caps Lock
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);

    // Mostrar si hay un Layer Lock activo (QK_LLCK)
    // Este ejemplo asume que tienes bloqueable el layer _FN
    bool any_locked = false;
    uint8_t locked_layers[] = {_NUM, _LOWER, _RAISE, _ADJUST};

    for (int i = 0; i < sizeof(locked_layers)/sizeof(locked_layers[0]); i++) {
        if (is_layer_locked(locked_layers[i])) {
            any_locked = true;
            break;
        }
    }

    if (any_locked) {
        oled_write_ln_P(PSTR("LOCK "), false);
    }

    return false;
}

// --- Tarea principal del OLED ---
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        return render_status();  // <- Asegúrate de definir esta función
    } else {
        render_logo();
        oled_scroll_left();  // Esto activa el scroll animado (si quieres que parpadee)
        return false;
    }
}

#endif