
#include "fdf.h"

int		fdf_get_file(t_env *e)
{
	int			fd;
	char		*line;
	int			value;
	t_container	*tmp;
	int			out;

	if ((fd = open(e->av[1], O_RDONLY)) == -1)
		return (ft_printf("%s unable to open %s.\n", e->av[0], e->av[1]), -1);
	if (!(e->file = ft_new_container(VECTOR, sizeof(t_container *))))
		return (-1);
	while (ft_gnl(fd, &line) > 0 \
			&& (tmp = ft_new_container(VECTOR, sizeof(int))))
	{
		ft_push_back(e->file, &tmp);
		while ((out = ft_sscanf(line, "%d %s", &value, line)))
		{
			e->min_value = (value < e->min_value) ? value : e->min_value;
			e->max_value = (value > e->max_value) ? value : e->max_value;
			if (ft_push_back(tmp, &value), out == 1)
				break ;
		}
		e->max_line = (ft_size(tmp) < e->max_line) ? ft_size(tmp) : e->max_line;
		free(line);
	}
	return (close(fd), 0);
}
