/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:35:38 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/17 22:33:27 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_is_prime(int n)
{
	int	i;

	i = 5;
	if (n == 2147483647)
		return (1);
	if (n == 2 || n == 3)
		return (1);
	if (n % 2 == 0 || n % 3 == 0)
		return (0);
	while (i * i <= n)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return (0);
		i += 6;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	z;

	z = 1;
	if (nb < 2)
		return (2);
	while (nb >= 2)
	{
		if (my_is_prime(nb) == 1)
			return (nb);
		nb++;
	}
	return (0);
}
/*
#include<stdio.h>
int main()
{
	int a = ft_find_next_prime(2147483645);
	int b = ft_find_next_prime(81);
	printf("max int: %d\nmyfunc: %d", a, b);
}
*/
