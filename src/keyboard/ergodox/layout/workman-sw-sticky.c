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
#define  lpush6   &kbfun_layer_push_5

#define  lsticky1   &kbfun_layer_sticky_1
#define  lsticky2   &kbfun_layer_sticky_2
#define  lsticky3   &kbfun_layer_sticky_3

#define  lpop     &kbfun_layer_pop_all
#define  lpop1    &kbfun_layer_pop_1
#define  lpop2    &kbfun_layer_pop_2
#define  lpop3    &kbfun_layer_pop_3
#define  lpop4    &kbfun_layer_pop_4
#define  lpop5    &kbfun_layer_pop_5
#define  lpop6    &kbfun_layer_pop_5

#define  dbtldr   &kbfun_jump_to_bootloader
#define  sshprre  &kbfun_shift_press_release
#define  sguprre  &kbfun_gui_press_release
#define  sctprre  &kbfun_ctrl_press_release
#define  ssgprre  &kbfun_shift_gui_press_release
#define  sagprre  &kbfun_alt_gui_press_release

// ----------------------------------------------------------------------------

// LAYOUT ---------------------------------------------------------------------
const uint8_t PROGMEM _kb_layout[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// LAYER 0
KB_MATRIX_LAYER(
	// unused
		0,
	// left hand
	_grave  , _stop  , _X , _C , _V  , _F , 5      ,
	_slash  , _Q     , _D , _R , _W  , _B , _tab   ,
	_shiftL , _A     , _S , _H , _T  , _G ,
	_ctrlL  , _Z     , _X , _M , _C  , _V , _enter ,
	_pageU  , _pageD , 1  , 3  , _bs ,
	_del  , 1      ,
	0     , 0      , _altL ,
	_guiL , _space , _esc  ,
	// right hand
	_dash     , _mute , _Z , _space , _Z      , _C         , _equal    ,
	_bracketL , _J    , _F , _U     , _P      , _semicolon , _bracketR ,
	_Y        , _N    , _E , _O     , _I      , _shiftR    ,
	2         , _K    , _L , _comma , _period , _quote     , _ctrlR    ,
	_space    , 1     , 3  , _arrowL , _arrowR ,
   _home  , _end,
	_altR,	0,	0,
	_guiR ,	_bs,	_enter
),
// LAYER 1
KB_MATRIX_LAYER(
	// unused
	0,
	// left hand
	0      , 0         , 0         , 0     , 0    , 0      , 0 ,
	_grave , _bracketL , _bracketR , 0x2F  , 0x30 , _5     , 0 ,
	_7     , 0x34      , _slash    , _dash , _0   , 0x33   ,
	0x35   , _6        , _7        , _8    , _9   , _equal , 0 ,
	0      , 0         , 0         , 0     , 0    ,
	_shiftL,	1,
	0,	0,	0,
	0,	0,	0,
	// right hand
	0          , 0  , 0       , 0  , 0      , 0      , 1          ,
	0          , _4 , _dash   , _3 , _2     , _1     , _6         ,
	_backslash , _1 , _9      , _0 , _equal , _slash ,
	0          , _8 , _2      , _3 , _4     , _5     , _backslash ,
	0          , 0  , 0 , 0  , 0      ,
	0      , 0 ,
	0      , 0 , 0 ,
	_ctrlR , 0 , 0
),
// LAYER 2
KB_MATRIX_LAYER(
	// unused
	0,
	// left hand
	0 , _1 , _2        , _3 , _4   , _5         , 6 ,
	0 , 0  , _A        , _B , _C   , _sub_kp    , 0 ,
	0 , 0  , _D        , _E , _F   , _add_kp    ,
	0 , _4 , _equal_kp , _X , 0x33 , _semicolon , 0 ,
	0 , 0  , 0         , 0  , 0    ,
	0 , 0  ,
	0 , 0  , 0 ,
	0 , 0  , 0 ,
	// right hand
	0     , _6          , _7    , _8    , _9      , _0      , 2       ,
	0     , _9          , _7_kp , _8_kp , _9_kp   , _div_kp , _sub_kp ,
	_0    , _4_kp       , _5_kp , _6_kp , _mul_kp , _add_kp ,
	2     , _dec_del_kp , _1_kp , _2_kp , _3_kp   , 0       , _enter  ,
	_0_kp , _dec_del_kp , 0     , 0     , 0       ,
	0 , 0 ,
	0 , 0 , 0     ,
	0 , 0 ,0
),
// LAYER 3
KB_MATRIX_LAYER(
	// unused
	0,
	// left hand
	0       , _F1 , _F2     , _F3     , _F4     , _F5      , _F11 ,
	0       , 0   , 0       , _arrowU , 0       , _volumeU , 0    ,
	_shiftL , 0   , _arrowL , _arrowD , _arrowR , _volumeD ,
	0       , 0   , 0       , 0       , 0       , 0        , 6    ,
	0       , 0   , 0       , 0       , 0       ,
	0,	0,
	0,	0,	0,
	0,	0,	0,
	// right hand
	_F12 , _F6     , _F7     , _F8     , _F9 , _F10    , 3 ,
	5    , 0       , 0       , _arrowU , 0   , 0       , 4 ,
	0    , _arrowL , _arrowD , _arrowR , 0   , _shiftR ,
	0    , 0       , 0       , 0       , 0   , 0       , 0 ,
	0    , 0       , 0       , 0       , 0   ,
	0,	0,
	0,	0,	0,
	0,	0,	0
),
// LAYER 4
KB_MATRIX_LAYER(
	// unused
	0,
	// left hand
	0,	KEY_1_Exclamation,	KEY_2_At,	KEY_3_Pound,	KEY_4_Dollar,	KEY_5_Percent,	KEY_Backslash_Pipe,
	KEY_Slash_Question,	KEY_q_Q,	KEY_w_W,	KEY_e_E,	KEY_r_R,	KEY_t_T,	KEY_Tab,
	KEY_LeftShift,	KEY_a_A,	KEY_s_S,	KEY_d_D,	KEY_f_F,	KEY_g_G,
	KEY_LeftControl,	KEY_z_Z,	KEY_x_X,	KEY_c_C,	KEY_v_V,	KEY_b_B,	KEY_ReturnEnter,
	0,	0,	0,	0,	0,
	0,	0,
	0,	0,	0,
	0,	0,	0,
	// right hand
	KEY_Dash_Underscore,	KEY_6_Caret,	KEY_7_Ampersand,	KEY_8_Asterisk,	KEY_9_LeftParenthesis,	KEY_0_RightParenthesis,	KEY_Equal_Plus,
	KEY_LeftBracket_LeftBrace,	KEY_y_Y,	KEY_u_U,	KEY_i_I,	KEY_o_O,	KEY_p_P,	KEY_RightBracket_RightBrace,
	KEY_h_H,	KEY_j_J,	KEY_k_K,	KEY_l_L,	KEY_Semicolon_Colon,	KEY_RightShift,
	2,	KEY_m_M,	KEY_n_N,	KEY_Comma_LessThan,	KEY_Period_GreaterThan,	KEY_SingleQuote_DoubleQuote,	KEY_RightControl,
	0,	0,	0,	0,	0,
	0,	0,
	0,	0,	0,
	0,	0,	0
),
// LAYER 5
KB_MATRIX_LAYER(
	// unused
	0,
	// left hand
	0 , _F1 , _F2 , _F3 , _F4 , _F5 , _F11 ,
	0 , 0   , 0   , 0   , 0   , 0   , 0    ,
	0 , 0   , 0   , 0   , 0   , 0   ,
	0 , 0   , 0   , 0   , 0   , 0   , 0    ,
	0 , 0   , 0   , 0   , 0   ,
	0,	0,
	0,	0,	0,
	0,	0,	0,
	// right hand
	_F12 , _F6 , _F7 , _F8 , _F9 , _F10 , 5 ,
	0    , 0   , 0   , 0   , 0   , 0    , 0 ,
	0    , 0   , 0   , 0   , 0   , 0    ,
	0    , 0   , 0   , 0   , 0   , 0    , 0 ,
	0    , 0   , 0   , 0   , 0   ,
	0,	0,
	0,	0,	0,
	0,	0,	0
),
// LAYER 6
KB_MATRIX_LAYER(
	// unused
	0,
	// left hand
	0 , 0  , 0  , 0  , 0  , 0  , 0 ,
	0 , 0  , 0  , 0  , 0  , 0  , 0 ,
	0 , _1 , _2 , _3 , _4 , _5 ,
	0 , 0  , 0  , 0  , 0  , 0  , 0 ,
	0 , 0  , 0  , 0  , 0  ,
	0,	0,
	0,	0,	0,
	0,	0,	0,
	// right hand
	0,	0,	0,	0,	0,	0,	6,
	0,	0,	0,	0,	0,	0,	0,
	_6,	_7,	_8,	_9,	_0,	0,
	0,	0,	0,	0,	0,	0,	0,
	0,	0,	0,	0,	0,
	0,	0,
	0,	0,	0,
	0,	0,	0
),
};
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// PRESS ----------------------------------------------------------------------
const void_funptr_t PROGMEM _kb_layout_press[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// LAYER 0
KB_MATRIX_LAYER(
	// unused
	NULL,
	// left hand
	kprrel , kprrel , sguprre  , sguprre  , sguprre , sguprre , lpush5 ,
	kprrel , kprrel , kprrel   , kprrel   , kprrel  , kprrel  , kprrel ,
	kprrel , kprrel , kprrel   , kprrel   , kprrel  , kprrel  ,
	kprrel , kprrel , kprrel   , kprrel   , kprrel  , kprrel  , kprrel ,
	kprrel , kprrel , lsticky1 , lsticky3 , kprrel  ,
	kprrel , lpush1 ,
	NULL,	NULL,	kprrel,
	kprrel,	kprrel,	kprrel,
	// right hand
	kprrel , kprrel   , sguprre  , ssgprre , ssgprre , sctprre , kprrel ,
	kprrel , kprrel   , kprrel   , kprrel  , kprrel  , kprrel  , kprrel ,
	kprrel , kprrel   , kprrel   , kprrel  , kprrel  , kprrel  ,
	lpush2 , kprrel   , kprrel   , kprrel  , kprrel  , kprrel  , kprrel ,
	kprrel , lsticky1 , lsticky3 , sguprre  , sguprre ,
	kprrel   , kprrel  ,
	kprrel  , NULL    , NULL   ,
	kprrel  , kprrel  , kprrel
),
// LAYER 1
KB_MATRIX_LAYER(
	// unused
	NULL,
	// left hand
	lpop    , ktrans  , ktrans , ktrans  , ktrans  , ktrans  , ktrans ,
	kprrel  , kprrel  , kprrel , sshprre , sshprre , sshprre , ktrans ,
	sshprre , sshprre , kprrel , kprrel  , kprrel  , sshprre ,
	sshprre , kprrel  , kprrel , kprrel  , kprrel  , sshprre , ktrans ,
	ktrans  , ktrans  , ktrans , ktrans  , ktrans  ,
	kprpst , lpop1 ,
	NULL   , NULL   , ktrans ,
	ktrans , ktrans , ktrans ,
	// right hand
	ktrans , ktrans  , ktrans  , ktrans  , ktrans  , ktrans  , lpop1   ,
	ktrans , sshprre , sshprre , sshprre , sshprre , sshprre , sshprre ,
	kprrel , kprrel  , sshprre , sshprre , kprrel  , sshprre ,
	ktrans , sshprre , kprrel  , kprrel  , kprrel  , kprrel  , sshprre ,
	ktrans , ktrans  , ktrans  , ktrans  , ktrans  ,
	ktrans,	ktrans,
	ktrans,	NULL,	NULL,
	kprpst,	ktrans,	ktrans
),
// LAYER 2
KB_MATRIX_LAYER(
    // unused
	NULL,
	// left hand
	lpop   , kprrel  , kprrel  , kprrel  , kprrel  , kprrel , lpush5 ,
	ktrans , ktrans  , sshprre , sshprre , sshprre , kprrel , ktrans ,
	ktrans , ktrans  , sshprre , sshprre , sshprre , kprrel ,
	ktrans , sshprre , kprrel  , kprrel  , sshprre , kprrel , ktrans ,
	ktrans , ktrans  , ktrans  , ktrans  , ktrans  ,
	ktrans,	ktrans,
	NULL,	NULL,	ktrans,
	ktrans,	ktrans,	ktrans,
	// right hand
	ktrans  , kprrel  , kprrel , kprrel , kprrel , kprrel , lpop2  ,
	ktrans  , sshprre , kprrel , kprrel , kprrel , kprrel , kprrel ,
	sshprre , kprrel  , kprrel , kprrel , kprrel , kprrel ,
	lpop2   , kprrel  , kprrel , kprrel , kprrel , ktrans , kprrel ,
	kprrel  , kprrel  , ktrans , ktrans , ktrans ,
	ktrans,	ktrans,
	ktrans,	NULL,	NULL,
	ktrans,	ktrans,	ktrans
),
// LAYER 3
KB_MATRIX_LAYER(
	// unused
	NULL,
	// left hand
	lpop,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	ktrans,	ktrans,	ktrans,	kprrel,	ktrans,	kprrel,	ktrans,
	kprpst,	ktrans,	kprrel,	kprrel,	kprrel,	kprrel,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	lpush6,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,
	NULL,	NULL,	ktrans,
	ktrans,	ktrans,	ktrans,
	// right hand
	kprrel , kprrel , kprrel , kprrel , kprrel , kprrel , lpop3  ,
	lpush5 , ktrans , ktrans , kprrel , ktrans , ktrans , lpush4 ,
	ktrans , kprrel , kprrel , kprrel , ktrans , kprpst ,
	ktrans , ktrans , ktrans , ktrans , ktrans , ktrans , ktrans ,
	ktrans , ktrans , ktrans , ktrans , ktrans ,
	ktrans,	ktrans,
	ktrans,	NULL,	NULL,
	ktrans,	ktrans,	ktrans
),
// LAYER 4
KB_MATRIX_LAYER(
	// unused
	NULL,
	// left hand
	lpop,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,
	NULL,	NULL,	ktrans,
	ktrans,	ktrans,	ktrans,
	// right hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	lpush2,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,
	ktrans,	NULL,	NULL,
	ktrans,	ktrans,	ktrans
),
// LAYER 5
KB_MATRIX_LAYER(
	// unused
	NULL,
	// left hand
	dbtldr , kprrel , kprrel , kprrel , kprrel , kprrel , kprrel ,
	ktrans , ktrans , ktrans , ktrans , ktrans , ktrans , ktrans ,
	ktrans , ktrans , ktrans , ktrans , ktrans , ktrans ,
	ktrans , ktrans , ktrans , ktrans , ktrans , ktrans , ktrans ,
	ktrans , ktrans , ktrans , ktrans , ktrans ,
	ktrans,	ktrans,
	ktrans,	NULL,	NULL,
	ktrans,	ktrans,	ktrans,
	// right hand
	kprrel , kprrel , kprrel , kprrel , kprrel , kprrel , lpop5  ,
	ktrans , ktrans , ktrans , ktrans , ktrans , ktrans , ktrans ,
	ktrans , ktrans , ktrans , ktrans , ktrans , ktrans ,
	ktrans , ktrans , ktrans , ktrans , ktrans , ktrans , ktrans ,
	ktrans , ktrans , ktrans , ktrans , ktrans ,
	ktrans,	ktrans,
	ktrans,	NULL,	NULL,
	ktrans,	ktrans,	ktrans
),
// LAYER 6
KB_MATRIX_LAYER(
	// unused
	NULL,
	// left hand
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,
	NULL,	NULL,	ktrans,
	ktrans,	ktrans,	ktrans,
	// right hand
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	lpop6,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	ktrans,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,
	ktrans,	NULL,	NULL,
	ktrans,	ktrans,	ktrans
),
};
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// RELEASE --------------------------------------------------------------------
const void_funptr_t PROGMEM _kb_layout_release[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
// LAYER 0
KB_MATRIX_LAYER(
	// unused
	NULL,
	// left hand
	kprrel , kprrel , sguprre  , sguprre  , sguprre , sguprre , NULL ,
	kprrel , kprrel , kprrel   , kprrel   , kprrel  , kprrel  , kprrel ,
	kprrel , kprrel , kprrel   , kprrel   , kprrel  , kprrel  ,
	kprrel , kprrel , kprrel   , kprrel   , kprrel  , kprrel  , kprrel ,
	kprrel , kprrel , lsticky1 , lsticky3 , kprrel  ,
	kprrel , NULL ,
	NULL   , NULL   , kprrel ,
	kprrel , kprrel , kprrel ,
	// right hand
	kprrel , kprrel   , sguprre  , ssgprre , ssgprre , sctprre , kprrel ,
	kprrel , kprrel   , kprrel   , kprrel  , kprrel  , kprrel  , kprrel ,
	kprrel , kprrel   , kprrel   , kprrel  , kprrel  , kprrel  ,
	NULL   , kprrel   , kprrel   , kprrel  , kprrel  , kprrel  , kprrel ,
	kprrel , lsticky1 , lsticky3 , sguprre  , sguprre ,
	kprrel   , kprrel,
	kprrel  , NULL    , NULL   ,
	kprrel  , kprrel  , kprrel
),
// LAYER 1
KB_MATRIX_LAYER(
	// unused
	NULL,
	// left hand
	NULL    , ktrans  , ktrans , ktrans  , ktrans  , ktrans  , ktrans ,
	kprrel  , kprrel  , kprrel , sshprre , sshprre , sshprre , ktrans ,
	sshprre , sshprre , kprrel , kprrel  , kprrel  , sshprre ,
	sshprre , kprrel  , kprrel , kprrel  , kprrel  , sshprre , ktrans ,
	ktrans  , ktrans  , ktrans , ktrans  , ktrans  ,
	kprpst,	NULL,
	NULL,	NULL,	ktrans,
	ktrans,	ktrans,	ktrans,
	// right hand
	ktrans , ktrans  , ktrans  , ktrans  , ktrans  , ktrans  , NULL    ,
	ktrans , sshprre , sshprre , sshprre , sshprre , sshprre , sshprre ,
	kprrel , kprrel  , sshprre , sshprre , kprrel  , sshprre ,
	ktrans , sshprre , kprrel  , kprrel  , kprrel  , kprrel  , sshprre ,
	ktrans , ktrans  , ktrans  , ktrans  , ktrans  ,
	ktrans,	ktrans,
	ktrans,	NULL,	NULL,
	kprpst,	ktrans,	ktrans
),
// LAYER 2
KB_MATRIX_LAYER(
	// unused
	NULL,
	// left hand
	NULL   , kprrel  , kprrel  , kprrel  , kprrel  , kprrel , NULL   ,
	ktrans , ktrans  , sshprre , sshprre , sshprre , kprrel , ktrans ,
	ktrans , ktrans  , sshprre , sshprre , sshprre , kprrel ,
	ktrans , sshprre , kprrel  , kprrel  , sshprre , kprrel , ktrans ,
	ktrans , ktrans  , ktrans  , ktrans  , ktrans  ,
	ktrans , ktrans ,
	NULL   , NULL   , ktrans ,
	ktrans , ktrans , ktrans ,
	// right hand
	ktrans  , kprrel  , kprrel , kprrel , kprrel , kprrel , NULL   ,
	ktrans  , sshprre , kprrel , kprrel , kprrel , kprrel , kprrel ,
	sshprre , kprrel  , kprrel , kprrel , kprrel , kprrel ,
	NULL    , kprrel  , kprrel , kprrel , kprrel , ktrans , kprrel ,
	kprrel  , kprrel  , ktrans , ktrans , ktrans ,
	ktrans , ktrans ,
	ktrans , NULL   , NULL   ,
	ktrans , ktrans , ktrans
),
// LAYER 3
KB_MATRIX_LAYER(
	// unused
	NULL,
	// left hand
	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	ktrans,	ktrans,	ktrans,	kprrel,	ktrans,	kprrel,	ktrans,
	kprpst,	ktrans,	kprrel,	kprrel,	kprrel,	kprrel,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	NULL,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,
	NULL,	NULL,	ktrans,
	ktrans,	ktrans,	ktrans,
	// right hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	NULL,
	lpop5,	ktrans,	ktrans,	kprrel,	ktrans,	ktrans,	NULL,
	ktrans,	kprrel,	kprrel,	kprrel,	ktrans,	kprpst,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,
	ktrans,	NULL,	NULL,
	ktrans,	ktrans,	ktrans
),
// LAYER 4
KB_MATRIX_LAYER(
	// unused
	NULL,
	// left hand
	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,
	NULL,	NULL,	ktrans,
	ktrans,	ktrans,	ktrans,
	// right hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,
	ktrans,	NULL,	NULL,
	ktrans,	ktrans,	ktrans
),
// LAYER 5
KB_MATRIX_LAYER(
	// unused
	NULL,
	// left hand
	NULL,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,
	ktrans,	NULL,	NULL,
	ktrans,	ktrans,	ktrans,
	// right hand
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	NULL,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,
	ktrans,	NULL,	NULL,
	ktrans,	ktrans,	ktrans
),
// LAYER 6
KB_MATRIX_LAYER(
	// unused
	NULL,
	// left hand
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,
	NULL,	NULL,	ktrans,
	ktrans,	ktrans,	ktrans,
	// right hand
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	NULL,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	kprrel,	kprrel,	kprrel,	kprrel,	kprrel,	ktrans,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,	ktrans,	ktrans,	ktrans,
	ktrans,	ktrans,
	ktrans,	NULL,	NULL,
	ktrans,	ktrans,	ktrans
),
};
// ----------------------------------------------------------------------------
