/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:11:24 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/15 19:08:21 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int	sig)
{
	if (sig == SIGUSR1)
		write(1, "Message received.\n", 18);
	if (sig == SIGUSR2)
		write(1, "Error.\n", 7);
}

void	str_to_bits(int pid, char *str)
{
	int		i;
	int		size;
	char	c;

	size = 0;
	i = 32;
	while(str[size])
		size++;
	while (--i >= 0)
	{
		printf("%d", size >> i & 1);
		if (size >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(200);
	}
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
			usleep(200);
		}
		str++;
	}
	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR2);
		usleep(200);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int pid;

	if (argc != 3)
		return (write(STDOUT_FILENO, "Invalid number of arguments.\n", 29));
	pid = atoi(argv[2]);
	if (pid < 0)
		return (write(STDOUT_FILENO, "Invalid PID.\n", 13));
	str_to_bits(pid, argv[1]);
	signal(SIGUSR1, &handler);
	signal(SIGUSR2, &handler);
	//while(1)
	//	pause();
	return (0);
}