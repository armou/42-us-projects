/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <aoudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 17:28:04 by aoudin            #+#    #+#             */
/*   Updated: 2017/05/26 11:50:35 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void        ft_buff(t_info *p, void *newstr, int size)
{
    int     diff;
    int     i;

    i = 0;
   // printf("BS = %d, b_index = %d, size = %d\n", PF_BUFFSIZE, p->b_index, size);
    while (PF_BUFFSIZE - p->b_index < size)
    {
     //   ft_putstr("lala");
        diff = PF_BUFFSIZE - p->b_index;
        ft_memcpy(&(p->buff[p->b_index]), &(newstr[i]), diff);
        size = size - diff;
        i = i + diff;
     //   p->b_index += diff;
       // write(1, p->buff, p->b_index);
        p->b_index = 0;
        p->len += diff;
    }
    ft_memcpy(&(p->buff[p->b_index]), &(newstr[i]), size);
    p->b_index += size;
    p->len += size;
    //ft_memdel(newstr);
}