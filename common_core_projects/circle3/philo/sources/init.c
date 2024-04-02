/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:08:27 by jlomic            #+#    #+#             */
/*   Updated: 2024/03/25 15:09:18 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_args(t_args *args, char **argv)
{
	args->dead = 0;
	args->num_of_philos = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		args->num_to_eat = ft_atoi(argv[5]);
	else
		args->num_to_eat = -1;
}

int	init_forks(t_args *args, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&args->d_lock, NULL) != 0)
		return (printf("Error: mutex init.\n"), -1);
	if (pthread_mutex_init(&args->w_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&args->d_lock);
		return (printf("Error: mutex init.\n"), -1);
	}
	if (pthread_mutex_init(&args->e_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&args->d_lock);
		pthread_mutex_destroy(&args->w_lock);
		return (printf("Error: mutex init.\n"), -1);
	}
	while (i < args->num_of_philos)
	{
		if (pthread_mutex_init(&forks[i++], NULL) == -1)
		{
			clean_forks(i, forks, args);
			return (printf("Error: mutex init.\n"), -1);
		}
	}
	return (0);
}

void	init_philos(t_args *args, t_philo *philo, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < args->num_of_philos)
	{
		philo[i].meals = 0;
		philo[i].eating = 0;
		philo[i].id = i + 1;
		philo[i].right = &forks[i];
		philo[i].dead = &args->dead;
		philo[i].left = &forks[i - 1];
		philo[i].d_lock = &args->d_lock;
		philo[i].w_lock = &args->w_lock;
		philo[i].e_lock = &args->e_lock;
		philo[i].begin = get_cur_time();
		philo[i].last_meal = get_cur_time();
		philo[i].num_to_eat = args->num_to_eat;
		philo[i].time_to_die = args->time_to_die;
		philo[i].time_to_eat = args->time_to_eat;
		philo[i].num_of_philos = args->num_of_philos;
		philo[i].time_to_sleep = args->time_to_sleep;
		if (i == 0)
			philo[i].left = &forks[args->num_of_philos - 1];
		i++;
	}
}
