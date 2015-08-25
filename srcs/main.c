
#include "fdf.h"

t_container	*fdf_get_file(char **av)
{
	int			fd;
	char		*line;
	t_container	*file;
	int			value;

	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (ft_printf("%s unable to open %s.\n", av[0], av[1]), NULL);
	if (!(file = ft_new_container(VECTOR, sizeof(t_container *))))
		return (NULL);
	while (ft_gnl(fd, &line) > 0)
	{
		ft_push_back(file, ft_new_container(VECTOR, sizeof(int)));
		while (ft_sscanf(line, "%d %s", &value, line) > 1)
			ft_push_back(ft_at_index(file, ft_size(file) - 1), &value);
		free(line);
	}
	return (file);
}

int		main(int ac, char **av)
{

	if (ac < 2)
		return (ft_printf("%s file\n", av[0]), EXIT_SUCCESS);
	if (!fdf_get_file(av))
		return (EXIT_FAILURE);

	return (0);
}
