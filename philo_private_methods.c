/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_private_methods.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:24:51 by psan-gre          #+#    #+#             */
/*   Updated: 2021/09/29 13:52:52 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_private.h"

int	philo_eating(t_philo *self)
{
	self->last_meal = get_timestamp();
	notify_state(self->print_lock, *self, _eating);
	while (get_timestamp() - self->last_meal < self->params.eat_time)
	{
		usleep(60);
		if (is_dead(*self))
		{
			notify_state(self->print_lock, *self, _died);
			return (0);
		}
	}
	return (1);
}

int	philo_sleeping(t_philo *self)
{
	u_int64_t	time_count;

	notify_state(self->print_lock, *self, _sleeping);
	time_count = get_timestamp();
	while (get_timestamp() - time_count < self->params.sleep_time)
	{
		usleep(60);
		if (is_dead(*self))
		{
			notify_state(self->print_lock, *self, _died);
			return (0);
		}
	}
	return (1);
}

int	philo_eat_and_sleep(t_philo *self, int *right, int *left)
{
	if (philo_eating(self) == 0)
		return (0);
	release_chopstick(right, self->right_lock, self->right_stick);
	release_chopstick(left, self->left_lock, self->left_stick);
	if (philo_sleeping(self) == 0)
		return (0);
	return (1);
}

void	philo_table_manners(t_philo self)
{
	if (self.id % 2 == 1)
		usleep(200);
}

int	philo_lifetime(t_philo self)
{
	int			i;
	int			right;
	int			left;

	i = 0;
	right = 0;
	left = 0;
	while (i != self.params.num_meals && *self.alive == 1)
	{
		philo_table_manners(self);
		get_chopstick(&right, self.right_lock, self.right_stick, self);
		get_chopstick(&left, self.left_lock, self.left_stick, self);
		if (left && right)
		{
			if (philo_eat_and_sleep(&self, &right, &left) == 0)
				return (0);
			i++;
		}
		else if (is_dead(self))
		{
			notify_state(self.print_lock, self, _died);
			return (0);
		}
	}
	return (0);
}
