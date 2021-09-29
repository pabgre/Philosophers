/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:56:55 by psan-gre          #+#    #+#             */
/*   Updated: 2021/09/29 14:02:11 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H
# include <stddef.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef pthread_mutex_t	t_mutex;
int			ft_atoi(char *str);
u_int64_t	get_timestamp(void);
#endif
