/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:39:05 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/13 12:57:53 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*templ;
	t_list	*tempc;

	if (!lst || !f || !del)
		return (0);
	result = 0;
	while (lst)
	{
		tempc = f(lst->content);
		templ = ft_lstnew(tempc);
		if (!templ)
		{
			free(templ);
			free(tempc);
			ft_lstclear(&result, del);
			return (0);
		}
		ft_lstadd_back(&result, templ);
		lst = lst->next;
	}
	return (result);
}
