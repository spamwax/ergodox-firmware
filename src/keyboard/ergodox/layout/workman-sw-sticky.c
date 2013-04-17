/* ----------------------------------------------------------------------------
* ergoDOX layout : COLEMAK JC Sticky Keys Mod
*     created by Ryan Prince
* Description: This layout is designed for programming with a focus on
*     minimizing/elimnating the need to take the hands out of home-row position
*     to reach other keys. Layer sticky keys are used to reduce the average
*     number of keystrokes required to access keys in other layers. Some
*     redundancy of navigation and spacing keys is added to the left hand to
*     allow for greater one-handed access when using a mouse with the right
*     hand.
*   The alpha key layout is COLEMAK with sticky layer keys on the thumb
*     switches for a symbol layer and a ten-key/function
*     layer.
*   Modifiers are symetric on each hand with the exception of the Alt
*     key because my primary machine is a Mac which utilizes command and ctrl
*     for chorded shortcuts more frequenty than ctrl and alt. The layer sticky
*     keys compliment standard modifier sticky keys (for shift, ctrl, command,
*     alt) to allow fast touch typing with minimal chording in favor of
*     sequential keying (preferably on alternate hands) for multi-key shortcuts
*     as chording introduces strain and fatigue and takes your hands out of
*     home row position increasing the likelihood of mistyping.
*   Sticky keys for standard modifiers are used as an operating system setting
*     for the benefit of key state visualization, though this can interfere
*     with the kbfun_shift_press_release() behavior which implicitly adds the
*     shift down modifier to output symbols that require it without knowledge
*     of the virtual sticky state maintained by the operating system.
*   The ErgoDox Layout Configurator layout that best approximates the layout
*     defined in this file is available here:
*     https://www.massdrop.com/ext/ergodox/?referer=EAZJPJ&hash=f26761358ba99e21ae937173da512849
*     The differences are mainly the use of layer toggles instead of sticky
*     layer keys and many of the symbols add the kbfun_shift_press_release()
*     which is not accessible for all keys in the cofigurator (as of
*     2013-04-10).
* -----------------------------------------------------------------------------
* Copyright (c) 2012 Ben Blazak <benblazak.dev@gmail.com>,
*    2013 Ryan Prince <judascleric@gmail.com>
* Released under The MIT License (MIT) (see "license.md")
* Project located at <https://github.com/benblazak/ergodox-firmware>
* -------------------------------------------------------------------------- */
#include <stdint.h>
#include <stddef.h>
#include <avr/pgmspace.h>
#include "../../../lib/data-types/misc.h"
#include "../../../lib/usb/usage-page/keyboard--short-names.h"
#include "../../../lib/key-functions/public.h"
#include "../matrix.h"
#include "../layout.h"
// FUNCTIONS ------------------------------------------------------------------
void kbfun_layer_pop_all(void) {
  kbfun_layer_pop_1();
  kbfun_layer_pop_2();
  kbfun_layer_pop_3();
  kbfun_layer_pop_4();
  kbfun_layer_pop_5();
  kbfun_layer_pop_6();
  kbfun_layer_pop_7();
  kbfun_layer_pop_8();
  kbfun_layer_pop_9();
  kbfun_layer_pop_10();
}

// DEFINITIONS ----------------------------------------------------------------
#define  kprrel   &kbfun_press_release
#define  kprpst   &kbfun_press_release_preserve_sticky
#define  ktrans   &kbfun_transparent
#define  lpush1   &kbfun_layer_push_1
#define  lpush2   &kbfun_layer_push_2
#define  lpush3   &kbfun_layer_push_3
#define  lpush4   &kbfun_layer_push_4
#define  lpush5   &kbfun_layer_push_5
#define  lsticky1   &kbfun_layer_sticky_1
#define  lsticky2   &kbfun_layer_sticky_2
#define  lpop     &kbfun_layer_pop_all
#define  lpop1    &kbfun_layer_pop_1
#define  lpop2    &kbfun_layer_pop_2
#define  lpop3    &kbfun_layer_pop_3
#define  lpop4    &kbfun_layer_pop_4
#define  dbtldr   &kbfun_jump_to_bootloader
#define  sshprre  &kbfun_shift_press_release
// ----------------------------------------------------------------------------

// LAYOUT ---------------------------------------------------------------------
const uint8_t PROGMEM _kb_layout[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// LAYER 0
KB_MATRIX_LAYER(
	// unused
	0,
	// left hand
	KEY_GraveAccent_Tilde,	KEY_Stop,	KEY_x_X,	KEY_c_C,	KEY_v_V,	KEY_f_F,	KEY_n_N,
	KEY_Backslash_Pipe,	KEY_q_Q,	KEY_d_D,	KEY_r_R,	KEY_w_W,	KEY_b_B,	KEY_Tab,
	KEY_LeftControl,	KEY_a_A,	KEY_s_S,	KEY_h_H,	KEY_t_T,	KEY_g_G,
	KEY_LeftShift,	KEY_z_Z,	KEY_x_X,	KEY_m_M,	KEY_c_C,	KEY_v_V,	KEY_ReturnEnter,
	3,	KEY_CapsLock,	KEY_PageUp,	KEY_PageDown,	1,
	KEY_Spacebar,	KEY_LeftAlt,
	0,	0,	KEY_Escape,
	KEY_DeleteBackspace,	KEY_LeftGUI,	1,
	// right hand
	KEY_Dash_Underscore,	KEY_Mute,	KEY_z_Z,	KEY_Spacebar,	KEY_z_Z,	KEY_c_C,	KEY_Equal_Plus,
	0x2F,	KEY_j_J,	KEY_f_F,	KEY_u_U,	KEY_p_P,	KEY_Semicolon_Colon,	0x30,
	KEY_y_Y,	KEY_n_N,	KEY_e_E,	KEY_o_O,	KEY_i_I,	KEY_RightControl,
	2,	KEY_k_K,	KEY_l_L,	KEY_Comma_LessThan,	KEY_Period_GreaterThan,	KEY_SingleQuote_DoubleQuote,	KEY_RightShift,
	1,	KEY_LeftArrow,	KEY_RightArrow,	KEY_DownArrow,	KEY_UpArrow,
	KEY_RightAlt,	KEY_DeleteForward,
	KEY_Home,	0,	0,
	KEY_End,	KEY_ReturnEnter,	KEY_Spacebar
),
// LAYER 1
KB_MATRIX_LAYER(
	// unused
	0,
	// left hand
	0,	KEY_1_Exclamation,	KEY_2_At,	KEY_3_Pound,	KEY_4_Dollar,	KEY_5_Percent,	0,
	KEY_GraveAccent_Tilde,	KEY_LeftBracket_LeftBrace,	KEY_RightBracket_RightBrace,	0x2F,	0x30,	KEY_5_Percent,	0,
	KEY_7_Ampersand,	0x34,	KEYPAD_Slash,	KEYPAD_Minus,	KEYPAD_0_Insert,	0x33,
	0x35,	KEYPAD_6_RightArrow,	KEYPAD_7_Home,	KEYPAD_8_UpArrow,	KEYPAD_9_PageUp,	KEYPAD_Plus,	0,
	0,	KEY_PrintScreen,	0,	0,	0,
	KEY_LeftShift,	0,
	0,	0,	0,
	0,	0,	1,
	// right hand
	0,	KEY_6_Caret,	KEY_7_Ampersand,	KEY_8_Asterisk,	KEY_9_LeftParenthesis,	KEY_0_RightParenthesis,	0,
	0,	KEY_4_Dollar,	0x2D,	KEY_3_Pound,	KEY_2_At,	KEY_1_Exclamation,	KEY_6_Caret,
	KEY_Backslash_Pipe,	KEYPAD_1_End,	KEY_9_LeftParenthesis,	KEY_0_RightParenthesis,	KEYPAD_Equal,	0x38,
	0,	KEYPAD_Asterisk,	KEYPAD_2_DownArrow,	KEYPAD_3_PageDown,	KEYPAD_4_LeftArrow,	KEYPAD_5,	0x31,
	0,	0,	0,	0,	0,
	KEY_RightControl,	0,
	0,	0,	0,
	0,	0,	0
),
// LAYER 2
KB_MATRIX_LAYER(
	// unused
	0,
	// left hand
	0,	KEY_F1,	KEY_F2,	KEY_F3,	KEY_F4,	KEY_F5,	KEY_F11,
	0,	0,	KEY_a_A,	KEY_b_B,	KEY_c_C,	KEYPAD_Minus,	0,
	0,	0,	KEY_d_D,	KEY_e_E,	KEY_f_F,	KEYPAD_Plus,
	0,	KEY_4_Dollar,	KEYPAD_Equal,	KEY_x_X,	0x33,	KEY_Semicolon_Colon,	0,
	3,	0,	0,	0,	0,
	KEY_Spacebar,	KEY_LeftAlt,
	0,	0,	KEY_Escape,
	KEY_DeleteBackspace,	KEY_LeftGUI,	1,
	// right hand
	KEY_F12,	KEY_F6,	KEY_F7,	KEY_F8,	KEY_F9,	KEY_F10,	0,
	0,	KEY_9_LeftParenthesis,	KEYPAD_7_Home,	KEYPAD_8_UpArrow,	KEYPAD_9_PageUp,	0,	KEYPAD_Minus,
	KEY_0_RightParenthesis,	KEYPAD_4_LeftArrow,	KEYPAD_5,	KEYPAD_6_RightArrow,	KEYPAD_Equal,	KEYPAD_Plus,
	0,	KEYPAD_00,	KEYPAD_1_End,	KEYPAD_2_DownArrow,	KEYPAD_3_PageDown,	KEYPAD_Slash,	KEYPAD_Asterisk,
	0,	0,	0,	0,	0,
	0,	0,
	0,	0,	0,
	0,	0,	KEYPAD_0_Insert
),
// LAYER 3
KB_MATRIX_LAYER(
	// unused
	0,
	// left hand
	0,	0,	0,	0,	0,	0,	0,
	KEYPAD_Minus,	0,	KEYPAD_7_Home,	KEYPAD_8_UpArrow,	KEYPAD_9_PageUp,	0,	0,
	KEYPAD_Plus,	KEYPAD_Equal,	KEYPAD_4_LeftArrow,	KEYPAD_5,	KEYPAD_6_RightArrow,	0,
	KEYPAD_Asterisk,	KEYPAD_Slash,	KEYPAD_1_End,	KEYPAD_2_DownArrow,	KEYPAD_3_PageDown,	0,	0,
	4,	0,	0,	0,	0,
	0,	0,
	0,	0,	0,
	KEY_DeleteBackspace,	KEY_LeftGUI,	0,
	// right hand
	0,	0,	0,	0,	0,	0,	0,
	0,	0,	0,	KEY_UpArrow,	0,	0,	0,
	0,	KEY_LeftArrow,	KEY_DownArrow,	KEY_RightArrow,	0,	0,
	0,	0,	0,	KEY_UpArrow,	0,	0,	0,
	KEY_LeftArrow,	KEY_DownArrow,	KEY_RightArrow,	0,	3,
	0,	0,
	0,	0,	0,
	0,	0,	0
),
// LAYER 4
KB_MATRIX_LAYER(
	// unused
	0,
	// left hand
	0,	KEY_Execute,	KEY_Help,	0,	0,	0,	0,
	0,	0,	0,	0,	0,	0,	0,
	0,	0,	0,	0,	0,	0,
	0,	0,	0,	0,	0,	0,	0,
	4,	0,	0,	0,	0,
	0,	0,
	0,	0,	0,
	0,	0,	0,
	// right hand
	0,	0,	0,	0,	0,	0,	0,
	0,	0,	0,	0,	0,	0,	0,
	0,	0,	0,	0,	0,	0,
	0,	0,	0,	0,	0,	0,	0,
	0,	0,	0,	0,	0,
	0,	0,
	0,	0,	0,
	0,	0,	0
),
};
// ----------------------------------------------------------------------------

// PRESS ----------------------------------------------------------------------
const void_funptr_t PROGMEM _kb_layout_press[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// LAYER 0
KB_MATRIX_LAYER(
	// unused
	NULL,
	// left hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	lpush3,	kprrel,	kprrel,	kprrel,	lsticky1,
	kprrel,	kprrel,
	NULL,	NULL,	kprrel,
	kprrel,	kprrel,	lpush1,
	// right hand
	kprrel, 	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	sshprre,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	sshprre,
	kprrel, 	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	lsticky2, 	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	lsticky1,	kprrel,	kprrel,	kprrel,	kprrel,
	kprrel,	kprrel,
	kprrel,	NULL,	NULL,
	kprrel,	kprrel,	kprrel
),
// LAYER 1
KB_MATRIX_LAYER(
	// unused
	NULL,
	// left hand
	lpop    , kprrel  , kprrel  , kprrel  , kprrel  , kprrel  , ktrans  ,
	kprrel  , kprrel  , kprrel  , sshprre , sshprre , kprrel  , ktrans  ,
	sshprre , sshprre , kprrel  , kprrel  , kprrel  , sshprre ,
	sshprre , kprrel  , kprrel  , kprrel  , kprrel  , kprrel  , ktrans  ,
	ktrans  , kprrel  , ktrans  , ktrans  , ktrans  ,
	kprrel  , ktrans  ,
	NULL    , NULL    , ktrans  ,
	ktrans  , ktrans  , lpop1   ,
	// right hand
	ktrans  , kprrel  , kprrel  , kprrel  , kprrel  , kprrel  , NULL    ,
	ktrans  , sshprre , sshprre , sshprre , sshprre , sshprre , sshprre ,
	kprrel  , kprrel  , sshprre , sshprre , kprrel  , sshprre ,
	ktrans  , kprrel  , kprrel  , kprrel  , kprrel  , kprrel  , sshprre ,
	ktrans  , ktrans  , ktrans  , ktrans  , ktrans  ,
	kprrel  , ktrans  ,
	ktrans  , NULL    , NULL    ,
	ktrans  , ktrans  , ktrans
),
// LAYER 2
KB_MATRIX_LAYER(
	NULL,
	// left hand
	lpop,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	ktrans,	ktrans,	sshprre,	sshprre,	sshprre,	kprrel,	ktrans,
	ktrans,	ktrans,	sshprre,	sshprre,	sshprre,	kprrel,
	ktrans,	sshprre,	kprrel,	kprrel,	sshprre,	kprrel,	ktrans,
	lpush3,	ktrans,	ktrans,	ktrans,	ktrans,
	kprrel,	kprrel,
	NULL,	NULL,	kprrel,
	kprrel,	kprrel,	lpush1,
	// right hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	lpop,
	ktrans,	sshprre,	kprrel,	kprrel,	kprrel,	ktrans,	kprrel,
	sshprre,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	ktrans,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,
	ktrans,	NULL,	NULL,
	ktrans,	ktrans,	kprrel
),
// LAYER 3
KB_MATRIX_LAYER(
	// unused
	NULL,
	// left hand
	dbtldr,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	kprrel,	ktrans,	kprrel,	kprrel,	kprrel,	ktrans,	ktrans,
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	ktrans,
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	ktrans,	ktrans,
	lpush4,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,
	NULL,	NULL,	ktrans,
	kprrel,	kprrel,	ktrans,
	// right hand
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	lpop,
	ktrans,	ktrans,	ktrans,	kprrel,	ktrans,	ktrans,	ktrans,
	ktrans,	kprrel,	kprrel,	kprrel,	ktrans,	ktrans,
	ktrans,	ktrans,	ktrans,	kprrel,	ktrans,	ktrans,	ktrans,
	kprrel,	kprrel,	kprrel,	ktrans,	lpop3,
	NULL,	NULL,
	NULL,	NULL,	NULL,
	NULL,	ktrans,	ktrans
),
// LAYER 4
KB_MATRIX_LAYER(
	// unused
	NULL,
	// left hand
	dbtldr,	kprrel,	kprrel,	NULL,	NULL,	NULL,	NULL,
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,
	lpop4,	NULL,	NULL,	NULL,	NULL,
	NULL,	NULL,
	NULL,	NULL,	NULL,
	NULL,	NULL,	NULL,
	// right hand
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	lpop,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,
	ktrans,	NULL,	NULL,
	ktrans,	ktrans,	ktrans
),
};
// ----------------------------------------------------------------------------

// RELEASE --------------------------------------------------------------------
const void_funptr_t PROGMEM _kb_layout_release[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// LAYER 0
KB_MATRIX_LAYER(
	// unused
	NULL,
	// left hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	NULL,	kprrel,	kprrel,	kprrel,	lsticky1,
	kprrel,	kprrel,
	NULL,	NULL,	kprrel,
	kprrel,	kprrel,	NULL,
	// right hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	sshprre,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	sshprre,
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	lsticky2,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	lsticky1,	kprrel,	kprrel,	kprrel,	kprrel,
	kprrel,	kprrel,
	kprrel,	NULL,	NULL,
	kprrel,	kprrel,	kprrel
),
// LAYER 1
KB_MATRIX_LAYER(
	// unused
	NULL,
	// left hand
	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	ktrans,
	kprrel,	kprrel,	kprrel,	sshprre,	sshprre,	kprrel,	ktrans,
	sshprre,	sshprre,	kprrel,	kprrel,	kprrel,	sshprre,
	sshprre,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	ktrans,
	ktrans,	kprrel,	ktrans,	ktrans,	ktrans,
	kprrel,	ktrans,
	NULL,	NULL,	ktrans,
	ktrans,	ktrans,	NULL,
	// right hand
	ktrans,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	NULL,
	ktrans,	sshprre,	sshprre,	sshprre,	sshprre,	sshprre,	sshprre,
	kprrel,	kprrel,	sshprre,	sshprre,	kprrel,	sshprre,
	ktrans,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	sshprre,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	kprrel,	ktrans,
	ktrans,	NULL,	NULL,
	ktrans,	ktrans,	ktrans
),
// LAYER 2
KB_MATRIX_LAYER(
	// unused
	NULL,
	// left hand
	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	ktrans,	ktrans,	sshprre,	sshprre,	sshprre,	kprrel,	ktrans,
	ktrans,	ktrans,	sshprre,	sshprre,	sshprre,	kprrel,
	ktrans,	sshprre,	kprrel,	kprrel,	sshprre,	kprrel,	ktrans,
	NULL,	ktrans,	ktrans,	ktrans,	ktrans,
	kprrel,	kprrel,
	NULL,	NULL,	kprrel,
	kprrel,	kprrel,	NULL,
	// right hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	NULL,
	ktrans,	sshprre,	kprrel,	kprrel,	kprrel,	ktrans,	kprrel,
	sshprre,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	ktrans,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,
	ktrans,	NULL,	NULL,
	ktrans,	ktrans,	kprrel
),
// LAYER 3
KB_MATRIX_LAYER(
	// unused
	NULL,
	// left hand
	NULL,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	kprrel,	ktrans,	kprrel,	kprrel,	kprrel,	ktrans,	ktrans,
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	ktrans,
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	ktrans,	ktrans,
	NULL,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,
	NULL,	NULL,	ktrans,
	kprrel,	kprrel,	ktrans,
	// right hand
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	NULL,
	ktrans,	ktrans,	ktrans,	kprrel,	ktrans,	ktrans,	ktrans,
	ktrans,	kprrel,	kprrel,	kprrel,	ktrans,	ktrans,
	ktrans,	ktrans,	ktrans,	kprrel,	ktrans,	ktrans,	ktrans,
	kprrel,	kprrel,	kprrel,	ktrans,	NULL,
	NULL,	NULL,
	NULL,	NULL,	NULL,
	NULL,	ktrans,	ktrans
),
// LAYER 4
KB_MATRIX_LAYER(
	// unused
	NULL,
	// left hand
	NULL,	kprrel,	kprrel,	NULL,	NULL,	NULL,	NULL,
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,
	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,
	NULL,	NULL,	NULL,	NULL,	NULL,
	NULL,	NULL,
	NULL,	NULL,	NULL,
	NULL,	NULL,	NULL,
	// right hand
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	NULL,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,
	ktrans,	NULL,	NULL,
	ktrans,	ktrans,	ktrans
),
};
// ----------------------------------------------------------------------------
