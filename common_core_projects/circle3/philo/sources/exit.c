/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:30:52 by jlomic            #+#    #+#             */
/*   Updated: 2024/03/25 14:16:29 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	clean_exit(t_args *args, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < args->num_of_philos)
		pthread_mutex_destroy(&forks[i++]);
	pthread_mutex_destroy(&args->d_lock);
	pthread_mutex_destroy(&args->w_lock);
	pthread_mutex_destroy(&args->e_lock);
}
