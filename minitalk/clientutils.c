/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:48:53 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/09 19:24:36 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

int	**checknull(int **ptr, char *str)
{
	int	byte;
	int	i;
	int	bit;

	byte = 0;
	if (str[byte] == '\0')
	{
		ptr[byte] = ft_calloc(8, sizeof(int));
		if (!ptr[byte])
			return (0);
		i = 7;
		bit = 0;
		while (i >= 0)
		{
			ptr[byte][bit++] = (str[byte] >> i) & 1;
			i--;
		}
		byte++;
	}
	ptr[byte] = 0;
	return (ptr);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	checker(int pid, int **ptr)
{
	if (kill(pid, 0) < 0)
	{
		ft_printf("Can't contact the server, exiting...\n");
		ft_free(ptr);
		exit(EXIT_FAILURE);
	}
}

void	ft_free(int **ptr)
{
	int	byte;

	byte = 0;
	while (ptr[byte])
	{
		free(ptr[byte]);
		byte++;
	}
	free(ptr);
}

int	bitcheck(int **p, int **ptr)
{
	int	byte;

	byte = 0;
	if (!p[byte])
	{
		ft_free(ptr);
		return (0);
	}
	return (1);
}
