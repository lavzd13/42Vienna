/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:24:12 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/27 22:27:29 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	smallcheck(char *temp, char *buffer)
{
	if (!temp)
	{
		free(buffer);
		return (0);
	}
	else
		return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return (str + i);
		++i;
	}
	if (str[i] == (unsigned char)c)
		return (str + i);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*total;
	size_t	size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2);
	total = (char *)malloc((size + 1) * sizeof(char));
	if (!total)
		return (NULL);
	while (s1[i] != '\0')
	{
		total[i] = s1[i];
		++i;
	}
	while (s2[j] != '\0')
	{
		total[i + j] = s2[j];
		++j;
	}
	total[size] = '\0';
	return (total);
}

char	*ft_sisaj(char *buffer)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		++i;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	temp = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!temp)
		return (NULL);
	i++;
	while (buffer[i])
		temp[j++] = buffer[i++];
	temp[j] = '\0';
	free(buffer);
	return (temp);
}
