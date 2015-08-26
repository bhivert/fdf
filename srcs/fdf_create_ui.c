
#include "fdf.h"

void	fdf_key_hook(void *param, int code, int type)
{
	(void)param;
	if (type == 2)
		return ;
	if (code == UI_KEY_ESC)
		exit(EXIT_SUCCESS);
}

int		fdf_create_ui(t_env *e)
{
	if (!(e->win = ui_new_window(e->av[0], 800, 600)))
		return (ft_printf("%s unable to create windows.\n"), -1);
	ui_window_set_color(e->win, 0x000000);
	e->img_id = ui_new_image(e->win, e->win->size.width, e->win->size.height);
	if (e->img_id == -1)
		return (ft_printf("%s unable to create image.\n"), -1);
	ui_widget_set_color(e->win, e->img_id, 0x000000);
	ui_widget_set_hook_param(e->win, e->img_id, e->img_id, e);
	ui_window_set_key_hook(e->win, &fdf_key_hook, NULL);
	return (0);
}
