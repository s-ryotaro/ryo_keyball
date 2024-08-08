/*
 *
 * 参考文献：
 * - リポジトリ：
 *   https://github.com/kamiichi99/keyball/tree/main/qmk_firmware/keyboards/keyball/keyball39/keymaps/kamidai
 *  QMK WEB
 * https://docs.qmk.fm/keycodes_basic

 * コード表：
 * - 公式ファームウェアのキーコード：
 * ▼remap ▼ ｷｰｺｰﾄﾞ
 * KB1:   KBC_RST  (0x5DA5): Keyball 設定のリセット
 * KB2:   KBC_SAVE (0x5DA6): 現在の Keyball 設定を EEPROM に保存します
 * KB3:   CPI_D100 (0x5DA8): CPI を 100 減少させます(最小:100)
 * KB4:   CPI_I1K  (0x5DA9): CPI を 1000 増加させます(最大:12000)
 * KB5:   CPI_D1K  (0x5DAA): CPI を 1000 減少させます(最小:100)
 * KB6:   SCRL_TO  (0x5DAB): タップごとにスクロールモードの ON/OFF を切り替えます
 * KB7:   SCRL_MO  (0x5DAC): キーを押している間、スクロールモードになります
 * KB8:   SCRL_DVI (0x5DAD): スクロール除数を１つ上げます(max D7 = 1/128)← 最もスクロール遅い
 * KB9:   SCRL_DVD (0x5DAE): スクロール除数を１つ下げます(min D0 = 1/1)← 最もスクロール速い
 *
 * - オリジナルのキーコード：
 *   KC_BACK_TO_LAYER0_BTN1(0x5DAF): レイヤー0に遷移できるBTN1
 *   KC_DOUBLE_CLICK_BTN1(0x5DB0): 1タップでダブルクリックできるBTN1
 *   KC_TRIPLE_CLICK_BTN1(0x5DB1): 1タップでトリプルクリックできるBTN1
 */

#include QMK_KEYBOARD_H
#include "quantum.h"

#include "utils/functions.h"
//#include "features/swipe_gesture.h"
#include "features/auto_click_layer.h"
// #include "features/back_to_layer0_btn1.h"
#include "features/one_tap_multi_click.h"
#include "features/macro_keys.h"

// 容量オーバーのため不使用（VIAをOFFにすれば、使用可能）
// #include "features/overrides.h"
#include "features/combo.h"
#include "features/tap_dance.h"
//#include "japanese_key/keymap_jp.h"


#define GUI_LEFT (LGUI(KC_LEFT))// WIN + Left Arrow
#define GUI_RIGHT (LGUI(KC_RIGHT))// WIN + Right Arrow
#define GUI_UP (LGUI(KC_UP))// WIN + Up Arrow
#define GUI_DOWN (LGUI(KC_DOWN))// WIN + Down Arrow

//ios
#define iOS_HOME (LGUI(KC_H))// COMAND + H
#define iOS_APP_SWICH (LGUI(KC_TAB))// COMAND + TAB
#define iOS_SCSHO_3 (LSG_T(kc_3))// COMAND + SFT + 3
#define iOS_SCSHO_4 (LSG_T(kc_4))// COMAND + SFT + 4


#define GUI_1 (LGUI(KC_1))
#define GUI_2 (LGUI(KC_2))
#define GUI_3 (LGUI(KC_3))
#define GUI_4 (LGUI(KC_4))
#define GUI_5 (LGUI(KC_5))
#define GUI_6 (LGUI(KC_6))
#define GUI_7 (LGUI(KC_7))
#define GUI_8 (LGUI(KC_8))
#define GUI_9 (LGUI(KC_9))


#define CTL_TAB (LCTL(KC_TAB))// ブラウザのタブ切替え→
#define CTL_SFT_TAB (LCTL(LSFT(KC_TAB)))// ブラウザのタブ切替え← 右修飾キー
#define ALT_UP (LALT(KC_UP)) // 上の階層へ

// どこでも良いので以下を記載
//https://qiita.com/toxaO/items/dc9ead660a6c4e8075c6
//#define KEYBALL_SCROLL_INV 1
// →　コンパイルエラーをGPT提案で回避「KEYBALL_SCROLL_INVの再定義を避ける」
//#ifndef KEYBALL_SCROLL_INV

//
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
  [0] = LAYOUT_universal(
    KC_ESC       , KC_W         , TD(TD_GUI_E) , KC_R         , KC_T           ,                                           KC_Y  , KC_U                , KC_I                , KC_O                 , KC_P             ,
    TD(TD_CTL_A) , LT(4,KC_S)   , TD(TD_GUI_D) , KC_F         , KC_G           ,                                           KC_H  , KC_J                , KC_K                , KC_L                 , KC_DOT           ,
    TD(TD_CTL_Z) , TD(TD_CTL_X) , TD(TD_CTL_C) , TD(TD_CTL_V) , KC_B           ,                                           LT(4,KC_N)  , KC_M                , TD(TD_BRACKETS)     , TD(TD_KANA_SYMBOLS)	, RSFT_T(KC_COMMA)  ,
    KC_LCTL      , _______      , _______      , _______      , SFT_T(KC_ENT)  , LGUI_T(KC_BSPC) ,          LT(2,KC_LNG1) , LT(1,KC_SPC) , LT(3,KC_LNG2)       , KC_RALT             , KC_RGUI              , KC_RCTL                 
  ),

  [1] = LAYOUT_universal(
    TD(TD_OTHER_Q_SYMBOLS_2) , KC_7     ,KC_8      ,KC_9      ,TD(TD_MULTI_DIVID)     ,                                                        KC_DEL , KC_F2                    , KC_UP           , KC_HOME          , KC_END             ,
    KC_DOT                   , KC_4     ,KC_5      ,KC_6      ,TD(TD_PLUS_MAINUS)     ,                                          TD(TD_OTHER_SYMBOLS) , KC_LEFT                  , KC_DOWN         , KC_RIGHT         , KC_PAGE_UP         ,
    KC_0                     , KC_1     ,KC_2      ,KC_3      ,TD(TD_EQUAL_CARET)     ,                                        TD(TD_COLON_SEMICOLON) , TD(TD_MINUS_TO_UNDUNDER) , TD(TD_FUTOUGOU) , TD(TD_QUOTATION) , RSFT_T(KC_PAGE_DOWN),
    _______                  , _______  , _______  , _______  , _______               , _______ ,                   _______ ,           _______       , _______                  , _______         , _______          , _______
  ),

  [2] = LAYOUT_universal( 
    KC_Q      , GUI_7  , GUI_8    , GUI_9     , _______   ,                            _______  , CTL_SFT_TAB , GUI_UP   , CTL_TAB  , ALT_UP  ,
    _______   , GUI_4  , GUI_5    , GUI_6     , _______   ,                            _______  , GUI_LEFT    , GUI_DOWN , GUI_RIGHT , _______  ,
    _______   , GUI_1  , GUI_2    , GUI_3     , KC_INT4   ,                            _______  , _______     , _______  , _______  , KC_LSFT  ,
    _______  , _______  , _______  , _______   , _______  , _______  ,      _______  , _______  , _______     , _______  , _______  , _______  
  ),

  [3] = LAYOUT_universal(
    SCRL_MO  , _______  , _______  , _______  ,CPI_I100  ,                            _______  , _______  , _______  , _______  , _______  ,
    SCRL_DVI , _______  , _______  , _______  ,CPI_D100  ,                            _______  , _______  , _______  , _______  , _______  ,
    SCRL_DVD , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , _______  , _______  
  ),

  [4] = LAYOUT_universal(
    _______  , _______  , iOS_HOME  , iOS_APP_SWICH  , iOS_SCSHO_3  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , iOS_SCSHO_4  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , _______  , _______  
  ),

  [5] = LAYOUT_universal(
    _______  ,KC_MS_BTN5,KC_MS_BTN4, _______  , _______  ,                            _______  , _______  ,KC_MS_BTN4,KC_MS_BTN5, _______  ,
    KC_MS_BTN3, _______ ,KC_DOUBLE_CLICK_BTN1 ,KC_MS_BTN1,KC_MS_BTN2,                KC_MS_BTN2 ,KC_MS_BTN1,KC_DOUBLE_CLICK_BTN1,KC_MS_BTN2,KC_MS_BTN3 ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , _______  , _______  
  ),
};
// clang-format on


layer_state_t layer_state_set_user(layer_state_t state) {
  // レイヤーが1または3の場合、スクロールモードが有効になる
  //keyball_set_scroll_mode(get_highest_layer(state) == 1 || get_highest_layer(state) == 3);
  keyball_set_scroll_mode(get_highest_layer(state) == 4);

  //★240808_2 stt
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    //keyball_keep_auto_mouse_layer_if_needed(state);★240808_2-1　コメントアウト化
    keyball_handle_auto_mouse_layer_change(state); //★240808_2-2
  //★240808_2　end
#endif
  return state;
}

#ifdef OLED_ENABLE

#include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
  // デバッグ用に変数を表示する
  // oled_write_P(PSTR("Debug:"), false);
  // oled_write(get_u8_str(xxx, ' '), false);

  keyball_oled_render_keyinfo();   // キー情報を表示
  keyball_oled_render_ballinfo();  // トラックボール情報を表示

  // <Layer>を表示する
  oled_write_P(PSTR("Layer:"), false);
  oled_write(get_u8_str(get_highest_layer(layer_state), ' '), false);

  // <マウス移動量 / クリックレイヤーしきい値>を表示
  // oled_write_P(PSTR(" MV:"), false);
  // oled_write(get_u8_str(mouse_movement, ' '), false);
  // oled_write_P(PSTR("/"), false);
  // oled_write(get_u8_str(to_clickable_movement, ' '), false);

  // <state>を表示
  switch (state) {
    case WAITING:
      oled_write_ln_P(PSTR("  WAITING"), false);
      break;
    case CLICKABLE:
      oled_write_ln_P(PSTR("  CLICKABLE"), false);
      break;
    case CLICKING:
      oled_write_ln_P(PSTR("  CLICKING"), false);
      break;
    case CLICKED:
      oled_write_ln_P(PSTR("  CLICKED"), false);
      break;
    /*  
    case SWIPE:
      oled_write_ln_P(PSTR("  SWIPE"), false);
      break;
    case SWIPING:
      oled_write_ln_P(PSTR("  SWIPING"), false);
      break;
    */
    case NONE:
      oled_write_ln_P(PSTR("  NONE"), false);
      break;
  }
}
#endif


/*
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
  [0] = LAYOUT_universal(
    LT(3,KC_ESCAPE), KC_W     , KC_E     , KC_R     , KC_T     ,                         KC_Y     , KC_U     , KC_I     , KC_O     , CTL_T(KC_P)     ,
    TD(TD_HOGEHOGE)     , KC_S     , TD(TD_PIYOPIYO)     , KC_F     , KC_G     ,                            KC_H     , KC_J     , KC_K     , KC_L     , KC_DOT   ,
    KC_Z     , KC_X     , KC_C     ,KC_V      ,LT(2,KC_B),                            KC_N, KC_M     ,KC_LEFT_CURLY_BRACE,KC_RIGHT_CURLY_BRACE	, KC_COMMA ,
    KC_LCTL  , _______  , _______  , _______  ,MT(1,KC_ENT),MT(mod, kc),               KC_LNG1,KC_SPC,KC_LNG2,KC_RALT,KC_RGUI,KC_LSFT
  ),

  [1] = LAYOUT_universal(
    KC_Q     ,KC_7      ,KC_8      ,KC_9      ,KC_F2     ,                           KC_DEL    ,KC_DEL    , KC_UP    ,KC_HOME    ,KC_END,
    _______  ,KC_4      ,KC_5      ,KC_6      ,KC_F4     ,                            KC_ASTR  ,KC_LEFT   , KC_DOWN  ,KC_RIGHT  ,KC_PAGE_UP ,
    KC_0     ,KC_1      ,KC_2      ,KC_3      , _______  ,                            KC_PLUS  ,KC_MINUS  ,KC_EQUAL  , _______  ,KC_PAGE_DOWN,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),





  [4] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , _______  , _______  
  ),

  */