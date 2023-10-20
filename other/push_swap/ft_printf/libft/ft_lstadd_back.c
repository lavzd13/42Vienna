/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:38:23 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/12 16:36:05 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newn)
{
	t_list	*temp;

	temp = ft_lstlast(*lst);
	if (!temp)
		*lst = newn;
	else
		temp->next = newn;
}
