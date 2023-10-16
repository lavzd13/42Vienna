/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:48:32 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/13 15:58:44 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list *astack)
{
	int		temp;
	t_list	*current;

	current = astack;
	if (!astack)
		return ;
	while (current->next != NULL)
	{
		temp = *(int *)(current->content);
		*(int *)(current->content) = *(int *)(current->next->content);
		*(int *)(current->next->content) = temp;
		current = current->next;
	}
}

void	rb(t_list *bstack)
{
	int		temp;
	t_list	*current;

	current = bstack;
	if (!bstack)
		return ;
	while (current->next != NULL)
	{
		temp = *(int *)(current->content);
		*(int *)(current->content) = *(int *)(current->next->content);
		*(int *)(current->next->content) = temp;
		current = current->next;
	}
}

void	rr(t_list*astack, t_list*bstack)
{
	ra(astack);
	rb(bstack);
}
