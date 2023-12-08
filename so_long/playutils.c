/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomke <lomke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 23:37:06 by lomke             #+#    #+#             */
/*   Updated: 2023/12/03 02:38:35 by lomke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	make_window(t_mlxdata *mlx, char *buffer)
{
	int	i;
	int	rows;
	int	cols;

	i = 0;
	rows = 0;
	cols = 0;
	while (buffer[i++] != '\n')
		cols++;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			rows++;
		i++;
	}
	mlx->win = mlx_new_window(mlx->mlx, cols * 60, rows * 60, "so_long");
	if (!mlx->win)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		puterror("Error\nFailed to create a window.\n");
	}
}

int	esckey(int keysum, t_mlxdata *data)
{
	if (keysum == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
	return (0);
}

void	check_images(t_images *t, t_mlxdata *mlx)
{
	if (!(t->b.img) || !(t->t.img) || !(t->r.img) || !(t->c.img) || !(t->h.img))
	{
		if (t->b.img)
			mlx_destroy_image(mlx->mlx, t->b.img);
		if (t->t.img)
			mlx_destroy_image(mlx->mlx, t->t.img);
		if (t->r.img)
			mlx_destroy_image(mlx->mlx, t->r.img);
		if (t->c.img)
			mlx_destroy_image(mlx->mlx, t->c.img);
		if (t->h.img)
			mlx_destroy_image(mlx->mlx, t->h.img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		puterror("Error\nFailed to create image. Check path.\n");
	}
	else
		return ;
}

void	read_and_put(t_mapdata *map, t_images *t, t_mlxdata *m)
{
	int		rows;
	int		cols;
	t_cor	cor;

	rows = 0;
	ft_memset(&cor, 0, sizeof(cor));
	while (rows < (map->rows))
	{
		cols = 0;
		cor.x = 0;
		while (cols < (map->cols + 1))
		{
			put(m, t, &cor, map->map[rows][cols]);
			if (map->map[rows][cols] == 'P')
			{
				map->start_pos[0] = rows;
				map->start_pos[1] = cols;
			}
			cols++;
		}
		rows++;
	}
}

void	makemap(t_mapdata *mapdata, char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		mapdata->cols = 0;
		while (buffer[i] != '\n')
		{
			mapdata->map[mapdata->rows][(mapdata->cols)++] = buffer[i++];
			if (buffer[i] == 'C')
				(mapdata->collectible)++;
		}
		mapdata->map[(mapdata->rows)++][mapdata->cols] = '\n';
		i++;
	}
}
