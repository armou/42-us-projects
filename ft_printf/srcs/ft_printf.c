/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <aoudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:30:17 by aoudin            #+#    #+#             */
/*   Updated: 2017/05/31 18:10:59 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/ft_printf.h"

void ft_padding(t_info *p, int n)
{
    int c;

    if (p->padding)
    {
        c = (p->f->zero) ? 48 : 32;
        if (!n && !(p->f->minus))
            while (p->padding--)
                ft_buff(p, &c, 1);
        else if (n && p->f->minus)
            while (p->padding--)
                ft_buff(p, &c, 1);
    }
}

void    ft_no_conv(t_info *p)
{
    if ((p->padding = p->width - 1) > 0)
    {
        ft_padding(p, 0);
        ft_buff(p, p->fmt, 1);
        ft_padding(p, 1);
    }
    else
        ft_buff(p, p->fmt, 1);
}

int ft_strchr_index(char *s, int c)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == c)
            return (i);
        ++i;
    }
    return (-1);
}

void ft_conversion_specifier(t_info *p, va_list ap)
{
    //  printf("debug");
    // dprintf(1, "debug5 fmt = %c", p->fmt[0]);
    if (p->fmt[0] == 's')
    {
        pf_putstr(p, ap);
        //    printf("debug1");
    }
    else if (p->fmt[0] == 'c' || p->fmt[0] == 'C')
        pf_putchar(p, va_arg(ap, unsigned));
    else if (p->fmt[0] == 'd' || p->fmt[0] == 'i' || p->fmt[0] == 'u' || p->fmt[0] == 'U')
    {
        //dprintf(1, "debug3");
        pf_putnbr(p, ap);
    }
    else if (p->fmt[0] == 'o' || p->fmt[0] == 'O')
        pf_putoct(p, ap);
    else if (p->fmt[0] == 'x' || p->fmt[0] == 'X')
        pf_printhexa(p, ap);
    else if (p->fmt[0] == 'p')
        pf_printaddr(p, ap);
    else
    {
        ft_no_conv(p);
    //    ft_buff(p, p->fmt, 1);
    }
    //  printf("debug");
    //  else if(ft_strchr("dDi", p->fmt[0]))
    //    pf_putnbr(p);
    //  else
    //      ft_wrong_convspec(p);
}

void ft_lengthmodif(t_info *p)
{
    if (p->fmt[0] == 'h' && p->fmt[1] != 'h')
    {
        p->m->h = 1;
        p->fmt++;
    }
    else if (p->fmt[0] == 'h' && p->fmt[1] == 'h')
    {
        p->m->hh = 1;
        p->fmt = p->fmt + 2;
    }
    else if (p->fmt[0] == 'l' && p->fmt[1] != 'l')
    {
        p->m->l = 1;
        p->fmt++;
    }
    else if (p->fmt[0] == 'l' && p->fmt[1] == 'l')
    {
        p->m->ll = 1;
        p->fmt = p->fmt + 2;
    }
    else if (p->fmt[0] == 'j')
    {
        p->m->j = 1;
        p->fmt++;
    }
    else if (p->fmt[0] == 'z')
    {
        p->m->z = 1;
        p->fmt++;
    }
    else if (p->fmt[0] == ' ')
    {
        p->f->space = 1;
        p->fmt++;
    }
    else
        return;
}

void ft_getprecision(t_info *p, va_list ap)
{
    char *ret;
    int i;

    i = 0;
    (void)ap;
    if (p->fmt[0] >= 48 && p->fmt[0] <= 57)
    {
        if ((p->width = ft_atoi(&p->fmt[0])) < 1)
            p->width = 1;
        ret = ft_itoa(p->width);
        while (i < (int)ft_strlen(ret))
        {
            // printf("debug %c", p->fmt[0]);
            ++p->fmt;
            i++;
        }
        ft_strdel(&ret);
    }
    else
        p->width = 0;
    // ++p->fmt;
    //  dprintf(1, "debug3");
    //  printf("debug %c", p->fmt[0]);
}

void ft_widthprecision(t_info *p, va_list ap)
{
    /*
    (void)ap;
   if (p->fmt[0] > 48 && p->fmt[0] < 58)
    {
        if ((p->width = ft_atoi(p->fmt)) < 1)
            p->width = 1;
        while (p->fmt[0] > 48 && p->fmt[0] < 58)
            ++p->fmt;
    }*/
    ft_getprecision(p, ap);
    if (p->fmt[0] == '.' && ++p->fmt)
    {
        if ((p->precision = ft_atoi(p->fmt)) < 0)
            p->precision = 0;
        while (p->fmt[0] >= 48 && p->fmt[0] <= 57)
            ++p->fmt;
        p->f->dot = 1;

    }
     //  ft_getprecision(p, ap);
    //ft_getwidth(p, ap);
  //  printf("precision = %d\n", p->precision);
}

void ft_findopt(t_info *p, va_list ap)
{
    int i;

    i = 0;
    // (void)ap;
    //  (void)p;
    ft_flags(p);
    ft_widthprecision(p, ap);
    ft_lengthmodif(p);
    ft_flags(p);
    ft_conversion_specifier(p, ap);
}

void ft_flags(t_info *p)
{
    //   printf("fmt = %c\n", p->fmt[0]);
    if (p->fmt[0] == '#' && ++p->fmt)
        p->f->sharp = 1;
    else if (p->fmt[0] == '-' && ++p->fmt)
    {
        p->f->minus = 1;
        // dprintf(1, "debug4");
    }
    else if (p->fmt[0] == '+' && ++p->fmt)
        p->f->plus = 1;
    else if (p->fmt[0] == '0' && ++p->fmt)
        p->f->zero = 1;
    else if (p->fmt[0] == ' ' && ++p->fmt)
        p->f->space = 1;
    else
        return;
}

void ft_setenv(t_info *p)
{

    if (!(p->f = (t_flag *)ft_memalloc(sizeof(t_flag))))
        exit(0);
    if (!(p->m = (t_mod *)ft_memalloc(sizeof(t_mod))))
        exit(0);
    if (!(p->c = (t_conv *)ft_memalloc(sizeof(t_conv))))
        exit(0);
    p->f->printed = 0;
    p->len = 0;
    p->precision = 0;
}

int ft_readf(const char *format, va_list ap, t_info *p)
{
    int i;
    //   char    *str;

    i = -1;
    p->fmt = (char *)format;
    ft_setenv(p);
    //    dprintf(1, "debug2");
    //  printf("debug2");
    while (p->fmt[0])
    {
        if (p->fmt[0] == '%')
        {
            ++p->fmt;
            ft_findopt(p, ap);
            //       str = va_arg(ap, char*);
            // printf("str = %s", str);
        }
        else
        {
            ft_buff(p, &p->fmt[0], 1);
        }
        ++p->fmt;
    }
    //   dprintf(1, "--- p->bindex = %d p->buff = %s ------\n", p->b_index, p->buff);
    write(1, p->buff, p->b_index);
    // dprintf(1, "debug2");
    return (p->len);
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    int ret;
    t_info p;

    //    dprintf(1, "debug1");
    ft_bzero(&p, sizeof(p));
    va_start(ap, format);
    ret = ft_readf(format, ap, &p);
    //   printf("format = %s\n", format);

    va_end(ap);
    return (ret);
}