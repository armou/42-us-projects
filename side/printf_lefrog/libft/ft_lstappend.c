/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 18:33:24 by amulin            #+#    #+#             */
/*   Updated: 2015/12/28 18:37:23 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list	*ptr;

	ptr = *alst;
	if (alst && *alst && new)
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
		new->next = NULL;
		new->prev = ptr;
	}
}
