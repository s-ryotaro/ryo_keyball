//https://yakinikunotare.boo.jp/orebase2/keyboard/diy_keyboard/qmk/tap_dance/start
//https://docs.qmk.fm/features/tap_dance

// Tap Dance declarations
enum {
  TD_HOGEHOGE = 0,
  TD_PIYOPIYO
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_HOGEHOGE] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_B),
    [TD_PIYOPIYO] = ACTION_TAP_DANCE_DOUBLE(KC_C, KC_D)
};


//キーマップの部分に、このように定義する。
//TD(TD_HOGEHOGE)




const uint16_t PROGMEM combo_0[] = {KC_ESCAPE, KC_W,  COMBO_END};
const uint16_t PROGMEM test_combo1[] = {KC_W, KC_E, COMBO_END};

combo_t key_combos[] = {
    // [COMBO_F14] = COMBO(f14_combo, KC_F14),
    // [COMBO_F15] = COMBO(f15_combo, KC_F15)
    // COMBO(combo_layer_1, MO(3)),
    // COMBO(combo_layer_2, MO(3)),
    // COMBO(combo_layer_3, MO(2)),

    COMBO(combo_0, KC_TAB),
    COMBO(test_combo1, KC_TAB),
};