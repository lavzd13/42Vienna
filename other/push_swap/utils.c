/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:43:04 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/14 20:18:13 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include "push_swap.h"

t_list	*putnum(int number, t_list *astack, t_list *bstack)
{
	t_list	*newnode;

	newnode = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!newnode)
	{
		freestack(astack);
		freestack(bstack);
		exit (EXIT_FAILURE);
	}
	newnode->content = (int *)ft_calloc(1, sizeof(int));
	if (!(newnode->content))
	{
		freestack(astack);
		freestack(bstack);
		free(newnode);
		exit (EXIT_FAILURE);
	}
	*(int *)(newnode->content) = number;
	newnode->next = NULL;
	return (newnode);
}

void	freestack(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp->content);
		free(temp);
	}
}

int	checkletter(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!((argv[i][j] >= 48 && argv[i][j] <= 57)
			|| (argv[i][j] == '+' || argv[i][j] == '-')))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	checkinput(char **argv)
{
	long long int	number;
	int				i;
	int				j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	i = 1;
	while (argv[i])
	{
		number = ft_atol(argv[i]);
		if (number > 2147483647 || number < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

t_list	*makelist(char **argv, int argc, t_list *astack, t_list *bstack)
{
	int		number;
	int		i;
	t_list	*newnode;

	i = 1;
	while (i < argc)
	{
		number = ft_atoi(argv[i]);
		newnode = putnum(number, astack, bstack);
		ft_lstadd_back(&astack, newnode);
		i++;
	}
	return (astack);
}
