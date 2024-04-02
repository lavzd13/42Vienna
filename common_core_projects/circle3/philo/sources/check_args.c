/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:10:54 by jlomic            #+#    #+#             */
/*   Updated: 2024/03/25 14:14:22 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_args(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == -1)
			return (1);
		i++;
	}
	if (ft_atoi(argv[1]) > 250)
		return (printf("Error: philos are limited to 250.\n"), 1);
	return (0);
}
