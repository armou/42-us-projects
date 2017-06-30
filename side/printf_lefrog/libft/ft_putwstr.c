/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:21:56 by amulin            #+#    #+#             */
/*   Updated: 2016/02/26 15:19:15 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putwstr(wchar_t const *wstr)
{
	int	i;
	int	outlen;

	i = 0;
	outlen = 0;
	while (wstr[i])
	{
		outlen += ft_putwchar(wstr[i]);
		i++;
	}
	return (outlen);
}
