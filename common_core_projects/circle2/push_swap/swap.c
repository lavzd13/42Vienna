/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:41:12 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/18 16:52:53 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "push_swap.h"

void	sa(t_list **astack)
{
	int	temp;

	if (!*astack)
		return ;
	temp = *(int *)((*astack)->content);
	*(int *)(*astack)->content = *(int *)(*astack)->next->content;
	*(int *)((*astack)->next->content) = temp;
}

void	sb(t_list **bstack)
{
	int		temp;

	if (!*bstack)
		return ;
	temp = *(int *)((*bstack)->content);
	*(int *)(*bstack)->content = *(int *)(*bstack)->next->content;
	*(int *)((*bstack)->next->content) = temp;
}

void	ss(t_list **astack, t_list **bstack)
{
	sa(astack);
	sb(bstack);
}
