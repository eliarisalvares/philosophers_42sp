/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:23:34 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/30 04:17:44 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	init_forks_mutex(t_program *program);
static int	alloc_philos(t_program *program);

/**
 * @brief This function is responsible for getting the arguments from the
 * main function and send them to the init_program_struct function which will
 * store them accordingly. Additionally, it will allocate memory for the
 * t_philo struct and the forks mutex and subsequently call the alloc_philos
 * and init_forks_mutex functions to allocate memory for each of the
 * philosophers and initialize their mutexes, making them available for use.
 *
 * @param program The program struct.
 * @param argv The arguments from the main function.
 * @param argc The number of arguments from the main function.
 * @return int Returns 1 if an error occurs, 0 otherwise.
 */
int	parser(t_program *program, char **argv, int argc)
{
	if (init_program_struct(program, argv, argc))
		return (EXIT_FAILURE);
	program->philo
		= malloc(program->dinner.total_philos * sizeof(t_philo *));
	program->philo_forks
		= malloc(program->dinner.total_philos * sizeof(pthread_mutex_t *));
	if (!program->philo || !program->philo_forks)
	{
		ft_putstr_fd(MALLOC_ERROR, STDERROR);
		return (EXIT_FAILURE);
	}
	if (!alloc_philos(program))
		return (EXIT_FAILURE);
	if (!init_forks_mutex(program))
		return (EXIT_FAILURE);
	if (!init_philo_struct(program))
		return (EXIT_FAILURE);
	return (0);
}

/**
 * @brief This function will initialize the forks mutexes using the
 * pthread_mutex_init function. A mutex is a synchronization mechanism
 * used to control access to a shared resource in a concurrent system
 * such as a multitasking operating system.
 *
 * @param program The program struct
 */
static int	init_forks_mutex(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->dinner.total_philos)
	{
		if (pthread_mutex_init(program->philo_forks[i], NULL) != 0)
		{
			ft_putstr_fd(MUTEX_ERROR, STDERROR);
			return (0);
		}
		i++;
	}
	return (1);
}

/**
 * @brief This function will allocate the memory for each of the philos and its
 * forks using the malloc function.
 *
 * @param program The program struct
 */
static int	alloc_philos(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->dinner.total_philos)
	{
		program->philo[i] = malloc(sizeof(t_philo));
		program->philo_forks[i] = malloc(sizeof(pthread_mutex_t));
		if (!program->philo[i] || !program->philo_forks[i])
		{
			ft_putstr_fd(MALLOC_ERROR, STDERROR);
			return (0);
		}
		i++;
	}
	return (1);
}
