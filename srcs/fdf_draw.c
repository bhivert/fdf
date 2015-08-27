
#include "fdf.h"

static void	fdf_convert_to_iso_proj(t_env *e, t_vertex *v0, t_vertex *v1)
{
	t_vertex	v0_tmp;
	t_img		*img;

	v0_tmp = vertex_mult_matrix(v0, e->iso_proj);
	*v1 = vertex_mult_matrix(v1, e->iso_proj);
	v0_tmp = vertex_mult_matrix(&v0_tmp, e->scale);
	*v1 = vertex_mult_matrix(v1, e->scale);
	v0_tmp = vertex_mult_matrix(&v0_tmp, e->translate);
	*v1 = vertex_mult_matrix(v1, e->translate);
	img = ui_widget_get_timg(e->win, e->img_id);
	fdf_bresenham(img, &v0_tmp, v1);
}

static void	fdf_manage_segment(t_env *e, int x, int y, int value)
{
	t_vertex	v0;
	t_vertex	v1;
	t_container	**line;

	v0 = new_vertex(x * 10, y * 10, value, NULL);
	line = ft_at_index(e->file, y);
	if (ft_at_index(*line, x + 1))
	{
		value = *(int *)ft_at_index(*line, x + 1);
		v1 = new_vertex((x + 1) * 10, y * 10, value, NULL);
		fdf_convert_to_iso_proj(e, &v0, &v1);
	}
	if ((line = ft_at_index(e->file, y + 1)))
	{
		if (ft_at_index(*line, x))
		{
			value = *(int *)ft_at_index(*line, x);
			v1 = new_vertex(x * 10, (y + 1) * 10, value, NULL);
			fdf_convert_to_iso_proj(e, &v0, &v1);
		}
	}
}

static void	fdf_generate_matrix(t_env *e)
{
	e->iso_proj = matrix_iso_proj();
	e->translate = matrix_trans( \
			(e->win->size.width >> 1) - ((e->max_line >> 1) * 10), \
			(e->win->size.height >> 1) - ((ft_size(e->file) >> 1) * 10), 0);
	e->scale = matrix_scale(1, 1, 1);
}

static void	fdf_free_matrix(t_env *e)
{
	free_matrix(e->iso_proj);
	e->iso_proj = NULL;
	free_matrix(e->translate);
	e->translate = NULL;
	free_matrix(e->scale);
	e->scale = NULL;
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
	fdf_generate_matrix(e);
	while (x = -1, ++y < ft_size(e->file))
	{
		line = ft_at_index(e->file, y);
		while (line && ++x < ft_size(*(t_container **)line))
		{
			if (!ft_at_index(*(t_container **)line, x))
				break ;
			value = *(int *)ft_at_index(*(t_container **)line, x);
			fdf_manage_segment(e, x, y, value);
		}
	}
	fdf_free_matrix(e);
}
