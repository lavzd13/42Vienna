/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomke <lomke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:35:58 by lomke             #+#    #+#             */
/*   Updated: 2023/12/07 17:49:28 by lomke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	puterror(char *message)
{
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	char	buffer[1000];
	char	*map;
	int		fd;
	ssize_t	bytesread;

	if (argc != 2)
		puterror("Error\nUsage ./so_long <path to map>\n");
	map = argv[1];
	checksuffix(map);
	fd = open(map, O_RDWR);
	if (fd < 0)
		puterror("Error\nFailed to open map.\n");
	bytesread = read(fd, buffer, sizeof(buffer));
	if (bytesread == -1)
		puterror("Error\nFailed to read map.\n");
	if (bytesread > 600)
		puterror("Error\nMap is too big.\n");
	buffer[bytesread] = '\0';
	check_invalid_chars(buffer);
	check_shapenwalls(buffer);
	check_valid_path(buffer);
	play(buffer);
}
