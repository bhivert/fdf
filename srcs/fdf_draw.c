/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhivert <bhivert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 13:46:20 by bhivert           #+#    #+#             */
/*   Updated: 2015/09/20 13:49:10 by bhivert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf_convert_to_proj(t_env *e, t_vertex *vtx)
{
	*vtx = vertex_mult_matrix(vtx, e->init);
	*vtx = vertex_mult_matrix(vtx, e->model);
	*vtx = vertex_mult_matrix(vtx, e->scale_mtx);
	*vtx = vertex_mult_matrix(vtx, e->iso_proj);
	*vtx = vertex_mult_matrix(vtx, e->m2w);
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
	if ((line = ft_at_index(e->file, y)) && img && ft_at_index(*line, x + 1))
	{
		value = *(int *)ft_at_index(*line, x + 1);
		color = set_color(e, value);
		v1 = new_vertex((x + 1), y, value, &color);
		fdf_convert_to_proj(e, &v1);
		fdf_bresenham(img, &v0, &v1);
	}
	if (img && (line = ft_at_index(e->file, y + 1)) && ft_at_index(*line, x))
	{
		value = *(int *)ft_at_index(*line, x);
		color = set_color(e, value);
		v1 = new_vertex(x, (y + 1), value, &color);
		fdf_convert_to_proj(e, &v1);
		fdf_bresenham(img, &v0, &v1);
	}
}

static void		fdf_generate_matrix(t_env *e)
{
	e->scale_mtx = matrix_scale(e->scaling, e->scaling, e->scaling);
}

static void		fdf_free_matrix(t_env *e)
{
	free_matrix(e->scale_mtx);
	e->scale_mtx = NULL;
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
	while (++y < ft_size(e->file))
	{
		x = -1;
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
