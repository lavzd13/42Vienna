/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:11:01 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/10 15:23:05 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

int	c_check(char const s, char const c)
{
	if (s == c)
		return (1);
	else
		return (0);
}

int	count(char const *str, char const c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && c_check(str[i], c))
			++i;
		if (str[i] != '\0')
			++count;
		while (str[i] != '\0' && !c_check(str[i], c))
			++i;
	}
	return (count);
}

int	ftsp_strlen(char const *str, char const c)
{
	size_t	i;

	i = 0;
	while (str[i] && !c_check(str[i], c))
		++i;
	return (i);
}

char	*ft_word(char const *str, char const c)
{
	size_t	i;
	size_t	len;
	char	*word;

	i = 0;
	len = ftsp_strlen(str, c);
	word = (char *)malloc((len + 1) * sizeof (char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		++i;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**array;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	array = (char **)malloc((count(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (s[j] != '\0')
	{
		while (s[j] != '\0' && c_check(s[j], c))
			++j;
		if (s[j] != '\0')
		{
			array[i] = ft_word(&s[j], c);
			++i;
		}
		while (s[j] != '\0' && !c_check(s[j], c))
			++j;
	}
	array[i] = 0;
	return (array);
}
/*
#include <stdio.h>
int main()
{
    char *arr = "  tripouille  42  ";
	char c = ' ';
    char **strings = ft_split(arr, c);
    int i;

    i = 0;
    while (strings[i] != 0)
    {
        printf("%s\n", strings[i]);
        ++i;
    }
	
	char *s = "      split       this for   me  !       ";

	char **result = ft_split(s, ' ');
	if (!result)
	{
		printf("TEST_SUCCESS\n");
		for (int i = 0; result[i] != 0; ++i)
			printf("%s\n", result[i]);
	}
	else
	{
		printf("TEST_FAILED\n");
		for (int i = 0; result[i] != 0; ++i)
            printf("%s\n", result[i]);
	}
	printf("%s\n", result[0]);
	
}*/
