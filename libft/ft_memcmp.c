/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:28:24 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/06 16:57:34 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	unsigned int		i;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}
/*
#include<stdio.h>
#include<string.h>
int	main()
{
	char str1[] = "aaaaaa";
	char str2[] = "ABCDEF";
	int res = ft_memcmp(str1, str2, 5);
	int res1 = memcmp(str1, str2, 5);
	printf("Mine: %d\nFunction: %d", res, res1);
}
*/
