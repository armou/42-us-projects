/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_utf8len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:40:24 by amulin            #+#    #+#             */
/*   Updated: 2016/03/18 17:51:22 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstr_utf8len(const wchar_t *wstr)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (wstr[i])
	{
		len += ft_wchar_utf8len(wstr[i]);
		i++;
	}
	return (len);
}
