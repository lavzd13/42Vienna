/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:25:42 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/10 13:21:30 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = '\0';
		++i;
	}
}
/*
#include<stdio.h>
#include<string.h>

int main()
{
    char str[] = "This is string.h library function";
	char str1[] = "This is string.h library function";

    puts(str);

    ft_bzero(str, 7);
    printf("Mine: %s\n", str);

	bzero(str1, 7);
	printf("Function: %s\n", str1);
}
*/
