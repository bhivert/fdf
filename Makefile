# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhivert <bhivert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/01 16:50:57 by bhivert           #+#    #+#              #
#    Updated: 2015/09/09 15:48:53 by bhivert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all, clean, fclean, re, _make, _make_clean, _make_fclean
.SUFFIXES:

NAME		=	fdf

DEBUG		=	0
ifeq ($(DEBUG), 0)
	CC	=	gcc
	CFLAGS	=	-Wall -Wextra -Werror $(INCS_FLAGS) -O3
else
	CC	=	clang
	CFLAGS	=	-Wall -Wextra $(INCS_FLAGS) -g3
endif

DEPENDS		=	libui/libui.a \
			lib3d/lib3d.a \
			libft/libft.a \

LIBS_DIR	=	-Llibui \
			-Llib3d \
			-Llibft \

LIBS		=	-lui \
			-l3d \
			-lft \
			-lm \
			-lmlx \
			-lXext \
			-lX11
#			-framework OpenGL \
#			-framework AppKit \
#			-lpthread \

INCS_FLAGS	=	-Iincludes \

SUB_MAKE	=	libui \
			lib3d \
			libft \

SRCS_DIR	=	srcs
SRCS_SRCS	=	$(SRCS_DIR)/fdf_bresenham.c \
			$(SRCS_DIR)/fdf_create_ui.c \
			$(SRCS_DIR)/fdf_draw.c \
			$(SRCS_DIR)/fdf_get_file.c \
			$(SRCS_DIR)/main.c \

SRCS		=	$(SRCS_SRCS) \

OBJS		=	$(SRCS:.c=.o)


all		:	_make $(NAME)

$(NAME)		:	$(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS_DIR) $(LIBS) -o $@

%.o	:	%.c $(DEPENDS)
	$(CC) $(CFLAGS) -c $< -o $@

clean		:	_make_clean
	rm -rf $(OBJS)

fclean		:	_make_fclean clean
	rm -rf $(NAME)

re			:	fclean all

_make		:
ifeq ($(DEBUG), 2)
	$(foreach MAKE, $(SUB_MAKE),make -C $(MAKE) DEBUG=$(DEBUG);)
else
	$(foreach MAKE, $(SUB_MAKE),make -C $(MAKE);)
endif

_make_clean		:
	$(foreach MAKE, $(SUB_MAKE),make -C $(MAKE) clean;)

_make_fclean		:
	$(foreach MAKE, $(SUB_MAKE),make -C $(MAKE) fclean;)
