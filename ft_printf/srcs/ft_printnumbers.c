/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <aoudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 10:28:54 by aoudin            #+#    #+#             */
/*   Updated: 2017/05/31 18:08:02 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

static char ft_itoa_char(t_info *p, uintmax_t nb, int base)
{
	const char *baze = "0123456789abcdef";
	const char *baze_upcase = "0123456789ABCDEF";
	
//	printf("--&&&--->nb = %ju %c <---&&&--\n", nb, baze[nb % base]);
	if (!p->c->xx)
	return (baze[nb % base]);
	else
	return (baze_upcase[nb % base]);
   // if (nb + '0' > 9 + '0' && base == 16)
   //     return (nb + 'a');
   // else if (nb + '0' > 9 + '0' && base == 16)
   //     return (nb + 'A');
   // else
   //     return (nb + '0');
}

char 	*ft_itoa_base_str(t_info *p, uintmax_t nb, int base, char *s)
{
	int 	len;
//	char 	c;

	len = p->f->printed;
//	printf("nb ito")
	while (len--)
	{
	//	s[len] = nb % base + ((nb % base < 10) ? '0' : ft_itoa_char(base, nb % base));
		s[len] = ft_itoa_char(p, nb, base);
	//	printf("----->len == %d s[%d] = %c <-----\n", len, len, s[len]);
	//	printf("nb modulo base == %lu\n", nb % base);
		nb /= base;
	}
	return (s);
}

void	ft_itoa_base_printf(t_info *p, uintmax_t nb, int base)
{
	uintmax_t	temp;
	char 		*s;
	int 		len;
//	char 		c;

	//printf("nb %jd\n", nb);
//	printf("nb %p\n", &nb);
	p->f->printed = 0;
	len = 0;
	temp = nb;
	while (temp && ++p->f->printed)
	{
		len++;
		temp /= base;
	}
	if (p->precision > p->f->printed)
		p->f->printed = p->precision;
	else if (base == 8)
		p->width--;
	else
		p->width -= 2;	
	if (p->f->zero)
		p->precision = p->width;
	else
		p->precision = 0;
	if (!(p->f->sharp) && base == 8)
		p->width++;
	else if (!(p->f->sharp) && base == 16)
		p->width += 2;
	if ((p->padding = (p->width - p->f->printed)) < 0)
		p->padding = 0;

/*	if (nb <= 0)
	{
		len++;
		p->f->printed++;
	}*/
//	printf("printed %d\n", p->f->printed);
//	printf("len %d\n", len);
	s = ft_strnew(len);
//		if (!s)
		//	return (NULL);
//	c = ft_itoa_char(base, nb);
//	printf("s == %s\n", s);
//	dprintf(1, "psharp = %d\n", p->f->sharp);
//	if (n )
	ft_padding(p, 0);		
	(nb == 0) ? s[0] = '0' : 0;
	if (p->f->sharp)
	{
		ft_buff(p, "0", 1);
		(p->c->xx) ? ft_buff(p, "X", 1) : ft_buff(p, "x", 1);
	}
//	ft_buff(p, s, ft_strlen(s));
	s = ft_itoa_base_str(p, nb, base, s);
	ft_buff(p, s, p->f->printed);
	ft_padding(p, 1);
}

void	ft_itoa_printf(t_info *p, intmax_t nb)
{
	int 		len;
	uintmax_t 	temp;
	char 		*s;

	len = 0;
	temp = nb < 0 ? -nb : nb;
	//printf("nb = %ld", nb);
	while(temp && ++p->f->printed)
	{
		temp /= 10;
		++len;
	}
	if ((nb < 0) || (p->f->plus) || (p->f->space))
	{
		p->precision -= 1;
	}
	p->f->printed = len > p->precision ? len : p->precision;
	temp = nb < 0 ? -nb : nb;
	if (nb < 0)
	{
		len++;
		++p->f->printed;
	}
	p->padding = (p->f->printed > p->width) ? 0 : p->width - p->f->printed;
	ft_padding(p, 0);

//printf("len = %d nb == %jd\n", len, nb);
s = ft_strnew(len);
s[len] = '\0';
//s = ft_itoa_base_str(p, nb, 10, s);
(nb == 0) ? s[0] = '0' : 0;
while (--len > -1)
{
	s[len] = (temp % 10) + '0';
	//printf("s[len] = %c\n", s[len]);
	temp /= 10;
}
//(p->f->space) ? ft_buff(p, " ", 1) : 0;
(nb < 0) ? s[0] = '-' : 0;
(p->f->plus && nb >= 0) ? ft_buff(p, "+", 1) : 0;
//printf("len = %d s == %s, nb == %jd\n", p->f->printed, s, nb);
ft_buff(p, s, ft_strlen(s));
//free(s);
	//printf("deeeebug");
}

void	ft_putoctal(unsigned long long nb)
{
	size_t		beg;
	size_t		end;
	const char	*base;

	base = "01234567";
	end = nb % 8;
	beg = (nb - end) / 8;
	if (beg)
		ft_putoctal(beg);
	ft_putchar(base[end]);
}