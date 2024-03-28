/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:59:54 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/26 15:43:02 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

unsigned char	*g_message;

void	allocate_size(int client_pid, unsigned char *number, int *bits, int *position)
{
	g_message = malloc(sizeof(unsigned char) * (*number + 1));
	if (!g_message)
	{
		kill(client_pid, SIGUSR2);
		write(1, "Malloc failed.\n", 15);
		exit(1);
	}
	memset_
	g_message[*number] = '\0';
	*number = 0;
	*bits = 0;
	*position += 1;
//	kill(client_pid, SIGUSR1);
}

void	message(int *client_pid, unsigned char *number, int *bits, int *position)
{
	*bits = 0;
	if (*number == 0)
	{
		write(1, g_message, ft_strlen((char*)g_message));
		kill(*client_pid, SIGUSR2);
		*client_pid = 0;
		*position = 0;
		free(g_message);
		*number = 0;
		return ;
	}
	g_message[(*position) - 1] = *number;
	*number = 0;
	*position += 1;
//	kill(*client_pid, SIGUSR1);
}

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	number = 0;
	static int				bits = 0;
	static int				client_pid = 0;
	static int				position = 0;

	(void)context;
	if (client_pid == 0)
		client_pid = info->si_pid;
	if (info->si_pid != client_pid)
		return ;
	number |= (sig == SIGUSR1);
	if (++bits == 8 && position != 0)
	{
		message(&client_pid, &number, &bits, &position);
	}
	else if (bits == 32 && position == 0)
	{
		allocate_size(client_pid, &number, &bits, &position);
	}
	else
	{
		number <<= 1;
	//	kill(client_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sig_action;
	int					pid;

	sigemptyset(&sig_action.sa_mask);
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
