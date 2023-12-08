/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomke <lomke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:41:34 by lomke             #+#    #+#             */
/*   Updated: 2023/12/07 17:57:28 by lomke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long_bonus.h"
#include <stdio.h>

void	find_path(t_mapdata *mapdata, int row, int col)
{
	if (row < 0 || row >= mapdata->rows || col < 0 || col >= mapdata->cols
		|| mapdata->map[row][col] == '1' || mapdata->map[row][col] == 'V'
		|| mapdata->map[row][col] == 'X')
		return ;
	if (mapdata->map[row][col] == 'C' || mapdata->map[row][col] == 'E')
	{
		if (mapdata->map[row][col] == 'C')
			(mapdata->collectible)--;
		else
			(mapdata->exit)--;
		mapdata->map[row][col] = 'V';
		find_path(mapdata, row - 1, col);
		find_path(mapdata, row + 1, col);
		find_path(mapdata, row, col - 1);
		find_path(mapdata, row, col + 1);
		if (mapdata->collectible == 0 || mapdata->exit == 0)
			return ;
	}
	else if (mapdata->map[row][col] == '0' || mapdata->map[row][col] == 'P')
	{
		mapdata->map[row][col] = 'V';
		(find_path(mapdata, row - 1, col), find_path(mapdata, row + 1, col));
		(find_path(mapdata, row, col - 1), find_path(mapdata, row, col + 1));
	}
}

void	find_start_pos(t_mapdata *mapdata)
{
	int	r;
	int	c;

	r = 0;
	while (r < (mapdata->rows - 1))
	{
		c = 0;
		while (c < (mapdata->cols - 1))
		{
			if (mapdata->map[r][c] == 'P')
			{
				mapdata->start_pos[0] = r;
				mapdata->start_pos[1] = c;
			}
			if (mapdata->map[r][c] == 'E')
				(mapdata->exit)++;
			if (mapdata->map[r][c] == 'C')
				(mapdata->collectible)++;
			c++;
		}
		r++;
	}
	find_path(mapdata, mapdata->start_pos[0], mapdata->start_pos[1]);
	if (mapdata->collectible != 0 || mapdata->exit != 0)
		puterror("Error\nCan't find the valid path.\n");
}

void	check_valid_path(char *buffer)
{
	t_mapdata	mapdata;
	int			i;

	i = 0;
	ft_memset(&mapdata, 0, sizeof(mapdata));
	while (buffer[i])
	{
		mapdata.cols = 0;
		while (buffer[i] != '\n')
			mapdata.map[mapdata.rows][(mapdata.cols)++] = buffer[i++];
		mapdata.map[(mapdata.rows)++][mapdata.cols] = '\n';
		i++;
	}
	mapdata.map[mapdata.rows][mapdata.cols] = '\0';
	if (mapdata.rows > 17 || mapdata.cols > 32)
		puterror("Error\nMap is too big.\n");
	find_start_pos(&mapdata);
}
