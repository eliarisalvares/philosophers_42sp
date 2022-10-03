/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:22:22 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/27 17:51:31 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * @brief This is the main function. It will check if the arguments are valid,
 * parse them and initialize all data structures. Then it will create the
 * threads and wait for them to finish using the start_simulation function.
 * Once the simulation is over, it will free all the allocated memory, clean
 * the structures and destroy the mutexes.
 *
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @return int Returns 0 if the simulation is successful. Otherwise, it will
 * return 1 (EXIT_FAILURE).
 */
int	main(int argc, char **argv)
{
	t_program	program;

	if (!check_arguments(argc, argv))
		return (EXIT_FAILURE);
	if (parser(&program, argv, argc))
		return (EXIT_FAILURE);
	if (!start_simulation(&program))
		return (EXIT_FAILURE);
	clean_table(&program);
	return (0);
}
