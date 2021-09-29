/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:43:54 by psan-gre          #+#    #+#             */
/*   Updated: 2021/09/29 14:07:19 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_PRIVATE_H
# define PHILO_PRIVATE_H
# include "philo.h"

void	get_chopstick(int *l_stick, t_mutex *lock, int *r_stick, t_philo philo);
void	release_chopstick(int *local_stick, t_mutex *lock, int *remote_stick);
int		philo_lifetime(t_philo self);
#endif
