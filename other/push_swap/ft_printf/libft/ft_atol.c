/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:26:31 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/19 22:51:59 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <unistd.h>

static int	idemo_nis(int *p, char *string)
{
	int				i;
	long long int	minus;

	i = 0;
	minus = 1;
	while ((string[i] >= 9 && string[i] <= 13) || string[i] == 32)
		++i;
	if (string[i] == '-' || string[i] == '+')
	{
		if (string[i] == '-')
			minus *= -1;
		++i;
	}
	*p = i;
	return (minus);
}

void	loopthrough(const char *str)
{
	int		i;
	char	*check;

	i = 0;
	check = (char *)str;
	if (check[0] == '+' || check[0] == '-')
		i++;
	while (check[i])
	{
		if (!(check[i] >= 48 && check[i] <= 57))
			(write(2, "Error\n", 6), exit(EXIT_FAILURE));
		i++;
	}
}

long long int	ft_atol(const char *nptr)
{
	int				i;
	long long int	number;
	long long int	sign;
	char			*str;

	loopthrough(nptr);
	number = 0;
	str = (char *)nptr;
	sign = idemo_nis(&i, str);
	if (str[i] < 48 || str[i] > 57)
		(write(2, "Error\n", 6), exit(EXIT_FAILURE));
	while (str[i] >= 48 && str[i] <= 57 && str[i])
	{
		number = (number * 10) + (str[i] - 48);
		++i;
	}
	return (number * sign);
}
/* #include<stdio.h>
#include<stdlib.h>
int main()
{
	long long int	proba;
	long long int	moje;
	char arr[] = "	-2147483649";

	proba = atol(arr);
	moje = ft_atol(arr);
	printf("String: %s\nInt atol: %lld\n", arr, proba);
	printf("String: %s\nInt mine: %lld\n", arr, moje);
} */
