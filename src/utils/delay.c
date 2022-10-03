/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delay.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:09:42 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/27 11:43:21 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * @brief This function receives a time in milliseconds and sleeps for that
 * time. It is used to delay the execution of the program.
 *
 * @param time_to_delay the time in milliseconds to delay the execution.
 */
void	delay(double time_to_delay)
{
	usleep(time_to_delay * 1000);
}
