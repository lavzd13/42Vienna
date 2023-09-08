/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:23:24 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/08 10:24:48 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		++i;
	}
	return (0);
}
/*
#include<stdio.h>
#include<string.h>
int main()
{
	char a[] = "testb";
	char b[] = "testa";
	unsigned int n = 6;
	int result1 = ft_strncmp(a, b, n);
	int result2 = strncmp(a, b, n);
	printf("Mine:%d\nStrncmp: %d", result1, result2);
}
*/
