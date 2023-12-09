/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:03:54 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/17 14:26:17 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	y;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (power % 2 == 0)
	{
		y = ft_recursive_power(nb, power / 2);
		return (y * y);
	}
	else
		return (nb * ft_recursive_power(nb, power - 1));
}
/*
#include<stdio.h>
int	main()
{
	int a = ft_recursive_power(5, 8);
	printf("%d", a);
}
*/
