/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:52:08 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/30 04:17:17 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * @brief In concurrency programming, a monitor is a synchronization construct
 * that allows threads to have both mutual exclusion and the ability to wait
 * for a certain condition to be met. In this case, the monitor is responsible
 * for checking if the dinner is over. It will check the number of philos that
 * are hungry (if 0, the dinner is over) and if any of the philos has died
 * using, respectively, the hungry_monitoring and death_monitoring functions.
 * The monitor wraps around a mutex lock and unlock to ensure that only one
 * thread can access the monitor at a time.
 *
 * @param philo The philosopher struct.
 * @return void* NULL.
 */
void	*monitor_routine(void *philo)
{
	t_philo	**monitor;

	monitor = (t_philo **)philo;
	if (hungry_monitoring(monitor, monitor[0]->dinner) == 0)
		display_status(monitor[0], SIMULATION_ENDED);
	return (NULL);
}
