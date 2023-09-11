/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:30:04 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/08 17:43:29 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst;
	const unsigned char	*source;

	i = 0;
	dst = (unsigned char *)dest;
	source = (const unsigned char *)src;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		dst[i] = source[i];
		++i;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main () 
{
	char str1[] = "Cpp  ";
	char str2[] = "Nuts Channel";

	ft_memcpy(str1 , str2, 5);
	printf("Mine: %s\n", str1);
}
*/
