/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playutils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomke <lomke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 22:05:42 by lomke             #+#    #+#             */
/*   Updated: 2023/12/07 16:29:27 by lomke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
