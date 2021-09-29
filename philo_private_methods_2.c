/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_private_methods_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:30:19 by psan-gre          #+#    #+#             */
/*   Updated: 2021/09/29 14:08:37 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_private.h"

void	get_chopstick(int *l_stick, t_mutex *lock, int *r_stick, t_philo philo)
{
	if (*l_stick == 0)
	{
		pthread_mutex_lock(lock);
		if (*r_stick == 0)
		{
			*r_stick = 1;
			*l_stick = 1;
			notify_state(philo.print_lock, philo, _fork_taken);
		}
		pthread_mutex_unlock(lock);
	}
}

void	release_chopstick(int *l_stick, t_mutex *lock, int *r_stick)
{
	pthread_mutex_lock(lock);
	*r_stick = 0;
	*l_stick = 0;
	pthread_mutex_unlock(lock);
}
