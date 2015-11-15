/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhivert <bhivert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 13:47:24 by bhivert           #+#    #+#             */
/*   Updated: 2015/09/20 13:47:32 by bhivert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_get_line(t_env *e, char *line)
{
	int				out;
	int				value;
	t_container		*tmp;

	if (!(tmp = ft_new_container(VECTOR, sizeof(int))))
		return (-1);
	ft_push_back(e->file, &tmp);
	while ((out = ft_sscanf(line, "%d %s", &value, line)))
	{
		e->min_value = (value < e->min_value) ? value : e->min_value;
		e->max_value = (value > e->max_value) ? value : e->max_value;
		ft_push_back(tmp, &value);
		if (out == 1)
			break ;
	}
	e->max_line = (ft_size(tmp) > e->max_line) ? ft_size(tmp) : e->max_line;
	return (0);
}

int			fdf_get_file(t_env *e)
{
	int			fd;
	char		*line;

	if ((fd = open(e->av[1], O_RDONLY)) == -1)
	{
		ft_printf("%s unable to open %s.\n", e->av[0], e->av[1]);
		return (-1);
	}
	if (!(e->file = ft_new_container(VECTOR, sizeof(t_container *))))
		return (-1);
	while (ft_gnl(fd, &line) > 0)
	{
		fdf_get_line(e, line);
		free(line);
	}
	close(fd);
	return (0);
}
