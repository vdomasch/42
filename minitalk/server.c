/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:59:54 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/14 13:15:31 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <unistd.h>

void	bits_to_str(int	position, int number)
{
	static char		*str;

	if (position == 0)
	{
		str = malloc(sizeof(char *) * (number + 1));
		if (!str)
			return ;
		str[position] = '\0';
	}
	else
		str[position] = number;
	if (number == 0)
	{
		write(STDIN_FILENO, str, strlen(str));
		kill(pid, SIGUSR1);
	}
}

void	signal_handler(int	sig, siginfo_t *info)
{
	static int	bits;
	static int	position;
	int	number;
	
	number = 0;
	if (sig == SIGUSR1)
	{
		printf("SIGUSR1\n");
		number = number << 1;
		number += 1;
		bits++;
	}
	if (sig == SIGUSR2)
	{
		printf("SIGUSR2\n");
		number = number << 1;
		bits++;
	}
	if (bits == 8)
	{
		bits_to_str(position, number);
		bits = 0;
		position++;
	}
	
}

int	main(void)
{
	struct sigaction	sig_action;
	int					pid;
	 
	pid = getpid();
	printf("Server PID:[%d]\n", pid);
	sig_action.sa_sigaction = &signal_handler;
	sig_action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig_action, NULL);
	sigaction(SIGUSR2, &sig_action, NULL);
	while (1)
		pause();
	return (0);
}