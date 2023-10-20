/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algobig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:44:10 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/19 17:11:30 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"
#include <limits.h>
#include <unistd.h>

#include <stdio.h>

int	findmax(t_list **stack)
{
	t_list	*max;
	t_list	*current;

	current = *stack;
	max = current;
	current = current->next;
	while (current)
	{
		if (*(int *)max->content < *(int *)current->content)
			max = current;
		current = current->next;
	}
	return (*(int *)max->content);
}

int	calculate(t_list **astack, t_list **bstack, int pos)
{
	t_list	*a;
	t_list	*min;
	int		moves;
	int		minmoves;

	min = *astack;
	a = *astack;
	minmoves = INT_MAX;
	while (a)
	{
		moves = 0;
		moves += bcalc(bstack, astack, pos, *(int *)a->content);
		if (moves < minmoves && moves)
		{
			minmoves = moves;
			min = a;
		}
		a = a->next;
	}
	return (*(int *)min->content);
}

void	moving(t_list **astack, t_list **bstack, int num, int bmax)
{
	int	apos;
	int	bpos;

	apos = finpos(astack, num);
	bpos = bposcalc(bstack, bmax, num);
	if (apos == 0 && bpos == 0)
		(pb(astack, bstack), write(1, "pb\n", 3));
	else if ((ft_lstsize(*astack) / 2) >= apos && \
			(ft_lstsize(*bstack) / 2) >= bpos && bpos != 0 && apos != 0)
		(rr(astack, bstack), write(1, "rr\n", 3));
	else if ((ft_lstsize(*astack) / 2) < apos && \
			(ft_lstsize(*bstack) / 2) < bpos && bpos != 0 && apos != 0)
		(rrr(astack, bstack), write(1, "rrr\n", 4));
	else
	{
		if ((ft_lstsize(*astack) / 2) >= apos && apos != 0)
			(ra(astack), write(1, "ra\n", 3));
		else if ((ft_lstsize(*astack) / 2) < apos && apos != 0)
			(rra(astack), write(1, "rra\n", 4));
		if ((ft_lstsize(*bstack) / 2) >= bpos && bpos != 0)
			(rb(bstack), write(1, "rb\n", 3));
		else if ((ft_lstsize(*bstack) / 2) < bpos && bpos != 0)
			(rrb(bstack), write(1, "rrb\n", 4));
	}
}

void	algobig(t_list **astack, t_list **bstack)
{
	int	max;
	int	pos;
	int	min;

	(pb(astack, bstack), write(1, "pb\n", 3));
	(pb(astack, bstack), write(1, "pb\n", 3));
	while (ft_lstsize(*astack) != 3)
	{
		max = findmax(bstack);
		pos = finpos(bstack, max);
		min = calculate(astack, bstack, pos);
		moving(astack, bstack, min, pos);
	}
	algothree(astack);
	while (*bstack)
		amoving(astack, bstack, *(int *)(*bstack)->content);
	if ((ft_lstsize(*astack) / 2) >= finpos(astack, findmin(astack)))
		while (finpos(astack, findmin(astack)) != 0)
			(ra(astack), write(1, "ra\n", 3));
	else
		while (finpos(astack, findmin(astack)) != 0)
			(rra(astack), write(1, "rra\n", 4));
}
