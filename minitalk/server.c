/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:59:54 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/15 19:05:46 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bits_to_str(int	*position, int number, pid_t client_pid)
{
	static char		*str;

	if (*position == 0)
	{
		str = malloc(sizeof(char *) * (number + 1));
		if (!str)
		{
			kill(client_pid, SIGUSR2);
			return ;
		}
		str[number] = '\0';
	}
	else
		str[*position - 1] = number;
	if (number == 0)
	{
		write(STDIN_FILENO, str, strlen(str));
		*position = -1;
		//usleep(100);
		//kill(client_pid, SIGUSR1);
	}
}

void	signal_handler(int	sig, siginfo_t *info, void *context)
{
	static int	bits = 0;
	static int	position = 0;
	static int	number = 0;
	
	(void*)context;
	if (sig == SIGUSR1)
	{
		number = number << 1;
		number += 1;
		bits++;
	}
	if (sig == SIGUSR2)
	{
		number = number << 1;
		bits++;
	}
	if (bits == 8 && position > 0)
	{
		bits_to_str(&position, number, info->si_pid);
		bits = 0;
		position++;
		number = 0;
	}
	if (bits == 32)
	{
		bits_to_str(&position, number, info->si_pid);
		position++;
		bits = 0;
		number = 0;
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