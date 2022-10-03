/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:44:02 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/30 15:09:28 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	assign_forks(t_program *program, int i);
static int	is_lastphilo(t_program *program, int i);

/**
 * @brief This function is responsible for initializing the philosopher struct
 * and its variables. If the number of philosophers is even, the first one will
 * always be the left fork. This is done to avoid deadlocks.
 * @param program The program struct.
 */
int	init_philo_struct(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->dinner.total_philos)
	{
		program->philo[i]->dinner = &program->dinner;
		program->philo[i]->index = i + 1;
		program->philo[i]->eaten_times = 0;
		program->philo[i]->philo_forks = malloc(2 * sizeof(pthread_mutex_t *));
		if (!program->philo[i]->philo_forks)
		{
			ft_putstr_fd(MALLOC_ERROR, STDERROR);
			return (0);
		}
		program->philo[i]->philo_forks[FIRST_FORK] = program->philo_forks[i];
		program->philo[i]->philo_forks[SECOND_FORK]
			= program->philo_forks[(i + 1)];
		if (is_lastphilo(program, i))
			assign_forks(program, i);
		program->philo[i]->last_meal = 0;
		i++;
	}
	return (1);
}

/**
 * @brief This function is responsible for assign the forks of the last
 * philosopher.
 *
 * @param program The program struct.
 * @param i The current philosopher.
 */
static void	assign_forks(t_program *program, int i)
{
	program->philo[i]->philo_forks[SECOND_FORK]
		= program->philo[i]->philo_forks[FIRST_FORK];
	program->philo[i]->philo_forks[FIRST_FORK]
		= program->philo_forks[0];
}

/**
 * @brief This function will return 1 if the current philosopher is the last 
 * one in the table, and 0 otherwise.
 *
 * @param program The program struct.
 * @param i The index of the current philosopher.
 * @return int 1 if the current philosopher is the last one in the table, 
 * and 0 otherwise.
 */
static int	is_lastphilo(t_program *program, int i)
{
	if ((i + 1) % program->dinner.total_philos == 0)
		return (1);
	return (0);
}
