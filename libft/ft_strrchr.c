/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:18:50 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/08 11:28:36 by jlomic           ###   ########.fr       */
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
		if (str[i] == c)
			index = i;
		++i;
	}
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
	char str[] = "AAAA!AAAAA!AAAA!AAAA!AAAAAA!AAAA!IDEMO NIIIIS";
	int ch = '.';
	char *r;
	char *res;

	r = ft_strrchr(str, ch);
	res = strrchr(str, ch);

	printf("Mine: %s\nFunction: %s\n", r, res);
}
*/
