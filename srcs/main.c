
#include "fdf.h"

int			main(int ac, char **av)
{
	t_env	env;

	env.ac = ac;
	env.av = av;
	if (env.ac < 2)
		return (ft_printf("%s file\n", env.av[0]), EXIT_SUCCESS);
	if (fdf_get_file(&env) == -1)
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

	return (EXIT_SUCCESS);
}
