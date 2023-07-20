/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:54:13 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/15 22:21:31 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] > s2[i])
		{
			return (1);
		}
		else if (s1[i] < s2[i])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}
/*
#include<stdio.h>
#include<string.h>
int main()
{
	char a[] = "BHVI$&gh2947gh-&^*svdj";
	char b[] = "UJHVOIJW(*#)!*G0h108g1h";
	unsigned int n = 12;
	int result1 = ft_strncmp(a, b, n);
	int result2 = strncmp(a, b, n);
	printf("Mine:%d\nStrncmp: %d", result1, result2);
}
*/
