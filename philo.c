/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:10:00 by psan-gre          #+#    #+#             */
/*   Updated: 2021/09/21 17:04:52 by psan-gre         ###   ########.fr       */
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
	philo.alive = malloc(sizeof(int *));
	*philo.alive = 1;
	philo.print_lock = *print_lock;
	left = id - 1;
	right = id % params.num_philo;
	if (id == params.num_philo)
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

int	philo_lifetime(t_philo self)
{
	int	i;
	int	right;
	int	left;

	i = 0;
	right = 0;
	left = 0;
	notify_state(self.print_lock, "Buenas", self.id);
	while (i < self.params.eat_time)
	{
		get_chopstick(&right, self.right_lock, self.right_stick);
		get_chopstick(&left, self.left_lock, self.left_stick);
		if (left && right)
		{
			notify_state(self.print_lock, "Estoy comiendo...", self.id);
			usleep(1000000);
			release_chopstick(&right, self.right_lock, self.right_stick);
			release_chopstick(&left, self.left_lock, self.left_stick);
			i++;
			notify_state(self.print_lock, "Buenas noches...", self.id);
			usleep(1000000);
		}
	}
	notify_state(self.print_lock, "Venga chao", self.id);
	return (0);
}
