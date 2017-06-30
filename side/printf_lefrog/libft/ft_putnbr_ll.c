/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:30:24 by amulin            #+#    #+#             */
/*   Updated: 2016/03/24 14:21:55 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_ll(long long n)
{
	if (n == LONG_MAX)
		ft_putstr("9223372036854775807");
	else if (n == LONG_MIN)
		ft_putstr("-9223372036854775808");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n > 9)
		{
			ft_putnbr_ll(n / 10);
			ft_putnbr_ll(n % 10);
		}
		else
			ft_putchar(n + '0');
	}
}
