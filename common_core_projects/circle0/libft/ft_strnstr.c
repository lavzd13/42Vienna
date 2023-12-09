/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:36:30 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/08 21:25:54 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[j] == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] && i + j < len)
			++j;
		if (little[j] == '\0')
			return ((char *)big + i);
		++i;
	}
	return (0);
}
/*
#include<bsd/string.h>
#include<stdio.h>

int	main()
{

	char str[] = "Hel@#^^()*-1lo";
	char to_find[] = "^^";
	char str1[] = "Hel@#^^()*-1lo";
	char to_find1[] = "^^";

	char *result1 = ft_strnstr(str, to_find, 10);
    char *result2 = strnstr(str1, to_find1, 10);

	printf("Mine: %s\nFunction: %s\n", result1, result2);

	char *s1 = "MZIRIBMZIRIBMZE123";
	char *s2 = "MZIRIBMZE";
	size_t max = strlen(s2);
	char *i1 = strnstr(s1, s2, max);
	char *i2 = ft_strnstr(s1, s2, max);

	if (i1 == i2)
		printf("TEST_SUCCESS\nMine: %s\nFunction: %s\n", i2, i1);
	else
		printf("TEST_FAILED\nMine: %s\nFunction: %s\n", i2, i1);
}
*/
