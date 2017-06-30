/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 16:22:53 by amulin            #+#    #+#             */
/*   Updated: 2015/02/13 17:19:19 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	unsigned int	len;
	char			*dst;

	i = 0;
	if (s != NULL && (*f) != NULL)
	{
		len = ft_strlen(s);
		dst = ft_strnew(len);
		if (!dst)
			return (NULL);
		while (s[i] != '\0')
		{
			dst[i] = (*f)(s[i]);
			i++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
