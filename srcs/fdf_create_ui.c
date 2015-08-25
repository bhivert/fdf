
#include "fdf.h"

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
	// set key press hook
	return (0);
}
