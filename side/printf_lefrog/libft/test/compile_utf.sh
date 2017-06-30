#!/bin/sh

make -C ..
gcc -Wall -Werror -Wextra main_utf8.c ft_uni_to_utf8.c -L../ -lft
