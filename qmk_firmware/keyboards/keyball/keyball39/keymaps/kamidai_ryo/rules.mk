#RGBLIGHT_ENABLE = yes

OLED_ENABLE = yes

VIA_ENABLE = yes

EXTRAKEY_ENABLE = yes


### 使っていないもの
### 以下はメモリ不足のため、VIAをOFFにする必要がある
# KEY_OVERRIDE_ENABLE = yes
COMBO_ENABLE = yes
# AUTO_SHIFT_ENABLE = yes

# ファームウェアのサイズを削減
EXTRAFLAGS += -flto
GRAVE_ESC_ENABLE = no  # 90バイト

###https://zenn.dev/koron/articles/98324ab760e83a
LTO_ENABLE = yes

CONSOLE_ENABLE = no

COMMAND_ENABLE = no

SPACE_CADET_ENABLE = no

MOUSEKEY_ENABLE = no

MAGIC_ENABLE = no