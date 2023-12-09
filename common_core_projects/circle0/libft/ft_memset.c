/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:15:51 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/09 11:18:28 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = c;
		++i;
	}
	return (s);
}
/*
#include<stdio.h>
#include<string.h>

int	main()
{
	char str[] = "This is string.h library function";
	char str1[] = "This is string.h library function";
	char buffer[5000];
	char buffer1[5000];

	
	puts(str);
	ft_memset(str, 'A', 4);
	printf("Mine: %s\n", str);

	memset(str1, 'A', 4);
	printf("Function: %s\n", str1);

	puts(buffer);
    ft_memset(buffer, 'A', 4000);
    printf("Mine: %s\n", buffer);

    memset(buffer1, 'A', 4000);
    printf("Function: %s\n", buffer1);
}
*/
