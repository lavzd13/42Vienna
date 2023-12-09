/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:06:36 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/20 21:08:18 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_formatcheck(va_list args, char c)
{
	int	result;

	result = 0;
	if (c == 'd' || c == 'i')
		result += ft_putnbr(va_arg(args, int));
	else if (c == 's')
		result += ft_putstr(va_arg(args, char *));
	else if (c == 'c')
		result += ft_putchar(va_arg(args, int));
	else if (c == 'u')
		result += ft_unsigned(va_arg(args, unsigned int));
	else if (c == 'p')
		result += ft_putptr(va_arg(args, void *));
	else if (c == 'x' || c == 'X')
		result += ft_puthex(va_arg(args, unsigned int), c);
	else if (c == '%')
		result += ft_putchar('%');
	return (result);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		result;
	int		i;

	i = 0;
	result = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (ft_strchr("cspdiuxX%", str[i + 1]) && str[i + 1])
			{
				result += ft_formatcheck(args, str[i + 1]);
				i++;
			}
		}
		else
			result += ft_putchar(str[i]);
		++i;
	}
	va_end(args);
	return (result);
}
/*
#include <stdio.h>
int	main()
{
	char *s = "Jovan";
	int a = 42;
	int x = ft_printf("My name is : %s, some number: %0100d", s, a);
	printf("\n");
	printf("Mine: %d\n", x);
	int y = printf("My name is : %s, some number: %0100d", s, a);
	printf("\n");
	printf("Printf: %d", y);
	int a = ft_printf(NULL);
	printf("%d", a);
}*/
