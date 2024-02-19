/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomke <lomke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 23:21:19 by lomke             #+#    #+#             */
/*   Updated: 2024/02/18 23:52:09 by lomke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_main			main;
	t_philo			philos[MAX];
	pthread_mutex_t	forks[MAX];

	if (argc != 5 && argc != 6)
		puterror("Invalid number of arguments.\n");
	check_value_of_input(argv);
	init_main(&main, philos);
	init_forks(philos, forks);
	init_philos(&main, philos, forks, argv);
	create_threads(&main, forks);
	clean_all(NULL, &main, forks);
}
