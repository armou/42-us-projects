# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoudin <aoudin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/09 14:39:38 by aoudin            #+#    #+#              #
#    Updated: 2017/05/15 16:11:44 by aoudin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra
INC = -I ./

SRCS_PATH = srcs/
OBJ_PATH  = obj/
LIBFT_PATH = ../libft/

SRCS_NAME = ft_printf.c \
			ft_output.c \
			ft_printnumbers.c \
			ft_printstring.c \
			ft_buff.c \
			ft_hexa.c \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@cp $(LIBFT_PATH)/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "libftprintf.a created"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	@gcc -c $(FLAGS) $(INC) $< -o $@

clean:
	@make -C $(LIBFT_PATH) clean
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re[M n.
