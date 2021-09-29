/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restaurant.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:47:31 by psan-gre          #+#    #+#             */
/*   Updated: 2021/09/29 14:13:53 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESTAURANT_H
# define RESTAURANT_H
# include "philo_structs.h"

int		notify_state(t_mutex *print_lock, t_philo philo, t_state state);
void	generate_chopsticks(int num_philo, int **sticks, t_mutex **locks);
#endif
