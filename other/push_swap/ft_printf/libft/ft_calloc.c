/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:45:14 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/13 15:52:25 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	nb;
	void	*p;

	nb = nmemb * size;
	if (nmemb != 0 && size != 0 && (nb / nmemb != size))
		return (NULL);
	p = malloc(nb);
	if (!p)
		return (NULL);
	ft_bzero(p, nb);
	return (p);
}
/*
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    int *ptr;
	int n, i;

    n = 20;

    ptr = (int*)ft_calloc(n, sizeof(int));

    if (ptr == NULL)
	{
        printf("Memory not allocated.\n");
        exit(0);
    }
    else
	{
        for (i = 0; i < n; ++i)
		{
            printf("%d,", ptr[i]);
        }
    }

    return 0;

	int size = 8539;

	void * d1 = ft_calloc(size, sizeof(int));
	void * d2 = calloc(size, sizeof(int));
	if (memcmp(d1, d2, size * sizeof(int)))
		printf("TEST_FAILED");
	else
	{
		free(d1);
		free(d2);
		printf("TEST_SUCCESS");
	}

	void *str = ft_calloc(0, 0);

	if (str == ((void*)0))
		printf("TEST_FAILED");
	else
{
		free(str);
		printf("TEST_SUCCESS");
}
}
*/
