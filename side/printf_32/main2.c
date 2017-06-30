/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 11:47:24 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/02/19 18:56:10 by tcharrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

int		main(void)
{
	t_return	*ret;
	char		*str = "Coucou";
	int			ret_printf;
	wchar_t		*str1 = L"lélala";

	char* l = setlocale(LC_ALL, "");
	ret = (t_return*)malloc(sizeof(*ret));
	ret->value = 0;
	check_string("%1.5s", str, ret);
	ft_putchar('\n');
	ret_printf = printf("%1.5s\n", str);
	printf("value = %d\nret_printf = %d\n", ret->value, ret_printf);
	return (0);
}
