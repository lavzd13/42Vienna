/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spriteutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomke <lomke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:22:37 by lomke             #+#    #+#             */
/*   Updated: 2023/12/08 20:53:38 by lomke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <mlx.h>

void	check_which_failed(t_spritedata *s, t_handlerdata *h)
{
	if (s->z.img)
		mlx_destroy_image(h->mlx->mlx, s->z.img);
	if (s->o.img)
		mlx_destroy_image(h->mlx->mlx, s->o.img);
	if (s->tw.img)
		mlx_destroy_image(h->mlx->mlx, s->tw.img);
	if (s->th.img)
		mlx_destroy_image(h->mlx->mlx, s->th.img);
	if (s->fo.img)
		mlx_destroy_image(h->mlx->mlx, s->fo.img);
	if (s->fi.img)
		mlx_destroy_image(h->mlx->mlx, s->fi.img);
	if (s->si.img)
		mlx_destroy_image(h->mlx->mlx, s->si.img);
	if (s->se.img)
		mlx_destroy_image(h->mlx->mlx, s->se.img);
	if (s->e.img)
		mlx_destroy_image(h->mlx->mlx, s->e.img);
	if (s->n.img)
		mlx_destroy_image(h->mlx->mlx, s->n.img);
	if (s->te.img)
		mlx_destroy_image(h->mlx->mlx, s->te.img);
}

void	check_simage(t_spritedata *s, t_handlerdata *h)
{
	if (!(s->z.img) || !(s->o.img) || !(s->tw.img)
		|| !(s->th.img) || !(s->fo.img) || !(s->fi.img)
		|| !(s->si.img) || !(s->se.img) || !(s->e.img)
		|| !(s->n.img) || !(s->te.img))
	{
		check_which_failed(s, h);
		mlx_destroy_window(h->mlx->mlx, h->mlx->win);
		mlx_destroy_display(h->mlx->mlx);
		free(h->mlx->mlx);
		puterror("Error\nFailed to load sprite images.\n");
	}
	else
		return ;
}

void	putframe(t_handlerdata *h, void *img, int x, int y)
{
	mlx_put_image_to_window(h->mlx->mlx, h->mlx->win, img, x, y);
}

void	reset(t_handlerdata *h, t_spritedata *s, int x, int y)
{
	mlx_put_image_to_window(h->mlx->mlx, h->mlx->win, s->h.img, x, y);
	mlx_put_image_to_window(h->mlx->mlx, h->mlx->win, s->v.img, x + 25, y + 25);
}
