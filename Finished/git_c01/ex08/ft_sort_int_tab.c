/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:51:25 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/10 19:40:27 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	while (size >= 0)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab [i + 1];
				tab [i + 1] = temp;
			}
			i++;
		}
		size--;
	}
}

/*
#include<stdio.h>

int main(void)
{
	int arr[] = {6, 3, 6, 9, 2, 1, 4, 8};
	int size = sizeof(arr) / sizeof(arr[0]);

	for (int j = 0; j < size; j++)
        printf("%d", arr[j]);

	printf("\n");

	ft_sort_int_tab(arr, size);

	for (int k = 0; k < size; k++)
        printf("%d", arr[k]);

}
*/
