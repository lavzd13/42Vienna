/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomke <lomke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:38:23 by jlomic            #+#    #+#             */
/*   Updated: 2023/11/12 18:41:59 by lomke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newN)
{
	t_list	*temp;

	temp = ft_lstlast(*lst);
	if (!temp)
		*lst = newN;
	else
		temp->next = newN;
}
