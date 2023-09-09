/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:54:15 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/09 11:37:15 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;
	size_t	destend;

	i = 0;
	srclen = ft_strlen(src);
	if (dst == 0 && size == 0)
		return (0);
	destlen = ft_strlen(dst);
	destend = destlen;
	if (destend < size - 1 && size > 0)
	{
		while (src[i] && i < size - 1 - destlen)
		{
			dst[destend] = src[i];
			++destend;
			++i;
		}
		dst[destend] = '\0';
	}
	if (destlen >= size)
		destlen = size;
	return (destlen + srclen);
}
/*
#include<bsd/string.h>
#include<stdio.h>
int main()
{

	char first[] = "This is ";
    char last[] = "a potentially long string";
	char first1[] = "This is ";
	char last1[] = "a potentially long string";
    int r;
	int res;
    int size = 16;
    char buffer[size];
	char buffer1[size];

    strcpy(buffer, first);
	strcpy(buffer1, first1);
    r = ft_strlcat(buffer, last, size);
	res = strlcat(buffer1, last1, size);

    puts(buffer);
	puts(buffer1);
    printf("Mine: %d\nFunction: %d\n", r, res);
    if( r > size )
        puts("String truncated");
    else
        puts("String was fully copied");

    return(0);

	char *str = "the cake is a lie !\0I'm hidden lol\r\n";
	char buff1[0xF00] = "there is no stars in the sky";
	char buff2[0xF00] = "there is no stars in the sky";
	size_t max = strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4;

	strlcat(buff1, str, max);
	ft_strlcat(buff2, str, max);
	if (!strcmp(buff1, buff2))
		printf("TEST_SUCCESS\nFunction: %s\nMine: %s\n", buff1, buff2);
	else
		printf("TEST_FAILED\nFunction: %s\nMine: %s\n", buff1, buff2);


	char b[0xF] = "nyan !";

	ft_strlcat(((void*)0), b, 0);
	printf("TEST_SUCCESS");
}
*/
