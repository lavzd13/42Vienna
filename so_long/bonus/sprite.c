/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomke <lomke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:02:52 by lomke             #+#    #+#             */
/*   Updated: 2023/12/08 21:21:43 by lomke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	clear_simages(t_spritedata *s, t_handlerdata *h)
{
	mlx_destroy_image(h->mlx->mlx, s->z.img);
	mlx_destroy_image(h->mlx->mlx, s->o.img);
	mlx_destroy_image(h->mlx->mlx, s->tw.img);
	mlx_destroy_image(h->mlx->mlx, s->th.img);
	mlx_destroy_image(h->mlx->mlx, s->fo.img);
	mlx_destroy_image(h->mlx->mlx, s->fi.img);
	mlx_destroy_image(h->mlx->mlx, s->si.img);
	mlx_destroy_image(h->mlx->mlx, s->se.img);
	mlx_destroy_image(h->mlx->mlx, s->e.img);
	mlx_destroy_image(h->mlx->mlx, s->n.img);
	mlx_destroy_image(h->mlx->mlx, s->te.img);
}

void	putting_frames(t_handlerdata *h, t_spritedata *s, int x, int y)
{
	(putframe(h, s->z.img, x + 15, y + 20), usleep(150000));
	reset(h, s, x, y);
	(putframe(h, s->o.img, x + 26, y + 26), usleep(100000));
	reset(h, s, x, y);
	(putframe(h, s->tw.img, x + 23, y + 23), usleep(100000));
	reset(h, s, x, y);
	(putframe(h, s->th.img, x + 21, y + 21), usleep(100000));
	reset(h, s, x, y);
	(putframe(h, s->fo.img, x + 20, y + 20), usleep(100000));
	reset(h, s, x, y);
	(putframe(h, s->fi.img, x + 18, y + 18), usleep(100000));
	reset(h, s, x, y);
	(putframe(h, s->si.img, x + 18, y + 18), usleep(100000));
	reset(h, s, x, y);
	(putframe(h, s->se.img, x + 18, y + 18), usleep(100000));
	reset(h, s, x, y);
	(putframe(h, s->e.img, x + 18, y + 18), usleep(100000));
	reset(h, s, x, y);
	(putframe(h, s->n.img, x + 18, y + 18), usleep(100000));
	reset(h, s, x, y);
	(putframe(h, s->te.img, x + 18, y + 18), usleep(100000));
	reset(h, s, x, y);
}

void	make_animation(t_handlerdata *h, t_spritedata *s, int r, int c)
{
	int	x;
	int	y;

	x = c * 60;
	y = r * 60;
	s->h.path = "textures/hill60.xpm";
	s->v.path = "textures/grenade.xpm";
	s->h.img = mlx_xpm_file_to_image(h->mlx->mlx, s->h.path, &s->h.w, &s->h.h);
	s->v.img = mlx_xpm_file_to_image(h->mlx->mlx, s->v.path, &s->v.w, &s->v.h);
	if (!(s->h.img) || !(s->v.img))
	{
		if (s->h.img)
			mlx_destroy_image(h->mlx->mlx, s->h.img);
		if (s->v.img)
			mlx_destroy_image(h->mlx->mlx, s->v.img);
		clear_simages(s, h);
		mlx_destroy_window(h->mlx->mlx, h->mlx->win);
		mlx_destroy_display(h->mlx->mlx);
		free(h->mlx->mlx);
		puterror("Error\nFailed to load sprite images.\n");
	}
	putting_frames(h, s, x, y);
	mlx_destroy_image(h->mlx->mlx, s->h.img);
	mlx_destroy_image(h->mlx->mlx, s->v.img);
}

void	make_sprite(t_handlerdata *h, int r, int c)
{
	t_spritedata	s;

	s.z.path = "textures/explosion_sprite/exp0.xpm";
	s.o.path = "textures/explosion_sprite/exp1.xpm";
	s.tw.path = "textures/explosion_sprite/exp2.xpm";
	s.th.path = "textures/explosion_sprite/exp3.xpm";
	s.fo.path = "textures/explosion_sprite/exp4.xpm";
	s.fi.path = "textures/explosion_sprite/exp5.xpm";
	s.si.path = "textures/explosion_sprite/exp6.xpm";
	s.se.path = "textures/explosion_sprite/exp7.xpm";
	s.e.path = "textures/explosion_sprite/exp8.xpm";
	s.n.path = "textures/explosion_sprite/exp9.xpm";
	s.te.path = "textures/explosion_sprite/exp10.xpm";
	s.z.img = mlx_xpm_file_to_image(h->mlx->mlx, s.z.path, &s.z.w, &s.z.h);
	s.o.img = mlx_xpm_file_to_image(h->mlx->mlx, s.o.path, &s.o.w, &s.o.h);
	s.tw.img = mlx_xpm_file_to_image(h->mlx->mlx, s.tw.path, &s.tw.w, &s.tw.h);
	s.th.img = mlx_xpm_file_to_image(h->mlx->mlx, s.th.path, &s.th.w, &s.th.h);
	s.fo.img = mlx_xpm_file_to_image(h->mlx->mlx, s.fo.path, &s.fo.w, &s.fo.h);
	s.fi.img = mlx_xpm_file_to_image(h->mlx->mlx, s.fi.path, &s.fi.w, &s.fi.h);
	s.si.img = mlx_xpm_file_to_image(h->mlx->mlx, s.si.path, &s.si.w, &s.si.h);
	s.se.img = mlx_xpm_file_to_image(h->mlx->mlx, s.se.path, &s.se.w, &s.se.h);
	s.e.img = mlx_xpm_file_to_image(h->mlx->mlx, s.e.path, &s.e.w, &s.e.h);
	s.n.img = mlx_xpm_file_to_image(h->mlx->mlx, s.n.path, &s.n.w, &s.n.h);
	s.te.img = mlx_xpm_file_to_image(h->mlx->mlx, s.te.path, &s.te.w, &s.te.h);
	(check_simage(&s, h), make_animation(h, &s, r, c), clear_simages(&s, h));
}

void	win_sprite(t_handlerdata *h)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < h->map->rows)
	{
		col = 0;
		while (col < h->map->cols)
		{
			if (h->map->map[row][col] == 'C')
			{
				make_sprite(h, row, col);
				usleep(300000);
			}
			col++;
		}
		row++;
	}
}
