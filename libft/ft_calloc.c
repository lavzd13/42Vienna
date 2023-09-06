/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:05:18 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/06 19:37:59 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t n, size_t size)
{
	size_t			nb;
	unsigned char	*p;
	unsigned char	*q;
	size_t			i;

	i = 0;
	nb = n * size;
	if (nb > 2147483647 || n == 0 || size == 0)
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

    n = 2147483647;
    printf("Enter number of elements: %d\n", n);

    ptr = (int*)calloc(n, sizeof(int));

    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {

        printf("Memory successfully allocated using calloc.\n");

        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }

        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
    }

    return 0;
}
*/
