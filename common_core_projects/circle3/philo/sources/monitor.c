/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:59:44 by jlomic            #+#    #+#             */
/*   Updated: 2024/03/30 14:18:32 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	checking2(t_philo *philo, int i, int *all_philos_finished_meals)
{
	pthread_mutex_lock(philo[i].w_lock);
	pthread_mutex_lock(philo[i].d_lock);
	pthread_mutex_lock(philo[i].e_lock);
	if ((get_cur_time() \
		- philo[i].last_meal) >= philo[i].time_to_die)
	{
		*philo->dead = 1;
		printf("%zu %d died\n", get_cur_time() - philo[i].begin, philo[i].id);
		pthread_mutex_unlock(philo[i].e_lock);
		pthread_mutex_unlock(philo[i].d_lock);
		pthread_mutex_unlock(philo[i].w_lock);
		return (1);
	}
	if (philo[i].meals >= philo[i].num_to_eat && philo[i].num_to_eat != -1)
		*all_philos_finished_meals += 1;
	pthread_mutex_unlock(philo[i].e_lock);
	pthread_mutex_unlock(philo[i].d_lock);
	pthread_mutex_unlock(philo[i].w_lock);
	return (0);
}

int	checking(t_philo *philo)
{
	int	i;
	int	all_philos_finished_meals;

	while (1)
	{
		i = 0;
		all_philos_finished_meals = 0;
		while (i < philo[0].num_of_philos)
		{
			if (checking2(philo, i, &all_philos_finished_meals) != 0)
				return (1);
			i++;
		}
		if (all_philos_finished_meals == philo[0].num_of_philos)
		{
			pthread_mutex_lock(philo[0].w_lock);
			pthread_mutex_lock(philo[0].d_lock);
			*philo->dead = 1;
			pthread_mutex_unlock(philo[0].d_lock);
			pthread_mutex_unlock(philo[0].w_lock);
			return (1);
		}
	}
}

void	*monitor(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	while (1)
	{
		if (checking(philo) == 1)
			break ;
	}
	return (p);
}
