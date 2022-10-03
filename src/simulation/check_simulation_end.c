/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_simulation_end.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 22:01:52 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/30 04:17:53 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * @brief This function is responsible for checking if the simulation has ended.
 * It will check if the number of meals has been reached and if the philosopher
 * has died. If any of these conditions is true, the simulation will end. In
 * this case, the function will return the corresponding enum value with the
 * reason for the simulation ending.
 *
 * @param philo The philosopher struct.
 * @return int The enum value with the reason for the simulation ending or
 * 0 if the simulation has not ended.
 */
int	check_simulation_end(t_philo *philo)
{
	pthread_mutex_lock(&philo->dinner->lock_forks);
	if (philo->dinner->philo_died != 0)
	{
		pthread_mutex_unlock(&philo->dinner->lock_forks);
		return (DIED);
	}
	if (philo->eaten_times == philo->dinner->minimum_meals)
	{
		pthread_mutex_unlock(&philo->dinner->lock_forks);
		return (EATING);
	}
	pthread_mutex_unlock(&philo->dinner->lock_forks);
	return (0);
}
