
#include "fdf.h"

#include "stdio.h"

static void	fdf_convert_to_proj(t_env *e, t_vertex *vtx)
{
//	*vtx = vertex_mult_matrix(vtx, e->trans_mtx0);
//	*vtx = vertex_mult_matrix(vtx, e->rot_X_mtx);
//	*vtx = vertex_mult_matrix(vtx, e->rot_Z_mtx);
//	*vtx = vertex_mult_matrix(vtx, e->iso_proj);
//	*vtx = vertex_mult_matrix(vtx, e->scale_mtx);
//	*vtx = vertex_mult_matrix(vtx, e->trans_mtx1);
}

t_color			set_color(t_env *e, double z)
{
	t_color		max;
	t_color		min;
	t_color		zero;
	t_color		ret;
	double		fact_Z;

	max = new_color_hex(0xE67E30);
	min = new_color_hex(0x003BFF);
	zero = new_color_hex(0xFFFFFF);
	fact_Z = z * 100 / e->max_value;
	if (z == 0)
		return (zero);
	else if (z < 0)
	{
		ret = new_color_rgb(zero.rgb[E_RED] - (fact_Z * (min.rgb[E_RED] - zero.rgb[E_RED]) / 100), \
				zero.rgb[E_GREEN] - (fact_Z * (min.rgb[E_GREEN] - zero.rgb[E_GREEN]) / 100), \
				zero.rgb[E_BLUE] - (fact_Z * (min.rgb[E_BLUE] - zero.rgb[E_BLUE]) / 100));
	}
	else
	{
		ret = new_color_rgb(zero.rgb[E_RED] + (fact_Z * (max.rgb[E_RED] - zero.rgb[E_RED]) / 100), \
				zero.rgb[E_GREEN] + (fact_Z * (max.rgb[E_GREEN] - zero.rgb[E_GREEN]) / 100), \
				zero.rgb[E_BLUE] + (fact_Z * (max.rgb[E_BLUE] - zero.rgb[E_BLUE]) / 100));
	}
	return (ret);
}

static void		fdf_manage_segment(t_env *e, int x, int y, int value)
{
	t_vertex	v0;
	t_vertex	v1;
	t_container	**line;
	t_img		*img;
	t_color		color;

	img = ui_widget_get_timg(e->win, e->img_id);
	color = set_color(e, value);
	v0 = new_vertex(x, y, value, &color);
	fdf_convert_to_proj(e, &v0);
	if (line = ft_at_index(e->file, y), img && ft_at_index(*line, x + 1))
	{
		value = *(int *)ft_at_index(*line, x + 1);
		color = set_color(e, value);
		v1 = new_vertex((x + 1), y, value, &color);
		fdf_convert_to_proj(e, &v1);
		fdf_bresenham(img, &v0, &v1);
	}
	if (img && (line = ft_at_index(e->file, y + 1)))
	{
		if (ft_at_index(*line, x))
		{
			value = *(int *)ft_at_index(*line, x);
			color = set_color(e, value);
			v1 = new_vertex(x, (y + 1), value, &color);
			fdf_convert_to_proj(e, &v1);
			fdf_bresenham(img, &v0, &v1);
		}
	}
}

static void		fdf_generate_matrix(t_env *e)
{
	t_vector	up;
/*
	e->scale_mtx = matrix_scale(e->scaling, e->scaling, e->scaling);
	e->rot_X_mtx = matrix_rotx(rad(e->rot_X));

	up = new_vector(0, 0, 1, NULL);
	up = vector_mult_matrix(&up, e->rot_X_mtx);
	e->rot_Z_mtx = matrix_axis_rot(up.x, up.y, up.z, rad(e->rot_Z));

	e->trans_mtx0 = matrix_trans(-((double)e->max_line / 2.0), \
				-((double)ft_size(e->file) / 2.0), \
				0);

	e->iso_proj = matrix_iso_proj();
	e->trans_mtx1 = matrix_trans((double)e->win->size.width / 2.0, \
				(double)e->win->size.height / 2.0, \
				0);
				*/
}

static void		fdf_free_matrix(t_env *e)
{
}

void			fdf_draw(int id, void *env)
{
	t_env		*e;
	size_t		x;
	size_t		y;
	t_container	*line;
	int			value;

	(void)id;
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
	ui_refresh(e->win);
}
