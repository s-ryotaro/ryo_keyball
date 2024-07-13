/* 
 * コード表：
 * - 公式ファームウェアのキーコード：
 *   KBC_RST(0x5DA5): Keyball 設定のリセット
 *   KBC_SAVE(0x5DA6): 現在の Keyball 設定を EEPROM に保存します
 *   CPI_I100(0x5DA7): CPI を 100 増加させます(最大:12000)
 *   CPI_D100(0x5DA8): CPI を 100 減少させます(最小:100)
 *   CPI_I1K(0x5DA9): CPI を 1000 増加させます(最大:12000)
 *   CPI_D1K(0x5DAA): CPI を 1000 減少させます(最小:100)
 *   SCRL_TO(0x5DAB): タップごとにスクロールモードの ON/OFF を切り替えます
 *   SCRL_MO(0x5DAC): キーを押している間、スクロールモードになります
 *   SCRL_DVI(0x5DAD): スクロール除数を１つ上げます(max D7 = 1/128)← 最もスクロール遅い
 *   SCRL_DVD(0x5DAE): スクロール除数を１つ下げます(min D0 = 1/1)← 最もスクロール速い
 */

enum custom_keycodes {
  KC_BACK_TO_LAYER0_BTN1 = KEYBALL_SAFE_RANGE,  // (0x5DAF): レイヤー0に遷移できるBTN1
  KC_DOUBLE_CLICK_BTN1,                         // (0x5DB0): 1タップでダブルクリックできるBTN1
  KC_TRIPLE_CLICK_BTN1,                         // (0x5DB1): 1タップでトリプルクリックできるBTN1
  SFT_T_G_KC_A,                                 // (0x5DB2):
  SFT_T_S_KC_SCOLON,                            // (0x5DB3):
  
   //COMBO_BRC,                                    // (0x5DB5):
  //COMBO_select_BRC,                             // (0x5DB5):
  //COMBO_S9_S0,                                  // (0x5DB5):
  //COMBO_select_S9_S0,                           // (0x5DB5):
  //COMBO_S_BRC,                                  // (0x5DB5):
  //COMBO_select_S_BRC,                           // (0x5DB5):
  //COMBO_sumitsuki_BRC,                          // (0x5DB5):
  //COMBO_select_sumitsuki_BRC,                   // (0x5DB5):
  //COMBO_MINUS_SPACE,                            // (0x5DB5):
  // CUSTOM_LT1_LEFT,                                    //
  // CUSTOM_LT1_LEFT,                                    //
  // CUSTOM_S9,                                    //
  // CUSTOM_S0,                                    //
  // KC_ALT_BTN1,                                  //
  // select_BRC,
  // CMD_SCRL,
};

// マクロキーの処理を行う関数
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  current_keycode = keycode;             // 押下されたキーコードを保存する
  bool mod_pressed = (get_mods() != 0);  // 修飾キーが押されているかを判定（0でなければ修飾キーが押されている）

  //static bool is_gui_active = false;　240710不要箇所削除に伴い不要
  //static bool is_ctrl_active = false;

  //static bool is_kana = false;  // レイヤー1の状態を追跡する変数

  switch (keycode) {
    // デフォルトのマウスキーを自動クリックレイヤーで使用可能にする
    case KC_MS_BTN1:
    case KC_MS_BTN2:
    case KC_MS_BTN3:
    case KC_MS_BTN4:
    case KC_MS_BTN5: {
      if (click_layer && get_highest_layer(layer_state) == click_layer) {
        if (record->event.pressed) {
          // キーダウン時: 状態をCLICKINGに設定
          state = CLICKING;
        } else {
          // キーアップ時: クリックレイヤーを有効にして、状態をCLICKEDに設定
          enable_click_layer();
          state = CLICKED;
        }
      }
      return true;
    }

    // 以下のキーは自動クリックレイヤーで使用可能にする
    case KC_LALT:
    case KC_LSFT: {
      return true;
    }



  // コンボ
  /*
    case CMB_ESCAPE:
  
      if (record->event.pressed) {
        if (keycode == CMB_ESCAPE) {
          tap_code(KC_ESCAPE);  // ESCAPEを送信
        }      
      return false;
    
      // コンボ
    case COMBO_BRC:
  
      if (record->event.pressed) {
        // 選択バージョン
        if (keycode == COMBO_select_BRC || keycode == COMBO_select_S9_S0 || keycode == COMBO_select_S_BRC || keycode == COMBO_select_sumitsuki_BRC) {
          tap_code16(G(KC_X));  // カット
        }

        // if (keycode == COMBO_BRC || keycode == COMBO_S9_S0 || keycode == COMBO_S_BRC || keycode == COMBO_sumitsuki_BRC) {
        if (keycode == COMBO_BRC || keycode == COMBO_select_BRC) {
          tap_code(KC_LBRC);  // 「　を送信
          tap_code(KC_RBRC);  //  」 を送信
        
      }
      return false;
    */

    // 以下スワイプジェスチャー
    // クリックすると state が SWIPE になり、離したら NONE になる
    case CMD_T(KC_SPACE):
    case SFT_T(KC_LNG2):
    case ALT_T(KC_F13): {
      if (record->event.pressed) {
        // キーダウン時
        state = SWIPE;
      } else {
        // キーアップ時
        clear_mods();           // すべての修飾キーの状態をクリアする
        disable_click_layer();  // クリックレイヤーを無効化する
      }

      // 複数の修飾キーが押された場合、LEDをオフにし、スワイプ状態を解除する
      if (mod_pressed) {
        //rgblight_sethsv(HSV_OFF);
        state = NONE;
        return true;  // キーのデフォルトの動作を続行させる
      }

      // スワイプが行われた場合、スワイプフラグをリセット
      if (is_swiped) {
        is_swiped = false;
        return false;  // キーのデフォルトの動作をスキップする
      }

      // スワイプが行われていなかった場合、キーのデフォルトの動作を続行させる
      if (!is_swiped) {
        return true;
      }
    }
     
    // その他のキーコードの場合
    default:
      if (record->event.pressed) {
        // キーダウン時
        disable_click_layer();  // クリックレイヤーを無効化
      }
  }
  return true;
}