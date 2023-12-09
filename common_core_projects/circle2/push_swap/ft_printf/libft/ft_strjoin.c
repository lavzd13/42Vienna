/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:15:32 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/10 15:13:57 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	funkcion1(char *total, const char *s1)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		total[i] = s1[i];
		++i;
	}
	return (i);
}

int	funkcion2(char *total, const char *s2, int i)
{
	int	j;

	j = 0;
	while (s2[j] != '\0')
	{
		total[i + j] = s2[j];
		++j;
	}
	return (i + j);
}

char	*ft_strjoin(char const *s1, char const *s2)
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
		return (0);
	if (s1)
		i = funkcion1(total, s1);
	if (s2)
		j = funkcion2(total, s2, i);
	total[j] = '\0';
	return (total);
}
