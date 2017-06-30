/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <aoudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 15:38:23 by aoudin            #+#    #+#             */
/*   Updated: 2017/05/27 18:55:59 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

size_t  ft_wstrlen(const wchar_t *ws)
{
    size_t      len;

    len = 0;
    while (*ws)
    {
        len++;
        ws++;
    }
    return (len);
}

void    pf_putwstr(t_info *p, va_list ap)
{
    wchar_t     *s;
  //  int         len_char;

    s = va_arg(ap, wchar_t *);
    (void)p;
  //  p->f->printed = (int)(ft_wstrlen((unsigned *)s));
    
}

void    pf_putwchar(t_info *p, unsigned int wc, int bytes)
{
    char        tmp[4];
   // unsigned    *wc;

//    wc = va_arg(ap, unsigned);
	if (bytes <= p->f->printed && bytes <= MB_CUR_MAX)
	{
		if (bytes == 1)
			tmp[0] = wc;
		else
		{
			if (bytes == 2)
				tmp[0] = ((wc & (0x1f << 6)) >> 6) | 0xC0;
			else
			{
				if (bytes == 3)
					tmp[0] = ((wc >> 12) & 0xf) | 0xE0;
				else
				{
					tmp[0] = ((wc >> 18) & 7) | 0xF0;
					tmp[1] = ((wc >> 12) & 0x3f) | 0x80;
				}
				tmp[bytes - 2] = ((wc >> 6) & 0x3f) | 0x80;
			}
			tmp[bytes - 1] = (wc & 0x3f) | 0x80;
		}
		ft_buff(p, tmp, bytes);
	}
}