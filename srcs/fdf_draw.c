
#include "fdf.h"

#include "stdio.h"

static void	fdf_convert_to_proj(t_env *e, t_vertex *vtx)
{

	*vtx = vertex_mult_matrix(vtx, e->trans_mtx0);
	*vtx = vertex_mult_matrix(vtx, e->rot_X_mtx);
	*vtx = vertex_mult_matrix(vtx, e->rot_Z_mtx);
	*vtx = vertex_mult_matrix(vtx, e->iso_proj);
	*vtx = vertex_mult_matrix(vtx, e->scale_mtx);
	*vtx = vertex_mult_matrix(vtx, e->trans_mtx1);
}

static void		fdf_manage_segment(t_env *e, int x, int y, int value)
{
	t_vertex	v0;
	t_vertex	v1;
	t_container	**line;
	t_img		*img;

	img = ui_widget_get_timg(e->win, e->img_id);
	v0 = new_vertex(x, y, value, NULL);
	fdf_convert_to_proj(e, &v0);
	if (line = ft_at_index(e->file, y), img && ft_at_index(*line, x + 1))
	{
		value = *(int *)ft_at_index(*line, x + 1);
		v1 = new_vertex((x + 1), y, value, NULL);
		fdf_convert_to_proj(e, &v1);
		fdf_bresenham(img, &v0, &v1);
	}
	if (img && (line = ft_at_index(e->file, y + 1)))
	{
		if (ft_at_index(*line, x))
		{
			value = *(int *)ft_at_index(*line, x);
			v1 = new_vertex(x, (y + 1), value, NULL);
			fdf_convert_to_proj(e, &v1);
			fdf_bresenham(img, &v0, &v1);
		}
	}
}

static void		fdf_generate_matrix(t_env *e)
{
	e->trans_mtx0 = matrix_trans(-((e->max_line >> 1) + (e->max_line % 2)), \
				-((int)(ft_size(e->file) >> 1) + (int)(ft_size(e->file) % 2)), \
				0);
	e->trans_mtx1 = matrix_trans(e->win->size.width >> 1, \
				e->win->size.height >> 1, \
				0);
	e->scale_mtx = matrix_scale(e->scaling, e->scaling, e->scaling);
	e->rot_X_mtx = matrix_rotx(rad(e->rot_X));
	e->rot_Z_mtx = matrix_rotz(rad(e->rot_Z));
	e->iso_proj = matrix_iso_proj();
}

static void		fdf_free_matrix(t_env *e)
{
	free_matrix(e->trans_mtx0);
	e->trans_mtx0 = NULL;
	free_matrix(e->trans_mtx1);
	e->trans_mtx1 = NULL;
	free_matrix(e->scale_mtx);
	e->scale_mtx = NULL;
	free_matrix(e->rot_X_mtx);
	e->rot_X_mtx = NULL;
	free_matrix(e->rot_Z_mtx);
	e->rot_Z_mtx = NULL;
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
