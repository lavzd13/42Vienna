/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomke <lomke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:30:24 by lomke             #+#    #+#             */
/*   Updated: 2023/12/20 15:17:31 by lomke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long_bonus.h"
#include <X11/X.h>
#include <mlx.h>
#include <stdio.h>

void	clear_images(t_mlxdata *mlx, t_images *t)
{
	mlx_destroy_image(mlx->mlx, t->b.img);
	mlx_destroy_image(mlx->mlx, t->t.img);
	mlx_destroy_image(mlx->mlx, t->r.img);
	mlx_destroy_image(mlx->mlx, t->c.img);
	mlx_destroy_image(mlx->mlx, t->h.img);
	mlx_destroy_image(mlx->mlx, t->e.img);
}

int	on_destroy(t_mlxdata *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

void	put(t_mlxdata *m, t_images *t, t_cor *c, char buffer)
{
	display_moves(m);
	if (buffer == '1')
	{
		mlx_put_image_to_window(m->mlx, m->win, t->b.img, c->x, c->y);
		c->x += t->b.w;
	}
	else if (buffer == '\n')
		c->y += t->b.h;
	else if (buffer == 'E')
		putexit(m, t, c);
	else if (buffer == 'C')
		putcollectible(m, t, c);
	else if (buffer == 'X')
		putenemy(m, t, c);
	else if (buffer == 'P')
	{
		mlx_put_image_to_window(m->mlx, m->win, t->t.img, c->x, c->y);
		mlx_put_image_to_window(m->mlx, m->win, t->r.img, c->x + 10, c->y + 10);
		c->x += t->t.w;
	}
	else
	{
		mlx_put_image_to_window(m->mlx, m->win, t->t.img, c->x, c->y);
		c->x += t->t.w;
	}
}

void	make(t_mapdata *map, t_mlxdata *mlx, int keysum)
{
	t_images	t;
	static char	key;

	if (keysum == 65361 || keysum == 97)
		key = 'L';
	else if (keysum == 65363 || keysum == 0 || keysum == 100)
		key = 'R';
	t.b.path = "textures/water60.xpm";
	t.t.path = "textures/hill60.xpm";
	t.r.path = "textures/rambo.xpm";
	t.a.path = "textures/ramboaround.xpm";
	t.c.path = "textures/grenade.xpm";
	t.h.path = "textures/heli.xpm";
	t.e.path = "textures/vietnam.xpm";
	t.b.img = mlx_xpm_file_to_image(mlx->mlx, t.b.path, &t.b.w, &t.b.h);
	t.t.img = mlx_xpm_file_to_image(mlx->mlx, t.t.path, &t.t.w, &t.t.h);
	if (key == 'L')
		t.r.img = mlx_xpm_file_to_image(mlx->mlx, t.a.path, &t.a.w, &t.a.h);
	else if (key == 'R' || key == 0)
		t.r.img = mlx_xpm_file_to_image(mlx->mlx, t.r.path, &t.r.w, &t.r.h);
	t.c.img = mlx_xpm_file_to_image(mlx->mlx, t.c.path, &t.c.w, &t.c.h);
	t.h.img = mlx_xpm_file_to_image(mlx->mlx, t.h.path, &t.h.w, &t.h.h);
	t.e.img = mlx_xpm_file_to_image(mlx->mlx, t.e.path, &t.e.w, &t.e.h);
	(check_images(&t, mlx), read_and_put(map, &t, mlx), clear_images(mlx, &t));
}

void	play(char *buffer)
{
	t_mlxdata		mlx;
	t_mapdata		mapdata;
	t_handlerdata	handler;

	ft_memset(&mlx, 0, sizeof(mlx));
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		puterror("Error\nFailed to initialize mlx\n");
	make_window(&mlx, buffer);
	ft_memset(&mapdata, 0, sizeof(mapdata));
	makemap(&mapdata, buffer);
	ft_memset(&handler, 0, sizeof(handler));
	handler.map = &mapdata;
	handler.mlx = &mlx;
	handler.animation = 1;
	while (1)
	{
		win_sprite(&handler);
		make(&mapdata, &mlx, 0);
		mlx_hook(mlx.win, 17, (1L << 17), &on_destroy, &mlx);
		mlx_hook(mlx.win, KeyRelease, KeyReleaseMask, esckey, &mlx);
		mlx_hook(mlx.win, KeyPress, KeyPressMask, &movekeys, &handler);
		mlx_loop(mlx.mlx);
	}
}
