/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paddzero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:47:39 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/19 15:58:08 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_minus(int nb, char *str)
{
	int		i;
	int		number;
	int		result;
	int		count;
	char	*string;

	i = 0;
	number = 0;
	count = ft_count(nb);
	result = 0;
	while (str[result] >= 48 && str[result] <= 57 && str[result])
		number = (number * 10) + (str[result++] - 48);
	result = 0;
	while (i < number - count)
	{
		i++;
		result += ft_putchar('0');
	}
	string = ft_itoa(nb);
	result += ft_putstr(string);
	free (string);
	return (result);
}

/*
#include <stdio.h>
int	main()
{
	char *str = "050d";
	int nb = 42;
	int b = ft_minus(nb, str);
	printf("\n");
	printf("Mine: %d\n", b);
	int z = printf("%050d", nb);
	printf("\n");
	printf("Printf: %d", z);
}
*/
