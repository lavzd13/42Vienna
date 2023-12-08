/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomke <lomke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:15:40 by lomke             #+#    #+#             */
/*   Updated: 2023/12/08 20:20:56 by lomke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define MAX_ROWS 20
# define MAX_COLS 40

typedef struct s_mapdata
{
	char	map[MAX_ROWS][MAX_COLS];
	int		start_pos[2];
	int		exit;
	int		start;
	int		collectible;
	int		first_row;
	int		rows;
	int		cols;
}	t_mapdata;

typedef struct s_check_map
{
	int	exit;
	int	player;
	int	collectible;
}	t_check_map;

typedef struct s_mlxdata
{
	void	*mlx;
	void	*win;
	int		moves;
	int		won;
}	t_mlxdata;

typedef struct s_imagedata
{
	void	*img;
	char	*path;
	int		w;
	int		h;
}	t_imagedata;

typedef struct s_images
{
	t_imagedata	b;
	t_imagedata	t;
	t_imagedata	r;
	t_imagedata	a;
	t_imagedata	c;
	t_imagedata	h;
	t_imagedata	e;
}	t_images;

typedef struct s_cor
{
	int	x;
	int	y;
}	t_cor;

typedef struct s_handlerdata
{
	t_mlxdata	*mlx;
	t_mapdata	*map;
	int			keysum;
	int			moves;
	int			animation;
}	t_handlerdata;

typedef struct s_spritedata
{
	t_imagedata	h;
	t_imagedata	v;
	t_imagedata	z;
	t_imagedata	o;
	t_imagedata	tw;
	t_imagedata	th;
	t_imagedata	fo;
	t_imagedata	fi;
	t_imagedata	si;
	t_imagedata	se;
	t_imagedata	e;
	t_imagedata	n;
	t_imagedata	te;
}	t_spritedata;

void	puterror(char *message);
void	check_invalid_chars(char *buffer);
void	checksuffix(char *map);
void	check_valid_path(char *buffer);
void	check_shapenwalls(char *buffer);
void	play(char *buffer);
void	make_window(t_mlxdata *mlx, char *buffer);
int		esckey(int keysum, t_mlxdata *data);
void	check_images(t_images *t, t_mlxdata *mlx);
void	clear_images(t_mlxdata *mlx, t_images *t);
void	put(t_mlxdata *m, t_images *t, t_cor *c, char buffer);
void	read_and_put(t_mapdata *map, t_images *t, t_mlxdata *m);
void	makemap(t_mapdata *mapdata, char *buffer);
int		movekeys(int keysum, t_handlerdata *handler);
void	update(int keysum, t_handlerdata *handler);
void	make(t_mapdata *map, t_mlxdata *mlx, int keysum);
void	putexit(t_mlxdata *m, t_images *t, t_cor *c);
void	putcollectible(t_mlxdata *m, t_images *t, t_cor *c);
void	putenemy(t_mlxdata *m, t_images *t, t_cor *c);
void	printmoves(t_handlerdata *h);
void	display_moves(t_mlxdata *m);
void	win_sprite(t_handlerdata *h);
void	check_simage(t_spritedata *s, t_handlerdata *h);
void	putframe(t_handlerdata *h, void *img, int x, int y);
void	reset(t_handlerdata *h, t_spritedata *s, int x, int y);
void	win(t_handlerdata *h);
int		spritemove(t_handlerdata *h);

#endif
