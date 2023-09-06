/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:15:51 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/05 19:31:40 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *s, int c, unsigned int n)
{
	unsigned int	i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (str[i] != '\0' && i < n)
	{
		str[i] = c;
		++i;
	}
	return (str);
}
/*
#include<stdio.h>
#include<string.h>

int	main()
{
	char str[] = "This is string.h library function";

	puts(str);

	ft_memset(str, '!', 100);
	puts(str);
}
*/
