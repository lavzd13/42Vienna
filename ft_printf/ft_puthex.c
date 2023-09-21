/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:30:04 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/20 22:18:23 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char format)
{
	int	result;

	result = 0;
	if (n > 15)
	{
		result += ft_puthex(n / 16, format);
		result += ft_puthex(n % 16, format);
	}
	else
	{
		if (format == 'x')
		{
			result += ft_putchar("0123456789abcdef"[n % 16]);
		}
		else if (format == 'X')
		{
			result += ft_putchar("0123456789ABCDEF"[n % 16]);
		}
	}
	return (result);
}
/*
#include <stdio.h>
int	main()
{
	int	a = 4111111111;
	int b = ft_puthex(a, 'x');
	ft_putchar('\n');
	int z = ft_puthex(a, 'X');
	printf("\n");
	printf("Mine X: %d\n", z);
	printf("Mine x: %d\n", b);
	int y = printf("%x", a);
	printf("\n");
	int x = printf("%X", a);
	printf("\n");
	printf("Printf x: %d\n", y);
	printf("Printf X: %d", x);
}
*/
