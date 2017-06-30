/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <aoudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:17:21 by aoudin            #+#    #+#             */
/*   Updated: 2017/05/31 18:16:36 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void    pf_printaddr(t_info *p, va_list ap)
{
    void            *ptr;
    unsigned long long nb;

    nb = ft_find_utype(p, ap);
    p->c->p = 1;
    p->f->sharp = 1;

   // printf("ppp === %d", (int)ptr);
   if (!nb)
        ft_itoa_base_printf(p, 0, 16);
    else
    {
        ptr = va_arg(ap, void*);
      ft_itoa_base_printf(p, (uintmax_t)ptr, 16);
    }
}

void    pf_puthex(t_info *p, va_list ap)
{
    uintmax_t       nb;

    p->c->x = 1;
    nb = va_arg(ap, uintmax_t);
    ft_itoa_base_printf(p, nb, 16);
}

void    pf_putoct(t_info *p, va_list ap)
{
    uintmax_t      nb;

    p->c->o = 1;
    nb = va_arg(ap, uintmax_t);
    ft_itoa_base_printf(p, nb, 8);
}

void    pf_putchar(t_info *p, unsigned c)
{
   // unsigned    *wc;

    if (p->fmt[0] == 'c')
        p->c->c = 1;
    else
        p->c->unprint = 1;
    if (p->c->unprint)
    {
        //wc = va_arg(ap, unsigned *);
        pf_putwchar(p, c, p->f->printed);
    }
    p->f->printed = 1;
    if ((p->padding = p->width - p->f->printed) < 0)
        p->padding = 0;
    ft_padding(p, 0);
  //  else if (p->fmt[0] == 'C')
  //      p->m->l = 1;
    ft_buff(p, &c, 1);
    ft_padding(p, 1);
}

void    pf_putnbr(t_info *p, va_list ap)
{
    long long       nb;

    nb = 0;
    if (p->fmt[0] == 'd')
        p->c->d = 1;
    if (p->fmt[0] == 'u')
        p->c->u = 1;
  //  if (p->fmt[0] == 'd')
    //    p->c->d = 1;
 //   dprintf(1, "debug6");
  //  nb = va_arg(ap, intmax_t);
  //  int i = va_arg(ap, _Generic())
    nb = (p->c->u) ? ft_find_utype(p, ap) : ft_find_type(p, ap);
 //   nb = va_arg(ap, int);
//	printf("nb %d\n", nb);
  //  printf("flagneg = %d\n", p->f->minus);
    ft_itoa_printf(p, nb);
}

void    pf_putstr(t_info *p, va_list ap)
{
    int         i;
    char        *str;
    char        c;

    if (p->fmt[0] == 's')
        p->c->s = 1;
    i = 0;
   //dprintf(1, "coucou");
   //     printf("(debug1)");
    str = va_arg(ap, char*);
    if (!str)
        ft_buff(p, "(null)", 6);
   else
    {
  // dprintf(1, "coucou");
    p->f->printed = (int)(ft_strlen(str));
 //  dprintf(1, "\n\nzero = %d || printed = %d || precision = %d || padding = %d || width = %d\n\n", p->f->zero, p->f->printed, p->precision, p->padding, p->width);
    if (p->f->dot)
        p->f->printed = p->f->printed > p->precision ? p->precision : p->f->printed;
    if ((p->padding = (p->width - p->f->printed)) > 0)
    {
     //   printf("(debug1)");
       // c = (p->f->zero) ? 48 : 32;
       c = 32;
        if (!p->f->minus)
            while (p->padding--)
                ft_buff(p, &c, 1);
        // p->padder  => 0 ou espace ??
    } 
    if (!(p->f->printed))
    {
        ft_buff(p, str, 0);
    }
    else
    {
        if (str == NULL)
            ft_buff(p, "(null)", 6);
        else
            ft_buff(p, str, p->f->printed);
    //    ft_putstr(str);
    }
    }
}