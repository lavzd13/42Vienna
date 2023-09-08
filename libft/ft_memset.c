/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:15:51 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/08 11:01:32 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (str[i] != '\0' && i < n)
	{
		str[i] = c;
		++i;
	}
	return (str);
}
/*
#include<stdio.h>
#include<string.h>

int	main()
{
	char str[] = "This is string.h library function";
	char str1[] = "This is string.h library function";

	
	puts(str);
	ft_memset(str, '!', 4);
	printf("Mine: %s\n", str);

	memset(str1, '!', 4);
	printf("Function: %s\n", str1);
}
*/
