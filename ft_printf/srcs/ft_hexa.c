/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <aoudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 16:08:39 by aoudin            #+#    #+#             */
/*   Updated: 2017/05/31 16:23:13 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

intmax_t	ft_find_type(t_info *p, va_list ap)
{
	intmax_t 	nb;

	nb = va_arg(ap, intmax_t);
	if (p->m->hh)
		nb = (char)nb;
	else if (p->m->ll)
		nb = (long long)nb;
	else if (p->m->h)
		nb = (short)nb;
	else if (p->m->l)
		nb = (long)nb;
	else if (p->m->j)
		nb = (intmax_t)nb;
	else if (p->m->z)
		nb = (size_t)nb;
	else
		nb = (int)nb;
	return (nb);
}

uintmax_t ft_find_utype(t_info *p, va_list ap)
{
	uintmax_t	nb;

	if (p->m->hh)
		nb = (unsigned char)va_arg(ap, int);
	else if (p->m->ll)
		nb = va_arg(ap, unsigned long long);
	else if (p->m->h)
		nb = (unsigned short)va_arg(ap, int);
	else if (p->m->l)
		nb = va_arg(ap, unsigned long);
	else if (p->m->j)
		nb = va_arg(ap, uintmax_t);
	else if (p->m->z)
		nb = va_arg(ap, unsigned long);
	else
		nb = va_arg(ap, unsigned int);
	return (nb);
}

void		ft_puthexa(t_info *p, unsigned long long nb)
{
	size_t first;
	size_t last;
	char *base; 

	if (p->c->x)	
		base = "0123456789abcdef";
    else
		base = "0123456789ABCDEF";
	last = nb % 16;
	first = (nb - last) / 16;
//	printf("\nnb = %llu, last = %zu, first = %zu", nb, last, first);
	if (first)
		ft_puthexa(p, first);
    ft_buff(p, &base[last], 1);
}

void			pf_printhexa(t_info *p, va_list ap)
{
	uintmax_t	nb;

	(p->fmt[0] == 'x') ? (p->c->x = 1) : (p->c->xx = 1);
	nb = ft_find_utype(p, ap);
//	dprintf(1, "debug1");
//if (p->f->sharp)
//	{
//		if (p->c->xx)
	//		ft_buff(p, "OX", 2);
//		else
//			ft_buff(p, "0x", 2);
//	}		
	if (nb != 0)
	{
			ft_itoa_base_printf(p, nb, 16);
		//	env->size += ft_size_hexoc(nb, 16);
	}
	else
		ft_buff(p, "0", 1);
}