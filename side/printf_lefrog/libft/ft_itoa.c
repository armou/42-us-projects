/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 13:06:01 by amulin            #+#    #+#             */
/*   Updated: 2015/02/13 18:14:17 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	my_process(int n, char *result, int i)
{
	size_t	index;

	index = 0;
	if (n < 0)
	{
		result[index] = '-';
		index++;
		n = -n;
	}
	while (i > 0)
	{
		result[index] = (n / i) + '0';
		n = n % i;
		i = i / 10;
		index++;
	}
	result[index] = '\0';
}

char		*my_exception(void)
{
	char	*result;

	result = ft_strnew(12);
	if (!result)
		return (NULL);
	ft_strcpy(result, "-2147483648");
	return (result);
}

char		*ft_itoa(int n)
{
	size_t	j;
	int		i;
	int		buf;
	char	*result;

	i = 1;
	buf = n;
	j = 1;
	if (buf == -2147483648LL)
		return (my_exception());
	if (buf < 0)
		buf = -buf;
	while (buf > 9)
	{
		buf = buf / 10;
		i = i * 10;
		j++;
	}
	result = ft_strnew(j + 1);
	if (!result)
		return (NULL);
	my_process(n, result, i);
	return (result);
}
