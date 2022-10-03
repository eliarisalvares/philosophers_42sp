/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:01:02 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/30 04:18:15 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * @brief This is the routine that the philosopher will follow. It will check
 * first it there's only one philosopher, if so, it will call the function
 * table_for_one.
 * One approach to this problem is to check if the philosopher has an even or
 * odd index and set the priority accordingly. The philosopher with the even
 * will wait until the philosopher with the odd index has finished eating. This
 * is a way to avoid the deadlock problem.
 * After that, if all the philosophers are alive and the simulation hasn't
 * ended, a loop will start. In this loop, we will check if the philosopher is
 * has eaten, if so, it can start sleeping. This is determined by the subject.
 * If the philosopher is not done eating and is no longer sleeping, it will
 * start thinking.
 *
 * @param philo The philosopher struct.
 */
void	*routine(void *philo)
{
	t_philo	*philo_struct;

	philo_struct = (t_philo *)philo;
	if (philo_struct->dinner->total_philos == 1)
		table_for_one(philo_struct);
	else if ((philo_struct->index % 2) == 0)
		delay(1.5);
	while (!check_simulation_end(philo_struct)
		&& philo_struct->dinner->total_philos != 1)
	{
		if (philo_eating(philo_struct) == 1
			&& !check_simulation_end(philo_struct))
			philo_sleeping(philo_struct);
		else
			break ;
		if (!check_simulation_end(philo_struct))
			philo_thinking(philo_struct);
	}
	return (NULL);
}
