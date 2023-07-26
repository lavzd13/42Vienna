/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:48:02 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/25 13:43:58 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	basecheck(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str[0] == '\0' || str[1] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] <= 32 || str[i] == 127 || str[i] == 43 || str[i] == 45)
			return (0);
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	whitespace(char *str, int *ptr)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			count *= -1;
		i++;
	}
	*ptr = i;
	return (count);
}

int	findbase(char str, char *base)
{
	int	num;

	num = 0;
	while (base[num] != '\0')
	{
		if (str == base[num])
			return (num);
		++num;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	minus;
	int	num;
	int	num2;
	int	len;

	i = 0;
	num = 0;
	len = basecheck(base);
	if (len >= 2)
	{
		minus = whitespace(str, &i);
		num2 = findbase(str[i], base);
		while (num2 != -1)
		{
			num = (num * len) + num2;
			++i;
			num2 = findbase(str[i], base);
		}
		return (num *= minus);
	}
	return (0);
}
/*
#include<stdio.h>
int	main()
{
	char arr[] = "  	+++--++-12345678aahfj124asd";
	char base[] = "0123456789";
	int a = ft_atoi_base(arr, base);
	printf("%d", a);
}
*/
