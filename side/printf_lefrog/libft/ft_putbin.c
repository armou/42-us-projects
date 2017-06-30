/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:57:44 by amulin            #+#    #+#             */
/*   Updated: 2016/03/25 16:58:21 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	This function is supposed to be used with type casting
*/

static void	fill_table(unsigned long long *n, char *out, int outlen)
{
	int	i;

	i = outlen - 1;
	while (*n && i >= 0)
	{
		if (*n % 2)
			out[i] = '1';
		else
			out[i] = '0';
		*n = *n / 2;
		i--;
	}
	while (i >= 0)
	{
		out[i] = '0';
		i--;
	}
}

int			ft_putbin(unsigned long long n, int sizeof_type)
{
	int		i;
	char	*out;
	int		binlen;

	binlen = sizeof_type * 8;
	if (!(binlen % 8))
	{
		out = ft_strnew(binlen + 1);
		ft_bzero(out, binlen);
		fill_table(&n, out, binlen);
		i = 0;
		while (out[i])
		{
			if (i && !(i % 8))
				ft_putchar(' ');
			ft_putchar(out[i]);
			i++;
		}
		ft_strdel(&out);
	}
	return (binlen + (binlen / 8 - 1));
}
