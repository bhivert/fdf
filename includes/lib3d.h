/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhivert <bhivert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 08:05:09 by bhivert           #+#    #+#             */
/*   Updated: 2015/11/15 16:08:59 by bhivert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB3D_H
# define LIB3D_H

# include <stdlib.h>
# include <math.h>

# ifndef T_COLOR
#  define T_COLOR

typedef union u_color	t_color;
# endif

# define VTR_IS_NULL(vtr)	(!vtr.x && !vtr.y && !vtr.z)

typedef struct s_vertex	t_vertex;
typedef struct s_vertex	t_vector;

double					rad(int degree);

t_color					new_color_hex(unsigned int color);
t_color					new_color_rgb(int r, int g, int b);
t_color					color_add(t_color *clr0, t_color *clr1);
t_color					color_sub(t_color *clr0, t_color *clr1);
t_color					color_mult(t_color *clr0, double f);
t_color					color_reverse(t_color *color);

t_vertex				new_vertex(double x, double y, double z, \
							t_color *color);

t_vector				new_vector(double x, double y, double z,\
							t_vertex *orig);
t_vector				vector_add(t_vector *vtr0, t_vector *vtr1);
t_vector				vector_sub(t_vector *vtr0, t_vector *vtr1);
t_vector				vector_opposite(t_vector *vtr);
double					vector_norm(t_vector *vtr);
t_vector				vector_normalize(t_vector *vtr);
t_vector				vector_scalar_product(t_vector *vtr, double scalar);
double					vector_dot(t_vector *vtr0, t_vector *vtr1);
double					vector_cos(t_vector *vtr0, t_vector *vtr1);
t_vector				vector_cross_product(t_vector *vtr0, t_vector *vtr1);

double					**matrix_identity(void);
double					**matrix_rotx(double alpha);
double					**matrix_roty(double alpha);
double					**matrix_rotz(double alpha);
double					**matrix_axis_rot(double x, double y, double z, \
							double a);
double					**matrix_trans(double tx, double ty, double tz);
double					**matrix_scale(double sx, double sy, double sz);

double					**matrix_view(t_vector *cam_pos, t_vector *cam_dir, \
							t_vector *up);
double					**matrix_proj(double fov, double ratio, double near, \
							double far);
double					**matrix_iso_proj(void);
double					**matrix_mult(double **mtx0, double **mtx1);
void					free_matrix(double **m);

t_vector				vector_mult_matrix(t_vector *vtr, double **m);
t_vertex				vertex_mult_matrix(t_vertex *vtx, double **m);

# ifndef U_COLOR
#  define U_COLOR

union					u_color
{
	unsigned int		hex;
	unsigned char		rgb[4];
};

enum					e_argb
{
	E_BLUE,
	E_GREEN,
	E_RED,
	E_ALPHA
};

#  define RED	0x00FF0000
#  define GREEN	0x0000FF00
#  define BLUE	0x000000FF
#  define WHITE	0x00FFFFFF
# endif

struct					s_vertex
{
	double				x;
	double				y;
	double				z;
	double				w;
	t_color				color;
};

#endif
