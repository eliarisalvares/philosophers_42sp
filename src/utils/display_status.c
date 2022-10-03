/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_status.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 02:29:32 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/27 11:04:49 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * @brief This function is responsible for displaying the status of the
 * philosophers. First, it locks the mutex responsible for printing the text.
 * Then, it gets the current time and calculates the time elapsed since the
 * beginning of the program. Finally, it prints the time elapsed,
 * the philosopher number, and the status.
 *
 * @param philo The philosopher structure.
 * @param status The status to be displayed.
 */
void	display_status(t_philo *philo, int status)
{
	long long int	now;

	pthread_mutex_lock(&philo->dinner->text);
	now = get_time() - philo->dinner->start;
	if (status == THINKING)
		printf("%-10lld %-3d %-20s\n", now, philo->index, THINKING_MSG);
	else if (status == SLEEPING)
		printf("%-10lld %-3d %-20s\n", now, philo->index, SLEEPING_MSG);
	else if (status == EATING)
		printf("%-10lld %-3d %-20s\n", now, philo->index, EATING_MSG);
	else if (status == TOOK_FORK)
		printf("%-10lld %-3d %-20s\n", now, philo->index, TOOK_FORK_MSG);
	else if (status == DIED)
		printf("%-10lld %-3d %-20s\n", now, philo->index, DIED_MSG);
	else if (status == SIMULATION_ENDED)
		if (philo->dinner->minimum_meals)
			printf(ATE_MSG, philo->eaten_times);
	pthread_mutex_unlock(&philo->dinner->text);
}
