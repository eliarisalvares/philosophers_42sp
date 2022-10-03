/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:32:19 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/30 04:18:27 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	create_threads(t_program *program);
static int	join_threads(t_program *program);

/**
 * @brief This function is responsible for starting the simulation. It will
 * set the start time of the dinner and then it will create the threads for
 * each philosopher. It will also create a monitor thread to check if the
 * dinner is over. After the creation of the threads, it will join them which
 * means that it will wait for them to finish.
 *
 * @param program The program struct.
 */
int	start_simulation(t_program *program)
{
	pthread_t	monitor;

	program->dinner.start = get_time();
	if (!create_threads(program))
		return (0);
	if (pthread_create(&monitor, NULL, &monitor_routine,
			(void *)program->philo) != 0)
	{
		ft_putstr_fd(THREAD_ERROR, STDERROR);
		return (0);
	}
	if (!join_threads(program))
		return (0);
	if (pthread_join(monitor, NULL) != 0)
	{
		ft_putstr_fd(JOIN_ERROR, STDERROR);
		return (0);
	}
	return (1);
}

/**
 * @brief This function will create the threads for each philosopher.
 *
 * @param program The program struct.
 */
static int	create_threads(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->dinner.total_philos)
	{
		if (pthread_create(&program->philo[i]->thread, NULL, &routine,
				(void *)program->philo[i]) != 0)
		{
			ft_putstr_fd(THREAD_ERROR, STDERROR);
			return (0);
		}
		i++;
	}
	return (1);
}

/**
 * @brief This function will join the threads for each philosopher. The
 * pthread_join function will wait for the created threads to terminate.
 *
 * @param program The program struct.
 */
static int	join_threads(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->dinner.total_philos)
	{
		if (pthread_join(program->philo[i]->thread, NULL) != 0)
		{
			ft_putstr_fd(JOIN_ERROR, STDERROR);
			return (0);
		}
		i++;
	}
	return (1);
}
