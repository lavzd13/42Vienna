/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:58:26 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/18 16:40:57 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include "push_swap.h"

void	rra(t_list **astack)
{
	t_list	*current;
	t_list	*l;

	if (!astack)
		return ;
	current = *astack;
	l = ft_lstlast(current);
	while (current->next->next != NULL)
		current = current->next;
	current->next = NULL;
	current = *astack;
	ft_lstadd_front(astack, l);
}

void	rrb(t_list **bstack)
{
	t_list	*current;
	t_list	*l;

	if (!bstack)
		return ;
	current = *bstack;
	l = ft_lstlast(current);
	while (current->next->next != NULL)
		current = current->next;
	current->next = NULL;
	current = *bstack;
	ft_lstadd_front(bstack, l);
}

void	rrr(t_list **astack, t_list **bstack)
{
	rra(astack);
	rrb(bstack);
}
