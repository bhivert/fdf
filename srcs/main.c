
#include "fdf.h"

void		init_env(t_env *e, int ac, char **av)
{
	e->ac = ac;
	e->av = av;
	e->file = NULL;
	e->max_line = 0;
	e->win = NULL;
	e->img_id = -1;
}

int			main(int ac, char **av)
{
	t_env	env;

	init_env(&env, ac, av);
	if (env.ac < 2)
		return (ft_printf("%s file\n", env.av[0]), EXIT_SUCCESS);
	if ((fdf_get_file(&env) == -1) || (fdf_create_ui(&env) == -1))
		return (EXIT_FAILURE);
	ui_loop(env.win);
	return (EXIT_SUCCESS);
}
