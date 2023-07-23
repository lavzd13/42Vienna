/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:36:23 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/23 12:47:58 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		++len;
	}
	return (len);
}

void	ft_strcpy(char *dest, char *src)
{
	while (*src != '\0')
	{
		*dest = *src;
		++dest;
		++src;
	}
	*dest = '\0';
}

char	*ft_memory(int length)
{
	char	*result;

	result = (char *)malloc(length);
	if (result == NULL)
		return (NULL);
	*result = '\0';
	return (result);
}

void	ft_put(int size, char **strs, char *result, char *sep)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (strs[i] != NULL)
		{
			ft_strcpy(result + ft_strlen(result), strs[i]);
			if (i < size - 1)
			{
				ft_strcpy(result + ft_strlen(result), sep);
			}
		}
		++i;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		length;
	int		i;
	char	*result;

	if (size == 0)
	{
		return (ft_memory(1));
	}
	length = 0;
	i = 0;
	while (i < size)
	{
		if (strs[i] != NULL)
		{
			length += ft_strlen(strs[i]);
		}
		++i;
	}
	length += (size - 1) * ft_strlen(sep) + 1;
	result = ft_memory(length);
	if (result == NULL)
		return (NULL);
	ft_put(size, strs, result, sep);
	return (result);
}
/*
#include<stdio.h>
int	main()
{
	char *word[] = {"Hello","Halo","Pozdrav","Ciao"};
	int	size = sizeof(word) / sizeof(word[0]);
	char *separator = "---";
	char *result = ft_strjoin(size, word, separator);
	if (result != NULL)
	{
		printf("Concatenated string: %s\n", result);
		free(result);
	}
	else
	{
		printf("Failed!\n");
	}
	char *empty[] = {};
	size = sizeof(empty) / sizeof(empty[0]);
	result = ft_strjoin(size, empty, separator);
	if (result != NULL)
	{
		printf("Concatenated string(prazno): %s\n", result);
		free(result);
	}
	else
	{
		printf("Failed!\n");
	}
	return (0);
}
*/
