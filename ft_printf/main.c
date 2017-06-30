/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <aoudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:34:32 by aoudin            #+#    #+#             */
/*   Updated: 2017/05/30 16:35:14 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>


int     main(void)
{
  //  va_list ap;
    char    *str;
    short f;
    char    *s2;
    int a = 4;

    str = "tata";
    s2 = NULL;
   // va_start(ap, str);
  //  ft_printf("mon printf %d%d%d%d%d\n", -42, 4, -1, 1, 4);
    //ft_printf("mon printf %S\n", str);
//    ft_printf("%s\n", s2);
    //ft_printf("%p\n", &a);
    ft_printf("%+d\n", 42);
    ft_printf("%#x\n", 42);
    //ft_printf("%10s\n", str);
	//printf("vrai printf %d%d%d%d%d\n", -42, 4, -1, 1, 4);
    //printf("vrai printf %S\n", str);
    //printf("%5s\n", s2);
    //printf("%p\n", &a);
    printf("%+d\n", 42);
    printf("%#x\n", 42);
    //printf("%10s\n", str);
	// ft_printf("   %x", 16);
    f = 0;
   // printf("%19.2f\n", 2.1);
    f |= (1 << 4);
   // printf("%d\n", f);
    //a_end(ap);
   // f |= (1 << 14);
   // printf("%d\n", f);
   // printf("%#08x", 42);
    return (0);
}
