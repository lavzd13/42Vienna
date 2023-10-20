/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:48:32 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/18 16:57:26 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

void	ra(t_list **astack)
{
	int		temp;
	t_list	*current;

	if (!astack)
		return ;
	current = *astack;
	while (current->next != NULL)
	{
		temp = *(int *)(current->content);
		*(int *)(current->content) = *(int *)(current->next->content);
		*(int *)(current->next->content) = temp;
		current = current->next;
	}
}

void	rb(t_list **bstack)
{
	int		temp;
	t_list	*current;

	if (!bstack)
		return ;
	current = *bstack;
	while (current->next != NULL)
	{
		temp = *(int *)current->content;
		*(int *)current->content = *(int *)current->next->content;
		*(int *)current->next->content = temp;
		current = current->next;
	}
}

void	rr(t_list **astack, t_list **bstack)
{
	ra(astack);
	rb(bstack);
}
