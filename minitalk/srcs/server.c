/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:59:54 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/20 14:10:26 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	number = 0;
	static int				bits = 0;
	static int				client_pid = 0;

	(void)context;
	client_pid = info->si_pid;
	number |= (sig == SIGUSR1);
	if (++bits == 8)
	{
		bits = 0;
		if (!number)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		write(STDIN_FILENO, &number, 1);
		number = 0;
		kill(client_pid, SIGUSR1);
	}
	else
	{
		number <<= 1;
		kill(client_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sig_action;
	int					pid;

	sig_action.sa_sigaction = &signal_handler;
	sig_action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig_action, NULL);
	sigaction(SIGUSR2, &sig_action, NULL);
	pid = getpid();
	printf("Server PID:[%d]\n", pid);
	while (1)
		;
	return (0);
}
