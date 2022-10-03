/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:44:02 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/30 14:54:20 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	take_forks(t_philo *philo);
static void	drop_forks(t_philo *philo);

/**
 * @brief This function is responsible for the philosopher eating. It will
 * lock the mutexes of the forks, call the display_status function to print the
 * action and its timestamp, then it will sleep for the given time and unlock
 * the mutexes.
 *
 * @param philo The philosopher struct.
 */
int	philo_eating(t_philo *philo)
{
	take_forks(philo);
	if (check_simulation_end(philo))
	{
		drop_forks(philo);
		return (0);
	}
	display_status(philo, TOOK_FORK);
	display_status(philo, TOOK_FORK);
	display_status(philo, EATING);
	pthread_mutex_lock(&philo->dinner->lock_forks);
	philo->eaten_times++;
	philo->last_meal = get_time() - philo->dinner->start;
	pthread_mutex_unlock(&philo->dinner->lock_forks);
	do_action(philo->dinner->time_to_eat);
	drop_forks(philo);
	return (1);
}

/**
 * @brief This function is used to lock the philosopher's forks and print the
 * message that he took both forks. It will also check if the dinner is over
 * and if it is, it will unlock the forks and return 0.
 *
 * @param philo a pointer to the philosopher's structure.
 * @return int 1 if the dinner is not over, 0 if it is.
 */
static void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->philo_forks[FIRST_FORK]);
	pthread_mutex_lock(philo->philo_forks[SECOND_FORK]);
}

/**
 * @brief This function is used to unlock the philosopher's both forks after
 * the philosopher has eaten or in case the dinner has ended.
 *
 * @param philo a pointer to the philosopher's structure.
 */
static void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->philo_forks[FIRST_FORK]);
	pthread_mutex_unlock(philo->philo_forks[SECOND_FORK]);
}
