#ifndef FDF_H
# define FDF_H

#include "ft_printf.h"
#include "ft_scanf.h"
#include "ft_containers.h"
#include "libui.h"
#include "lib3d.h"
#include <fcntl.h>
#include <limits.h>

typedef struct	s_cam
{
	t_vector	pos;
	t_vector	dir;
	t_vector	up;
}				t_cam;

typedef struct	s_env
{
	int			ac;
	char		**av;
	t_container	*file;
	size_t		max_line;
	int			min_value;
	int			max_value;
	t_cam		*cam;
	t_win		*win;
	int			img_id;
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
t_cam			*init_camera(t_env *e);
void			fdf_draw(int w_id, void *env);

#endif
