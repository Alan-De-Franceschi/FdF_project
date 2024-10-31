# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 10:39:22 by ade-fran          #+#    #+#              #
#    Updated: 2023/11/13 10:39:25 by ade-fran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES = ft_atoi.c ft_isalpha.c ft_memchr.c \
			ft_memset.c ft_strlcpy.c ft_strrchr.c \
			ft_bzero.c ft_isascii.c ft_memcmp.c \
			ft_strchr.c ft_strlen.c ft_tolower.c \
			ft_calloc.c ft_isdigit.c ft_memcpy.c \
			ft_strdup.c ft_strncmp.c ft_toupper.c \
			ft_isalnum.c ft_isprint.c ft_memmove.c \
			ft_strlcat.c ft_strnstr.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_substr.c ft_strjoin.c ft_itoa.c \
			ft_strtrim.c ft_split.c ft_strmapi.c \
			ft_striteri.c ft_putnbr_base_fd.c ft_putptr.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c \
			ft_printf.c ft_print_list.c ft_lstdelfirst.c \
			ft_count_word.c ft_free_strtab.c ft_get_next_line.c \
			ft_check_new_line.c ft_abs.c ft_int_in_lst.c \
			ft_lstsort.c

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

$(NAME) : $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

clean: 
	rm -f $(OBJECTS)

fclean: 
	rm -f $(NAME) $(OBJECTS)

re: fclean all

.PHONY: fclean clean all re
