/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hungry_monitoring.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:52:08 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/30 04:17:09 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * @brief This function will iterate through the total number of philos (if
 * alive), first of all checking whether any of them has died. If not, it will
 * iterate through the philos again, checking whether they already ate the
 * number of times they were supposed to. If all philos have eaten the number
 * of times they were supposed to, the dinner is over.
 *
 * @param monitor The monitor struct.
 * @param dinner The dinner struct.
 * @return int The number of philos that are still hungry. -1 if any of the
 * philos has died.
 */
int	hungry_monitoring(t_philo **monitor, t_dinner *dinner)
{
	int	i;
	int	hungry_philos;

	hungry_philos = monitor[0]->dinner->total_philos;
	while (!dinner->philo_died && hungry_philos)
	{
		delay(0.5);
		i = death_monitoring(monitor, dinner);
		if (i == -1)
			return (-1);
		hungry_philos = dinner->total_philos;
		while (i < monitor[0]->dinner->total_philos)
		{
			pthread_mutex_lock(&dinner->lock_forks);
			if (monitor[i]->eaten_times == dinner->minimum_meals)
				hungry_philos--;
			pthread_mutex_unlock(&dinner->lock_forks);
			i++;
		}
	}
	return (hungry_philos);
}
