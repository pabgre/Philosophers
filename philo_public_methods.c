/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_private_methods.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:24:48 by psan-gre          #+#    #+#             */
/*   Updated: 2021/09/29 13:25:58 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	anyone_dead(t_philo *philo_crew, int num_philo)
{
	int	i;

	i = 0;
	while (i < num_philo)
	{
		if ((*philo_crew[i].alive) == 0)
		{
			i = 0;
			while (i < num_philo)
			{
				*philo_crew[i].alive = 0;
				i++;
			}
			return (0);
		}
		i++;
	}
	return (1);
}

void	wake_up_philo(t_philo *philo_crew, int num_philo)
{
	pthread_t	thid;
	int			i;

	i = 0;
	while (i < num_philo)
	{
		if (pthread_create(&thid, NULL, philo_thread, &philo_crew[i]) != 0)
		{
			perror("pthread_create() error");
			exit(1);
		}
		i++;
	}
}

int	is_dead(t_philo philo)
{
	if (get_timestamp() - philo.last_meal >= philo.params.death_time)
	{
		*philo.alive = 0;
		return (1);
	}
	return (0);
}
