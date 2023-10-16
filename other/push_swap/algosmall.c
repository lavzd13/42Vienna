/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algosmall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:55:37 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/14 13:20:13 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include "push_swap.h"

int	checkorder(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (*(int *)(stack->content) > *(int *)(stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	swaping(int first, int second, int third, t_list *astack)
{
	if (first < second && second > third)
	{
		if (first > third)
			rra(astack);
		else
		{
			rra(astack);
			sa(astack);
		}
	}
	else if (first > second && second < third)
	{
		if (first > third)
			ra(astack);
		else
			sa(astack);
	}
	else if (first > second && second > third)
	{
		sa(astack);
		rra(astack);
	}
	else
		return ;
}

void	algothree(t_list *astack)
{
	int	size;
	int	first;
	int	second;
	int	third;

	size = ft_lstsize(astack);
	if (size == 1)
		return ;
	first = *(int *)astack->content;
	second = *(int *)astack->next->content;
	if (size == 2)
	{
		if (!(checkorder(astack)))
			sa(astack);
	}
	if (size == 3)
	{
		third = *(int *)astack->next->next->content;
		swaping(first, second, third, astack);
	}
}
