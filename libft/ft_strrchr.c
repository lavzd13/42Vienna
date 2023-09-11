/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:18:50 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/10 21:36:33 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		index;
	char	*str;

	i = 0;
	index = -1;
	str = (char *)s;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			index = i;
		++i;
	}
	if (str[i] == c)
		return (str + i);
	if (index == -1)
		return (0);
	else
		return (str + index);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	//char str[] = "";
	//int ch = '.';
	char *r;
	char *res;

	r = ft_strrchr("teste", '\0');
	res = strrchr("teste", '\0');

	printf("Mine: %s\nFunction: %s\n", r, res);
}
*/
