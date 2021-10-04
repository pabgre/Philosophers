/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_constructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:23:18 by psan-gre          #+#    #+#             */
/*   Updated: 2021/10/04 11:40:32 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_private.h"

t_philo	philo_init(t_params params, int id, t_mutex *locks, int *sticks)
{
	t_philo			philo;
	int				left;
	int				right;

	philo.params = params;
	philo.id = id;
	philo.last_meal = get_timestamp();
	philo.alive = malloc(sizeof(int *));
	*philo.alive = 1;
	philo.print_lock = params.print_lock;
	left = id - 1;
	right = id % params.num_philo;
	if (id % 2 == 1)
	{
		left = right;
		right = id - 1;
	}
	philo.left_lock = &locks[left];
	philo.right_lock = &locks[right];
	philo.left_stick = &sticks[left];
	philo.right_stick = &sticks[right];
	return (philo);
}

void	*philo_thread(void *arg)
{
	t_philo	philo;

	philo = *(t_philo *)(arg);
	philo_lifetime(philo);
	*philo.alive = 0;
	pthread_exit(0);
}
