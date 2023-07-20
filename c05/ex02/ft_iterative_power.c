/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:41:21 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/17 14:22:51 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	temp;

	i = 1;
	temp = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (i < power)
	{
		nb = nb * temp;
		i++;
	}
	return (nb);
}
/*
#include<stdio.h>
int	main()
{
	int a = ft_iterative_power(5,3);
	printf("%d", a);
}
*/
