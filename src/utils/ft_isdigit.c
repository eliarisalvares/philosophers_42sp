/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 16:22:22 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/16 15:10:08 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

/**
 * @brief checks if the passed character is a decimal digit character -
 * 0 1 2 3 4 5 6 7 8 9.
 *
 * @param c the character to be checked.
 * @return int, this function returns non-zero value if c is a digit, else it
 * returns 0.
 */
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
