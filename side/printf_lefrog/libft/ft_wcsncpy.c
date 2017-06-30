/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 17:13:11 by amulin            #+#    #+#             */
/*   Updated: 2016/03/18 17:13:12 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wcsncpy(wchar_t *dst, const wchar_t *src, size_t n)
{
	size_t lensrc;
	size_t i;

	if (dst != NULL && src != NULL)
	{
		lensrc = ft_wcslen(src);
		i = 0;
		while (i < lensrc && i < n)
		{
			dst[i] = src[i];
			i++;
		}
		if (lensrc < n)
		{
			while (i < n)
			{
				dst[i] = '\0';
				i++;
			}
		}
	}
	return (dst);
}
