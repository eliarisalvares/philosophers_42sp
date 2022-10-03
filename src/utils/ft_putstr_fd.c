/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:24:14 by elraira-          #+#    #+#             */
/*   Updated: 2022/09/21 18:12:42 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

/**
 * @brief Outputs the string 's' to the given file descriptor.
 *
 * @param s the string to output.
 * @param fd he file descriptor on which to write. in C, stdin, stdout, and
 * stderr are FILE*, which UNIX respectively map to file descriptors 0, 1 and 2.
 */
void	ft_putstr_fd(const char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}
