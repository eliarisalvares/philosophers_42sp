/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thinking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:42:22 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/30 04:16:48 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * @brief This function is responsible for the philosopher thinking. It will
 * call the display_status function to print the action and its timestamp, then,
 * as no time is given, it will sleep for 1 millisecond.
 *
 * @param philo The philosopher struct.
 */
void	philo_thinking(t_philo *philo)
{
	display_status(philo, THINKING);
	do_action(1);
}
