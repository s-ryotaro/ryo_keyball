//https://yakinikunotare.boo.jp/orebase2/keyboard/diy_keyboard/qmk/tap_dance/start
//https://docs.qmk.fm/features/tap_dance

/*
#include "quantum_keycodes.h"

// Define missing keycodes if not already defined
#ifndef KC_RBRC
#define KC_RBRC 0x1E  // Example value for right bracket key
#endif

#ifndef KC_BSLS
#define KC_BSLS 0x2B  // Example value for backslash key
#endif
*/

// Tap Dance declarations
enum tap_dance{
  TD_GUI_D,
  TD_GUI_E,

  TD_CTL_A,
  TD_CTL_Z,
  TD_CTL_X,
  TD_CTL_C,
  TD_CTL_V,

  TD_MINUS_TO_UNDUNDER,   //レイヤ2

  //記号 計算
  TD_PLUS_MAINUS,         //レイヤ2
  TD_MULTI_DIVID,         //レイヤ2
  TD_EQUAL_CARET,         //レイヤ2
  
  
  //記号 その他
  TD_COLON_SEMICOLON,     //レイヤ2
  TD_FUTOUGOU,            //レイヤ2
  TD_QUOTATION,           //レイヤ2

  //▼3回以上タップ
  TD_BRACKETS,            //レイヤ1
  TD_KANA_SYMBOLS,        //レイヤ1
  TD_OTHER_SYMBOLS,       //レイヤ2
  TD_OTHER_Q_SYMBOLS_2,   //レイヤ2
};


//▼3回以上タップの関数
//TD_BRACKETSの関数*******************************
void send_tap_code_with_left_arrow(uint16_t keycode) {
    tap_code16(keycode);
    tap_code(KC_LEFT);
}

void dance_brackets_finished(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            // ※ひらがな入力時「」, []
            send_tap_code_with_left_arrow(KC_BSLS);  // 「
            send_tap_code_with_left_arrow(KC_RBRC);  // 」
            break;
        case 2:
            // （）
            send_tap_code_with_left_arrow(S(KC_8));
            send_tap_code_with_left_arrow(S(KC_9));
            break;
        case 3:
            // {}
            send_tap_code_with_left_arrow(S(KC_BSLS));  
            send_tap_code_with_left_arrow(S(KC_RBRC));
            break;
    }
    reset_tap_dance(state);
}
//TD_BRACKETSの関数 ここまで

//TD_KANA_SYMBOLSの関数*******************************
void dance_kana_symbols_finished(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code16(KC_QUES);  // "？"
            break;
        case 2:
            tap_code16(KC_EXLM);  // "！"
            break;
        case 3:
            tap_code16(S(KC_EQL));  // "～"※ひらがな入力時
            break;
    }
    reset_tap_dance(state);
}
//TD_ TD_SYMBOLSの関数　ここまで

//TD_OTHER_SYMBOLSの関数*******************************
void dance_other_symbols_finished(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code16(KC_LBRC);   // "@"
            break;
        case 2:
            tap_code16(KC_PERC);  // "%"
            break;
        case 3:
            tap_code16(KC_INT3);  // "￥"
            break;
        case 4:
            tap_code16(KC_HASH);  // "#"
            break;
        case 5:
            tap_code16(S(KC_7));  // "&"
            break;
        case 6:
            tap_code16(S(KC_4));  // "$"
            break;
    }
    reset_tap_dance(state);
}
//TD_OTHER_SYMBOLSの関数　ここまで*


//TD_TD_OTHER_SYMBOLS_2の関数*******************************
void dance_other_Q_symbols_2_finished(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:   // 1回タップで（Q）
            tap_code(KC_Q);
            break;
        case 2:   // 2回タップで中点（・）※ひらがな入力時
            tap_code(KC_SLSH);
            break;
        case 3:   // 3回タップで縦棒（｜）   
            tap_code16(S(KC_INT3));
            break;
        case 4:    // 4回タップで「\」  
            tap_code(KC_INT1);
            break;
    }
    reset_tap_dance(state);
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    //マクロ
    [TD_GUI_E] = ACTION_TAP_DANCE_DOUBLE(KC_E,LGUI(KC_E)),
    [TD_GUI_D] = ACTION_TAP_DANCE_DOUBLE(KC_D,LGUI(KC_D)),

    [TD_CTL_A] = ACTION_TAP_DANCE_DOUBLE(KC_A,LCTL(KC_A)),
    [TD_CTL_Z] = ACTION_TAP_DANCE_DOUBLE(KC_Z,LCTL(KC_Z)),
    [TD_CTL_X] = ACTION_TAP_DANCE_DOUBLE(KC_X,LCTL(KC_X)),
    [TD_CTL_C] = ACTION_TAP_DANCE_DOUBLE(KC_C,LCTL(KC_C)),
    [TD_CTL_V] = ACTION_TAP_DANCE_DOUBLE(KC_V,LCTL(KC_V)),
    
    [TD_MINUS_TO_UNDUNDER] = ACTION_TAP_DANCE_DOUBLE(KC_MINUS,S(KC_INT1)),

    //記号 計算
    [TD_PLUS_MAINUS]= ACTION_TAP_DANCE_DOUBLE(S(KC_SCLN),KC_MINS),         //  +  -    LSFT(KC_EQL)
    [TD_MULTI_DIVID]= ACTION_TAP_DANCE_DOUBLE(S(KC_QUOT),KC_SLSH),         //  *  /
    [TD_EQUAL_CARET]= ACTION_TAP_DANCE_DOUBLE(S(KC_MINS),KC_EQL),          //  =  ^    (KC_EQL,LSFT(KC_6)), 
    
    //記号 その他
    [TD_COLON_SEMICOLON]= ACTION_TAP_DANCE_DOUBLE(KC_QUOT,KC_SCLN),        //  :  ;
    [TD_FUTOUGOU]= ACTION_TAP_DANCE_DOUBLE(S(KC_COMM),S(KC_DOT)),          //  <  >
    [TD_QUOTATION]= ACTION_TAP_DANCE_DOUBLE(S(KC_7),S(KC_2)),              //  '  "

    //▼3回以上タップ
    [TD_BRACKETS] = ACTION_TAP_DANCE_FN(dance_brackets_finished),
    [TD_KANA_SYMBOLS] = ACTION_TAP_DANCE_FN(dance_kana_symbols_finished),
    [TD_OTHER_SYMBOLS] = ACTION_TAP_DANCE_FN(dance_other_symbols_finished),
    [TD_OTHER_Q_SYMBOLS_2] = ACTION_TAP_DANCE_FN(dance_other_Q_symbols_2_finished),

};


//キーマップの部分に、このように定義する。
//TD(TD_HOGEHOGE)
