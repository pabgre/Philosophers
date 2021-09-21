/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:21:54 by psan-gre          #+#    #+#             */
/*   Updated: 2021/09/21 17:07:12 by psan-gre         ###   ########.fr       */
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

typedef struct s_params{
	int	num_philo;
	int	death_time;
	int	eat_time;
	int	sleep_time;
	int	num_meals;
}				t_params;

typedef struct s_philo{
	int				id;
	int				*alive;
	t_params		params;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*left_lock;
	pthread_mutex_t	*right_lock;
	int				*left_stick;
	int				*right_stick;
}				t_philo;

void			generate_chopsticks(int num_philo, int **sticks, pthread_mutex_t**locks);
int				philo_lifetime(t_philo self);
t_philo			philo_init(t_params params, int id, pthread_mutex_t *locks, int *sticks, pthread_mutex_t **print_lock);
void			*philo_thread(void *arg);
int				all_dead(t_philo *philo_crew, int num_philo);
void			wake_up_philo(t_philo *philo_crew, int num_philo);
int				philo_lifetime(t_philo self);
int				notify_state(pthread_mutex_t *print_lock, char *msg, int id);
void			get_chopstick(int *local_stick, pthread_mutex_t *lock, int *remote_stick);
void			release_chopstick(int *local_stick, pthread_mutex_t *lock, int *remote_stick);
#endif
