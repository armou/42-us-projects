/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endian_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:59:59 by amulin            #+#    #+#             */
/*   Updated: 2016/02/25 18:01:22 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_endian_swap(unsigned int input)
{
	unsigned int	output;

	if (sizeof(input) != 4)
	{
		ft_putendl("error: int size not supported. End of program");
		return (0);
	}
	output = (input << 24);
	output |= ((input << 8) & 0x00FF0000);
	output |= ((input >> 8) & 0x0000FF00);
	output |= (input >> 24);
	return (output);
}
