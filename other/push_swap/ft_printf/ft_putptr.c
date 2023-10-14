/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:17:05 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/20 21:41:35 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_ptr(unsigned long long int n, char format)
{
	int	result;

	result = 0;
	if (n > 15)
	{
		result += ft_puthex_ptr(n / 16, format);
		result += ft_puthex_ptr(n % 16, format);
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

int	ft_putptr(void *p)
{
	int						result;
	unsigned long long int	ptr;

	result = 0;
	if (!p)
		return (write(1, "(nil)", 5));
	ptr = (unsigned long long int)p;
	result += write(1, "0x", 2);
	result += ft_puthex_ptr(ptr, 'x');
	return (result);
}
/*
#include <stdio.h>
int	main()
{
	unsigned long long int	i = 21474836478;
	unsigned long long int	*p = &i;
	int a = ft_putptr(p);
	printf("\n");
	int b = printf("%p", p);
	printf("\n");
	printf("Mine: %d\nPrintf: %d", a, b);
}
*/
