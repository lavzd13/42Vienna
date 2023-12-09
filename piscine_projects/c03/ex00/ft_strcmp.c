/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:31:34 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/14 10:35:57 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' || s2[i] == '\0')
		{
			break ;
		}
		i++;
	}
	if ((s1[i] - s2[i]) < 0)
	{
		return (s1[i] - s2[i]);
	}
	if ((s1[i] - s2[i]) > 0)
	{
		return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}

/*
#include<stdio.h>
#include<string.h>
int	main()
{
	char a[] = "IYG&%R&Itfi6t75di7";
	char b[] = "IHV@(*$U)GJ@PI)V*!@_(B";
	int result1 = ft_strcmp(a, b);
	int result2 = strcmp(a, b);
	printf("Mine: %d\n", result1);
	printf("Strcmp: %d", result2);

}
*/
