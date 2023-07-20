/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 12:43:11 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/09 14:38:14 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	check_for_xyrc(int x, int y, int r, int c)
{	
	char	bslash;

	if (r == 1 || r == y || c == 1 || c == x)
	{
		bslash = '\\';
		if (r == 1 && c == 1)
			ft_putchar('/');
		else if (r == 1 && c == x)
			ft_putchar(bslash);
		else if (r == y && c == 1)
			ft_putchar(bslash);
		else if (r == y && c == x)
			ft_putchar('/');
		else
			ft_putchar('*');
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
