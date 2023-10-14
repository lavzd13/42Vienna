/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:21:37 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/09 21:06:14 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		++i;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	char	*nb;
	int		result;

	nb = ft_itoa(n);
	result = ft_putstr(nb);
	free(nb);
	return (result);
}

int	ft_unsigned(unsigned int n)
{
	int	result;

	result = 0;
	if (n == 0)
	{
		return (write(1, "0", 1));
	}
	if (n > 9)
	{
		result += ft_unsigned(n / 10);
		result += ft_unsigned(n % 10);
	}
	else
		result += ft_putchar(n + '0');
	return (result);
}
/*
#include <stdio.h>
int	main()
{
	unsigned int n = 0;

	int x = ft_unsigned(n);
	printf("\n");
	printf("Value of mine: %d\n", x);
	int a = printf("%u", n);
	printf("\n");
	printf("Value of printf: %d\n", a);
	char *str = "050d";
	int nb = 42;
	int b = ft_minus(nb, str);
	printf("\n");
	printf("Mine: %d\n", b);
	int z = printf("%050d", nb);
	printf("\n");
	printf("Printf: %d", z);
	//int w = write(1, "Hello!", 6);
	//printf("Write: %d", w);
	//int b = 033;
	//printf("D: %d I: %i", 0x11, 0x11);
}
*/
