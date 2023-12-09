/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:38:45 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/13 12:47:15 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*temp;

	if (!lst || !(del))
		return ;
	ptr = *lst;
	while (ptr != NULL)
	{
		temp = ptr;
		ptr = ptr->next;
		del(temp->content);
		free(temp);
	}
	*lst = NULL;
}
