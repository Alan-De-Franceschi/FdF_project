# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 09:53:28 by ade-fran          #+#    #+#              #
#    Updated: 2024/01/31 09:53:30 by ade-fran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIB = libft/libft.a

SOURCES = main.c \
			srcs/check_args/check_args.c \
			srcs/serv_management/serv_management.c \
			srcs/parsing/read_file.c \
			srcs/parsing/parsing.c \
			srcs/parsing/fill_colors.c \
			srcs/parsing/parsing_utils.c \
			srcs/dots_computing/dots_computing.c \
			srcs/dots_computing/computing_utils.c \
			srcs/tracing/tracing.c \
			srcs/tracing/x_segment.c \
			srcs/tracing/y_segment.c \
			srcs/coloring/coloring.c \
			srcs/coloring/put_pixel.c \
			srcs/coloring/get_trgb.c \
			srcs/coloring/color_gradient.c \

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I $(INCLD_DIR)

MLX_FLAGS = -L minilibx-linux/ -lmlx -lXext -lX11

MLX = minilibx-linux/libmlx_Linux.a

INCLD_DIR = ./

CC = cc

all:  $(NAME)

$(LIB): 
	make -C libft/

$(MLX):
	make -C minilibx-linux/

$(NAME): $(OBJECTS) $(LIB) $(MLX)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIB) $(MLX_FLAGS) -o $(NAME) -lm

clean:
	make fclean -C libft/
	make clean -C minilibx-linux/
	rm -f $(LIB) $(OBJECTS)

fclean:
	make fclean -C libft/
	make clean -C minilibx-linux/
	rm -f $(NAME) $(LIB) $(OBJECTS)

re: fclean all

.PHONY: fclean clean all re libft minilibx
