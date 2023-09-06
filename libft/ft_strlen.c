/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:40:17 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/05 14:56:54 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return (i);
}
/*
#include<stdio.h>
int	main()
{
	int a = ft_strlen("Hello");
	printf("%d", a);
}
*/
