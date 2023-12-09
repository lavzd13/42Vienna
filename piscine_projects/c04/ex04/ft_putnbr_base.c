/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:05:38 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/18 12:31:45 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	my_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	put_char(char c)
{
	write(1, &c, 1);
}

int	ft_check(int baz, char *bas)
{
	int	i;
	int	j;

	i = 0;
	if (bas[0] == '\0' || baz == 1)
		return (0);
	while (bas[i] != '\0')
	{
		if (bas[i] <= 32 || bas[i] == 127 || bas[i] == 43 || bas[i] == 45)
			return (0);
		j = i + 1;
		while (j < baz)
		{
			if (bas[i] == bas[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	a;
	int		baza;
	int		provera;

	a = nbr;
	baza = my_strlen(base);
	provera = ft_check(baza, base);
	if (provera == 1)
	{
		if (a < 0)
		{
			put_char('-');
			a *= -1;
		}
		if ((a / baza) != 0)
		{
			ft_putnbr_base((a / baza), base);
			ft_putnbr_base((a % baza), base);
		}
		else
			put_char(base[a % baza]);
	}
}

#include<stdio.h>
int main()
{
	ft_putnbr_base(-2147483648, "0123456789");printf("\n");
	ft_putnbr_base(-2147483648, "01234567");printf("\n");
	ft_putnbr_base(-2147483648, "0123456789ABCDEF");printf("\n");
	ft_putnbr_base(2147483647, "01");printf("\n");
	ft_putnbr_base(-2147483648, "poneyvif");printf("\n");
}

