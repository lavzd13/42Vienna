/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:48:55 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/13 10:29:02 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	put_char1(unsigned char c)
{
	write(1, &c, 1);
}

void	put_char2(unsigned char a)
{
	write(1, &a, 1);
}
void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
		{
			write(1, &str[i], 1);
		}
		else
		{
			write(1, "\\", 1);
			put_char1("0123456789abcdef"[str[i] / 16]);
			put_char2("0123456789abcdef"[str[i] % 16]);
		}
		i++;
	}
}

