/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:31:53 by jlomic            #+#    #+#             */
/*   Updated: 2024/02/26 14:21:27 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	died(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	pthread_mutex_lock(philo->meal_lock);
	if (get_current_time() - philo->last_meal >= philo->time_to_die
		&& philo->eating == 0)
	{
		pthread_mutex_unlock(philo->meal_lock);
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->meal_lock);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

int	is_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->num_of_philos)
	{
		if (died(&philo[i]) == 1)
		{
			pthread_mutex_lock(philo[i].write_lock);
			pthread_mutex_lock(philo->dead_lock);
			*philo->dead = 1;
			printf("%zu %d %s\n", get_current_time()
				- philo[i].start_time, philo[i].id, "died");
			pthread_mutex_unlock(philo->dead_lock);
			pthread_mutex_unlock(philo[i].write_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	all_ate(t_philo *philo)
{
	int	i;
	int	done;

	if (philo[0].times_to_eat == -1)
		return (0);
	i = 0;
	done = 0;
	while (i < philo[0].num_of_philos)
	{
		pthread_mutex_lock(philo[i].meal_lock);
		if (philo[i].meals_eaten >= philo[i].times_to_eat)
			done++;
		pthread_mutex_unlock(philo[i].meal_lock);
		i++;
	}
	if (done == philo[0].num_of_philos)
	{
		pthread_mutex_lock(philo[0].dead_lock);
		*philo->dead = 1;
		pthread_mutex_unlock(philo[0].dead_lock);
		return (1);
	}
	return (0);
}

void	*checking(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	while (1)
	{
		if (is_dead(philo) == 1 || all_ate(philo) == 1)
			break ;
	}
	return (pointer);
}
