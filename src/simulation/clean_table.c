/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:21:47 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/30 04:18:06 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	clean_philos(t_program *program);

/**
 * @brief This function is used to free the memory allocated for the program
 * to run, clean the structs and destroy the mutexes.
 *
 * @param program The program struct.
 */
void	clean_table(t_program *program)
{
	clean_philos(program);
	pthread_mutex_destroy(&program->dinner.lock_forks);
	pthread_mutex_destroy(&program->dinner.text);
	free(program->philo_forks);
	program->philo_forks = NULL;
	free(program->philo);
	program->philo = NULL;
}

/**
 * @brief This function is used to free the memory allocated for each
 * philosopher, clean the structs and destroy the mutexes.
 *
 * @param program The program struct.
 */
static void	clean_philos(t_program *program)
{
	int	index;

	index = 0;
	while (index < program->dinner.total_philos)
	{
		pthread_mutex_destroy(program->philo_forks[index]);
		free(program->philo_forks[index]);
		program->philo_forks[index] = NULL;
		free(program->philo[index]->philo_forks);
		program->philo[index]->philo_forks = NULL;
		free(program->philo[index]);
		program->philo[index] = NULL;
		index++;
	}
}
