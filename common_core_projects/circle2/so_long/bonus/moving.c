/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomke <lomke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:31:39 by lomke             #+#    #+#             */
/*   Updated: 2023/12/08 21:22:44 by lomke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long_bonus.h"
#include <mlx.h>
#include <stdio.h>
#include <unistd.h>

int	movekeys(int keysum, t_handlerdata *h)
{
	if (keysum == 65361 || keysum == 97)
		update(keysum, h);
	else if (keysum == 65362 || keysum == 119)
		update(keysum, h);
	else if (keysum == 65363 || keysum == 100)
		update(keysum, h);
	else if (keysum == 65364 || keysum == 115)
		update(keysum, h);
	return (0);
}

void	win_or_lose(t_handlerdata *h, int nr, int nc)
{
	if (h->map->collectible == 0 && h->map->map[nr][nc] == 'E')
	{
		ft_putstr_fd("YOU WON!\n", 1);
		mlx_destroy_window(h->mlx->mlx, h->mlx->win);
		mlx_destroy_display(h->mlx->mlx);
		free(h->mlx->mlx);
		exit(0);
	}
	if (h->map->map[nr][nc] == 'X')
	{
		ft_putstr_fd("YOU LOSE!\n", 1);
		mlx_destroy_window(h->mlx->mlx, h->mlx->win);
		mlx_destroy_display(h->mlx->mlx);
		free(h->mlx->mlx);
		exit(0);
	}
}

void	update(int keysum, t_handlerdata *h)
{
	int	nr;
	int	nc;

	nr = h->map->start_pos[0];
	nc = h->map->start_pos[1];
	if (keysum == 65361 || keysum == 97)
		nc = h->map->start_pos[1] - 1;
	else if (keysum == 65362 || keysum == 119)
		nr = h->map->start_pos[0] - 1;
	else if (keysum == 65363 || keysum == 100)
		nc = h->map->start_pos[1] + 1;
	else if (keysum == 65364 || keysum == 115)
		nr = h->map->start_pos[0] + 1;
	win_or_lose(h, nr, nc);
	if (h->map->map[nr][nc] != '1' && nr < h->map->rows && nr >= 0
		&& nc >= 0 && nc < h->map->cols && h->map->map[nr][nc] != 'E')
	{
		if (h->map->map[nr][nc] == 'C')
			(h->map->collectible)--;
		h->map->map[h->map->start_pos[0]][h->map->start_pos[1]] = '0';
		h->map->map[nr][nc] = 'P';
		(h->mlx->moves)++;
	}
	make(h->map, h->mlx, keysum);
}
