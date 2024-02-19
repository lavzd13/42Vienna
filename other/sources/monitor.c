/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomke <lomke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:18:17 by lomke             #+#    #+#             */
/*   Updated: 2024/02/18 23:39:47 by lomke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	died(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_current_time() - philo->last_meal >= time_to_die && philo->eating == 0)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	is_dead(t_philo *philo)
{
	int	i;

	i = 0;

	while (i < philo->num_of_philos)
	{
		if (died(&philo[i], philo[i].time_to_die))
		{
			ft_print("died", &philo[i], philo[i].id);
			pthread_mutex_lock(philo[0].dead_lock);
			*philo->dead = 1;
			pthread_mutex_unlock(philo[0].dead_lock);
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

	i = 0;
	done = 0;

	if (philo->times_to_eat == -1)
		return (0);
	while (i < philo->num_of_philos)
	{
		pthread_mutex_lock(philo[i].meal_lock);
		if (philo[i].meals_eaten >= philo[i].times_to_eat)
			done++;
		pthread_mutex_unlock(philo[i].meal_lock);
		i++;
	}
	if (done == philo->num_of_philos)
	{
		pthread_mutex_lock(philo[0].dead_lock);
		*philo->dead = 1;
		pthread_mutex_unlock(philo[0].dead_lock);
		return (1);
	}
	return (0);
}

void	*monitoring(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	while (1)
	{
		if (is_dead(philo) || all_ate(philo))
			break ;
	}
	return (pointer);
}
