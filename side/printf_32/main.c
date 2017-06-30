/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 11:47:24 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/02/19 11:17:06 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdio.h>

//void	ft_putchar(char c);

int		main(void)
{
	char	*str = "Sa marche";

	/*normal_string("%-s", str);
	ft_putchar('\n');
	printf("%-s\n", str);*/

	normal_string("%-5s", str);
	ft_putchar('\n');
	printf("%-5s\n", str);

	/*normal_string("%-5.18s", str);
	ft_putchar('\n');
	printf("%-5.18s\n", str);*/

	/*normal_string("%5s", str);
	ft_putchar('\n');
	printf("%5s\n", str);*/

	/*normal_string("%5.18s", str);
	ft_putchar('\n');
	printf("%5.18s\n", str);*/

	/*normal_string("%5.2s", str);
	ft_putchar('\n');
	printf("%5.2s\n", str);*/

	/*normal_string("%-s", str);
	ft_putchar('\n');
	printf("%-s\n", str);*/
	return (0);
}
