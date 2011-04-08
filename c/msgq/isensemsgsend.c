#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
typedef enum E_OLSP_EventKeyTag
{
    E_OLSP_EVENT_KEY_NONE = -1,
    E_OLSP_EVENT_KEY_ALL = 0,
    
    /* Event keys list for keyboard device */
    E_OLSP_EVENT_KEY_KEYBOARD_ESCAPE,
    E_OLSP_EVENT_KEY_KEYBOARD_LEFT,
    E_OLSP_EVENT_KEY_KEYBOARD_RIGHT,
    E_OLSP_EVENT_KEY_KEYBOARD_UP,
    E_OLSP_EVENT_KEY_KEYBOARD_DOWN,
    E_OLSP_EVENT_KEY_KEYBOARD_TAB,
    E_OLSP_EVENT_KEY_KEYBOARD_ENTER,
    E_OLSP_EVENT_KEY_KEYBOARD_SPACE,
    E_OLSP_EVENT_KEY_KEYBOARD_BACKSPACE,
    E_OLSP_EVENT_KEY_KEYBOARD_INSERT,
    E_OLSP_EVENT_KEY_KEYBOARD_DELETE,
    E_OLSP_EVENT_KEY_KEYBOARD_HOME,
    E_OLSP_EVENT_KEY_KEYBOARD_END,
    E_OLSP_EVENT_KEY_KEYBOARD_PAGE_UP,
    E_OLSP_EVENT_KEY_KEYBOARD_PAGE_DOWN,
    E_OLSP_EVENT_KEY_KEYBOARD_PRINT_SCREEN,
    E_OLSP_EVENT_KEY_KEYBOARD_PAUSE,
    E_OLSP_EVENT_KEY_KEYBOARD_QUOTE_LEFT,
    E_OLSP_EVENT_KEY_KEYBOARD_MINUS_SIGN,
    E_OLSP_EVENT_KEY_KEYBOARD_EQUALS_SIGN,
    E_OLSP_EVENT_KEY_KEYBOARD_BRACKET_LEFT,
    E_OLSP_EVENT_KEY_KEYBOARD_BRACKET_RIGHT,
    E_OLSP_EVENT_KEY_KEYBOARD_BACKSLASH,
    E_OLSP_EVENT_KEY_KEYBOARD_SEMICOLON,
    E_OLSP_EVENT_KEY_KEYBOARD_QUOTE_RIGHT,
    E_OLSP_EVENT_KEY_KEYBOARD_COMMA,
    E_OLSP_EVENT_KEY_KEYBOARD_PERIOD,
    E_OLSP_EVENT_KEY_KEYBOARD_SLASH,
    E_OLSP_EVENT_KEY_KEYBOARD_CAPS_LOCK,
    E_OLSP_EVENT_KEY_KEYBOARD_NUM_LOCK,
    E_OLSP_EVENT_KEY_KEYBOARD_SCROLL_LOCK,
    E_OLSP_EVENT_KEY_KEYBOARD_SHIFT_LEFT,
    E_OLSP_EVENT_KEY_KEYBOARD_SHIFT_RIGHT,
    E_OLSP_EVENT_KEY_KEYBOARD_CONTROL_LEFT,
    E_OLSP_EVENT_KEY_KEYBOARD_CONTROL_RIGHT,
    E_OLSP_EVENT_KEY_KEYBOARD_ALT_LEFT,
    E_OLSP_EVENT_KEY_KEYBOARD_ALT_RIGHT,
    E_OLSP_EVENT_KEY_KEYBOARD_F1,
    E_OLSP_EVENT_KEY_KEYBOARD_F2,
    E_OLSP_EVENT_KEY_KEYBOARD_F3,
    E_OLSP_EVENT_KEY_KEYBOARD_F4,
    E_OLSP_EVENT_KEY_KEYBOARD_F5,
    E_OLSP_EVENT_KEY_KEYBOARD_F6,
    E_OLSP_EVENT_KEY_KEYBOARD_F7,
    E_OLSP_EVENT_KEY_KEYBOARD_F8,
    E_OLSP_EVENT_KEY_KEYBOARD_F9,
    E_OLSP_EVENT_KEY_KEYBOARD_F10,
    E_OLSP_EVENT_KEY_KEYBOARD_F11,
    E_OLSP_EVENT_KEY_KEYBOARD_F12,
    E_OLSP_EVENT_KEY_KEYBOARD_0,
    E_OLSP_EVENT_KEY_KEYBOARD_1,
    E_OLSP_EVENT_KEY_KEYBOARD_2,
    E_OLSP_EVENT_KEY_KEYBOARD_3,
    E_OLSP_EVENT_KEY_KEYBOARD_4,
    E_OLSP_EVENT_KEY_KEYBOARD_5,
    E_OLSP_EVENT_KEY_KEYBOARD_6,
    E_OLSP_EVENT_KEY_KEYBOARD_7,
    E_OLSP_EVENT_KEY_KEYBOARD_8,
    E_OLSP_EVENT_KEY_KEYBOARD_9,
    E_OLSP_EVENT_KEY_KEYBOARD_A,
    E_OLSP_EVENT_KEY_KEYBOARD_B,
    E_OLSP_EVENT_KEY_KEYBOARD_C,
    E_OLSP_EVENT_KEY_KEYBOARD_D,
    E_OLSP_EVENT_KEY_KEYBOARD_E,
    E_OLSP_EVENT_KEY_KEYBOARD_F,
    E_OLSP_EVENT_KEY_KEYBOARD_G,
    E_OLSP_EVENT_KEY_KEYBOARD_H,
    E_OLSP_EVENT_KEY_KEYBOARD_I,
    E_OLSP_EVENT_KEY_KEYBOARD_J,
    E_OLSP_EVENT_KEY_KEYBOARD_K,
    E_OLSP_EVENT_KEY_KEYBOARD_L,
    E_OLSP_EVENT_KEY_KEYBOARD_M,
    E_OLSP_EVENT_KEY_KEYBOARD_N,
    E_OLSP_EVENT_KEY_KEYBOARD_O,
    E_OLSP_EVENT_KEY_KEYBOARD_P,
    E_OLSP_EVENT_KEY_KEYBOARD_Q,
    E_OLSP_EVENT_KEY_KEYBOARD_R,
    E_OLSP_EVENT_KEY_KEYBOARD_S,
    E_OLSP_EVENT_KEY_KEYBOARD_T,
    E_OLSP_EVENT_KEY_KEYBOARD_U,
    E_OLSP_EVENT_KEY_KEYBOARD_V,
    E_OLSP_EVENT_KEY_KEYBOARD_W,
    E_OLSP_EVENT_KEY_KEYBOARD_X,
    E_OLSP_EVENT_KEY_KEYBOARD_Y,
    E_OLSP_EVENT_KEY_KEYBOARD_Z,
    E_OLSP_EVENT_KEY_KEYBOARD_ALL,

    /* Event keys list for mouse device */
    E_OLSP_EVENT_KEY_MOUSE_LEFT,
    E_OLSP_EVENT_KEY_MOUSE_RIGHT,
    E_OLSP_EVENT_KEY_MOUSE_CENTRE,
    E_OLSP_EVENT_KEY_MOUSE_WHEEL_UP,
    E_OLSP_EVENT_KEY_MOUSE_WHEEL_DOWN,
    E_OLSP_EVENT_KEY_MOUSE_WHEEL,
    E_OLSP_EVENT_KEY_MOUSE_POINTER,
    E_OLSP_EVENT_KEY_MOUSE_ALL,
    
    /* Event keys list for remote control device */
    E_OLSP_EVENT_KEY_REMOTE_POWER,
    E_OLSP_EVENT_KEY_REMOTE_TIMER_OFF,
    E_OLSP_EVENT_KEY_REMOTE_PORTAL,
    E_OLSP_EVENT_KEY_REMOTE_BACK,
    E_OLSP_EVENT_KEY_REMOTE_FORWORD,
    E_OLSP_EVENT_KEY_REMOTE_UP_ALLOW,
    E_OLSP_EVENT_KEY_REMOTE_DOWN_ALLOW,
    E_OLSP_EVENT_KEY_REMOTE_LEFT_ALLOW,
    E_OLSP_EVENT_KEY_REMOTE_RIGHT_ALLOW,
    E_OLSP_EVENT_KEY_REMOTE_ENTER,
    E_OLSP_EVENT_KEY_REMOTE_EPG,
    E_OLSP_EVENT_KEY_REMOTE_MENU,
    E_OLSP_EVENT_KEY_REMOTE_SETTING,
    E_OLSP_EVENT_KEY_REMOTE_VOD,
    E_OLSP_EVENT_KEY_REMOTE_RES_REC_MENU,
    E_OLSP_EVENT_KEY_REMOTE_NW_1,
    E_OLSP_EVENT_KEY_REMOTE_NW_2,
    E_OLSP_EVENT_KEY_REMOTE_NW_3,
    E_OLSP_EVENT_KEY_REMOTE_NW_4,
    E_OLSP_EVENT_KEY_REMOTE_PROVIDER_LIST,
    E_OLSP_EVENT_KEY_REMOTE_REC_LIST,
    E_OLSP_EVENT_KEY_REMOTE_DLAN,
    E_OLSP_EVENT_KEY_REMOTE_INPUT_SELECT,
    E_OLSP_EVENT_KEY_REMOTE_DATABROADCAST,
    E_OLSP_EVENT_KEY_REMOTE_AUDIO_SET,
    E_OLSP_EVENT_KEY_REMOTE_DISPLAY_INFO,
    E_OLSP_EVENT_KEY_REMOTE_VIDEO_SELECT,
    E_OLSP_EVENT_KEY_REMOTE_CLOSED_CAPTION,
    E_OLSP_EVENT_KEY_REMOTE_BLUE,
    E_OLSP_EVENT_KEY_REMOTE_RED,
    E_OLSP_EVENT_KEY_REMOTE_YELLOW,
    E_OLSP_EVENT_KEY_REMOTE_GREEN,
    E_OLSP_EVENT_KEY_REMOTE_CHANEL_UP,
    E_OLSP_EVENT_KEY_REMOTE_CHANNEL_DOWN,
    E_OLSP_EVENT_KEY_REMOTE_VOLUME_UP,
    E_OLSP_EVENT_KEY_REMOTE_VOLUME_DOWN,
    E_OLSP_EVENT_KEY_REMOTE_NUMBER_1,
    E_OLSP_EVENT_KEY_REMOTE_NUMBER_2,
    E_OLSP_EVENT_KEY_REMOTE_NUMBER_3,
    E_OLSP_EVENT_KEY_REMOTE_NUMBER_4,
    E_OLSP_EVENT_KEY_REMOTE_NUMBER_5,
    E_OLSP_EVENT_KEY_REMOTE_NUMBER_6,
    E_OLSP_EVENT_KEY_REMOTE_NUMBER_7,
    E_OLSP_EVENT_KEY_REMOTE_NUMBER_8,
    E_OLSP_EVENT_KEY_REMOTE_NUMBER_9,
    E_OLSP_EVENT_KEY_REMOTE_NUMBER_10,
    E_OLSP_EVENT_KEY_REMOTE_NUMBER_11,
    E_OLSP_EVENT_KEY_REMOTE_NUMBER_12,
    E_OLSP_EVENT_KEY_REMOTE_PLAY,
    E_OLSP_EVENT_KEY_REMOTE_PLAY_FAST_FORWARD,
    E_OLSP_EVENT_KEY_REMOTE_PLAY_FAST_REWIND,
    E_OLSP_EVENT_KEY_REMOTE_PAUSE,
    E_OLSP_EVENT_KEY_REMOTE_PLAY_SKIP_FORWARD,
    E_OLSP_EVENT_KEY_REMOTE_PLAY_SKIP_REWIND,
    E_OLSP_EVENT_KEY_REMOTE_STOP,
    E_OLSP_EVENT_KEY_REMOTE_PLAY_SLOW_FORWARD,
    E_OLSP_EVENT_KEY_REMOTE_PLAY_SLOW_REWIND,
    E_OLSP_EVENT_KEY_REMOTE_REC,
    E_OLSP_EVENT_KEY_REMOTE_REC_STOP,
    E_OLSP_EVENT_KEY_REMOTE_HDMI_SELECT,
    E_OLSP_EVENT_KEY_REMOTE_RSV_1,
    E_OLSP_EVENT_KEY_REMOTE_RSV_2,
    E_OLSP_EVENT_KEY_REMOTE_RSV_3,
    E_OLSP_EVENT_KEY_REMOTE_RSV_4,
    E_OLSP_EVENT_KEY_REMOTE_RSV_5,
    E_OLSP_EVENT_KEY_REMOTE_RSV_6,
    E_OLSP_EVENT_KEY_REMOTE_RSV_7,
    E_OLSP_EVENT_KEY_REMOTE_RSV_8,
    E_OLSP_EVENT_KEY_REMOTE_RSV_9,
    E_OLSP_EVENT_KEY_REMOTE_RSV_10,
    E_OLSP_EVENT_KEY_REMOTE_RSV_11,
    E_OLSP_EVENT_KEY_REMOTE_RSV_12,
    E_OLSP_EVENT_KEY_REMOTE_RELEASE,
    E_OLSP_EVENT_KEY_REMOTE_ALL,
    
    /* Event keys list for front panel device */
    E_OLSP_EVENT_KEY_FRONT_POWER,
    E_OLSP_EVENT_KEY_FRONT_UP_ALLOW,
    E_OLSP_EVENT_KEY_FRONT_DOWN_ALLOW,
    E_OLSP_EVENT_KEY_FRONT_LEFT_ALLOW,
    E_OLSP_EVENT_KEY_FRONT_RIGHT_ALLOW,
    E_OLSP_EVENT_KEY_FRONT_ENTER,
    E_OLSP_EVENT_KEY_FRONT_ALL
} E_OLSP_EventKey_t;

typedef enum E_OLSP_KeyCodeTag
{
    E_OLSP_KEY_CODE_NONE                  = E_OLSP_EVENT_KEY_NONE,
    E_OLSP_KEY_ALL                        = E_OLSP_EVENT_KEY_ALL,

    /* Key codes for Keyboard device */
    E_OLSP_KEY_KEYBOARD_ESCAPE            = E_OLSP_EVENT_KEY_KEYBOARD_ESCAPE,
    E_OLSP_KEY_KEYBOARD_LEFT              = E_OLSP_EVENT_KEY_KEYBOARD_LEFT,
    E_OLSP_KEY_KEYBOARD_RIGHT             = E_OLSP_EVENT_KEY_KEYBOARD_RIGHT,
    E_OLSP_KEY_KEYBOARD_UP                = E_OLSP_EVENT_KEY_KEYBOARD_UP,
    E_OLSP_KEY_KEYBOARD_DOWN              = E_OLSP_EVENT_KEY_KEYBOARD_DOWN,
    E_OLSP_KEY_KEYBOARD_TAB               = E_OLSP_EVENT_KEY_KEYBOARD_TAB,
    E_OLSP_KEY_KEYBOARD_ENTER             = E_OLSP_EVENT_KEY_KEYBOARD_ENTER,
    E_OLSP_KEY_KEYBOARD_SPACE             = E_OLSP_EVENT_KEY_KEYBOARD_SPACE,
    E_OLSP_KEY_KEYBOARD_BACKSPACE         = E_OLSP_EVENT_KEY_KEYBOARD_BACKSPACE,
    E_OLSP_KEY_KEYBOARD_INSERT            = E_OLSP_EVENT_KEY_KEYBOARD_INSERT,
    E_OLSP_KEY_KEYBOARD_DELETE            = E_OLSP_EVENT_KEY_KEYBOARD_DELETE,
    E_OLSP_KEY_KEYBOARD_HOME              = E_OLSP_EVENT_KEY_KEYBOARD_HOME,
    E_OLSP_KEY_KEYBOARD_END               = E_OLSP_EVENT_KEY_KEYBOARD_END,
    E_OLSP_KEY_KEYBOARD_PAGE_UP           = E_OLSP_EVENT_KEY_KEYBOARD_PAGE_UP,
    E_OLSP_KEY_KEYBOARD_PAGE_DOWN         = E_OLSP_EVENT_KEY_KEYBOARD_PAGE_DOWN,
    E_OLSP_KEY_KEYBOARD_PRINT_SCREEN      = E_OLSP_EVENT_KEY_KEYBOARD_PRINT_SCREEN,
    E_OLSP_KEY_KEYBOARD_PAUSE             = E_OLSP_EVENT_KEY_KEYBOARD_PAUSE,
    E_OLSP_KEY_KEYBOARD_QUOTE_LEFT        = E_OLSP_EVENT_KEY_KEYBOARD_QUOTE_LEFT,
    E_OLSP_KEY_KEYBOARD_MINUS_SIGN        = E_OLSP_EVENT_KEY_KEYBOARD_MINUS_SIGN,
    E_OLSP_KEY_KEYBOARD_EQUALS_SIGN       = E_OLSP_EVENT_KEY_KEYBOARD_EQUALS_SIGN,
    E_OLSP_KEY_KEYBOARD_BRACKET_LEFT      = E_OLSP_EVENT_KEY_KEYBOARD_BRACKET_LEFT,
    E_OLSP_KEY_KEYBOARD_BRACKET_RIGHT     = E_OLSP_EVENT_KEY_KEYBOARD_BRACKET_RIGHT,
    E_OLSP_KEY_KEYBOARD_BACKSLASH         = E_OLSP_EVENT_KEY_KEYBOARD_BACKSLASH,
    E_OLSP_KEY_KEYBOARD_SEMICOLON         = E_OLSP_EVENT_KEY_KEYBOARD_SEMICOLON,
    E_OLSP_KEY_KEYBOARD_QUOTE_RIGHT       = E_OLSP_EVENT_KEY_KEYBOARD_QUOTE_RIGHT,
    E_OLSP_KEY_KEYBOARD_COMMA             = E_OLSP_EVENT_KEY_KEYBOARD_COMMA,
    E_OLSP_KEY_KEYBOARD_PERIOD            = E_OLSP_EVENT_KEY_KEYBOARD_PERIOD,
    E_OLSP_KEY_KEYBOARD_SLASH             = E_OLSP_EVENT_KEY_KEYBOARD_SLASH,
    E_OLSP_KEY_KEYBOARD_CAPS_LOCK         = E_OLSP_EVENT_KEY_KEYBOARD_CAPS_LOCK,
    E_OLSP_KEY_KEYBOARD_NUM_LOCK          = E_OLSP_EVENT_KEY_KEYBOARD_NUM_LOCK,
    E_OLSP_KEY_KEYBOARD_SCROLL_LOCK       = E_OLSP_EVENT_KEY_KEYBOARD_SCROLL_LOCK,
    E_OLSP_KEY_KEYBOARD_SHIFT_LEFT        = E_OLSP_EVENT_KEY_KEYBOARD_SHIFT_LEFT,
    E_OLSP_KEY_KEYBOARD_SHIFT_RIGHT       = E_OLSP_EVENT_KEY_KEYBOARD_SHIFT_RIGHT,
    E_OLSP_KEY_KEYBOARD_CONTROL_LEFT      = E_OLSP_EVENT_KEY_KEYBOARD_CONTROL_LEFT,
    E_OLSP_KEY_KEYBOARD_CONTROL_RIGHT     = E_OLSP_EVENT_KEY_KEYBOARD_CONTROL_RIGHT,
    E_OLSP_KEY_KEYBOARD_ALT_LEFT          = E_OLSP_EVENT_KEY_KEYBOARD_ALT_LEFT,
    E_OLSP_KEY_KEYBOARD_ALT_RIGHT         = E_OLSP_EVENT_KEY_KEYBOARD_ALT_RIGHT,
    E_OLSP_KEY_KEYBOARD_F1                = E_OLSP_EVENT_KEY_KEYBOARD_F1,
    E_OLSP_KEY_KEYBOARD_F2                = E_OLSP_EVENT_KEY_KEYBOARD_F2,
    E_OLSP_KEY_KEYBOARD_F3                = E_OLSP_EVENT_KEY_KEYBOARD_F3,
    E_OLSP_KEY_KEYBOARD_F4                = E_OLSP_EVENT_KEY_KEYBOARD_F4,
    E_OLSP_KEY_KEYBOARD_F5                = E_OLSP_EVENT_KEY_KEYBOARD_F5,
    E_OLSP_KEY_KEYBOARD_F6                = E_OLSP_EVENT_KEY_KEYBOARD_F6,
    E_OLSP_KEY_KEYBOARD_F7                = E_OLSP_EVENT_KEY_KEYBOARD_F7,
    E_OLSP_KEY_KEYBOARD_F8                = E_OLSP_EVENT_KEY_KEYBOARD_F8,
    E_OLSP_KEY_KEYBOARD_F9                = E_OLSP_EVENT_KEY_KEYBOARD_F9,
    E_OLSP_KEY_KEYBOARD_F10               = E_OLSP_EVENT_KEY_KEYBOARD_F10,
    E_OLSP_KEY_KEYBOARD_F11               = E_OLSP_EVENT_KEY_KEYBOARD_F11,
    E_OLSP_KEY_KEYBOARD_F12               = E_OLSP_EVENT_KEY_KEYBOARD_F12,
    E_OLSP_KEY_KEYBOARD_0                 = E_OLSP_EVENT_KEY_KEYBOARD_0,
    E_OLSP_KEY_KEYBOARD_1                 = E_OLSP_EVENT_KEY_KEYBOARD_1,
    E_OLSP_KEY_KEYBOARD_2                 = E_OLSP_EVENT_KEY_KEYBOARD_2,
    E_OLSP_KEY_KEYBOARD_3                 = E_OLSP_EVENT_KEY_KEYBOARD_3,
    E_OLSP_KEY_KEYBOARD_4                 = E_OLSP_EVENT_KEY_KEYBOARD_4,
    E_OLSP_KEY_KEYBOARD_5                 = E_OLSP_EVENT_KEY_KEYBOARD_5,
    E_OLSP_KEY_KEYBOARD_6                 = E_OLSP_EVENT_KEY_KEYBOARD_6,
    E_OLSP_KEY_KEYBOARD_7                 = E_OLSP_EVENT_KEY_KEYBOARD_7,
    E_OLSP_KEY_KEYBOARD_8                 = E_OLSP_EVENT_KEY_KEYBOARD_8,
    E_OLSP_KEY_KEYBOARD_9                 = E_OLSP_EVENT_KEY_KEYBOARD_9,
    E_OLSP_KEY_KEYBOARD_A                 = E_OLSP_EVENT_KEY_KEYBOARD_A,
    E_OLSP_KEY_KEYBOARD_B                 = E_OLSP_EVENT_KEY_KEYBOARD_B,
    E_OLSP_KEY_KEYBOARD_C                 = E_OLSP_EVENT_KEY_KEYBOARD_C,
    E_OLSP_KEY_KEYBOARD_D                 = E_OLSP_EVENT_KEY_KEYBOARD_D,
    E_OLSP_KEY_KEYBOARD_E                 = E_OLSP_EVENT_KEY_KEYBOARD_E,
    E_OLSP_KEY_KEYBOARD_F                 = E_OLSP_EVENT_KEY_KEYBOARD_F,
    E_OLSP_KEY_KEYBOARD_G                 = E_OLSP_EVENT_KEY_KEYBOARD_G,
    E_OLSP_KEY_KEYBOARD_H                 = E_OLSP_EVENT_KEY_KEYBOARD_H,
    E_OLSP_KEY_KEYBOARD_I                 = E_OLSP_EVENT_KEY_KEYBOARD_I,
    E_OLSP_KEY_KEYBOARD_J                 = E_OLSP_EVENT_KEY_KEYBOARD_J,
    E_OLSP_KEY_KEYBOARD_K                 = E_OLSP_EVENT_KEY_KEYBOARD_K,
    E_OLSP_KEY_KEYBOARD_L                 = E_OLSP_EVENT_KEY_KEYBOARD_L,
    E_OLSP_KEY_KEYBOARD_M                 = E_OLSP_EVENT_KEY_KEYBOARD_M,
    E_OLSP_KEY_KEYBOARD_N                 = E_OLSP_EVENT_KEY_KEYBOARD_N,
    E_OLSP_KEY_KEYBOARD_O                 = E_OLSP_EVENT_KEY_KEYBOARD_O,
    E_OLSP_KEY_KEYBOARD_P                 = E_OLSP_EVENT_KEY_KEYBOARD_P,
    E_OLSP_KEY_KEYBOARD_Q                 = E_OLSP_EVENT_KEY_KEYBOARD_Q,
    E_OLSP_KEY_KEYBOARD_R                 = E_OLSP_EVENT_KEY_KEYBOARD_R,
    E_OLSP_KEY_KEYBOARD_S                 = E_OLSP_EVENT_KEY_KEYBOARD_S,
    E_OLSP_KEY_KEYBOARD_T                 = E_OLSP_EVENT_KEY_KEYBOARD_T,
    E_OLSP_KEY_KEYBOARD_U                 = E_OLSP_EVENT_KEY_KEYBOARD_U,
    E_OLSP_KEY_KEYBOARD_V                 = E_OLSP_EVENT_KEY_KEYBOARD_V,
    E_OLSP_KEY_KEYBOARD_W                 = E_OLSP_EVENT_KEY_KEYBOARD_W,
    E_OLSP_KEY_KEYBOARD_X                 = E_OLSP_EVENT_KEY_KEYBOARD_X,
    E_OLSP_KEY_KEYBOARD_Y                 = E_OLSP_EVENT_KEY_KEYBOARD_Y,
    E_OLSP_KEY_KEYBOARD_Z                 = E_OLSP_EVENT_KEY_KEYBOARD_Z,
    E_OLSP_KEY_KEYBOARD_ALL               = E_OLSP_EVENT_KEY_KEYBOARD_ALL,
    
    /* Key code for Mouse device */
    E_OLSP_KEY_MOUSE_LEFT                 = E_OLSP_EVENT_KEY_MOUSE_LEFT,
    E_OLSP_KEY_MOUSE_RIGHT                = E_OLSP_EVENT_KEY_MOUSE_RIGHT,
    E_OLSP_KEY_MOUSE_CENTRE               = E_OLSP_EVENT_KEY_MOUSE_CENTRE,
    E_OLSP_KEY_MOUSE_WHEEL_UP             = E_OLSP_EVENT_KEY_MOUSE_WHEEL_UP,
    E_OLSP_KEY_MOUSE_WHEEL_DOWN           = E_OLSP_EVENT_KEY_MOUSE_WHEEL_DOWN,
    E_OLSP_KEY_MOUSE_WHEEL                = E_OLSP_EVENT_KEY_MOUSE_WHEEL,
    E_OLSP_KEY_MOUSE_POINTER              = E_OLSP_EVENT_KEY_MOUSE_POINTER,
    E_OLSP_KEY_MOUSE_ALL                  = E_OLSP_EVENT_KEY_MOUSE_ALL,
    
    /* Key code for Remote control device */
    E_OLSP_KEY_REMOTE_POWER               = E_OLSP_EVENT_KEY_REMOTE_POWER,
    E_OLSP_KEY_REMOTE_HOME                = E_OLSP_EVENT_KEY_REMOTE_TIMER_OFF,
    E_OLSP_KEY_REMOTE_PORTAL              = E_OLSP_EVENT_KEY_REMOTE_PORTAL,
    E_OLSP_KEY_REMOTE_BACK                = E_OLSP_EVENT_KEY_REMOTE_BACK,
    E_OLSP_KEY_REMOTE_FORWORD             = E_OLSP_EVENT_KEY_REMOTE_FORWORD,
    E_OLSP_KEY_REMOTE_UP_ALLOW            = E_OLSP_EVENT_KEY_REMOTE_UP_ALLOW,
    E_OLSP_KEY_REMOTE_DOWN_ALLOW          = E_OLSP_EVENT_KEY_REMOTE_DOWN_ALLOW,
    E_OLSP_KEY_REMOTE_LEFT_ALLOW          = E_OLSP_EVENT_KEY_REMOTE_LEFT_ALLOW,
    E_OLSP_KEY_REMOTE_RIGHT_ALLOW         = E_OLSP_EVENT_KEY_REMOTE_RIGHT_ALLOW,
    E_OLSP_KEY_REMOTE_ENTER               = E_OLSP_EVENT_KEY_REMOTE_ENTER,
    E_OLSP_KEY_REMOTE_EPG                 = E_OLSP_EVENT_KEY_REMOTE_EPG,
    E_OLSP_KEY_REMOTE_MENU                = E_OLSP_EVENT_KEY_REMOTE_MENU,
    E_OLSP_KEY_REMOTE_SETTING             = E_OLSP_EVENT_KEY_REMOTE_SETTING,
    E_OLSP_KEY_REMOTE_VOD                 = E_OLSP_EVENT_KEY_REMOTE_VOD,
    E_OLSP_KEY_REMOTE_RES_REC_MENU        = E_OLSP_EVENT_KEY_REMOTE_RES_REC_MENU,
    E_OLSP_KEY_REMOTE_NW_1                = E_OLSP_EVENT_KEY_REMOTE_NW_1,
    E_OLSP_KEY_REMOTE_NW_2                = E_OLSP_EVENT_KEY_REMOTE_NW_2,
    E_OLSP_KEY_REMOTE_NW_3                = E_OLSP_EVENT_KEY_REMOTE_NW_3,
    E_OLSP_KEY_REMOTE_NW_4                = E_OLSP_EVENT_KEY_REMOTE_NW_4,
    E_OLSP_KEY_REMOTE_PROVIDER_LIST       = E_OLSP_EVENT_KEY_REMOTE_PROVIDER_LIST,
    E_OLSP_KEY_REMOTE_REC_LIST            = E_OLSP_EVENT_KEY_REMOTE_REC_LIST,
    E_OLSP_KEY_REMOTE_DLAN                = E_OLSP_EVENT_KEY_REMOTE_DLAN,
    E_OLSP_KEY_REMOTE_INPUT_SELECT        = E_OLSP_EVENT_KEY_REMOTE_INPUT_SELECT,
    E_OLSP_KEY_REMOTE_DATABROADCAST       = E_OLSP_EVENT_KEY_REMOTE_DATABROADCAST,
    E_OLSP_KEY_REMOTE_AUDIO_SET           = E_OLSP_EVENT_KEY_REMOTE_AUDIO_SET,
    E_OLSP_KEY_REMOTE_DISPLAY_INFO        = E_OLSP_EVENT_KEY_REMOTE_DISPLAY_INFO,
    E_OLSP_KEY_REMOTE_VIDEO_SELECT        = E_OLSP_EVENT_KEY_REMOTE_VIDEO_SELECT,
    E_OLSP_KEY_REMOTE_CLOSED_CAPTION      = E_OLSP_EVENT_KEY_REMOTE_CLOSED_CAPTION,
    E_OLSP_KEY_REMOTE_BLUE                = E_OLSP_EVENT_KEY_REMOTE_BLUE,
    E_OLSP_KEY_REMOTE_RED                 = E_OLSP_EVENT_KEY_REMOTE_RED,
    E_OLSP_KEY_REMOTE_YELLOW              = E_OLSP_EVENT_KEY_REMOTE_YELLOW,
    E_OLSP_KEY_REMOTE_GREEN               = E_OLSP_EVENT_KEY_REMOTE_GREEN,
    E_OLSP_KEY_REMOTE_CHANEL_UP           = E_OLSP_EVENT_KEY_REMOTE_CHANEL_UP,
    E_OLSP_KEY_REMOTE_CHANNEL_DOWN        = E_OLSP_EVENT_KEY_REMOTE_CHANNEL_DOWN,
    E_OLSP_KEY_REMOTE_VOLUME_UP           = E_OLSP_EVENT_KEY_REMOTE_VOLUME_UP,
    E_OLSP_KEY_REMOTE_VOLUME_DOWN         = E_OLSP_EVENT_KEY_REMOTE_VOLUME_DOWN,
    E_OLSP_KEY_REMOTE_NUMBER_1            = E_OLSP_EVENT_KEY_REMOTE_NUMBER_1,
    E_OLSP_KEY_REMOTE_NUMBER_2            = E_OLSP_EVENT_KEY_REMOTE_NUMBER_2,
    E_OLSP_KEY_REMOTE_NUMBER_3            = E_OLSP_EVENT_KEY_REMOTE_NUMBER_3,
    E_OLSP_KEY_REMOTE_NUMBER_4            = E_OLSP_EVENT_KEY_REMOTE_NUMBER_4,
    E_OLSP_KEY_REMOTE_NUMBER_5            = E_OLSP_EVENT_KEY_REMOTE_NUMBER_5,
    E_OLSP_KEY_REMOTE_NUMBER_6            = E_OLSP_EVENT_KEY_REMOTE_NUMBER_6,
    E_OLSP_KEY_REMOTE_NUMBER_7            = E_OLSP_EVENT_KEY_REMOTE_NUMBER_7,
    E_OLSP_KEY_REMOTE_NUMBER_8            = E_OLSP_EVENT_KEY_REMOTE_NUMBER_8,
    E_OLSP_KEY_REMOTE_NUMBER_9            = E_OLSP_EVENT_KEY_REMOTE_NUMBER_9,
    E_OLSP_KEY_REMOTE_NUMBER_10           = E_OLSP_EVENT_KEY_REMOTE_NUMBER_10,
    E_OLSP_KEY_REMOTE_NUMBER_11           = E_OLSP_EVENT_KEY_REMOTE_NUMBER_11,
    E_OLSP_KEY_REMOTE_NUMBER_12           = E_OLSP_EVENT_KEY_REMOTE_NUMBER_12,
    E_OLSP_KEY_REMOTE_PLAY                = E_OLSP_EVENT_KEY_REMOTE_PLAY,
    E_OLSP_KEY_REMOTE_PLAY_FAST_FORWARD   = E_OLSP_EVENT_KEY_REMOTE_PLAY_FAST_FORWARD,
    E_OLSP_KEY_REMOTE_PLAY_FAST_REWIND    = E_OLSP_EVENT_KEY_REMOTE_PLAY_FAST_REWIND,
    E_OLSP_KEY_REMOTE_PAUSE               = E_OLSP_EVENT_KEY_REMOTE_PAUSE,
    E_OLSP_KEY_REMOTE_PLAY_SKIP_FORWARD   = E_OLSP_EVENT_KEY_REMOTE_PLAY_SKIP_FORWARD,
    E_OLSP_KEY_REMOTE_PLAY_SKIP_REWIND    = E_OLSP_EVENT_KEY_REMOTE_PLAY_SKIP_REWIND,
    E_OLSP_KEY_REMOTE_STOP                = E_OLSP_EVENT_KEY_REMOTE_STOP,
    E_OLSP_KEY_REMOTE_PLAY_SLOW_FORWARD   = E_OLSP_EVENT_KEY_REMOTE_PLAY_SLOW_FORWARD,
    E_OLSP_KEY_REMOTE_PLAY_SLOW_REWIND    = E_OLSP_EVENT_KEY_REMOTE_PLAY_SLOW_REWIND,
    E_OLSP_KEY_REMOTE_REC                 = E_OLSP_EVENT_KEY_REMOTE_REC,
    E_OLSP_KEY_REMOTE_REC_STOP            = E_OLSP_EVENT_KEY_REMOTE_REC_STOP,
    E_OLSP_KEY_REMOTE_HDMI_SELECT         = E_OLSP_EVENT_KEY_REMOTE_HDMI_SELECT,
    E_OLSP_KEY_REMOTE_RSV_1               = E_OLSP_EVENT_KEY_REMOTE_RSV_1,
    E_OLSP_KEY_REMOTE_RSV_2               = E_OLSP_EVENT_KEY_REMOTE_RSV_2,
    E_OLSP_KEY_REMOTE_RSV_3               = E_OLSP_EVENT_KEY_REMOTE_RSV_3,
    E_OLSP_KEY_REMOTE_RSV_4               = E_OLSP_EVENT_KEY_REMOTE_RSV_4,
    E_OLSP_KEY_REMOTE_RSV_5               = E_OLSP_EVENT_KEY_REMOTE_RSV_5,
    E_OLSP_KEY_REMOTE_RSV_6               = E_OLSP_EVENT_KEY_REMOTE_RSV_6,
    E_OLSP_KEY_REMOTE_RSV_7               = E_OLSP_EVENT_KEY_REMOTE_RSV_7,
    E_OLSP_KEY_REMOTE_RSV_8               = E_OLSP_EVENT_KEY_REMOTE_RSV_8,
    E_OLSP_KEY_REMOTE_RSV_9               = E_OLSP_EVENT_KEY_REMOTE_RSV_9,
    E_OLSP_KEY_REMOTE_RSV_10              = E_OLSP_EVENT_KEY_REMOTE_RSV_10,
    E_OLSP_KEY_REMOTE_RSV_11              = E_OLSP_EVENT_KEY_REMOTE_RSV_11,
    E_OLSP_KEY_REMOTE_RSV_12              = E_OLSP_EVENT_KEY_REMOTE_RSV_12,
    E_OLSP_KEY_REMOTE_RELEASE             = E_OLSP_EVENT_KEY_REMOTE_RELEASE,
    E_OLSP_KEY_REMOTE_ALL                 = E_OLSP_EVENT_KEY_REMOTE_ALL,
    
    /* Key code for Front panel device */
    E_OLSP_KEY_FRONT_POWER                = E_OLSP_EVENT_KEY_FRONT_POWER,
    E_OLSP_KEY_FRONT_UP_ALLOW             = E_OLSP_EVENT_KEY_FRONT_UP_ALLOW,
    E_OLSP_KEY_FRONT_DOWN_ALLOW           = E_OLSP_EVENT_KEY_FRONT_DOWN_ALLOW,
    E_OLSP_KEY_FRONT_LEFT_ALLOW           = E_OLSP_EVENT_KEY_FRONT_LEFT_ALLOW,
    E_OLSP_KEY_FRONT_RIGHT_ALLOW          = E_OLSP_EVENT_KEY_FRONT_RIGHT_ALLOW,
    E_OLSP_KEY_FRONT_ENTER                = E_OLSP_EVENT_KEY_FRONT_ENTER,
    E_OLSP_KEY_FRONT_ALL                  = E_OLSP_EVENT_KEY_FRONT_ALL
} E_OLSP_KeyCode_t;

typedef enum E_OLSP_InputEventTag
{
    E_OLSP_INPUT_EVENT_INVALID = 0,
    E_OLSP_INPUT_EVENT_KEY_PRESS,
    E_OLSP_INPUT_EVENT_KEY_RELEASE,
    E_OLSP_INPUT_EVENT_BUTTON_PRESS,
    E_OLSP_INPUT_EVENT_BUTTON_RELEASE,
    E_OLSP_INPUT_EVENT_WHEEL_MOTION,
    E_OLSP_INPUT_EVENT_POINTER_MOTION
} E_OLSP_InputEvent_t;

typedef struct {
E_OLSP_InputEvent_t event;
E_OLSP_KeyCode_t key_code;
} S_event_t;


struct my_msgbuf 
{
    long mtype;
    S_event_t event;
};
int main(void)
{
    struct my_msgbuf buf;
    int msqid;
    key_t key;
    if ((key = ftok("isense", 'B')) == -1)
    {
        perror("ftok");
        exit(1);
    }
    if ((msqid = msgget(key, 0644 | IPC_CREAT)) == -1)
    {
        perror("msgget");
        exit(1);
    }
    printf("MSG Q ID IS %d\n", msqid);
    printf("Enter lines of text, ^D to quit:\n");
    buf.mtype = 2; /* we don't really care in this case */

//    while(fgets(buf.mtext, sizeof(buf.mtext), stdin) != NULL)
    while(1) 
    {
        printf("Sending event\n");
        buf.event.event = E_OLSP_INPUT_EVENT_KEY_PRESS;
        buf.event.key_code = E_OLSP_EVENT_KEY_KEYBOARD_LEFT;

        if (msgsnd(msqid, &buf, sizeof(S_event_t), 0) == -1) /* +1 for '\0' */
        {
            perror("msgsnd");
        }
    }
    if (msgctl(msqid, IPC_RMID, NULL) == -1)
    {
        perror("msgctl");
        exit(1);
    }
    return 0;
}
