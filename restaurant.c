/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restaurant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:17:01 by psan-gre          #+#    #+#             */
/*   Updated: 2021/09/21 16:13:10 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	generate_chopsticks(int num_philo, int **sticks, pthread_mutex_t **locks)
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

int	notify_state(pthread_mutex_t *print_lock, char *msg, int id)
{
	pthread_mutex_unlock(print_lock);
	printf("Filosofo %d dice %s\n", id, msg);
	pthread_mutex_unlock(print_lock);
	return (0);
}
