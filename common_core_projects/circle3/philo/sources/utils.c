/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:56:30 by jlomic            #+#    #+#             */
/*   Updated: 2024/03/25 14:13:58 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_print(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->w_lock);
	time = get_cur_time() - philo->begin;
	if (!dead(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->w_lock);
}

void	clean_forks(int i, pthread_mutex_t *forks, t_args *args)
{
	int	c;

	c = 0;
	while (c < i)
		pthread_mutex_destroy(&forks[c++]);
	pthread_mutex_destroy(&args->d_lock);
	pthread_mutex_destroy(&args->w_lock);
	pthread_mutex_destroy(&args->e_lock);
}

int	ft_atoi(char *str)
{
	int			i;
	long long	num;

	num = 0;
	i = 0;
	if (str[0] == '+')
		i++;
	else if (str[0] == '-')
		return (printf("Error: numbers can only have preceding +.\n"), -1);
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			num = num * 10 + (str[i] - '0');
		else if (str[i] == '-')
			return (printf("Error: nope.\n"), -1);
		else
			return (printf("Error: no letters only numbers.\n"), -1);
		i++;
	}
	if (num <= 0)
		return (printf("Error: can't be zero.\n"), -1);
	if (num > 2147483647)
		return (printf("Error: bigger than max int.\n"), -1);
	return (num);
}

size_t	get_cur_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds, t_philo *philo)
{
	size_t	start;

	start = get_cur_time();
	while ((get_cur_time() - start) < milliseconds)
	{
		pthread_mutex_lock(philo->d_lock);
		if (*philo->dead == 1)
		{
			pthread_mutex_unlock(philo->d_lock);
			return (1);
		}
		pthread_mutex_unlock(philo->d_lock);
		usleep(500);
	}
	return (0);
}
