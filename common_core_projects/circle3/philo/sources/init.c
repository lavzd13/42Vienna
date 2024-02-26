/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:10:00 by jlomic            #+#    #+#             */
/*   Updated: 2024/02/25 17:50:01 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_args(t_philo *philo, char **argv)
{
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->num_of_philos = ft_atoi(argv[1]);
	if (argv[5])
		philo->times_to_eat = ft_atoi(argv[5]);
	else
		philo->times_to_eat = -1;
}

void	init_main(t_main *main, t_philo *philo, pthread_mutex_t *forks)
{
	main->philo = philo;
	main->dead_flag = 0;
	if (pthread_mutex_init(&main->dead_lock, NULL) != 0)
		clean_all("Init failed.\n", forks, main);
	if (pthread_mutex_init(&main->meal_lock, NULL) != 0)
		clean_all("Init failed.\n", forks, main);
	if (pthread_mutex_init(&main->write_lock, NULL) != 0)
		clean_all("Init failed.\n", forks, main);
}

int	init_forks(int num_of_philos, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < num_of_philos)
		if (pthread_mutex_init(&forks[i++], NULL) != 0)
			return (init_fail(forks, i), 1);
	return (0);
}

void	init_philos(t_main *main, t_philo *philo, pthread_mutex_t *forks, \
			char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philo[i].id = i + 1;
		philo[i].eating = 0;
		philo[i].meals_eaten = 0;
		init_args(&philo[i], argv);
		philo[i].last_meal = get_current_time();
		philo[i].start_time = get_current_time();
		philo[i].dead_lock = &main->dead_lock;
		philo[i].meal_lock = &main->meal_lock;
		philo[i].write_lock = &main->write_lock;
		philo[i].dead = &main->dead_flag;
		philo[i].r_fork = &forks[i];
		if (i == 0)
			philo[i].l_fork = &forks[philo[i].num_of_philos - 1];
		else
			philo[i].l_fork = &forks[i - 1];
		i++;
	}
}
