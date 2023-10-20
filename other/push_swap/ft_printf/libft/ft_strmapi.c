/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:52:02 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/10 13:59:01 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	size;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		str[i] = s[i];
		str[i] = (*f)(i, str[i]);
		++i;
	}
	str[i] = '\0';
	return (str);
}
