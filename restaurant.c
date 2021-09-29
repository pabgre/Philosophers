/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restaurant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:17:01 by psan-gre          #+#    #+#             */
/*   Updated: 2021/09/29 14:03:27 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "restaurant.h"

void	generate_chopsticks(int num_philo, int **sticks, t_mutex **locks)
{
	int				i;
	pthread_mutex_t	*my_locks;
	int				*my_sticks;

	i = 0;
	my_locks = malloc(sizeof(pthread_mutex_t) * num_philo);
	my_sticks = malloc(sizeof(int) * num_philo);
	while (i < num_philo)
	{
		pthread_mutex_init(&my_locks[i], NULL);
		pthread_mutex_unlock(&my_locks[i]);
		my_sticks[i] = 0;
		i++;
	}
	*locks = my_locks;
	*sticks = my_sticks;
}

int	notify_state(t_mutex *print_lock, t_philo philo, t_state state)
{
	u_int64_t	time_stamp;

	time_stamp = get_timestamp() - philo.params.init_time;
	pthread_mutex_lock(print_lock);
	if (state == _fork_taken)
		printf("[%ld] %d has taken a fork.\n", time_stamp, philo.id);
	if (state == _eating)
		printf("[%ld] %d is eating.\n", time_stamp, philo.id);
	if (state == _sleeping)
		printf("[%ld] %d is sleeping.\n", time_stamp, philo.id);
	if (state == _thinking)
		printf("[%ld] %d is thinking.\n", time_stamp, philo.id);
	if (state == _died)
		printf("[%ld] %d died.\n", time_stamp, philo.id);
	if (state != _died)
		pthread_mutex_unlock(print_lock);
	return (0);
}
