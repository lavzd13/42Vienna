/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algobig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:44:10 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/16 15:17:33 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdio.h>
// current = *bstack[0] is the top element of B stack because we are adding vlaues on the front
// current = ft_lstlast(*bstack) is the bottom element of the B stack

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

void	calculate(t_list **astack, t_list **bstack, int max, int pos)
{
	t_list	*a;
	t_list	*min;
	int		moves;
	int		minmoves;
	int		newnum;
	int		newpos;
	(void)max;

	a = *astack;
	minmoves = INT_MAX;
	while (a)
	{
		moves = 0;
		if ((biggest(bstack, *(int *)a->content))
			|| (lowest(bstack, *(int *)a->content)))
		{
			printf("The value entered here BIG or LOW: %d\n", *(int *)a->content);
			if (pos == 0)
				moves++;
			else if ((ft_lstsize(*bstack) / 2) >= pos)
				moves = moves + pos;
			else if ((ft_lstsize(*bstack) / 2) < pos)
				moves = moves + (ft_lstsize(*bstack) - pos);
			printf("Moves after big or low: %d and position %d\n", moves, pos);
		}
		else
		{
			moves = 0;
			printf("The value passed to findlower function: %d\n", *(int *)a->content);
			newnum = findlower(*bstack, *(int *)a->content);
			newpos = finpos(bstack, newnum);
			if (newpos == 0)
				moves++;
			else if ((ft_lstsize(*bstack) / 2) >= newpos)
				moves = moves + newpos;
			else if ((ft_lstsize(*bstack) / 2) < newpos)
				moves = moves + (ft_lstsize(*bstack) - newpos);
			printf("The value of the num: %d and his pos: %d\n", newnum, newpos);
			printf("Moves after else: %d\n", moves);
		}
		if (moves < minmoves && moves)
		{
			minmoves = moves;
			min = a;
		}
		a = a->next;
	}
	printf("Min moves: %d\n", minmoves);
	printf("Min: %d\n", *(int *)min->content);
}

void	algobig(t_list **astack, t_list **bstack)
{
	int	max;
	int	pos;

	pb(astack, bstack);
	pb(astack, bstack);
	pb(astack, bstack);
	pb(astack, bstack);
	max = findmax(bstack);
	pos = finpos(bstack, max);
	printf("Pos of max num %d = %d\n", max, pos);
	calculate(astack, bstack, max, pos);
	//algothree(*astack);
	printf("Astack[0]: %d\n", *(int *)(*astack)->content);
	printf("Bstack[0]: %d\n", *(int *)(*bstack)->content);
}
