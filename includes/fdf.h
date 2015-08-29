#ifndef FDF_H
# define FDF_H

#include "ft_printf.h"
#include "ft_scanf.h"
#include "ft_containers.h"
#include "libui.h"
#include "lib3d.h"
#include <fcntl.h>
#include <limits.h>

typedef struct	s_env
{
	int			ac;
	char		**av;
	t_container	*file;
	int			max_line;
	int			min_value;
	int			max_value;
	t_win		*win;
	int			img_id;
	int			rot_X;
	int			rot_Z;
	int			scaling;
	double		**scale_mtx;
	double		**trans_mtx0;
	double		**trans_mtx1;
	double		**rot_X_mtx;
	double		**rot_Z_mtx;
	double		**iso_proj;
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
