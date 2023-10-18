/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algosmall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:55:37 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/18 15:36:06 by jlomic           ###   ########.fr       */
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

void	swaping(int first, int second, int third, t_list **astack)
{
	if (first < second && second > third)
	{
		if (first > third)
		{
			rra(astack);
			write(1, "rra\n", 4);
		}
		else
		{
			rra(astack);
			write(1, "rra\n", 4);
			sa(astack);
			write(1, "sa\n", 3);
		}
	}
	else if (first > second && second < third)
	{
		if (first > third)
		{
			ra(astack);
			write(1, "ra\n", 3);
		}
		else
		{
			sa(astack);
			write(1, "sa\n", 3);
		}
	}
	else if (first > second && second > third)
	{
		sa(astack);
		write(1, "sa\n", 3);
		rra(astack);
		write(1, "rra\n", 4);
	}
	else
		return ;
}

void	algothree(t_list **astack)
{
	int	size;
	int	first;
	int	second;
	int	third;

	size = ft_lstsize(*astack);
	if (size == 1)
		return ;
	first = *(int *)(*astack)->content;
	second = *(int *)(*astack)->next->content;
	if (size == 2)
	{
		if (!(checkorder(*astack)))
		{
			sa(astack);
			write(1, "sa\n", 3);
		}
	}
	if (size == 3)
	{
		third = *(int *)(*astack)->next->next->content;
		swaping(first, second, third, astack);
	}
}
