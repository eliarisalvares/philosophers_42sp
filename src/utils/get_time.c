/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:45:29 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/27 12:43:15 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * @brief This function is used to get the current time in milliseconds.
 *
 * @return long long int The current time in milliseconds.
 */
long long int	get_time(void)
{
	struct timeval	time;
	long long int	now;

	gettimeofday(&time, NULL);
	if (gettimeofday(&time, NULL) == -1)
	{
		ft_putstr_fd(GET_TIME_ERROR, STDERROR);
		return (-1);
	}
	now = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (now);
}
