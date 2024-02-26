/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 00:26:29 by jlomic            #+#    #+#             */
/*   Updated: 2024/02/26 14:47:34 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	iritating(t_philo *philo)
{
	if (philo->time_to_eat <= philo->time_to_sleep)
		usleep(1000 * (philo->time_to_sleep - philo->time_to_eat) + 500);
	else
		usleep(1000 * (philo->time_to_eat - philo->time_to_sleep) + 500);
}

void	init_fail(pthread_mutex_t *forks, int failed)
{
	int	i;

	i = 0;
	while (i < failed)
		pthread_mutex_destroy(&forks[i++]);
}

void	creation_failed(t_main *main, pthread_mutex_t *forks, int failed)
{
	int	i;

	i = 0;
	while (i < failed)
		pthread_join(main->philo[i++].thread, NULL);
	i = 0;
	while (i < main->philo->num_of_philos)
		pthread_mutex_destroy(&forks[i++]);
}

void	oddpickup(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->r_fork);
}

void	putdown(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
}
