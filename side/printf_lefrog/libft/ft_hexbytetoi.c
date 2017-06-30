/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexbytetoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:25:47 by amulin            #+#    #+#             */
/*   Updated: 2016/03/07 17:52:02 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexbytetoi(char *hexbyte)
{
	int		value;
	char	buf[3];

	if (!hexbyte || !ft_ishexa((int)hexbyte[0]) || !ft_ishexa((int)hexbyte[1]))
		return (-1);
	ft_strncpy(buf, hexbyte, 2);
	value = ft_hexchartoi(buf[0]) * 16 + ft_hexchartoi(buf[1]);
	return (value);
}
