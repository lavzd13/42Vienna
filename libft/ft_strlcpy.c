/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:48:51 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/08 11:22:38 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	my_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = my_strlen((char *)src);
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	return (srclen);
}
/*
#include<stdio.h>
#include<bsd/string.h>
int main()
{
	char dst[] = "IDEMO ";
	const char src[] = "NIIIS!";
	printf("Mine: %zu\nDest.String: %s\n",ft_strlcpy(dst, src, 10), dst);
	printf("Function: %zu\nDest.String: %s\n", strlcpy(dst, src, 10), dst);
}
*/
