/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:11:24 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/14 13:12:49 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

void	handler(int	sig)
{
	if (sig == SIGUSR1)
		write(STDIN_FILENO, "Signal received.\n", 17);
}

void	str_to_bits(int pid, char *str)
{
	int		i;
	char	c;

	while(*str)
	{
		i = 8;
		c = *str;
		while (--i >= 0)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(500);
			printf("%d\n", SIGUSR1);
		}
		str++;
	}
	while (i < 8)
	{
		kill(pid, SIGUSR2);
		usleep(500);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int pid;

	if (argc != 3)
		return (write(STDOUT_FILENO, "Invalid number of arguments.\n", 29));
	pid = atoi(argv[1]);
	if (pid < 0)
		return (write(STDOUT_FILENO, "Invalid PID.\n", 13));
	str_to_bits(pid, argv[2]);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
}