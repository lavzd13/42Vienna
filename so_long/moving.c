/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomke <lomke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:31:39 by lomke             #+#    #+#             */
/*   Updated: 2023/12/04 20:37:42 by lomke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include <stdio.h>

void	printmoves(t_handlerdata *h)
{
	(h->moves)++;
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(h->moves, 1);
	ft_putchar_fd('\n', 1);
}

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

void	win(t_handlerdata *h)
{
	mlx_destroy_window(h->mlx->mlx, h->mlx->win);
	mlx_destroy_display(h->mlx->mlx);
	free(h->mlx->mlx);
	exit(0);
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
	if (h->map->collectible == 0 && h->map->map[nr][nc] == 'E')
		win(h);
	if (h->map->map[nr][nc] != '1' && nr < h->map->rows && nr >= 0
		&& nc >= 0 && nc < h->map->cols && h->map->map[nr][nc] != 'E')
	{
		if (h->map->map[nr][nc] == 'C')
			(h->map->collectible)--;
		h->map->map[h->map->start_pos[0]][h->map->start_pos[1]] = '0';
		h->map->map[nr][nc] = 'P';
		printmoves(h);
	}
	make(h->map, h->mlx, keysum);
}
