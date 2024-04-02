/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:30:02 by jlomic            #+#    #+#             */
/*   Updated: 2024/03/30 14:18:25 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	dead(t_philo *philo)
{
	pthread_mutex_lock(philo->d_lock);
	pthread_mutex_lock(philo->e_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->e_lock);
		pthread_mutex_unlock(philo->d_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->e_lock);
	pthread_mutex_unlock(philo->d_lock);
	return (0);
}

void	take(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left);
		pthread_mutex_lock(philo->right);
	}
	else
	{
		pthread_mutex_lock(philo->right);
		pthread_mutex_lock(philo->left);
	}
	ft_print("has taken a fork", philo, philo->id);
	ft_print("has taken a fork", philo, philo->id);
}

void	release(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
	}
	else
	{
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
	}
}

void	eat(t_philo *philo)
{
	if (philo->num_of_philos == 1)
	{
		pthread_mutex_lock(philo->left);
		ft_print("has taken a fork", philo, philo->id);
		ft_usleep(philo->time_to_die, philo);
		pthread_mutex_unlock(philo->left);
		return ;
	}
	take(philo);
	ft_print("is eating", philo, philo->id);
	pthread_mutex_lock(philo->w_lock);
	pthread_mutex_lock(philo->e_lock);
	philo->last_meal = get_cur_time();
	pthread_mutex_unlock(philo->e_lock);
	pthread_mutex_unlock(philo->w_lock);
	ft_usleep(philo->time_to_eat, philo);
	pthread_mutex_lock(philo->w_lock);
	pthread_mutex_lock(philo->e_lock);
	philo->meals++;
	pthread_mutex_unlock(philo->e_lock);
	pthread_mutex_unlock(philo->w_lock);
	release(philo);
}

void	*routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	if (philo->id % 2 == 0)
		usleep(500);
	while (!dead(philo))
	{
		eat(philo);
		ft_print("is sleeping", philo, philo->id);
		ft_usleep(philo->time_to_sleep, philo);
		ft_print("is thinking", philo, philo->id);
		if (philo->num_of_philos % 2 != 0 && !dead(philo))
		{
			if (philo->time_to_eat <= philo->time_to_sleep)
				usleep(1000 * (philo->time_to_sleep \
					- philo->time_to_eat) + 500);
			else
				usleep(1000 * (philo->time_to_eat \
					- philo->time_to_sleep) + 500);
		}
	}
	return (p);
}
