/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhivert <bhivert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 13:47:38 by bhivert           #+#    #+#             */
/*   Updated: 2015/09/20 13:47:50 by bhivert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		init_env(t_env *e, int ac, char **av)
{
	e->ac = ac;
	e->av = av;
	e->file = NULL;
	e->max_line = 0;
	e->min_value = INT_MAX;
	e->max_value = INT_MIN;
	e->win = NULL;
	e->img_id = -1;
	e->scaling = 1;
	e->up = new_vector(0, 0, 1, NULL);
	e->rt = new_vector(1, 0, 0, NULL);
	e->model = NULL;
	e->init = NULL;
	e->iso_proj = NULL;
}

int			main(int ac, char **av)
{
	t_env	env;

	init_env(&env, ac, av);
	if (env.ac < 2)
		return (ft_printf("%s file\n", env.av[0]), EXIT_SUCCESS);
	if ((fdf_get_file(&env) == -1) || (fdf_create_ui(&env) == -1))
		return (EXIT_FAILURE);
	env.init = matrix_trans(-((double)env.max_line / 2.0), \
				-((double)ft_size(env.file) / 2.0), \
				0);
	env.model = matrix_identity();
	env.m2w = matrix_trans((double)env.win->size.width / 2.0, \
				(double)env.win->size.height / 2.0, \
				0);
	env.iso_proj = matrix_iso_proj();
	ui_loop(env.win);
	return (EXIT_SUCCESS);
}
