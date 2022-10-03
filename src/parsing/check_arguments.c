/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:40:11 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/30 04:13:55 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * @brief This function checks if the given arguments for './philo' are valid.
 *
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @return int Returns 1 if the arguments are valid, 0 otherwise.
 */
int	check_arguments(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < ARG_MIN || argc > ARG_MAX)
	{
		ft_putstr_fd(ARG_NUM_ERROR, STDERROR);
		return (0);
	}
	while (argv[i])
	{
		if (!ft_str_isdigit(argv[i]) || ft_atoi(argv[i]) <= 0
			|| ft_atoi(argv[i]) > INT_MAX)
		{
			ft_putstr_fd(ARG_VALUE_ERROR, STDERROR);
			return (0);
		}
		i++;
	}
	if (ft_atoi(argv[1]) > 200)
	{
		ft_putstr_fd(ARG_MAX_ERROR, STDERROR);
		return (0);
	}
	return (1);
}
