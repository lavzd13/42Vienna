/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:10:30 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/18 18:35:58 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

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

int	bcalc(t_list **bstack, int pos, int content)
{
	int	newnum;
	int	moves;

	moves = 0;
	if ((biggest(bstack, content))
		|| (lowest(bstack, content)))
	{
		if ((ft_lstsize(*bstack) / 2) >= pos)
			moves = moves + pos;
		else if ((ft_lstsize(*bstack) / 2) < pos)
			moves = moves + (ft_lstsize(*bstack) - pos);
	}
	else
	{
		newnum = findlower(bstack, content);
		if ((ft_lstsize(*bstack) / 2) >= finpos(bstack, newnum))
			moves = moves + finpos(bstack, newnum);
		else if ((ft_lstsize(*bstack) / 2) < finpos(bstack, newnum))
			moves = moves + (ft_lstsize(*bstack) - finpos(bstack, newnum));
	}
	return (moves);
}

int	acalc(t_list **astack, int content)
{
	int	pos;
	int	moves;
	int	size;

	moves = 0;
	size = ft_lstsize(*astack);
	pos = finpos(astack, content);
	if ((size / 2) >= pos)
		moves += pos;
	else if ((size / 2) < pos)
	{
		moves = moves + (size - pos);
	}
	return (moves);
}
