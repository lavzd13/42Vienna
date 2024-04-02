/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:54:08 by jlomic            #+#    #+#             */
/*   Updated: 2024/03/25 15:11:37 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_args			args;
	t_philo			philo[MAX];
	pthread_mutex_t	forks[MAX];

	if (argc != 5 && argc != 6)
		return (printf("Error: invalid number of args.\n"), 1);
	if (check_args(argv) == 1)
		return (1);
	init_args(&args, argv);
	if (init_forks(&args, forks) == -1)
		return (1);
	init_philos(&args, philo, forks);
	if (init_threads(&args, philo, forks) == -1)
		return (1);
	clean_exit(&args, forks);
}
