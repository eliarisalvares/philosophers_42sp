/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitoring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:52:08 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/30 04:16:59 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * @brief This function is used to monitor the death of the philosophers. It
 * will check whether the "time_to_die" time has passed since the last time 
 * the philosopher ate. If it has, it will call the display_status function to 
 * print the action and its timestamp and then change the "dinner->philo_died"
 * variable to 1, so the other threads can stop.
 *
 * @param monitor The monitor thread struct.
 * @param dinner The dinner struct.
 * @return int -1 if any of the philos has died, 0 otherwise.
 */
int	death_monitoring(t_philo **monitor, t_dinner *dinner)
{
	int				i;
	long long int	elapsed_time;

	i = 0;
	elapsed_time = get_time() - dinner->start;
	while (i < monitor[0]->dinner->total_philos)
	{
		pthread_mutex_lock(&monitor[0]->dinner->lock_forks);
		if ((elapsed_time - monitor[i]->last_meal > dinner->time_to_die)
			&& monitor[i]->eaten_times != dinner->minimum_meals)
		{
			display_status(monitor[i], DIED);
			dinner->philo_died = 1;
			pthread_mutex_unlock(&monitor[0]->dinner->lock_forks);
			return (-1);
		}
		pthread_mutex_unlock(&monitor[0]->dinner->lock_forks);
		i++;
	}
	return (0);
}
