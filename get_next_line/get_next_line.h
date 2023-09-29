/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:10:38 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/26 11:59:08 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

/* typedef struct s_line
{
	char			tempstr;
	struct s_line	*next_line;
}	t_line; */

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_sisaj(char *buffer);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
int		smallcheck(char *temp, char *buffer);

#endif
