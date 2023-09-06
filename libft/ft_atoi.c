/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:54:04 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/06 13:01:15 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	idemo_nis(int *p, char *string)
{
	int	i;
	int	minus;

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

int	ft_atoi(const char *nptr)
{
	int		i;
	int		number;
	int		sign;
	char	*str;

	number = 0;
	str = (char *)nptr;
	sign = idemo_nis(&i, str);
	if (str[i] < 48 || str[i] > 57)
		return (0);
	while (str[i] >= 48 && str[i] <= 57 && str[i])
	{
		number = (number * 10) + (str[i] - 48);
		++i;
	}
	return (number * sign);
}

/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int proba;
    int moje;
    char arr[] = "	  \v-14562314ab567";

    proba = atoi(arr);
    moje = ft_atoi(arr);
    printf("String: %s\nInt atoi: %d\n", arr, proba);
    printf("String: %s\nInt moje: %d", arr, moje);
}
*/
