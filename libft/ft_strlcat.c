/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:27:25 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/06 12:07:33 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dst, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	destlen;
	unsigned int	srclen;
	unsigned int	destend;

	i = 0;
	srclen = ft_strlen(src);
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
#include<string.h>
#include<stdio.h>
int main()
{
    char first[] = "";
    char last[] = "a potentially long string";
    int r;
    int size = 0;
    char buffer[size];

    strcpy(buffer,first);
    r = ft_strlcat(buffer,last,size);

    puts(buffer);
    printf("Value returned: %d\n",r);
    if( r > size )
        puts("String truncated");
    else
        puts("String was fully copied");

    return(0);
}
*/
