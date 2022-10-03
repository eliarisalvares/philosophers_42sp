/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:12:51 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/30 04:16:02 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	*define(int variable, t_program *program);

/**
 * @brief This function is responsible for initializing the program struct. It
 * will take the arguments from the command line and store them in the struct.
 * It will also initialize the mutexes of said struct. If the user gave a sixth
 * argument, it will set the minimum number of meals to be eaten by each
 * philosopher according to the user's input. If the user did not give a sixth
 * argument, it will set the minimum number of meals to -1, which means that the
 * philosophers will not stop eating (unless they die).
 *
 * @param program The program struct.
 * @param argv The arguments from the command line.
 * @param argc The number of arguments from the command line.
 * @return int Returns 0 if successful, 1 if not.
 */
int	init_program_struct(t_program *program, char **argv, int argc)
{
	int	i;
	int	*aux;

	i = 0;
	while (i < argc)
	{
		aux = define(i, program);
		*aux = ft_atoi(argv[i]);
		i++;
	}
	if (argc == 6)
		program->dinner.minimum_meals = ft_atoi(argv[5]);
	else
		program->dinner.minimum_meals = -1;
	program->dinner.philo_died = 0;
	if (pthread_mutex_init(&program->dinner.lock_forks, NULL) != 0
		|| pthread_mutex_init(&program->dinner.text, NULL) != 0)
	{
		ft_putstr_fd(MUTEX_ERROR, STDERROR);
		return (EXIT_FAILURE);
	}
	return (0);
}

/**
 * @brief This function will take each argument from the command line by index
 * and assign it to the correct variable in the program struct.
 *
 * @param argc The index of the argument in the command line.
 * @param program The program struct.
 * @return int* The address of the variable in the program struct.
 */
static int	*define(int argc, t_program *program)
{
	if (argc == 1)
		return (&program->dinner.total_philos);
	else if (argc == 2)
		return (&program->dinner.time_to_die);
	else if (argc == 3)
		return (&program->dinner.time_to_eat);
	else if (argc == 4)
		return (&program->dinner.time_to_sleep);
	else
		return (&program->dinner.minimum_meals);
}
