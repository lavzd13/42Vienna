/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:02:13 by jlomic            #+#    #+#             */
/*   Updated: 2024/02/26 14:21:13 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_main			main;
	t_philo			philo[MAX];
	pthread_mutex_t	forks[MAX];

	if (argc != 5 && argc != 6)
		return (printf("Not a valid number of args.\n"), 1);
	if (check_value_of_input(argv) == 1)
		return (1);
	init_main(&main, philo, forks);
	init_forks(ft_atoi(argv[1]), forks);
	init_philos(&main, philo, forks, argv);
	if (create_threads(&main, forks) == 1)
		return (1);
	clean_all(NULL, forks, &main);
}
