/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_utf8len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 19:09:59 by amulin            #+#    #+#             */
/*   Updated: 2016/03/24 19:10:13 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wchar_utf8len(wchar_t const wc)
{
	size_t	len;

	if (wc < 0)
		return (0);
	len = 0;
	if (wc <= 0x007F)
		len = 1;
	else if (wc <= 0x7FF)
		len = 2;
	else if ((wc >= 0x0800 && wc <= 0xD7FF) || (wc >= 0xE000 && wc <= 0xFFFF))
		len = 3;
	else if ((wc >= 0x10000 && wc <= 0x2FFFF)
			|| (wc >= 0xE0000 && wc <= 0x10FFFF))
		len = 4;
	return (len);
}
