#ifndef FDF_H
# define FDF_H

//#include "libft.h"
#include "ft_printf.h"
#include "ft_scanf.h"
#include "ft_containers.h"
#include "libui.h"
#include "lib3d.h"
#include <fcntl.h>

typedef struct	s_env
{
	int			ac;
	char		**av;
	t_container	*file;
	size_t		max_line;
	t_win		*win;
	int			img_id;
}				t_env;


int		fdf_get_file(t_env *e);
int		fdf_create_ui(t_env *e);

#endif