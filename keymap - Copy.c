 #include QMK_KEYBOARD_H

#define _QWERTY 0
#define _COLEMAK 1
#define _LAYER2 2
#define _LAYER3 3
#define _ADJUST 4
#define _GAME 5

#define LT2B = LT(_LAYER2, KC_BSPC);
#define LT3S = LT(_LAYER3, KC_SPC);
#define bigBrac ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR);
#define midBrac ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC);
#define smallBrac ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN);
#define quote ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO);


enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    LAYER2,
    LAYER3,
    ADJUST,
    GAME,
    ALT_TAB,
};

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_QWERTY] = LAYOUT_preonic_1x2uC(
    KC_GESC,        KC_1,       KC_2,        KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSPC,
    KC_TAB,         KC_Q,       KC_W,        KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_DEL,
    CTL_T(KC_BSPC), KC_A,       KC_S,        KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_ENT,
    OSM(MOD_LSFT),  KC_Z,       KC_X,        KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_UP,
    CTL_T(KC_CAPS), KC_LALT,    KC_LGUI,  OSM(MOD_LSFT), LT2B,          SFT_T(KC_SPC),       LT3S,       KC_LALT,    KC_LEFT,    KC_RGHT,    KC_DOWN
 ),

 [_COLEMAK] = LAYOUT_preonic_1x2uC(
    KC_TRNS,        KC_1,       KC_2,        KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_TRNS,
    KC_TRNS,        KC_Q,       KC_W,        KC_F,       KC_P,       KC_B,       KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,    KC_TRNS,
    KC_TRNS,        KC_A,       KC_R,        KC_S,       KC_T,       KC_G,       KC_M,       KC_N,       KC_E,       KC_I,       KC_O,       KC_TRNS,
    KC_TRNS,        KC_Z,       KC_X,        KC_C,       KC_D,       KC_V,       KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_TRNS,
    KC_TRNS,        KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,      SFT_T(KC_SPC),     LT(3, KC_SPC), KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
 ),

[_LAYER2] = LAYOUT_preonic_1x2uC(
    KC_MUTE,        KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_VOLD,    KC_VOLU,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_LPRN,    KC_RPRN,    KC_CALC,
    ALT_TAB,        KC_TRNS,    C(KC_W),    KC_EQL,     KC_PPLS,    KC_PAST,    C(KC_Y),  S(KC_MINS),   KC_LPRN,    KC_RPRN,    KC_BSLS,    C(KC_DEL),
    C(KC_BSPC),     C(KC_A),    C(KC_S),    KC_0,       KC_MINS,    KC_SLSH,    KC_TRNS,    KC_LCBR,    KC_LBRC,    KC_RBRC,    KC_RCBR,    KC_QUOT,
    KC_TRNS,        C(KC_Z),    C(KC_X),    C(KC_C),    C(KC_V),    KC_EXLM,    KC_PIPE,    KC_AMPR,    KC_LT,      KC_GT,      KC_QUES,    KC_PGUP,
    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,            KC_SPC,     KC_TRNS,    KC_HOME,    KC_END,     KC_PGDN
 ),

[_LAYER3] = LAYOUT_preonic_1x2uC(
    KC_F11,         KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F12,
    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_HOME,    C(KC_LEFT), KC_UP,      C(KC_RGHT), KC_END,    C(KC_BSPC),
    C(KC_BSPC),     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F11,     KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_TRNS,    KC_DQUO,
    KC_TRNS,        KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F12,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_BSPC,          KC_TRNS,        KC_TRNS,    KC_TRNS,    MO(_ADJUST),   TG(_COLEMAK), TG(_GAME)
 ),

[_ADJUST] = LAYOUT_preonic_1x2uC(
    MU_TOG,         MEH(KC_1),  MEH(KC_2),  MEH(KC_3),  MEH(KC_4),  MEH(KC_5),  MEH(KC_6),  MEH(KC_7),  MEH(KC_8),  MEH(KC_9),  MEH(KC_0),  DEBUG,
    AU_TOG,         KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_SYSTEM_SLEEP,
    MU_MOD,         KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    RGB_TOG,    RGB_MOD,    RGB_HUI,    RGB_SAI,    RGB_VAI,    RGB_SPI,
    RESET,          KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    RGB_RMOD,   RGB_HUD,    RGB_SAD,    RGB_VAD,    RGB_SPD,
    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
 ),

[_GAME] = LAYOUT_preonic_1x2uC(
    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_KP_0,    KC_TRNS,
    KC_TRNS,        KC_Q,       KC_W,       KC_E,        KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_TRNS,
    KC_LSFT,        KC_A,       KC_S,       KC_D,        KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_ENT,
    KC_LCTL,        KC_Z,       KC_X,       KC_C,        KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_TRNS,
    KC_LCTL,        KC_M,       KC_CAPS,    KC_LALT,     KC_SPC,        KC_SPC,              KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
 ),

};


// LED physical location index
//     6 5 4 3
//        0
//     7 8 1 2

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 4, HSV_WHITE}       // starting 3, #4
);
const rgblight_segment_t PROGMEM left_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {5, 4, HSV_CYAN}
);
const rgblight_segment_t PROGMEM right_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 4, HSV_RED}
);
const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, 2, HSV_GREEN}
);
const rgblight_segment_t PROGMEM game_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, HSV_MAGENTA}
);
const rgblight_segment_t PROGMEM colemak_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {7, 2, HSV_PINK},
    {1, 2, HSV_PINK}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    colemak_layer,
    game_layer,
    my_capslock_layer,
    left_layer,
    right_layer,
    adjust_layer

);
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(2, led_state.caps_lock);
    return true;
}

//layer_state_t default_layer_state_set_user(layer_state_t state) {
//    rgblight_set_layer_state(1, layer_state_cmp(state, _DVORAK));
//    return state;
//}
bool is_alt_tab_active = false; // ADD this near the begining of keymap.c

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(3, layer_state_cmp(state, _LAYER2));
    rgblight_set_layer_state(4, layer_state_cmp(state, _LAYER3));
    rgblight_set_layer_state(5, layer_state_cmp(state, _ADJUST));
    rgblight_set_layer_state(1, layer_state_cmp(state, _GAME));
    rgblight_set_layer_state(0, layer_state_cmp(state, _COLEMAK));

    if (is_alt_tab_active) {
        unregister_code(KC_LALT);
        is_alt_tab_active = false;
    }
    return state;
}

//void update_swapper(
//    bool *active,
//    uint16_t cmdish,
//    uint16_t tabish,
//    uint16_t trigger,
//    uint16_t keycode,
//    keyrecord_t *record
//) {
//    if (keycode == trigger) {
//        if (record->event.pressed) {
//            if (!*active) {
//                *active = true;
//                register_code(cmdish);
//            }
//            register_code(tabish);
//        } else {
//            unregister_code(tabish);
//            // Don't unregister cmdish until some other key is hit or released.
//        }
//    } else if (*active) {
//        unregister_code(cmdish);
//        *active = false;
//    }
//}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   //update_swapper(&is_alt_tab_active, KC_LALT, KC_TAB, ALT_TAB, keycode, record);

    switch (keycode){
        case ALT_TAB: // super alt tab macro
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;

        return false;
    }
    return true;
}
