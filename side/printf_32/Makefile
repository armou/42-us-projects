# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcharrey <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/29 19:25:05 by tcharrey          #+#    #+#              #
#    Updated: 2016/02/19 15:08:54 by tcharrey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libftprintf.a

SRC = 	string.c useful_string.c put_printf.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJ) libft/libft.a
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

libft/libft.a:
	make -C libft/

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -I ./includes/ -c $(SRC)

all: $(NAME)

clean:
	make clean -C libft/
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

re: fclean all 
