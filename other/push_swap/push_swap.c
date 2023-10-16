/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:54:56 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/15 13:23:09 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_list	*astack;
	t_list	*bstack;
	int		size;

	astack = NULL;
	bstack = NULL;
	if (argc <= 1)
		return (-1);
	if (checkinput(argv) == 0 || checkletter(argv) == 0)
		return (write(2 ,"Error\n", 6));
	astack = makelist(argv, argc, astack, bstack);
	size = ft_lstsize(astack);
	if (size <= 3)
		algothree(astack);
	else if (size > 3 && size <= 5)
		algofive(&astack, &bstack);
	else
		algobig(&astack, &bstack);
	t_list *current;
	current = astack;
	while (current)
	{
		printf("-- %d --\n", *(int *)current->content);
		current = current->next;
	}
	printf("Stack A\n");
	current = bstack;
	while (current != NULL)
	{
		printf("-- %d --\n", *(int *)current->content);
		current = current->next;
	}
	printf("Stack B\n");
	freestack(astack);
	freestack(bstack);
}
