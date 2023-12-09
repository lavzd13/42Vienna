/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:49:47 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/14 12:44:20 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[j] != '\0')
	{
		j++;
	}
	i = 0;
	while (src[i] != '\0')
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
/*
#include<stdio.h>
#include<string.h>
int	main()
{
	char dest[45] = "Jss%(jWVOU&^*$@*)^*fwyigi16*)8";
	char src[] = "HJDVWvsj987v&(*^@$*";
	char dest1[45] = "Jss%(jWVOU&^*$@*)^*fwyigi16*)8";
	char src1[] = "HJDVWvsj987v&(*^@$*";

	ft_strcat(dest, src);
	strcat(dest1, src1);
	printf("Moje: %s\nStrcat: %s", dest, dest1);
}
*/
