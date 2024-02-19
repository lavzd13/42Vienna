/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomke <lomke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:48:00 by lomke             #+#    #+#             */
/*   Updated: 2024/02/18 23:25:55 by lomke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_print(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time() -philo->start_time;
	if (!dead_philo(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}

void	clean_all(char *str, t_main *main, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (str)
		while (str[i])
			write(2, &str[i++], 1);
	i = 0;
	while (i < main->philos->num_of_philos)
		pthread_mutex_destroy(&forks[i++]);
	pthread_mutex_destroy(&main->dead_lock);
	pthread_mutex_destroy(&main->meal_lock);
	pthread_mutex_destroy(&main->write_lock);
}
