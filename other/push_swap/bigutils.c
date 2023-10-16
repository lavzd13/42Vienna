/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:10:30 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/16 15:03:16 by jlomic           ###   ########.fr       */
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
		{
			return (0);
		}
		b = b->next;
	}
	return (1);
}

int	findlower(t_list *bstack, int current)
{
	int		top;
	int		lower;
	t_list	*b;

	if (bstack == NULL)
		return (-1);
	b = bstack;
	top = *(int *)b->content;
	lower = findlower(b->next, current);
	if (top <= current && (lower == -1 || top > lower))
		return (top);
	else
		return (lower);
}

int	bcalc(t_list **bstack, t_list **astack, int pos)
