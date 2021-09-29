/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:53:51 by psan-gre          #+#    #+#             */
/*   Updated: 2021/09/29 13:18:43 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	ft_atoi(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i] != '\0')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

u_int64_t	get_timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
