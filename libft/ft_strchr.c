/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:14:21 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/08 10:18:01 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (str + i);
		++i;
	}
	return (0);
}
/*
#include<string.h>
#include<stdio.h>

int	main()
{
	const char str[] = "AAAAAAAAAAAA!IDEMO NIIIIS!";
	int ch = '!';
	char *r;
	char *res;

	r = ft_strchr(str, ch);
	res = strchr(str, ch);

	printf("Mine: %s\nFunction: %s\n", r, res);
}
*/
