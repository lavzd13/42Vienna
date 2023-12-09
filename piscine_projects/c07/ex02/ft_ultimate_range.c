/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:47:12 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/21 11:34:17 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	j;
	int	*ptr;

	len = max - min;
	ptr = malloc(sizeof(int) * len);
	*range = ptr;
	j = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	if (ptr == NULL)
	{
		*range = 0;
		return (-1);
	}
	while (j < len)
	{
		ptr[j] = min;
		++min;
		++j;
	}
	return (len);
}
/*
#include<stdio.h>
int main()
{
	int	min;
	int	max;
	int	*tab;
	int	size;
	int	i = 0;

	min = 2147483600;
	max = 2147483647;
	size = ft_ultimate_range(&tab, min, max);
	while(i < size)
	{
		printf("%d, ", tab[i]);
		i++;
	}	
}
*/
