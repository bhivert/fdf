/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhivert <bhivert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 10:03:23 by bhivert           #+#    #+#             */
/*   Updated: 2014/12/21 21:52:00 by bhivert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_H
# define LIBUI_H

# include <sys/time.h>
# include <mlx.h>
# include <pthread.h>

# include "libft.h"
# include "ft_printf.h"

# include "libui_types.h"

# define UI_DFL_GROUND_COLOR	0xC8C8C8

t_win	*ui_new_window(char *caption, int width, int height);
int		ui_new_group(t_win *win, int width, int height);
int		ui_new_image(t_win *win, int width, int height);
int		ui_new_button(t_win *win, char *caption);
int		ui_new_label(t_win *win, char *caption);

void	ui_window_set_user_thread(t_win *win, void (*thread)(void *), \
			void *param);
void	ui_window_set_color(t_win *win, unsigned int color);
void	ui_window_set_key_hook(t_win *win, void (key_hook)(void *, int, int), \
			void *key_hook_param);

void	ui_widget_set_caption(t_win *win, int wid, char *caption);
void	ui_widget_set_size(t_win *win, int wid, int width, int height);
void	ui_widget_set_pos(t_win *win, int wid, size_t x, size_t y);
void	ui_widget_set_color(t_win *win, int wid, unsigned int color);
void	ui_widget_set_group(t_win *win, int wid, int gid);

void	ui_widget_set_align_grid(t_win *win, int wid, t_ui_size *grid_size, \
			size_t spacing);
void	ui_widget_set_align_file(t_win *win, int wid, t_ui_size *spacing);
void	ui_widget_set_align_list(t_win *win, int wid, t_ui_size *spacing);

void	ui_widget_set_hook_param(t_win *win, int wid, int hook_id, \
			void *hook_param);
void	ui_widget_set_click_hook(t_win *win, int wid, \
			void (*hook_fct)(int, t_bool, void *));
void	ui_widget_set_focus_hook(t_win *win, int wid, \
			void (*hook_fct)(int, t_bool, void *));
void	ui_widget_set_enable_hook(t_win *win, int wid, \
			void (*hook_fct)(int, t_bool, void *));
void	ui_widget_set_visible_hook(t_win *win, int wid, \
			void (*hook_fct)(int, t_bool, void *));
void	ui_widget_set_refresh_hook(t_win *win, int wid, \
			void (*hook_fct)(int, void *));
/*
** ================================================
** |  Tools functions for:						  |
** |	void (*hook_fct)(t_wid *, t_bool, int)	  |
*/
void	ui_hook_set_click(t_win *win, int wid, t_bool state);
void	ui_hook_set_focus(t_win *win, int wid, t_bool state);
void	ui_hook_set_enable(t_win *win, int wid, t_bool state);
void	ui_hook_set_visible(t_win *win, int wid, t_bool state);
t_bool	ui_hook_widget_is_enable(t_win *win, int wid);
t_bool	ui_hook_widget_is_visible(t_win *win, int wid);
/*
** ================================================
*/

void	ui_widget_set_click_bind(t_win *win, int wid, int target, \
			void (*bind_fct)(t_wid *, t_bool, int));
void	ui_widget_set_focus_bind(t_win *win, int wid, int target, \
			void (*bind_fct)(t_wid *, t_bool, int));
void	ui_widget_set_enable_bind(t_win *win, int wid, int target, \
			void (*bind_fct)(t_wid *, t_bool, int));
void	ui_widget_set_visible_bind(t_win *win, int wid, int target, \
			void (*bind_fct)(t_wid *, t_bool, int));
/*
** ================================================
** |  Tools functions for:						  |
** |	void (*bind_fct)(t_wid *, t_bool, int)	  |
*/
void	ui_bind_set_click(t_wid *wid, t_bool state);
void	ui_bind_set_focus(t_wid *wid, t_bool state);
void	ui_bind_bind_set_enable(t_wid *wid, t_bool state);
void	ui_bind_bind_set_visible(t_wid *wid, t_bool state);
t_bool	ui_bind_widget_is_enable(t_wid *wid);
t_bool	ui_bind_widget_is_visible(t_wid *wid);
/*
** ================================================
*/

int		ui_refresh(void *win);
void	ui_loop(t_win *win);

t_img	*ui_widget_get_timg(t_win *win, int wid);

void	ui_type_set_pos(t_ui_pos *pos, int x, int y);
void	ui_type_set_size(t_ui_size *size, int height, int width);

int		ui_put_pixel_to_img(t_img *img, int x, int y, unsigned int color);
int		ui_clear_img(t_img *img, unsigned int color);
int		ui_draw_vertical_to_img(t_img *img, int x, int y[2], \
			unsigned int color);
int		ui_draw_horizontal_to_img(t_img *img, int x[2], int y, \
			unsigned int color);
void	ui_draw_square_to_img(t_img *img, t_ui_pos *pos, size_t s, \
			unsigned int color);
void	ui_draw_rectangle_to_img(t_img *img, t_ui_pos *pos, t_ui_size *size, \
			unsigned int color);
int		ui_draw_circle_to_img(t_img *img, t_ui_pos *pos, size_t r, \
			unsigned int color);
void	ui_draw_disk_to_img(t_img *img, t_ui_pos *pos, size_t r, \
			unsigned int color);

#endif
