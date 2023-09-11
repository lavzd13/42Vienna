/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:41:49 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/09 16:07:26 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

int	set_check(char const s, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == s)
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	beg;
	size_t	end;
	size_t	i;
	char	*string;

	if (s1 == NULL)
		return (NULL);
	beg = 0;
	while (s1[beg] && set_check(s1[beg], set))
		++beg;
	end = ft_strlen(s1);
	while (end > beg && set_check(s1[end - 1], set))
		--end;
	string = (char *)malloc((end - beg + 1) * sizeof(*s1));
	if (string == NULL)
		return (NULL);
	i = 0;
	while (beg < end)
	{
		string[i] = s1[beg];
		++beg;
		++i;
	}
	string[i] = '\0';
	return (string);
}
