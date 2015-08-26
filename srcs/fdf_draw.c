
#include "fdf.h"

static void	fdf_convert_to_iso_proj(t_env *e, t_vertex *v0, t_vertex *v1)
{
}

static void	fdf_manage_segment(t_env *e, int x, int y, int value)
{
	t_vertex	v0;
	t_vertex	v1;
	t_container	**line;

	v0 = new_vertex(x, y, value, NULL);
	line = ft_at_index(e->file, y);
	if (ft_at_index(*line, x + 1))
	{
		value = **(int **)ft_at_index(*line, x + 1);
		v1 = new_vertex(x + 1, y, value, NULL);
		fdf_convert_to_iso_proj(e, &v0, &v1);
	}
	if ((line = ft_at_index(e->file, y + 1)))
	{
		if (ft_at_index(*line, x))
		{
			value = **(int **)ft_at_index(*line, x);
			v1 = new_vertex(x, y + 1, value, NULL);
			fdf_convert_to_iso_proj(e, &v0, &v1);
		}
	}
}

void		fdf_draw(void *env)
{
	t_env		*e;
	size_t		x;
	size_t		y;
	t_container	*line;
	int			value;

	e = (t_env *)env;
	y = -1;
	while (x = -1, ++y < ft_size(e->file))
	{
		line = ft_at_index(e->file, y);
		while (line && ++x < ft_size(*(t_container **)line))
		{
			if (!ft_at_index(*(t_container **)line, x))
				break ;
			value = **(int **)ft_at_index(*(t_container **)line, x);
			fdf_manage_segment(e, x, y, value);
		}
	}
}
