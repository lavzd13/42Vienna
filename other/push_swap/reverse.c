/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:58:26 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/14 19:11:26 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"

void	rra(t_list *astack)
{
	int		temp;
	t_list	*current;
	int		last;

	if (!astack)
		return ;
	current = astack;
	while (current->next != NULL)
		current = current->next;
	last = *(int *)current->content;
	current = astack;
	while (current != NULL)
	{
		temp = *(int *)(current->content);
		*(int *)(current->content) = last;
		last = temp;
		current = current->next;
	}
	*(int *)(astack->content) = last;
}

void	rrb(t_list *bstack)
{
	int		temp;
	t_list	*current;
	int		last;

	if (!bstack)
		return ;
	current = bstack;
	while (current->next != NULL)
		current = current->next;
	last = *(int *)current->content;
	current = bstack;
	while (current != NULL)
	{
		temp = *(int *)(current->content);
		*(int *)(current->content) = last;
		last = temp;
		current = current->next;
	}
	*(int *)(bstack->content) = last;
}

void	rrr(t_list*astack, t_list*bstack)
{
	rra(astack);
	rrb(bstack);
}
