/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomke <lomke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:55:01 by lomke             #+#    #+#             */
/*   Updated: 2024/02/19 00:12:26 by lomke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_main(t_main *main, t_philo *philo)
{
	main->philos = philo;
	main->dead_flag = 0;
	pthread_mutex_init(&main->dead_lock, NULL);
	pthread_mutex_init(&main->meal_lock, NULL);
	pthread_mutex_init(&main->write_lock, NULL);
}

void	init_args(t_philo *philo, char **argv)
{
	philo->num_of_philos = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->times_to_eat = ft_atoi(argv[5]);
	else
		philo->times_to_eat = -1;
}

void	init_philos(t_main *main, t_philo *philo, pthread_mutex_t *forks, char **argv)
{
	int	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philo[i].id = i + 1;
		philo[i].dead = 0;
		philo[i].eating = 0;
		philo[i].start_time = get_current_time();
		
		init_args(&philo[i], argv);
		philo[i].dead_lock = &main->dead_lock;
		philo[i].meal_lock = &main->meal_lock;
		philo[i].write_lock = &main->write_lock;
		philo[i].dead = &main->dead_flag;
		philo[i].l_fork = &forks[i];
		if (i == 0)
			philo[i].r_fork = &forks[philo[i].num_of_philos - 1];
		else
			philo[i].r_fork = &forks[i - 1];
		i++;
	}
}

void	init_forks(t_philo *philo, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < philo->num_of_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}
