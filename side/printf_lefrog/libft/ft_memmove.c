/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:09:12 by amulin            #+#    #+#             */
/*   Updated: 2015/02/13 17:28:38 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*tmp;

	if (dst != NULL && src != NULL)
	{
		tmp = ft_memalloc(len);
		if (!tmp)
			return (NULL);
		ft_memcpy(tmp, src, len);
		ft_memcpy(dst, tmp, len);
		return (dst);
	}
	return (NULL);
}
