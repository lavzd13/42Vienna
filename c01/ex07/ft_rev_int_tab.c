/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:18:13 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/10 19:37:50 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	p;
	int	k;
	int	temp;

	p = 0;
	k = size - 1;
	while (p < k)
	{
		temp = tab[p];
		tab[p] = tab[k];
		tab[k] = temp;
		p++;
		k--;
	}
}
/*

#include<stdio.h>

int main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	int size = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < size; i++)
		printf("%d", arr[i]);

	printf("\n");

	ft_rev_int_tab(arr, size);

	for (int i = 0; i < size; i++)
        printf("%d", arr[i]);

}
*/
