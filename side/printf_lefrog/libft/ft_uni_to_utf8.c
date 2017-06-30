/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_to_utf8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:59:39 by amulin            #+#    #+#             */
/*   Updated: 2016/02/26 15:05:40 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_uni_to_utf8(wchar_t uni)
{
	unsigned char	cont_byte;
	unsigned int	out;

	if (!(out = 0) && uni <= 0x007F)
		out = (unsigned int)uni;
	else if ((cont_byte = 0x80) && uni <= 0x1FFFFF)
	{
		out = (((unsigned char)(uni << 2) >> 2) | cont_byte) << 8;
		if (uni <= 0x7FF)
			out |= (uni >> 6) | 0xC0;
		else
		{
			out <<= 8;
			out |= (((unsigned char)(uni >> 4) >> 2) | cont_byte) << 8;
			if (uni <= 0xFFFF)
				out |= (uni >> 12) | 0xE0;
			else
			{
				out <<= 8;
				out |= (((unsigned char)(uni >> 10) >> 2) | cont_byte) << 8;
				out |= (uni >> 20) | 0xF0;
			}
		}
	}
	return (out);
}
