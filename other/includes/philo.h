/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomke <lomke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 23:24:29 by lomke             #+#    #+#             */
/*   Updated: 2024/02/17 23:50:50 by lomke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

# define MAX 300

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;

}					t_philo;

typedef struct s_main
{
	int				dead_flag;
	t_philo			*philos;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	meal_lock;
}					t_main;

void	puterror(char *str);
int		ft_atoi(const char *str);
void	check_value_of_input(char **argv);
size_t	get_current_time(void);
int		ft_usleep(size_t milliseconds);
void	init_main(t_main *main, t_philo *philo);
void	init_philos(t_main *main, t_philo *philo, pthread_mutex_t *forks, char **argv);
void	init_forks(t_philo *philo, pthread_mutex_t *forks);
int		create_threads(t_main *main, pthread_mutex_t *forks);
void	clean_all(char *str, t_main *main, pthread_mutex_t *forks);
void	*monitoring(void *pointer);
void	*philo_routine(void *pointer);
int	dead_philo(t_philo *philo);
void	ft_print(char *str, t_philo *philo, int id);

#endif
