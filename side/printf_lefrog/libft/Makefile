# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft/Makefile                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amulin <amulin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 16:56:12 by amulin            #+#    #+#              #
#    Updated: 2016/03/24 14:20:22 by amulin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# OS detection (Linux / OSX)
#
OS_NAME = $(shell uname -s)
ifeq ($(OS_NAME),Linux)
	CC = gcc
endif
ifeq ($(OS_NAME),Darwin)
	CC = clang
endif


NAME = libft.a

FLAGS = -Wall -Werror -Wextra

SRCS = ft_putchar.c ft_putstr.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	   ft_putnbr_fd.c ft_putendl.c ft_putendl_fd.c ft_strlen.c ft_strdup.c \
	   ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c \
	   ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c \
	   ft_strncmp.c ft_atoi.c ft_strnew.c ft_strdel.c ft_strclr.c ft_itoa.c\
	   ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
	   ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
	   ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	   ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c \
	   ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	   ft_toupper.c ft_tolower.c \
	   ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstiter.c ft_lstappend.c \
	   ft_lstmap.c ft_lstadd.c get_next_line.c \
	   ft_abs.c ft_abs_ll.c ft_print_memory.c \
	   ft_tabmax.c ft_tabmin.c ft_getmax.c \
	   ft_endian_swap.c ft_putbin.c ft_uni_to_utf8.c \
	   ft_putwchar.c ft_putwstr.c \
	   ft_wchar_utf8len.c ft_wstr_utf8len.c ft_utf8ncpy.c \
	   ft_wstr_memsize.c \
	   ft_wcslen.c ft_wcsncpy.c \
	   ft_hexchartoi.c ft_hexbytetoi.c ft_ishexa.c \
	   ft_itoa_ll.c ft_itoa_ull.c \
	   ft_puthex.c ft_puthex_ull.c ft_putnbr_ll.c ft_putnbr_ull.c \
	   ft_putoctal.c

HEADERS = libft.h

INCLUDIR = includes/

INCLUDES = $(addsuffix $(INCLUDIR), $(HEADERS))

OBJECTS = $(subst .c,.o,$(SRCS))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(SRCS) $(INLUDES)
	$(CC) $(FLAGS) -c $(SRCS) -I $(INCLUDIR)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
