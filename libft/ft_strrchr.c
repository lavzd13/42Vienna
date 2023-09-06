/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:43:57 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/05 12:17:52 by jlomic           ###   ########.fr       */
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
#include<stdio.h>
#include<string.h>

int	main()
{
	char str[] = "https://www.tutorialspoint.com";
	int ch = '.';
	char *ret;
	char *ret1;

	ret = strrchr(str, ch);
	ret1 = ft_strrchr(str, ch);

	printf("Function: %s\nMy function: %s", ret, ret1);
}
*/
