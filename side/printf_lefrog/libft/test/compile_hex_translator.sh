#!/bin/sh

make -C ..
gcc -Wall -Werror -Wextra main_hex_to_ascii.c -L../ -lft -I../includes \
	-o hex_translator.out
