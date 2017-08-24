/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhivert <bhivert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 16:25:35 by bhivert           #+#    #+#             */
/*   Updated: 2015/09/23 16:25:39 by bhivert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_H
# define FT_CONTAINERS_H

# include "libft.h"

typedef enum	e_cont_t
{
	DEQUE = 0,
	VECTOR,
	MAP,
	UMAP,
	CONT_NTYPE
}				t_cont_t;

typedef void	*t_container;

t_container		*ft_new_container(t_cont_t type, size_t content_size);

void			ft_set_key_size(t_container *cont, size_t size);
void			ft_set_content_destroy(t_container *cont, \
					void (*content_destroy)(void *));

void			ft_erase_index(t_container *cont, size_t i);
void			ft_erase_key(t_container *cont, void *key);

size_t			ft_size(t_container *cont);
void			ft_reserve(t_container *cont, size_t capacity);
size_t			ft_capacity(t_container *cont);

void			*ft_at_index(t_container *cont, size_t index);
void			*ft_at_key(t_container *cont, void *key);

void			ft_insert(t_container *cont, void *content, void *key);

void			ft_push_front(t_container *cont, void *content);
void			ft_push_back(t_container *cont, void *content);

void			ft_push_sort(t_container *cont, void *content, \
					int (*content_cmp)(void *, void *));

void			ft_pop_front(t_container *cont);
void			ft_pop_back(t_container *cont);

void			ft_iter(t_container *cont, void (*fct)(void *content));

void			ft_debug_container(t_container *cont, \
					void (*put_content)(void *));
void			ft_clear(t_container *cont);
void			ft_delete_container(t_container **cont);

#endif
