/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:21:52 by jlomic            #+#    #+#             */
/*   Updated: 2024/02/26 14:48:08 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	think(t_philo *philo)
{
	ft_print("is thinking", philo, philo->id);
}

void	papa(t_philo *philo)
{
	ft_print("is sleeping", philo, philo->id);
	ft_usleep(philo, philo->time_to_sleep);
}

void	pickup(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(philo->l_fork);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
	}
}

void	eat(t_philo *philo)
{
	if (philo->num_of_philos == 1)
	{
		pthread_mutex_lock(philo->l_fork);
		ft_print("has taken a fork", philo, philo->id);
		ft_usleep(philo, philo->time_to_die);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	pickup(philo);
	ft_print("has taken a fork", philo, philo->id);
	ft_print("has taken a fork", philo, philo->id);
	philo->eating = 1;
	ft_print("is eating", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo, philo->time_to_eat);
	philo->eating = 0;
	putdown(philo);
}

void	*philo_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		usleep(100);
	while (!philo_dead(philo))
	{
		eat(philo);
		papa(philo);
		think(philo);
		if (philo->num_of_philos % 2 != 0 && !philo_dead(philo))
			iritating(philo);
	}
	return (pointer);
}
