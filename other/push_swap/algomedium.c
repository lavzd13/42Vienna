/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algomedium.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:02:52 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/15 15:40:37 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include "push_swap.h"

int	findmin(t_list **stack)
{
	t_list	*lowest;
	t_list	*current;

	current = *stack;
	lowest = current;
	current = current->next;
	while (current)
	{
		if (*(int *)lowest->content > *(int *)current->content)
			lowest = current;
		current = current->next;
	}
	return (*(int *)lowest->content);
}

int	finpos(t_list **stack, int lowmax)
{
	int		i;
	t_list	*current;

	i = 0;
	current = *stack;
	while (current)
	{
		if (*(int *)current->content == lowmax)
			return (i);
		i++;
		current = current->next;
	}
	return (0);
}

void	puttop(int size, int pos, t_list **astack)
{
	t_list	*current;

	current = *astack;
	if (pos == 0)
		return ;
	else if (pos == 1)
		sa(current);
	else if (pos == 2)
	{
		ra(current);
		ra(current);
	}
	else if ((size / 2) < pos)
	{
		if (pos == (ft_lstsize(current) - 1))
			rra(current);
		else
		{
			rra(current);
			rra(current);
		}
	}
}

void	algofive(t_list **astack, t_list **bstack)
{
	int	low;
	int	pos;
	int	size;

	while (ft_lstsize(*astack) != 3)
	{
		size = ft_lstsize(*astack);
		low = findmin(astack);
		pos = finpos(astack, low);
		puttop(size, pos, astack);
		pb(astack, bstack);
	}
	algothree(*astack);
	while (ft_lstsize(*bstack))
		pa(astack, bstack);
}
