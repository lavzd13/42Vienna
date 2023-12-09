/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:00:29 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/11 19:41:19 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*
#include <string.h>
#include <stdio.h>
#include <unistd.h>
int	main()
{
	char dest[] = "Hel";
	char src[] = "3210123";
	char dest1[] = "Hel";
	char src1[] = "3210123";
	int n = 7;
	ft_strncpy(dest, src, n);
	printf("My code: %s\n",dest);
	strncpy(dest1, src1, n);
	printf("Strncpy: %s\n", dest1);
}
*/
