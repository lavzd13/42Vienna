/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 21:19:21 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/19 16:10:00 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	funkcion(int *s, char *string)
{
	int	brojac;
	int	i;

	i = 0;
	brojac = 1;
	while ((string[i] >= 9 && string[i] <= 13) || string[i] == 32)
		i++;
	while (string[i] == 43 || string[i] == 45)
	{
		if (string[i] == 45)
			brojac *= -1;
		i++;
	}
	*s = i;
	return (brojac);
}

int	ft_atoi(char *str)
{
	int	i;
	int	minus;
	int	number;

	number = 0;
	minus = funkcion(&i,str);
	while (str[i] >= 48 && str[i] <= 57 && str[i])
	{
		number = (number * 10) + (str[i] - 48);
		i++;
	}
	return (number * minus);
}

#include<stdio.h>
#include<stdlib.h>
int	main()
{
	int proba;
	int moje;
	char arr[] = "	  ---+--+01234506789ab567";

	proba = atoi(arr);
	moje = ft_atoi(arr);
	printf("String: %s\nInt atoi: %d\n", arr, proba);
	printf("String: %s\nInt moje: %d", arr, moje);
}

