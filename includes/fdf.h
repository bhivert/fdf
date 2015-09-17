/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhivert <bhivert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 09:42:47 by bhivert           #+#    #+#             */
/*   Updated: 2015/09/17 11:15:32 by bhivert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_printf.h"
# include "ft_scanf.h"
# include "ft_containers.h"
# include "libui.h"
# include "lib3d.h"
# include <fcntl.h>
# include <limits.h>

typedef struct	s_env
{
	int			ac;
	char		**av;
	t_container	*file;
	size_t		max_line;
	int			min_value;
	int			max_value;
	t_win		*win;
	int			img_id;
	int			scaling;
	double		**scale_mtx;
	t_vector	up;
	t_vector	right;
	double		**model;
	double		**m2w;
	double		**iso_proj;
	double		**init;
}				t_env;

typedef struct	s_bresenham
{
	int			dX;
	int			dY;
	int			X_inc;
	int			Y_inc;
	int			err;
	int			err_inc;
	int			err_dec;
}				t_bresenham;

int				fdf_get_file(t_env *e);
int				fdf_create_ui(t_env *e);
void			fdf_bresenham(t_img *img, t_vertex *v0, t_vertex *v1);
void			fdf_draw(int w_id, void *env);

#endif
