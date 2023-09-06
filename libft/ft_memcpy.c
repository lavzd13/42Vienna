/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:39:36 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/06 12:09:59 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	unsigned int		i;
	unsigned char		*dst;
	const unsigned char	*source;

	i = 0;
	dst = (unsigned char *)dest;
	source = (const unsigned char *)src;
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
   char str1[] = "Cpp";
   char str2[] = "Nuts Channel Is Back";

   puts(str2);
   ft_memcpy(str2 + 2, str2, sizeof(char)*5);
   puts(str2);
}
*/
