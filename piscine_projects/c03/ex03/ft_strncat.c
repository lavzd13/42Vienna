/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:09:55 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/15 22:37:07 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	j;
	unsigned int	i;

	i = 0;
	j = 0;
	while (dest[j] != '\0')
	{
		j++;
	}
	while (i < nb && src[i] != '\0')
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[i + j] = '\0';
	return (dest);
}
/*
#include<stdio.h>
#include<string.h>
int main()
{
	char dest[100] = "JVOWEOjvlsj9823u0f8(&*^";
	char src[] = "SLKBNogwoh298vn(&492(&$@)*";
	char dest1[100] = "JVOWEOjvlsj9823u0f8(&*^";
	char src1[] = "SLKBNogwoh298vn(&492(&$@)*";
	int n = 12;

	printf("Moje: %s\nStrncat: %s",ft_strncat(dest,src,n), strncat(dest1, src1,n));
}
*/
