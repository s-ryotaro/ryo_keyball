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
    [TD_PIYOPIYO] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_D)
};


//キーマップの部分に、このように定義する。
//TD(TD_HOGEHOGE)
