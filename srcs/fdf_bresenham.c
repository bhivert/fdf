/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhivert <bhivert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 13:43:07 by bhivert           #+#    #+#             */
/*   Updated: 2015/09/20 13:43:10 by bhivert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_color	fdf_manage_color_increment(t_bresenham *b, \
					t_vertex *v0, t_vertex *v1)
{
	t_color	inc;
	int		r;

	r = (ft_abs(b->dx) >= ft_abs(b->dy)) ? ft_abs(b->dx) : ft_abs(b->dy);
	if (v0->z > v1->z)
	{
		inc.rgb[E_RED] = v0->color.rgb[E_RED] - v1->color.rgb[E_RED];
		inc.rgb[E_GREEN] = v0->color.rgb[E_GREEN] - v1->color.rgb[E_GREEN];
		inc.rgb[E_BLUE] = v0->color.rgb[E_BLUE] - v1->color.rgb[E_BLUE];
	}
	else
	{
		inc.rgb[E_RED] = v1->color.rgb[E_RED] - v0->color.rgb[E_RED];
		inc.rgb[E_GREEN] = v1->color.rgb[E_GREEN] - v0->color.rgb[E_GREEN];
		inc.rgb[E_BLUE] = v1->color.rgb[E_BLUE] - v0->color.rgb[E_BLUE];
	}
	if (r != 0)
	{
		inc.rgb[E_RED] /= r;
		inc.rgb[E_GREEN] /= r;
		inc.rgb[E_BLUE] /= r;
	}
	return (inc);
}

static void		fdf_bresenham_vertical_octant(t_img *img, t_bresenham *b, \
					t_vertex *v0, t_vertex *v1)
{
	int		x;
	int		y;
	t_color	color;
	t_color	color_inc;

	x = (int)v0->x;
	y = (int)v0->y;
	color = (v0->z > v1->z) ? v0->color : v1->color;
	color_inc = fdf_manage_color_increment(b, v0, v1);
	color_inc = color_mult(&color_inc, 1 / ((double)v0->y - v1->y));
	while ((b->y_inc < 0 && y > (int)v1->y) \
			|| (!(b->y_inc < 0) && y < (int)v1->y))
	{
		ui_put_pixel_to_img(img, x, y, color.hex);
		color = color_add(&color, &color_inc);
		if ((b->err += b->err_inc) >= 0)
		{
			x += b->x_inc;
			b->err += b->err_dec;
		}
		y += b->y_inc;
	}
	ui_put_pixel_to_img(img, x, y, color.hex);
}

static void		fdf_bresenham_horizontal_octant(t_img *img, t_bresenham *b, \
					t_vertex *v0, t_vertex *v1)
{
	int		x;
	int		y;
	t_color	color;
	t_color	color_inc;

	x = (int)v0->x;
	y = (int)v0->y;
	color = (v0->z > v1->z) ? v0->color : v1->color;
	color_inc = fdf_manage_color_increment(b, v0, v1);
	color_inc = color_mult(&color_inc, 1 / ((double)v0->x - v1->x));
	while ((b->x_inc < 0 && x > (int)v1->x) \
			|| (!(b->x_inc < 0) && x < (int)v1->x))
	{
		ui_put_pixel_to_img(img, x, y, color.hex);
		color = color_add(&color, &color_inc);
		if ((b->err += b->err_inc) >= 0)
		{
			y += b->y_inc;
			b->err += b->err_dec;
		}
		x += b->x_inc;
	}
	ui_put_pixel_to_img(img, x, y, color.hex);
}

void			fdf_bresenham(t_img *img, t_vertex *v0, t_vertex *v1)
{
	t_bresenham	b;

	b.dx = v1->x - v0->x;
	b.dy = v1->y - v0->y;
	b.x_inc = (b.dx < 0) ? -1 : 1;
	b.y_inc = (b.dy < 0) ? -1 : 1;
	if (ft_abs(b.dx) >= ft_abs(b.dy))
	{
		b.err = -ft_abs(b.dx);
		b.err_inc = ft_abs(b.dy) + ft_abs(b.dy);
		b.err_dec = -(ft_abs(b.dx) + ft_abs(b.dx));
		fdf_bresenham_horizontal_octant(img, &b, v0, v1);
	}
	else
	{
		b.err = -ft_abs(b.dy);
		b.err_inc = ft_abs(b.dx) + ft_abs(b.dx);
		b.err_dec = -(ft_abs(b.dy) + ft_abs(b.dy));
		fdf_bresenham_vertical_octant(img, &b, v0, v1);
	}
}
