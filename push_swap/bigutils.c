/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:10:30 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/19 17:27:08 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"

int	biggest(t_list **bstack, int current)
{
	t_list	*b;

	b = *bstack;
	while (b)
	{
		if (*(int *)b->content > current)
		{
			return (0);
		}
		b = b->next;
	}
	return (1);
}

int	lowest(t_list **bstack, int current)
{
	t_list	*b;

	b = *bstack;
	while (b)
	{
		if (*(int *)b->content < current)
			return (0);
		b = b->next;
	}
	return (1);
}

int	findlower(t_list **bstack, int current)
{
	int		min;
	t_list	*b;

	if (bstack == NULL)
		return (-1);
	b = *bstack;
	min = findmin(bstack);
	while (b)
	{
		if (*(int *)b->content > min && *(int *)b->content < current)
			min = *(int *)b->content;
		b = b->next;
	}
	return (min);
}

void	acalc(t_list **astack, int content, t_moves *moves)
{
	if ((ft_lstsize(*astack) / 2) >= finpos(astack, content))
		moves->ra = finpos(astack, content);
	else
		moves->rra = (ft_lstsize(*astack) - finpos(astack, content));
	while (moves->ra != 0 && moves->rb != 0)
	{
		(moves->rr)++;
		(moves->ra)--;
		(moves->rb)--;
	}
	while (moves->rra != 0 && moves->rrb != 0)
	{
		(moves->rrr)++;
		(moves->rra)--;
		(moves->rrb)--;
	}
	moves->final = moves->ra + moves->rb + moves->rr
		+ moves->rra + moves->rrb + moves->rrr + 1;
}

int	bcalc(t_list **bstack, t_list **astack, int pos, int content)
{
	int		newnum;
	t_moves	moves;

	ft_memset(&moves, 0, sizeof(moves));
	if ((biggest(bstack, content))
		|| (lowest(bstack, content)))
	{
		if ((ft_lstsize(*bstack) / 2) >= pos)
			moves.rb = pos;
		else if ((ft_lstsize(*bstack) / 2) < pos)
			moves.rrb = (ft_lstsize(*bstack) - pos);
	}
	else
	{
		newnum = findlower(bstack, content);
		if ((ft_lstsize(*bstack) / 2) >= finpos(bstack, newnum))
			moves.rb = finpos(bstack, newnum);
		else if ((ft_lstsize(*bstack) / 2) < finpos(bstack, newnum))
			moves.rrb = (ft_lstsize(*bstack) - finpos(bstack, newnum));
	}
	acalc(astack, content, &moves);
	return (moves.final);
}
