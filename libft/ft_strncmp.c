/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:38:47 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/05 14:09:22 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

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
	char a[] = "test";
	char b[] = "testa";
	unsigned int n = 6;
	int result1 = ft_strncmp(a, b, n);
	int result2 = strncmp(a, b, n);
	printf("Mine:%d\nStrncmp: %d", result1, result2);
}
*/
