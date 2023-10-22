/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigmoving.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:13:31 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/19 17:16:51 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"
#include <unistd.h>

int	bposcalc(t_list **bstack, int pos, int content)
{
	int	newnum;

	if ((biggest(bstack, content))
		|| (lowest(bstack, content)))
		return (pos);
	else
	{
		newnum = findlower(bstack, content);
		return (finpos(bstack, newnum));
	}
}

int	findhigher(t_list **bstack, int current)
{
	int		max;
	t_list	*b;

	if (bstack == NULL)
		return (-1);
	b = *bstack;
	max = findmax(bstack);
	while (b)
	{
		if (*(int *)b->content < max && *(int *)b->content > current)
			max = *(int *)b->content;
		b = b->next;
	}
	return (max);
}

void	amoving(t_list **astack, t_list **bstack, int content)
{
	if ((biggest(astack, content))
		|| (lowest(astack, content)))
	{
		if ((ft_lstsize(*astack) / 2) >= finpos(astack, findmin(astack)))
			while (finpos(astack, findmin(astack)) != 0)
				(ra(astack), write(1, "ra\n", 3));
		else
			while (finpos(astack, findmin(astack)) != 0)
				(rra(astack), write(1, "rra\n", 4));
	}
	else
	{
		if ((ft_lstsize(*astack) / 2) >= \
			finpos(astack, findhigher(astack, content)))
			while (finpos(astack, findhigher(astack, content)) != 0)
				(ra(astack), write(1, "ra\n", 3));
		else
			while (finpos(astack, findhigher(astack, content)) != 0)
				(rra(astack), write(1, "rra\n", 4));
	}
	pa(astack, bstack);
	write(1, "pa\n", 3);
}

int	checkdescending(t_list **stack)
{
	t_list	*current;

	current = *stack;
	while (current)
	{
		if (current->content < current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

int	checkascending(t_list **stack)
{
	t_list	*current;

	if (!stack)
		return (0);
	current = *stack;
	while (current)
	{
		if (current->next)
		{
			if (*(int *)current->content > *(int *)current->next->content)
				return (0);
		}
		current = current->next;
	}
	return (1);
}
