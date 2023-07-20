/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:56:56 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/08 13:17:01 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			put_char (a / 10 + '0');
			put_char (a % 10 + '0');
			put_char (' ');
			put_char (b / 10 + '0');
			put_char (b % 10 + '0');
			b++;
			if (a != 98)
			{
				write(1, ", ", 2);
			}
		}
		a++;
	}
}
