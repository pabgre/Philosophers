/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:04:59 by psan-gre          #+#    #+#             */
/*   Updated: 2021/09/22 11:58:58 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_chopstick(int *local_stick, pthread_mutex_t *lock, int *remote_stick, t_philo philo)
{
	if (*local_stick == 0)
	{
		pthread_mutex_lock(lock);
		if (*remote_stick == 0)
		{
			*remote_stick = 1;
			*local_stick = 1;
			notify_state(philo.print_lock, philo, _fork_taken);
		}
		pthread_mutex_unlock(lock);
	}
}

void	release_chopstick(int *local_stick, pthread_mutex_t *lock, int *remote_stick)
{
	pthread_mutex_lock(lock);
	*remote_stick = 0;
	*local_stick = 0;
	pthread_mutex_unlock(lock);
}
