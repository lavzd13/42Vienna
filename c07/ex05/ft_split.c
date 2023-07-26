/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:32:40 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/26 12:58:02 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	sep_check(char s, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (s == charset[i])
			return (1);
		++i;
	}
	return (0);
}

int	count_str(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && sep_check(str[i], charset))
			str++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !sep_check(str[i], charset))
			str++;
	}
	return (count);
}

int	ft_strlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !sep_check(str[i], charset))
		i++;
	return (i);
}

char	*ft_word(char *str, char *charset)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	len = ft_strlen(str, charset);
	word = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		word[i] = str[i];
		++i;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**array;
	int		i;
	int		j;

	array = (char **)malloc(sizeof(char *) * (count_str(str, charset) + 1));
	i = 0;
	j = 0;
	while (str[j] != '\0')
	{
		while (str[j] != '\0' && sep_check(str[j], charset))
			++j;
		if (str[j] != '\0')
		{
			array[i] = ft_word(&str[j], charset);
			++i;
		}
		while (str[j] != '\0' && !sep_check(str[j], charset))
			++j;
	}
	array[i] = 0;
	return (array);
}
/*
#include <stdio.h>
int	main()
{
	char arr[] = "Hello..1....+....-..my.name";
	char charset[] = "+-1...";
	char **strings = ft_split(arr, charset);
	int	i;
	
	i = 0;
	while (strings[i] != 0)
	{
		printf("%s\n", strings[i]);
		++i;
	}
}
*/
