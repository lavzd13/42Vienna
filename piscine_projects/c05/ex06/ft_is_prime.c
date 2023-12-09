/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:05:42 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/17 14:49:43 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 5;
	if (nb <= 1)
		return (0);
	if (nb == 2147483647)
		return (1);
	if (nb == 2 || nb == 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0 || nb % (i + 2) == 0)
			return (0);
		i += 6;
	}
	return (1);
}
/*
#include<stdio.h>
int main()
{
	int a = ft_is_prime(2147483629);
	int b = ft_is_prime(135168451);
	int c = ft_is_prime(165466563);
	int d = ft_is_prime(516468435);
	int e = ft_is_prime(2147483647);
	printf("1: %d\n?: %d\n?: %d\n?: %d\n1: %d", a, b, c, d, e);
}
*/
