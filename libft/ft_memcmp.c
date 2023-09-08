/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:31:39 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/08 10:35:27 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

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
	char str2[] = "@ABCDEF";
	int res = ft_memcmp(str1, str2, 5);
	int res1 = memcmp(str1, str2, 5);
	printf("Mine: %d\nFunction: %d", res, res1);
}
*/
