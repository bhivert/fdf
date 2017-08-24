/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhivert <bhivert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 15:39:32 by bhivert           #+#    #+#             */
/*   Updated: 2015/11/15 13:06:38 by bhivert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCANF_H
# define FT_SCANF_H

# include "libft.h"
# include <stdarg.h>

int	ft_sscanf(const char *str, const char *format, ...);
int	ft_vsscanf(const char *str, const char *format, va_list ap);

int	ft_int_vsscanf_get_var_type(const char *str, const char *format, \
		size_t *i, size_t *j);
int	ft_int_vsscanf_get_var(const char *str, const char *format, \
		size_t *i, va_list ap);

#endif
