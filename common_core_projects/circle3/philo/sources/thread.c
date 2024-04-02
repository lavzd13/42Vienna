/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:20:34 by jlomic            #+#    #+#             */
/*   Updated: 2024/03/25 17:06:41 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	thread_failed(int i, t_philo *philo, t_args *args, \
					pthread_mutex_t *forks)
{
	int	c;

	c = 0;
	if (i != 0)
	{
		while (c < i)
		{
			pthread_join(philo[c].thread, NULL);
			c++;
		}
	}
	c = 0;
	while (c < args->num_of_philos)
		pthread_mutex_destroy(&forks[c++]);
	pthread_mutex_destroy(&args->e_lock);
	pthread_mutex_destroy(&args->d_lock);
	pthread_mutex_destroy(&args->w_lock);
}

int	init_threads(t_args *args, t_philo *philo, pthread_mutex_t *forks)
{
	pthread_t	monitor_t;
	int			i;

	i = 0;
	if (pthread_create(&monitor_t, NULL, &monitor, philo) == -1)
		return (thread_failed(0, philo, args, forks), printf("Error: t\n"), -1);
	while (i < args->num_of_philos)
	{
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]) == -1)
		{
			thread_failed(i, philo, args, forks);
			pthread_join(monitor_t, NULL);
			return (printf("Error: creating threads.\n"), -1);
		}
		i++;
	}
	i = 0;
	if (pthread_join(monitor_t, NULL) == -1)
		return (thread_failed(args->num_of_philos, philo, args, forks), -1);
	while (i < args->num_of_philos)
		if (pthread_join(philo[i++].thread, NULL) == -1)
			return (printf("Error: thread join.\n"), -1);
	return (0);
}
