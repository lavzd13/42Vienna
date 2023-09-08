/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 22:32:49 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/05 15:59:48 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	destlen;
	unsigned int	srclen;

	i = 0;
	destlen = 0;
	srclen = 0;
	while (dest[destlen] != '\0')
	{
		destlen++;
	}
	while (src[srclen] != '\0')
	{
		srclen++;
	}
	if (destlen == size)
		return (destlen + srclen);
	while (src[i] != '\0' && destlen + i < size - 1)
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (destlen + srclen);
}

#include<string.h>
#include<stdio.h>
int main()
{	
	int size = 8;
	char dest[15] = "Halo ";
	char src[] = "du wapl";
	
	int r;
	r = ft_strlcat(dest, src, size);
	int a = strlcat(dest, src, size);
	printf("Value returned: %d\nString: %s\nFunction: %d", r, dest, a);
}
