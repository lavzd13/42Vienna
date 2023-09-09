/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:15:32 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/09 15:17:25 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*total;
	size_t	size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2);
	total = (char *)malloc((size + 1) * sizeof(char));
	if (total == NULL)
		return (0);
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
	total[i + j] = '\0';
	return (total);
}
