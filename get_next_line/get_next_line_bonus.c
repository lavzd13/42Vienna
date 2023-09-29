/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:24:05 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/28 12:05:09 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	buffer[fd] = ft_read(buffer[fd], fd);
	if (buffer[fd])
	{
		line = ft_new(buffer[fd]);
		buffer[fd] = ft_sisaj(buffer[fd]);
		return (line);
	}
	else
		return (NULL);
}

/* #include <stdio.h>
#include <fcntl.h>
int	main()
{
	char *temp;
	char *temp2;
	char *temp3;
	char *temp4;
	int	i = 1;
	int fd = open("test.txt", O_RDWR);
	int fd1 = open("test2.txt", O_RDWR);
	int fd2 = open("test3.txt", O_RDWR);
	int fd3 = open("test4.txt", O_RDWR);
	printf("FD: %d\nFD1: %d\nFD2: %d\nFD3: %d\n", fd, fd1, fd2, fd3);
	while (i <= 10)
	{
		temp = get_next_line(fd);
		temp2 = get_next_line(fd1);
		temp3 = get_next_line(fd2);
		temp4 = get_next_line(fd3);
		printf("FD: %sFD1: %sFD2: %sFD3: %s", temp, temp2, temp3, temp4);
		free(temp);
		free(temp2);
		free(temp3);
		free(temp4);
		i++;
	}
} */
