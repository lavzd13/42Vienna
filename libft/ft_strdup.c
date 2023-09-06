/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:45:25 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/06 19:56:06 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
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
	dest = (char *)malloc(ft_strlen(str) * (sizeof(char) + 1));
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
	printf("%s", target);
}
*/
