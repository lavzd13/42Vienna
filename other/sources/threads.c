/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomke <lomke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:14:37 by lomke             #+#    #+#             */
/*   Updated: 2024/02/19 00:23:40 by lomke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	dead_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

int	create_threads(t_main *main, pthread_mutex_t *forks)
{
	pthread_t	monitor;
	int			i;


	if (pthread_create(&monitor, NULL, &monitoring, main->philos) != 0)
		clean_all("Failed to create thread.\n", main, forks);
	i = 0;
	while (i < main->philos->num_of_philos)
	{
		if (pthread_create(&main->philos[i].thread, NULL, &philo_routine, &main->philos[i]) != 0)
			clean_all("Failed to create thread.\n", main, forks);
		i++;
	}
	i = 0;
	if (pthread_join(monitor, NULL) != 0)
		clean_all("Failed to join thread.\n", main, forks);
	while (i < main->philos[0].num_of_philos)
	{
		if (pthread_join(main->philos[i].thread, NULL) != 0)
			clean_all("Failed to join thread.\n", main, forks);
		i++;
	}
	return (0);
}
