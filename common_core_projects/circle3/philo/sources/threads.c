/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:02:18 by jlomic            #+#    #+#             */
/*   Updated: 2024/02/26 14:20:29 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_print(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time() - philo->start_time;
	if (!philo_dead(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}

int	philo_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

int	create_threads(t_main *main, pthread_mutex_t *forks)
{
	pthread_t	checker;
	int			i;

	i = 0;
	if (pthread_create(&checker, NULL, &checking, main->philo) != 0)
		return (clean_all("Checker thread creation failed.\n", forks, main), 1);
	while (i < main->philo->num_of_philos)
	{
		if (pthread_create(&main->philo[i].thread, NULL,
				&philo_routine, &main->philo[i]) != 0)
			return (creation_failed(main, forks, i), 1);
		i++;
	}
	i = 0;
	if (pthread_join(checker, NULL) != 0)
		return (clean_all("Checker thread joining failed.\n", forks, main), 1);
	while (i < main->philo->num_of_philos)
	{
		if (pthread_join(main->philo[i].thread, NULL) != 0)
			return (clean_all("Thread joining failed.\n", forks, main), 1);
		i++;
	}
	return (0);
}
