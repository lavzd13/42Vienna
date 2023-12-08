/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playutils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomke <lomke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 22:05:42 by lomke             #+#    #+#             */
/*   Updated: 2023/12/08 19:36:39 by lomke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long_bonus.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

void	putexit(t_mlxdata *m, t_images *t, t_cor *c)
{
	mlx_put_image_to_window(m->mlx, m->win, t->h.img, c->x, c->y);
	c->x += t->t.w;
}

void	putcollectible(t_mlxdata *m, t_images *t, t_cor *c)
{
	mlx_put_image_to_window(m->mlx, m->win, t->t.img, c->x, c->y);
	mlx_put_image_to_window(m->mlx, m->win, t->c.img, c->x + 25, c->y + 25);
	c->x += t->t.w;
}

void	putenemy(t_mlxdata *m, t_images *t, t_cor *c)
{
	mlx_put_image_to_window(m->mlx, m->win, t->t.img, c->x, c->y);
	mlx_put_image_to_window(m->mlx, m->win, t->e.img, c->x + 10, c->y + 10);
	c->x += t->t.w;
}

void	display_moves(t_mlxdata *m)
{
	char	*moves;

	moves = ft_itoa(m->moves);
	mlx_string_put(m->mlx, m->win, 10, 15, 0xFF00FF, "MOVES: ");
	mlx_string_put(m->mlx, m->win, 50, 15, 0xFF00FF, moves);
	free(moves);
}
