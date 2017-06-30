/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 17:51:09 by amulin            #+#    #+#             */
/*   Updated: 2015/02/13 12:32:25 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*new;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c)
		{
			new = &s[i];
			return ((char*)new);
		}
		i--;
	}
	return (NULL);
}
