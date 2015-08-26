
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




	size_t	i;
	size_t	j;
	t_container	*line;

	i = -1;

	while (j = -1, ++i < ft_size(env.file))
	{
		line = ft_at_index(env.file, i);
		while (++j < ft_size(*(t_container **)line))
		{
			ft_putnbr(*((int *)ft_at_index(*(t_container **)line, j)));
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	ui_loop(env.win);
	return (EXIT_SUCCESS);
}
