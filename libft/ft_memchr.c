/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:25:38 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/08 10:29:28 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*str;

	i = 0;
	ch = (unsigned char )c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == c)
			return (str + i);
		++i;
	}
	return (0);
}
/*
#include<stdio.h>
#include<string.h>

int	main()
{
	char test[] = "AAA!!!IDEMO NIIIIS!!";
	char *result = ft_memchr(test, 'I', 20);
	char *result1 = memchr(test, 'I', 20);
	printf("Mine: %s\nFunction: %s\n", result, result1);
}
*/
