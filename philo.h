/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:21:54 by psan-gre          #+#    #+#             */
/*   Updated: 2021/09/22 12:32:45 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include "ft_utils.h"
# include <sys/time.h>

typedef struct s_params{
	int			num_philo;
	u_int64_t	death_time;
	u_int64_t	eat_time;
	u_int64_t	sleep_time;
	int			num_meals;
	u_int64_t	init_time;
}				t_params;

typedef struct s_philo{
	int				id;
	u_int64_t		last_meal;
	int				*alive;
	t_params		params;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*left_lock;
	pthread_mutex_t	*right_lock;
	int				*left_stick;
	int				*right_stick;
}				t_philo;

enum	e_philo_state{_fork_taken, _eating, _sleeping, _thinking, _died};

void			generate_chopsticks(int num_philo, int **sticks, pthread_mutex_t**locks);
int				philo_lifetime(t_philo self);
t_philo			philo_init(t_params params, int id, pthread_mutex_t *locks, int *sticks, pthread_mutex_t **print_lock);
void			*philo_thread(void *arg);
int				all_dead(t_philo *philo_crew, int num_philo);
int				anyone_dead(t_philo *philo_crew, int num_philo);
void			wake_up_philo(t_philo *philo_crew, int num_philo);
int				philo_lifetime(t_philo self);
int				notify_state(pthread_mutex_t *print_lock, t_philo philo, enum e_philo_state state);
void			get_chopstick(int *local_stick, pthread_mutex_t *lock, int *remote_stick, t_philo philo);
void			release_chopstick(int *local_stick, pthread_mutex_t *lock, int *remote_stick);
u_int64_t		get_timestamp(void);
#endif
