/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:22:51 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/15 22:27:12 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		while (str[i + j] == to_find[j] && str[i + j] != '\0')
			j++;
		if (to_find[j] == '\0')
			return (str + i);
		i++;
		j = 0;
	}
	return (0);
}
/*
#include<stdio.h>
#include<string.h>
int main()
{
	char str[] = "Hel@#^^()*-1lo";
	char to_find[] = "^^";
	char str1[] = "Hel@#^^()*-1lo";
	char to_find1[] = "^^";

	char *result1 = ft_strstr(str, to_find);
	char *result2 = strstr(str1, to_find1);
	printf("Moje: %s\nStrstr: %s", result1, result2);
}
*/
