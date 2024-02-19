/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomke <lomke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 23:24:19 by lomke             #+#    #+#             */
/*   Updated: 2024/02/17 01:42:20 by lomke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	puterror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(2, &str[i++], 1);
	exit(EXIT_FAILURE);
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

void	check_value_of_input(char **argv)
{
	if (ft_atoi(argv[1]) >= MAX || ft_atoi(argv[1]) <= 0)
		puterror("Invalid number of philosophers.\n");
	if (ft_atoi(argv[2]) <= 0)
		puterror("Invalid time to die.\n");
	if (ft_atoi(argv[3]) <= 0)
		puterror("Invalid time to eat.\n");
	if (ft_atoi(argv[4]) <= 0)
		puterror("Invalid time to sleep.\n");
	if (argv[5] && ft_atoi(argv[5]) < 0)
		puterror("Invalid number of time each philo needs to eat.\n");
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}
