
#include "fdf.h"

void	fdf_key_hook(void *param, int code, int type)
{
	t_env	*e;

	e = (t_env *)param;
	if (type == 2)
		return ;
	if (code == UI_KEY_ESC)
		exit(EXIT_SUCCESS);
	else if (code == UI_KEY_RIGHT || code == UI_KEY_PAD_6)
		e->rot_Z = (e->rot_Z + 15) % 360;
	else if (code == UI_KEY_LEFT || code == UI_KEY_PAD_4)
		e->rot_Z = (e->rot_Z + 360 - 15) % 360;
	else if (code == UI_KEY_UP || code == UI_KEY_PAD_8)
		e->rot_X = (e->rot_X + 360 - 15) % 360;
	else if (code == UI_KEY_DOWN || code == UI_KEY_PAD_5)
		e->rot_X = (e->rot_X + 15) % 360;
	else if (code == UI_KEY_PUP || code == UI_KEY_PAD_P)
		++e->scaling;
	else if (code == UI_KEY_PDW || code == UI_KEY_PAD_M)
		e->scaling -= (e->scaling > 1) ? 1 : 0;
}

int		fdf_create_ui(t_env *e)
{
	if (!(e->win = ui_new_window(e->av[0], 1600, 1200)))
		return (ft_printf("%s unable to create windows.\n", e->av[0]), -1);
	ui_window_set_color(e->win, 0x000000);
	e->img_id = ui_new_image(e->win, e->win->size.width, e->win->size.height);
	if (e->img_id == -1)
		return (ft_printf("%s unable to create image.\n", e->av[0]), -1);
	ui_widget_set_color(e->win, e->img_id, 0x000000);
	ui_window_set_key_hook(e->win, &fdf_key_hook, e);
	ui_widget_set_hook_param(e->win, e->img_id, e->img_id, e);
	ui_widget_set_refresh_hook(e->win, e->img_id, &fdf_draw);
	return (0);
}
