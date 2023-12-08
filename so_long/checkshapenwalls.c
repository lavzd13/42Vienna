/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkshapenwalls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomke <lomke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:04:16 by lomce             #+#    #+#             */
/*   Updated: 2023/11/19 00:26:23 by lomke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(t_mapdata *mapdata)
{
	int	i;

	i = 0;
	while (mapdata->map[0][i] != '\n'
		&& mapdata->map[mapdata->rows - 1][i] != '\0')
	{
		if (mapdata->map[0][i] != '1'
			|| mapdata->map[mapdata->rows - 1][i] != '1')
			puterror("Error\nMap not surronded by walls.\n");
		i++;
	}
	i = 0;
	while (i < (mapdata->rows - 1))
	{
		if (mapdata->map[i][0] != '1'
			|| mapdata->map[i][mapdata->cols - 1] != '1')
			puterror("Error\nMap not surronded by walls.\n");
		i++;
	}
}

void	check_shapenwalls(char *buffer)
{
	t_mapdata	mapdata;
	int			i;
	int			c;

	i = 0;
	ft_memset(&mapdata, 0, sizeof(mapdata));
	while (buffer[i])
	{
		c = 0;
		while (buffer[i] != '\n')
			mapdata.map[mapdata.rows][c++] = buffer[i++];
		if (!(mapdata.first_row))
		{
			mapdata.cols = c;
			mapdata.first_row = 1;
		}
		else
			if (mapdata.cols != c)
				puterror("Error\nMap is not in the right form.\n");
		mapdata.map[(mapdata.rows)++][c] = '\n';
		i++;
	}
	mapdata.map[mapdata.rows][c] = '\0';
	check_walls(&mapdata);
}
