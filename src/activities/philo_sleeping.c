/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleeping.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 23:51:56 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/30 04:16:37 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * @brief This function is responsible for the philosopher sleeping. It will
 * call the display_status function to print the action and its timestamp and
 * then it will sleep for the given time.
 *
 * @param philo The philosopher struct.
 */
void	philo_sleeping(t_philo *philo)
{
	display_status(philo, SLEEPING);
	do_action(philo->dinner->time_to_sleep);
}
