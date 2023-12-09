/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:15:20 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/19 15:19:43 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	k;

	k = 0;
	while (s1[k] != '\0' || s2[k] != '\0')
	{
		if (s1[k] == s2[k])
			k++;
		if (s1[k] > s2[k] || s1[k] < s2[k])
			return (s1[k] - s2[k]);
	}
	return (0);
}

void	ft_swap(char **c, char **d)
{
	char	*temp;

	temp = *c;
	*c = *d;
	*d = temp;
}

int	main(int argc, char **argv)
{
	int	j;
	int	i;

	i = 1;
	while (i < argc - 1)
	{
		j = 1;
		while (j < argc - 1)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				ft_swap(&argv[j], &argv[j + 1]);
			}
			j++;
		}
		i++;
	}
	j = 1;
	while (j < argc)
	{
		ft_str(argv[j]);
		ft_putchar('\n');
		j++;
	}
}
