/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:54:16 by psan-gre          #+#    #+#             */
/*   Updated: 2021/09/29 14:11:00 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCTS_H
# define PHILO_STRUCTS_H
# include "ft_utils.h"

typedef struct s_params{
	int				num_philo;
	u_int64_t		death_time;
	u_int64_t		eat_time;
	u_int64_t		sleep_time;
	int				num_meals;
	u_int64_t		init_time;
	pthread_mutex_t	*print_lock;
}				t_params;

typedef struct s_philo{
	int				id;
	u_int64_t		last_meal;
	int				*alive;
	t_params		params;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*left_lock;
	pthread_mutex_t	*right_lock;
	int				*left_stick;
	int				*right_stick;
}				t_philo;

enum	e_philo_state{_fork_taken, _eating, _sleeping, _thinking, _died};
typedef enum e_philo_state	t_state;
#endif
