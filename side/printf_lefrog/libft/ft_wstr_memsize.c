/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_memsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:39:03 by amulin            #+#    #+#             */
/*   Updated: 2016/02/26 16:39:20 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstr_memsize(const wchar_t *wstr)
{
	size_t	len;

	len = 0;
	while (wstr[len])
		len++;
	return (len * 4);
}
