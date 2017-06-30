/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 12:44:07 by amulin            #+#    #+#             */
/*   Updated: 2016/03/24 19:05:53 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwchar(wchar_t c)
{
	unsigned int	utf;
	int				outlen;

	if (c < 0)
		return (0);
	outlen = 0;
	utf = ft_uni_to_utf8(c);
	if (c <= 0x007F)
		outlen = 1;
	else if (c <= 0x7FF)
		outlen = 2;
	else if ((c >= 0x0800 && c <= 0xD7FF) || (c >= 0xE000 && c <= 0xFFFF))
		outlen = 3;
	else if ((c >= 0x10000 && c <= 0x2FFFF) || (c >= 0xE0000 && c <= 0x10FFFF))
		outlen = 4;
	write(1, &utf, outlen);
	return (outlen);
}
