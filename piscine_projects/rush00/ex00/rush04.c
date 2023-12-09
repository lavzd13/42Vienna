/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:55 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/09 13:53:00 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	check_for_xyrc(int x, int y, int r, int c)
{
	if (r == 1 || r == y || c == 1 || c == x)
	{
		if (r == 1 && c == 1)
			ft_putchar('A');
		else if (r == 1 && c == x)
			ft_putchar('C');
		else if (r == y && c == 1)
			ft_putchar('C');
		else if (r == y && c == x)
			ft_putchar('A');
		else
			ft_putchar('B');
	}
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	r;
	int	c;

	if (x < 1 || y < 1)
		return ;
	r = 1;
	while (r <= y)
	{	
		c = 1;
		while (c <= x)
		{
			check_for_xyrc(x, y, r, c);
			c++;
		}
		ft_putchar('\n');
		r++;
	}
}
