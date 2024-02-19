/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomke <lomke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:48:54 by lomke             #+#    #+#             */
/*   Updated: 2024/02/18 22:58:32 by lomke            ###   ########.fr       */
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
	ft_usleep(philo->time_to_sleep);
}
void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	ft_print("has taken a fork", philo, philo->id);
	if (philo->num_of_philos == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	ft_print("has taken a fork", philo, philo->id);
	philo->eating = 1;
	ft_print("is eating", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
void	*philo_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->num_of_philos % 2 == 0)
		ft_usleep(1);
	while (!dead_philo(philo))
	{
		eat(philo);
		papa(philo);
		think(philo);
	}
	return (pointer);
}
