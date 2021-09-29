/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:10:00 by psan-gre          #+#    #+#             */
/*   Updated: 2021/09/29 09:07:27 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	philo_init(t_params params, int id, pthread_mutex_t *locks, int *sticks, pthread_mutex_t **print_lock)
{
	t_philo			philo;
	int				left;
	int				right;

	philo.params = params;
	philo.id = id;
	philo.last_meal = get_timestamp();
	philo.alive = malloc(sizeof(int *));
	*philo.alive = 1;
	philo.print_lock = *print_lock;
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

int	all_dead(t_philo *philo_crew, int num_philo)
{
	int	i;
	int	dead;

	dead = 1;
	i = 0;
	while (i < num_philo && dead != 0)
	{
		dead = dead & !(*philo_crew[i].alive);
		i++;
	}
	return (dead);
}

int	anyone_dead(t_philo *philo_crew, int num_philo)
{
	int	i;
	int	dead;

	dead = 1;
	i = 0;
	while (i < num_philo && dead != 0)
	{
		if ((*philo_crew[i].alive) == 0)
			return (1);
		i++;
	}
	return (0);
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
	return (get_timestamp() - philo.last_meal >= philo.params.death_time);
}

int	philo_lifetime(t_philo self)
{
	int			i;
	int			right;
	int			left;
	u_int64_t	time_count;

	i = 0;
	right = 0;
	left = 0;
	while (i != self.params.num_meals)
	{
		get_chopstick(&right, self.right_lock, self.right_stick, self);
		get_chopstick(&left, self.left_lock, self.left_stick, self);
		if (left && right)
		{
			notify_state(self.print_lock, self, _eating);
			self.last_meal = get_timestamp();
			time_count = 0;
			while (time_count < self.params.eat_time)
			{
				usleep(1000);
				time_count += 1;
				if (is_dead(self))
				{
					notify_state(self.print_lock, self, _died);
					return (0);
				}
			}
			i++;
			release_chopstick(&right, self.right_lock, self.right_stick);
			release_chopstick(&left, self.left_lock, self.left_stick);
			notify_state(self.print_lock, self, _sleeping);
			time_count = 0;
			while (time_count < self.params.sleep_time)
			{
				usleep(1000);
				time_count += 1;
				if (is_dead(self))
				{
					notify_state(self.print_lock, self, _died);
					return (0);
				}
			}
		}
		else if (is_dead(self))
		{
			notify_state(self.print_lock, self, _died);
			return (0);
		}
	}
	return (0);
}
