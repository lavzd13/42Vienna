/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:31:29 by jlomic            #+#    #+#             */
/*   Updated: 2024/03/25 15:09:55 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

# define MAX 250

typedef struct s_args
{
	int				dead;
	pthread_mutex_t	d_lock;
	pthread_mutex_t	w_lock;
	pthread_mutex_t	e_lock;
	int				num_to_eat;
	int				time_to_eat;
	int				time_to_die;
	int				num_of_philos;
	int				time_to_sleep;
}		t_args;

typedef struct s_philo
{
	int				id;
	int				*dead;
	int				meals;
	int				eating;
	size_t			begin;
	int				num_to_eat;
	int				time_to_eat;
	size_t			last_meal;
	int				time_to_sleep;
	int				num_of_philos;
	pthread_t		thread;
	size_t			time_to_die;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	*d_lock;
	pthread_mutex_t	*w_lock;
	pthread_mutex_t	*e_lock;
}					t_philo;

//----------UTILS.C---------//
int		ft_atoi(char *str);
size_t	get_cur_time(void);
void	clean_forks(int i, pthread_mutex_t *forks, t_args *args);
void	ft_print(char *str, t_philo *philo, int id);
int		ft_usleep(size_t milliseconds, t_philo *philo);

//----------INIT.C----------//
void	init_args(t_args *args, char **argv);
int		init_forks(t_args *args, pthread_mutex_t *forks);
void	init_philos(t_args *args, t_philo *philo, pthread_mutex_t *forks);
int		init_threads(t_args *args, t_philo *philo, pthread_mutex_t *forks);

//-------CHECK_ARGS.C-------//
int		check_args(char **argv);

//---------ROUTINE.C--------//
void	*routine(void *philo);
int		dead(t_philo *philo);

//----------EXIT.C----------//
void	clean_exit(t_args *args, pthread_mutex_t *forks);

//-----ROUTINE_UTILS.C------//
void	take(t_philo *philo);
void	release(t_philo *philo);

//---------MONITOR.C--------//
void	*monitor(void *p);

#endif