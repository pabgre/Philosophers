/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:21:42 by psan-gre          #+#    #+#             */
/*   Updated: 2021/09/29 14:12:50 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_params	process_input(int argc, char **argv)
{
	t_params	params;

	params.num_philo = ft_atoi(argv[1]);
	params.death_time = ft_atoi(argv[2]);
	params.eat_time = ft_atoi(argv[3]);
	params.sleep_time = ft_atoi(argv[4]);
	params.init_time = get_timestamp();
	params.print_lock = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(params.print_lock, NULL);
	if (argc > 5)
		params.num_meals = ft_atoi(argv[5]);
	else
		params.num_meals = -1;
	return (params);
}

int	main_thread(t_philo *philo_crew, int num_philo)
{
	int	i;

	i = 0;
	while (anyone_dead(philo_crew, num_philo))
	{
		i = 0;
	}
	usleep(1000);
	return (i);
}

int	main(int argc, char**argv)
{
	t_params		params;
	t_philo			*philo_crew;
	pthread_mutex_t	*locks;
	int				*sticks;
	int				i;

	if (argc > 4)
	{
		params = process_input(argc, argv);
		generate_chopsticks(params.num_philo, &sticks, &locks);
		philo_crew = malloc(sizeof(t_philo) * params.num_philo);
		i = 0;
		while (i < params.num_philo)
		{
			philo_crew[i] = philo_init(params, i + 1, locks, sticks);
			i ++;
		}
		wake_up_philo(philo_crew, params.num_philo);
		main_thread(philo_crew, params.num_philo);
	}
	return (0);
}
