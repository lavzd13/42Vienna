/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:13:19 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/05 18:26:40 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *s, unsigned int n)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)s;
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

    puts(str);

    ft_bzero(str, 7);
    puts(str);
}
*/
