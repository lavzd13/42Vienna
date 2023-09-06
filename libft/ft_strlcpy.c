/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:47:52 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/05 17:15:01 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	srclen;

	i = 0;
	srclen = ft_strlen((char *)src);
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
int main()
{
	char dst[] = "IDEMO ";
	const char src[] = "NIIIS!";
	printf("Function: %d\nDest.String:%s ",ft_strlcpy(dst, src, 10), dst);
}
*/
