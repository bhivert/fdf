/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhivert <bhivert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 22:18:05 by bhivert           #+#    #+#             */
/*   Updated: 2015/09/13 12:05:00 by bhivert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_TYPES_H
# define LIBUI_TYPES_H

typedef const void		*t_img;

typedef struct			s_ui_pos
{
	int					x;
	int					y;
}						t_ui_pos;

typedef struct			s_ui_size
{
	int					width;
	int					height;
}						t_ui_size;

typedef struct			s_wid
{
	char				*caption;
	t_ui_size			size;
	t_ui_pos			pos;
	unsigned int		color;
	int					fps;
}						t_wid;

typedef struct s_wid	t_win;

# define UI_KEY_ESC			53
# define UI_KEY_ENTER		65293
# define UI_KEY_SPACE		32

# define UI_KEY_F1			65470
# define UI_KEY_F2			65471
# define UI_KEY_F3			65472
# define UI_KEY_F4			65473
# define UI_KEY_F5			65474
# define UI_KEY_F6			65475
# define UI_KEY_F7			65476
# define UI_KEY_F8			65477
# define UI_KEY_F9			65478
# define UI_KEY_F10			65479
# define UI_KEY_F11			65480
# define UI_KEY_F12			65481

# define UI_KEY_TAB			65289
# define UI_KEY_CAPSLOCK	65509
# define UI_KEY_LSHIFT		65505
# define UI_KEY_RSHIFT		65506
# define UI_KEY_LCTRL		65507
# define UI_KEY_RCTRL		65508
# define UI_KEY_ALT			65513
# define UI_KEY_ALTGR		65027

# define UI_KEY_INSERT		65379
# define UI_KEY_DELETE		65535
# define UI_KEY_HOME		65360
# define UI_KEY_END			65367
# define UI_KEY_PUP			116
# define UI_KEY_PDW			121

# define UI_KEY_LEFT		123
# define UI_KEY_UP			126
# define UI_KEY_RIGHT		124
# define UI_KEY_DOWN		125

# define UI_KEY_NUMLOCK		65407
# define UI_KEY_PAD_ENTER	65434
# define UI_KEY_PAD_0		65438
# define UI_KEY_PAD_1		65436
# define UI_KEY_PAD_2		65433
# define UI_KEY_PAD_3		65435
# define UI_KEY_PAD_4		86
# define UI_KEY_PAD_5		87
# define UI_KEY_PAD_6		88
# define UI_KEY_PAD_7		65429
# define UI_KEY_PAD_8		91
# define UI_KEY_PAD_9		65434
# define UI_KEY_PAD_P		69
# define UI_KEY_PAD_M		78
# define UI_KEY_PAD_X		65450
# define UI_KEY_PAD_D		65455

# define UI_KEY_0			48
# define UI_KEY_1			49
# define UI_KEY_2			50
# define UI_KEY_3			51
# define UI_KEY_4			52
# define UI_KEY_5			53
# define UI_KEY_6			54
# define UI_KEY_7			55
# define UI_KEY_8			56
# define UI_KEY_9			57

# define UI_KEY_A			97
# define UI_KEY_B			98
# define UI_KEY_C			99
# define UI_KEY_D			100
# define UI_KEY_E			101
# define UI_KEY_F			102
# define UI_KEY_G			103
# define UI_KEY_H			104
# define UI_KEY_I			105
# define UI_KEY_J			106
# define UI_KEY_K			107
# define UI_KEY_L			108
# define UI_KEY_M			109
# define UI_KEY_N			110
# define UI_KEY_O			111
# define UI_KEY_P			112
# define UI_KEY_Q			113
# define UI_KEY_R			114
# define UI_KEY_S			115
# define UI_KEY_T			116
# define UI_KEY_U			117
# define UI_KEY_V			118
# define UI_KEY_W			119
# define UI_KEY_X			120
# define UI_KEY_Y			121
# define UI_KEY_Z			122

#endif
