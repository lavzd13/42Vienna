/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:36:30 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/08 10:40:10 by jlomic           ###   ########.fr       */
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
	while (i < len && (big[i] != '\0'))
	{
		while (big[i + j] == little[j] && big[i + j] != '\0')
			++j;
		if (little[j] == '\0')
			return ((char *)big + i);
		++i;
		j = 0;
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
}
*/
