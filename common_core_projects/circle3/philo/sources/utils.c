/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:55:27 by jlomic            #+#    #+#             */
/*   Updated: 2024/02/25 17:47:20 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	clean_all(char *str, pthread_mutex_t *forks, t_main *main)
{
	int	i;

	i = 0;
	if (str)
		while (str[i])
			write(2, &str[i++], 1);
	i = 0;
	while (i < main->philo->num_of_philos)
		pthread_mutex_destroy(&forks[i++]);
	pthread_mutex_destroy(&main->dead_lock);
	pthread_mutex_destroy(&main->meal_lock);
	pthread_mutex_destroy(&main->write_lock);
}

int	ft_atoi(const char *str)
{
	long int	n;
	int			sign;

	n = 0;
	sign = 1;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		str++;
	if (*str == '-')
		return (-1);
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			n = n * 10 + (*str++ - '0');
		else
			return (-1);
	}
	return ((int)(n * sign));
}

int	check_value_of_input(char **argv)
{
	if (ft_atoi(argv[1]) >= MAX || ft_atoi(argv[1]) <= 0)
		return (printf("Invalid number of philosophers.\n"), 1);
	if (ft_atoi(argv[2]) <= 0)
		return (printf("Invalid time to die.\n"), 1);
	if (ft_atoi(argv[3]) <= 0)
		return (printf("Invalid time to eat.\n"), 1);
	if (ft_atoi(argv[4]) <= 0)
		return (printf("Invalid time to sleep.\n"), 1);
	if (argv[5] && ft_atoi(argv[5]) < 0)
		return (printf("Invalid number of time each philo needs to eat.\n"), 1);
	return (0);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(t_philo *philo, size_t milliseconds)
{
	size_t	start;

	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead != 0)
		return (pthread_mutex_unlock(philo->dead_lock), -1);
	pthread_mutex_unlock(philo->dead_lock);
	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}
