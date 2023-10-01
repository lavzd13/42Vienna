/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:26:25 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/01 13:23:52 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_joinfree(char *buff, char *temp)
{
	char	*tmp;

	tmp = ft_strjoin(buff, temp);
	free(buff);
	return (tmp);
}

int	ft_bytecheck(ssize_t bytes, char *buffer, char *temp)
{
	if (bytes == -1)
	{
		free(buffer);
		free(temp);
		return (0);
	}
	else
		return (1);
}

char	*ft_new(char *buffer)
{
	int		i;
	char	*temp;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		++i;
	if (buffer[i] == '\n')
		i += 2;
	i++;
	temp = malloc(i * sizeof(char));
	if (!(smallcheck(temp, buffer)))
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		temp[i] = buffer[i];
		++i;
	}
	if (buffer[i] && buffer[i] == '\n')
		temp[i++] = '\n';
	temp[i] = '\0';
	return (temp);
}

char	*ft_read(char *buffer, int fd)
{
	char	*temp;
	ssize_t	bytesread;

	if (!buffer)
	{
		buffer = malloc(1);
		if (!buffer)
			return (NULL);
		*buffer = 0;
	}
	bytesread = 1;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	while (bytesread)
	{
		bytesread = read(fd, temp, BUFFER_SIZE);
		if (!(ft_bytecheck(bytesread, buffer, temp)))
			return (NULL);
		temp[bytesread] = '\0';
		buffer = ft_joinfree(buffer, temp);
		if (ft_strchr(temp, '\n'))
			break ;
	}
	free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(buffer, fd);
	if (buffer)
	{
		line = ft_new(buffer);
		buffer = ft_sisaj(buffer);
		return (line);
	}
	else
		return (NULL);
}

#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int		fd = open("test.txt", O_RDWR);
	int		i = 0;
	char	*tmp;

	while (i < 1)
	{
		tmp = get_next_line(fd);
		printf("%s", tmp);
		free(tmp);
		i++;
	}
	close(fd);
}
