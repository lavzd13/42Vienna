/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:42:42 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/10 16:21:55 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	size_t	sublen;
	char	*string;

	i = 0;
	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (slen <= start)
		sublen = 0;
	else if (len + start <= slen)
		sublen = len;
	else
		sublen = slen - start;
	string = (char *)malloc((sublen + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	while (i < sublen)
	{
		string[i] = s[start + i];
		++i;
	}
	string[i] = '\0';
	return (string);
}
/*
#include<stdio.h>
#include<string.h>
int	main()
{
	char *str = "i just want this part #############";
	size_t size = 22;
	char *ret = ft_substr(str, 0, size);

	printf("%s\n", ret);
	if (!strncmp(ret, str, size))
	{
		free(ret);
		printf("TEST_SUCCESS\nString: %s", ret);
	}
	else
	{
		free(ret);
		printf("TEST_FAILED\nString: %s", ret);
	}
	
	char *str = "geeksaaaaaaa";
	printf("%s", ft_substr(str, 3, 3));
}
*/
