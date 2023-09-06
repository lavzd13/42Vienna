/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:52:18 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/06 16:28:04 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned int	i;
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
	char *result = memchr(test, 'I', 20);
	printf("%s", result);
}
*/
