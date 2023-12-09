/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:39:41 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/10 19:03:31 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	change;

	change = *b;
	*b = *a;
	*a = change;
}

/*
#include <stdio.h>

int	main(void)
{
	int one = 1;
	int two = 2;
	int	*a = &one;
	int *b = &two;

	printf("Before a:%d and b:%d \n", one, two);
	ft_swap(a, b);
	printf("After a:%d and b:%d", one, two);
}
*/
