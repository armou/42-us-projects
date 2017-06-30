/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_hex_to_ascii.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 16:32:37 by amulin            #+#    #+#             */
/*   Updated: 2016/03/07 17:56:54 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		ft_putstr("usage: ");
		ft_putstr(argv[0]);
		ft_putstr(" <hexadecimal string, bytes separated by space>\n");
	}
	else
	{
		ft_putstr("\033[33m\n");
		ft_putstr(argv[1]);
		ft_putstr("\033[0m :\n\"\033[36m ");
		i = 0;
		while (argv[1][i] && i < (int)ft_strlen(argv[1]))
		{
			ft_putchar(ft_hexbytetoi(&argv[1][i]));
			i += 3;
		}
//		ft_putnbr(ft_hexbytetoi(argv[1]));
		ft_putstr("\"\033[0m\n");
	}
	return (0);
}
