/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_for_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:49:33 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/30 14:54:00 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * @brief This function is used to check if there is only one philosopher.
 * If there is only one philosopher, it will inevitably die of starvation, so
 * this function will only lock the philosopher's fork and print the message
 * that it took the only fork available to him, then it will await for the
 * given time to die and unlock the fork.
 *
 * @param philo a pointer to the philosopher's structure.
 */
void	table_for_one(t_philo *philo)
{
	pthread_mutex_lock(philo->philo_forks[FIRST_FORK]);
	display_status(philo, TOOK_FORK);
	do_action(philo->dinner->time_to_die);
	pthread_mutex_unlock(philo->philo_forks[FIRST_FORK]);
}
