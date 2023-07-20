/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:33:41 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/10 19:32:41 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	mod;

	mod = *a % *b;
	*a = *a / *b;
	*b = mod;
}

/*
#include<stdio.h>

int	main(void)
{
	int x = 6;
	int y = 4;
	int *a = &x;
	int *b = &y;

	ft_ultimate_div_mod(a, b);
	printf("Division: %d\nModul: %d", *a, *b);
}
*/
