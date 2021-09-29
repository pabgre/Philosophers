/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:21:54 by psan-gre          #+#    #+#             */
/*   Updated: 2021/09/29 14:13:13 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include "ft_utils.h"
# include "restaurant.h"
# include "philo_structs.h"

int		philo_lifetime(t_philo self);
t_philo	philo_init(t_params params, int id, t_mutex *locks, int *sticks);
void	*philo_thread(void *arg);
int		anyone_dead(t_philo *philo_crew, int num_philo);
void	wake_up_philo(t_philo *philo_crew, int num_philo);
int		is_dead(t_philo philo);
#endif
