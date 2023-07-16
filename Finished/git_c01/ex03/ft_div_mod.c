/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:08:41 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/10 19:30:54 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
#include<stdio.h>

int	main(void)
{
	int x = 5;
	int y = 2;
	int *div;
	int *mod;
	int razlika;
	int moduo;

	div = &razlika;
	mod = &moduo;

	ft_div_mod(x, y, div, mod);

	printf("Divide: %d\nModule: %d", *div, *mod);
}
*/
