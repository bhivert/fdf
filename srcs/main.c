
#include "fdf.h"

void		init_env(t_env *e, int ac, char **av)
{
	e->ac = ac;
	e->av = av;
	e->file = NULL;
	e->max_line = 0;
	e->min_value = INT_MAX;
	e->max_value = INT_MIN;
	e->win = NULL;
	e->img_id = -1;
	e->rot_X = 0;
	e->rot_Z = 0;
	e->scaling = 1;
	e->scale_mtx = NULL;
	e->trans_mtx0 = NULL;
	e->trans_mtx1 = NULL;
	e->rot_X_mtx = NULL;
	e->rot_Z_mtx = NULL;
	e->iso_proj = NULL;
}

int			main(int ac, char **av)
{
	t_env	env;

	init_env(&env, ac, av);
	if (env.ac < 2)
		return (ft_printf("%s file\n", env.av[0]), EXIT_SUCCESS);
	if ((fdf_get_file(&env) == -1) || (fdf_create_ui(&env) == -1))
		return (EXIT_FAILURE);
	ft_printf("%d\n", env.max_line);
	ui_loop(env.win);
	return (EXIT_SUCCESS);
}
