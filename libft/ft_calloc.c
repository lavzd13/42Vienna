/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:45:14 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/08 11:39:42 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			nb;
	unsigned char	*p;
	unsigned char	*q;
	size_t			i;

	i = 0;
	nb = nmemb * size;
	if (nb > 2147483647 || nmemb == 0 || size == 0)
		return (NULL);
	p = malloc(nb);
	q = malloc(nb);
	if (p == NULL)
		return (NULL);
	while (i < nb)
	{
		*p++ = 0;
		i++;
	}
	return (q);
}
/*
#include<stdio.h>

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
}
*/
