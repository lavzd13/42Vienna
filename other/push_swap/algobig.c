/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algobig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:44:10 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/14 21:55:11 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"

void	algobig(t_list **astack, t_list **bstack)
{
	t_list	*current;

	pb(astack, bstack);
	pb(astack, bstack);
	current = *astack;
	pb(astack, bstack);
	algothree(*astack);
	rra(*astack);
	pa(astack, bstack);
	pa(astack, bstack);
	pa(astack, bstack);
	rra(*astack);
	rra(*astack);
}
