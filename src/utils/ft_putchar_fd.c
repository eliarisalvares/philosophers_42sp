/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:12:07 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/21 16:55:44 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

/**
 * @brief Outputs the character 'c' to the given file descriptor.
 *
 * @param c the character to output.
 * @param fd the file descriptor on which to write. in C, stdin, stdout, and
 * stderr are FILE*, which UNIX respectively map to file descriptors 0, 1 and 2.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
