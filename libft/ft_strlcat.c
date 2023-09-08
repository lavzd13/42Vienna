/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:54:15 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/08 10:03:40 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	mystrlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;
	size_t	destend;

	i = 0;
	srclen = mystrlen(src);
	destlen = 0;
	while (dst[destlen] != '\0' && destlen < size)
		++destlen;
	destend = destlen;
	if (destlen < size)
	{
		while (src[i] != '\0' && i < size - 1 - destlen)
		{
			dst[destend] = src[i];
			++destend;
			++i;
			if (destend == size - 1)
				break ;
		}
	}
	dst[destend] = '\0';
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
}
*/
