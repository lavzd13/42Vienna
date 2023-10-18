/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:29:21 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/18 16:17:04 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	pa(t_list **astack, t_list **bstack)
{
	int		bfirst;
	t_list	*temp;
	t_list	*newnode;

	if (*bstack)
	{
		bfirst = *(int *)((*bstack)->content);
		newnode = putnum(bfirst, astack, bstack);
		ft_lstadd_front(astack, newnode);
		temp = *bstack;
		*astack = newnode;
		*bstack = (*bstack)->next;
		free(temp->content);
		free(temp);
	}
	else
		return ;
}

void	pb(t_list **astack, t_list **bstack)
{
	int		afirst;
	t_list	*temp;
	t_list	*newnode;

	if (*astack)
	{
		afirst = *(int *)((*astack)->content);
		newnode = putnum(afirst, astack, bstack);
		ft_lstadd_front(bstack, newnode);
		temp = *astack;
		*bstack = newnode;
		*astack = (*astack)->next;
		free(temp->content);
		free(temp);
	}
	else
		return ;
}
