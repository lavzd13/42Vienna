/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:02:24 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/17 14:19:46 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	number;

	i = 0;
	number = 1;
	if (nb == 1 || nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	while (i < nb)
	{
		number = number * (i + 1);
		i++;
	}
	return (number);
}
/*
#include<stdio.h>
int main()
{
	int a = ft_iterative_factorial(-3);
	printf("%d", a);
}
*/
