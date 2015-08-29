
#include "fdf.h"

t_cam	*init_camera(t_env *e)
{
	t_cam	*cam;

	if (!(cam = malloc(sizeof(t_cam))))
		return (NULL);
	cam->pos = new_vector((e->max_line >> 1) + (e->max_line % 2), \
			ft_size(e->file) << 1, 0, NULL);
	cam->dir = new_vector((e->max_line >> 1) + (e->max_line % 2), \
			(ft_size(e->file) >> 1) + (ft_size(e->file) % 2) , \
			0, NULL);
	cam->up = new_vector(0, 0, 1, NULL);
	return (cam);
}
