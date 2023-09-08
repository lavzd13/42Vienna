/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:03:08 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/08 11:03:13 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft1_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;
	char	*str;

	i = 0;
	str = (char *)s;
	dest = (char *)malloc(ft1_strlen(str) * (sizeof(char) + 1));
	if (dest == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include<stdio.h>
#include<string.h>
int main()
{
	char source[] = "Hello";
	char *target = ft_strdup(source);
	char *target2 = strdup(source);
	printf("Mine: %s\nFucntion: %s\n", target, target2);
}
*/
