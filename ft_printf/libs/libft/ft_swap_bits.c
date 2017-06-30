/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <aoudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 15:29:03 by aoudin            #+#    #+#             */
/*   Updated: 2016/07/06 15:31:01 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	ft_swap_bits(unsigned char octet)
{
	return ((octet & 0b11110000) >> 4) | ((octet & 0b00001111) << 4);
}