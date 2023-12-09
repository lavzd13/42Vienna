/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomke <lomke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:35:31 by lomke             #+#    #+#             */
/*   Updated: 2023/12/07 17:55:18 by lomke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	final_check(t_check_map *checkmap)
{
	if (checkmap->exit != 1 || checkmap->player != 1)
	{
		if (checkmap->player != 1 && checkmap->exit == 1)
			puterror("Error\nMap have multiple players.\n");
		else if (checkmap->player == 1 && checkmap->exit != 1)
			puterror("Error\nMap have multiple exits.\n");
		else if (checkmap->player == 1 && checkmap->exit == 0)
			puterror("Error\nMap is missing exit.\n");
		else if (checkmap->player == 0 && checkmap->exit == 1)
			puterror("Error\nMap is missing player.\n");
		else if (checkmap->player == 0 && checkmap->exit == 0)
			puterror("Error\nMap is missing player and exit.\n");
		else
			puterror("Error\nMap have multiple exits and players.\n");
	}
	if (checkmap->collectible <= 0)
		puterror("Error\nMap does not contain any collectible.\n");
}

void	checksuffix(char *map)
{
	int		i;
	int		j;
	char	*suffix;

	i = 0;
	j = 0;
	suffix = "ber";
	while (map[i] != '.')
		i++;
	i++;
	while (map[i + j])
	{
		if (map[i + j] != suffix[j])
			puterror("Error\nInvalid type of map\n");
		j++;
	}
}

int	check_for_valid(char c)
{
	int		i;
	int		valid;
	char	*valid_chars;

	valid_chars = "10PCEX\n";
	i = 0;
	valid = 0;
	while (valid_chars[i])
	{
		if (valid_chars[i] == c)
			valid = 1;
		i++;
	}
	if (valid)
		return (1);
	else
		return (0);
}

void	check_invalid_chars(char *buffer)
{
	t_check_map	checkmap;
	int			i;

	i = 0;
	ft_memset(&checkmap, 0, sizeof(checkmap));
	while (buffer[i] != '\0')
	{
		if (buffer[i] == 'E')
			(checkmap.exit)++;
		else if (buffer[i] == 'P')
			(checkmap.player)++;
		else if (buffer[i] == 'C')
			(checkmap.collectible)++;
		if (check_for_valid(buffer[i]) == 0)
			puterror("Error\nMap contain invalid characters.\n");
		i++;
	}
	final_check(&checkmap);
}
