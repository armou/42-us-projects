/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 16:23:04 by amulin            #+#    #+#             */
/*   Updated: 2016/01/15 16:21:49 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*ptr;

	ptr = *alst;
	if (alst && *alst && new)
	{
		ptr->prev = new;
		new->next = *alst;
		new->prev = NULL;
		*alst = new;
	}
}
