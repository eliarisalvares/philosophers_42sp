/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:09:42 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/27 11:15:17 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * @brief This function receives the corresponding "time_to_" variable and
 * sleeps for that time times 1000 microseconds.
 *
 * @param time the "time_to_" variable.
 */
void	do_action(long long int time)
{
	usleep(time * 1000);
}
