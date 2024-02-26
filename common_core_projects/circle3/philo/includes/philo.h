/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:44:27 by jlomic            #+#    #+#             */
/*   Updated: 2024/02/26 14:36:44 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

# define MAX 250

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
}				t_philo;

typedef struct s_main
{
	int				dead_flag;
	t_philo			*philo;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
}					t_main;

/*--------------------UTILS.C--------------------*/
int		ft_atoi(const char *str);
int		check_value_of_input(char **argv);
size_t	get_current_time(void);
int		ft_usleep(t_philo *philo, size_t milliseconds);
void	clean_all(char *str, pthread_mutex_t *forks, t_main *main);

/*--------------------INIT.C---------------------*/
void	init_args(t_philo *philo, char **argv);
void	init_main(t_main *main, t_philo *philo, pthread_mutex_t *forks);
int		init_forks(int num_of_philos, pthread_mutex_t *forks);
void	init_philos(t_main *main, t_philo *philo, pthread_mutex_t *forks, \
			char **argv);

/*--------------------THREADS.C------------------*/
int		create_threads(t_main *main, pthread_mutex_t *forks);
int		philo_dead(t_philo *philo);
void	ft_print(char *str, t_philo *philo, int id);

/*----------------THREADSUTILS.C-----------------*/
void	creation_failed(t_main *main, pthread_mutex_t *forks, int failed);
void	init_fail(pthread_mutex_t *forks, int failed);
void	putdown(t_philo *philo);
void	oddpickup(t_philo *philo);
void	iritating(t_philo *philo);

/*--------------------ROUTINE.C------------------*/
void	*philo_routine(void *pointer);

/*--------------------MONITOR.C------------------*/
void	*checking(void *pointer);

#endif
