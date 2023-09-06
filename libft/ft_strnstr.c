/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:03:15 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/05 13:53:30 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *big, const char *little, unsigned int len)
{
	int	i;
	int	j;

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
#include<string.h>
#include<stdio.h>

int	main()
{
	char str[] = "Hel@#^^()*-1lo";
	char to_find[] = "^^";
	char str1[] = "Hel@#^^()*-1lo";
	char to_find1[] = "^^";

	char *result1 = ft_strnstr(str, to_find, 3);
    //char *result2 = strnstr(str1, to_find1, 10);

	printf("Mine: %s\nFunction: ", result1);
}
*/
