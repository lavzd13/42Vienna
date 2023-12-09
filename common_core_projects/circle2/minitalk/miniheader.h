/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniheader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:38:54 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/09 19:23:30 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIHEADER_H
# define MINIHEADER_H

# define _GNU_SOURCE
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

int		**checknull(int **ptr, char *str);
int		ft_strcmp(char *s1, char *s2);
void	checker(int pid, int **ptr);
void	ft_free(int **ptr);
int		bitcheck(int **p, int **ptr);

#endif
