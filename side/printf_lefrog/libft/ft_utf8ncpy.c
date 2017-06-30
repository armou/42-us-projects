/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8ncpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 17:36:11 by amulin            #+#    #+#             */
/*   Updated: 2016/03/18 19:22:50 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	This funtion was primarily designed for precision management with S
**	conversion in the context of ft_printf().
**	The main difference with ft_wcsncpy() is that ft_utf8ncpy() copies an
**	undefined number of wchar_t, provided that their bytes are included in the
**	n "active" bytes of the source string.
*/

wchar_t	*ft_utf8ncpy(wchar_t *dst, const wchar_t *src, size_t n)
{
	int				lensrc;
	int				wchar_index;
	size_t			wchar_utf8len;
	size_t			byte_index;

	if (dst != NULL && src != NULL)
	{
		lensrc = ft_wcslen(src);
		byte_index = 0;
		wchar_index = -1;
		while (++wchar_index < lensrc && byte_index +
				(wchar_utf8len = ft_wchar_utf8len(src[wchar_index])) <= n)
			if (byte_index + wchar_utf8len <= n)
			{
				dst[wchar_index] = src[wchar_index];
				byte_index += wchar_utf8len;
			}
		if (wchar_index < lensrc)
			while (wchar_index < lensrc)
			{
				dst[wchar_index] = 0;
				wchar_index++;
			}
	}
	return (dst);
}
