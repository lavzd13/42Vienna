/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:11:29 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/08 09:13:58 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return (i);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	int a = ft_strlen("Hello");
	int b = strlen("Hello");
	printf("Mine: %d\nFunction: %d", a, b);
}
*/
