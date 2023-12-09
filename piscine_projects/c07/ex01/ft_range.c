/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:08:37 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/22 19:24:28 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	len;
	int	*ptr;
	int	i;

	len = max - min;
	ptr = (int *)malloc(sizeof(*ptr) * len);
	i = 0;
	if (min >= max)
		return (NULL);
	while (i < len)
	{
		ptr[i] = min;
		++min;
		++i;
	}
	return (ptr);
}
/*
#include<stdio.h>
int	main()
{
	int max = 10;
	int min = 3;
	int len = max - min;
	int *range = ft_range(min, max);
	int	i = 0;

	while (i < len)
	{
		printf("%d\n", range[i]);
		++i;
	}
	
}
*/
