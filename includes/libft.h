/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhivert <bhivert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:39:25 by bhivert           #+#    #+#             */
/*   Updated: 2015/09/23 10:09:24 by bhivert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# ifndef T_BOOL
#  define T_BOOL
#  define D_FALSE		((char)	0)
#  define D_TRUE		((char)	1)

typedef char			t_bool;
# endif

# ifndef T_INT
#  define T_INT			long long int
#  define T_UINT		unsigned long long int

typedef T_INT			t_int;
typedef T_UINT			t_uint;
# endif

# ifndef XOR
#  define XOR(a,b)		((a && !b) || (!a && b))
# endif

# ifndef MIN
#  define MIN(a,b)		((a < b) ? a : b)
# endif

# ifndef MAX
#  define MAX(a,b)		((a > b) ? a : b)
# endif

# ifndef STR_NPOS
#  define STR_NPOS		((size_t) -1)
# endif

/*
** =============================================================================
** ================================== CHAR =====================================
*/
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_isspace(int c);

int						ft_toupper(int c);
int						ft_tolower(int c);

/*
** =============================================================================
** =================================== IO ======================================
** #include "ft_printf.h"
** ft_printf(const char *format, ...);
** ft_fprintf(int fd, const char *format, ...);
** ft_sprintf(char **str, const char *format, ...);
*/
# define GNL_BUFF_SIZE	128

int						ft_gnl(int fd, char **line);

int						ft_putchar(int c);
int						ft_putchar_fd(int c, int fd);

void					ft_putstr(char const *s);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl(char const *s);
void					ft_putendl_fd(char const *s, int fd);

void					ft_putnbr(int n);
void					ft_putnbr_fd(int n, int fd);

/*
** =============================================================================
** =================================== STR =====================================
*/
size_t					ft_strlen(char const *s);

char					*ft_strnew(size_t size);
char					*ft_strdup(char const *s1);
char					*ft_strcpy(char *s1, char const *s2);
char					*ft_strncpy(char *s1, char const *s2, size_t n);
void					ft_strclr(char *s);
void					ft_strdel(char **as);

int						ft_strcmp(char const *s1, char const *s2);
int						ft_strncmp(char const *s1, char const *s2, size_t n);
t_bool					ft_strequ(char const *s1, char const *s2);
t_bool					ft_strnequ(char const *s1, char const *s2, size_t n);

char					*ft_strcat(char *s1, char const *s2);
char					*ft_strncat(char *s1, char const *s2, size_t n);
size_t					ft_strlcat(char *s1, char const *s2, size_t size);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strjoin_free(char *s1, char const *s2);

char					*ft_strsub(char const *s, unsigned int start, \
							size_t len);
char					**ft_strsplit(char const *s, char c);

char					*ft_strchr(char const *s, int c);
char					*ft_strrchr(char const *s, int c);
char					*ft_strstr(char const *s1, char const *s2);
char					*ft_strnstr(char const *s1, char const *s2, size_t n);

void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s, \
							char (*f)(unsigned int, char));

char					*ft_strtrim(char const *s);

/*
** =============================================================================
** =================================== NUM =====================================
*/
int						ft_atoi(char const *s);
char					*ft_itoa(t_int n);
char					*ft_uitoa(t_uint n);

double					ft_atof(const char *str, size_t *len);

size_t					ft_intlen(t_int n);
t_int					ft_abs(t_int n);
int						ft_pow(int nbr, int pow);

char					*ft_convert_base(char *nbr, char *base_from, \
							char *base_to);
char					*ft_convert_base_free(char *nbr, char *base_from, \
							char *base_to);

/*
** =============================================================================
** =================================== MEM =====================================
*/
void					*ft_memalloc(size_t size);
void					*ft_memrealloc(void *ptr, size_t size, size_t new_size);
int						ft_memdel(void **ap);

void					ft_bzero(void *s, size_t n);
void					*ft_memset(void *b, int c, size_t len);

void					*ft_memdup(void *buf, size_t size);
void					*ft_memcpy(void *s1, void const *s2, size_t n);
void					*ft_memccpy(void *s1, void const *s2, int c, size_t n);
void					*ft_memmove(void *s1, void const *s2, size_t n);

int						ft_memcmp(void const*s1, void const *s2, size_t n);

void					*ft_memchr(void const *s, int c, size_t n);

/*
** =============================================================================
** =================================== LIST ====================================
*/
typedef struct			s_list
{
	struct s_list		*next;
	void				*content;
}						t_list;

t_list					*ft_lstnew(void const *content);
void					ft_lstadd(t_list **alst, void *n);
void					ft_lstaddend(t_list **alst, void *n);

void					ft_lstdel(t_list **alst, void (*del)(void *));
void					ft_lstdel_if(t_list **alst, void (*del)(), \
							void *ref, int (*cmp)());
void					ft_lstdelone(t_list **alst, void (*del)(void *));

size_t					ft_lstcount(void *alst);

void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void					ft_lstsort(t_list **alst, int (*f)(t_list *elem1, \
							t_list *elem2));
/*
** =============================================================================
** =================================== TREE ====================================
*/
typedef enum			e_btdir
{
	FT_BT_SAME,
	FT_BT_LEFT,
	FT_BT_RIGHT
}						t_btdir;

typedef struct			s_btree
{
	struct s_btree		*father;
	struct s_btree		*left;
	struct s_btree		*right;
	void				*content;
}						t_btree;

t_btree					*ft_btreeadd(t_btree **atree, void *content, \
							t_btdir (*cmp)(t_btree *, void *));
int						ft_btreeiter(t_btree *atree, \
							t_btdir (*cmp)(t_btree *, t_btree *, void *), \
							int (*fct)(t_btree *, int, void *), \
							void *ref);
void					ft_put_btree(t_btree *tree, int depth, \
							void (*putfunc)(void *));
/*
** =============================================================================
** =================================== TAB =====================================
*/
size_t					ft_tablen(char **tab);
char					**ft_tabcpy(char **tab);
void					*ft_tabrealloc(void *tab, \
							size_t old_size, size_t new_size, size_t unit);
void					ft_tabprint(char **tab);
void					ft_tabfree(char **tab);
/*
** =============================================================================
** ================================= PARSING ===================================
*/
int						ft_charset_parser(const char *str, \
							const char *charset, size_t *len);
ssize_t					ft_word_parser(const char *str, const char *word, \
							size_t w_size);
int						ft_natoi(const char *str, size_t size);
double					ft_natof(const char *str, size_t size, size_t *len);

#endif
