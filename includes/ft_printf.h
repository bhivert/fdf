/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhivert <bhivert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 00:16:11 by bhivert           #+#    #+#             */
/*   Updated: 2014/10/15 09:11:53 by bhivert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define PF_MDELIM		(char *)	"%"
# define PF_NDELIM		(int)		10

typedef enum			e_pf_ltype
{
	E_PF_NONE,
	E_PF_CHAR,
	E_PF_STR,
	E_PF_INT,
	E_PF_UINT,
	E_PF_OCT,
	E_PF_HEX,
	E_PF_HEXUP,
	E_PF_PTR
}						t_pf_ltype;

typedef enum			e_pf_length
{
	E_PF_L_NONE,
	E_PF_L_SHORT,
	E_PF_L_LONG,
	E_PF_L_LLONG,
	E_PF_L_USIGN
}						t_pf_length;

typedef struct			s_format
{
	t_bool				left;
	t_bool				sign;
	t_bool				space;
	t_bool				prefix;
	t_bool				zero;
	int					width;
	int					precision;
}						t_format;

typedef struct			s_pf_delim
{
	t_pf_ltype			*type;
	char				*match;
}						t_pf_delim;

typedef struct			s_pf_lexer
{
	t_pf_ltype			*type;
	char				*data;
	struct s_pf_lexer	*next;
}						t_pf_lexer;

int						ft_printf(const char *format, ...);
int						ft_fprintf(int fd, const char *format, ...);
int						ft_asprintf(char **str, const char *format, ...);

t_pf_lexer				*pf_lexer(char *s);
void					pf_free_tlexer(t_pf_lexer *alex, t_bool free_data);

t_pf_delim				***pf_get_delimiter_list(void);
void					pf_free_delim_list(t_pf_delim ***list);
t_pf_lexer				*pf_new_tlexer(t_pf_ltype type, char *data);
t_pf_lexer				*pf_new_tlexer_delim(char *str, size_t index, \
							size_t *len, t_pf_delim *delim);
void					pf_add_tlexer(t_pf_lexer **alex, t_pf_lexer *n);

t_list					*pf_parser(t_pf_lexer *alex, va_list ap, int *len);
size_t					get_format(t_format *format, t_pf_lexer *node, \
							va_list ap);
char					*set_out_int(t_bool usign, t_format *format, char *n, \
							int len);
char					*set_out_base(t_pf_ltype type, t_format *format, \
							char *n, int len);
char					*set_out_ptr(t_format *format, char *n, int len);
t_list					*data_is_none(t_pf_lexer *node, va_list ap, int *len);
t_list					*data_is_char(t_pf_lexer *node, va_list ap, int *len);
t_list					*data_is_str(t_pf_lexer *node, va_list ap, int *len);
t_list					*data_is_int(t_pf_lexer *node, va_list ap, int *len);
t_list					*data_is_uint(t_pf_lexer *node, va_list ap, int *len);
t_list					*data_is_oct(t_pf_lexer *node, va_list ap, int *len);
t_list					*data_is_hex(t_pf_lexer *node, va_list ap, int *len);
t_list					*data_is_hexup(t_pf_lexer *node, va_list ap, int *len);
t_list					*data_is_ptr(t_pf_lexer *node, va_list ap, int *len);

#endif
