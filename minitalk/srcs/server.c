/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:59:54 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/28 13:55:34 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

unsigned char	*g_message;

void	allocate_size(int client_pid, unsigned int *number, int *bits, int *size_status)
{
	g_message = ft_calloc(sizeof(unsigned char), (*number + 1));
	if (!g_message)
	{
		kill(client_pid, SIGUSR2);
		write(1, "Malloc failed.\n", 15);
		exit(1);
	}
	*number = 0;
	*bits = 0;
	*size_status = 1;
	kill(client_pid, SIGUSR1);
}

void	message(int *client_pid, unsigned char *number, int *bits, int *position)
{
	*bits = 0;
	if (*number == 0)
	{
		write(1, g_message, *position);
		kill(*client_pid, SIGUSR2);
		*client_pid = 0;
		*position = 0;
		free(g_message);
		*number = 0;
		return ;
	}
	g_message[*position] = *number;
	*number = 0;
	*position += 1;
	kill(*client_pid, SIGUSR1);
}

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned int		number = 0;
	static int				bits = 0;
	static int				client_pid = 0;
	static int				position = 0;
	static int				size_status = 0;

	(void)context;
	if (client_pid == 0)
	{
		client_pid = info->si_pid;
		size_status = 0;
	}
	if (info->si_pid != client_pid)
		return ;
	number |= (sig == SIGUSR1);
	if (++bits == 8 && size_status != 0)
		message(&client_pid, (unsigned char *)&number, &bits, &position);
	else if (bits == 32 && size_status == 0)
		allocate_size(client_pid, &number, &bits, &size_status);
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

	sigemptyset(&sig_action.sa_mask);
	sig_action.sa_sigaction = &signal_handler;
	sig_action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig_action, NULL);
	sigaction(SIGUSR2, &sig_action, NULL);
	pid = getpid();
	write(1, "Server PID: [", 13);
	ft_putnbr_fd(pid, 1);
	write(1, "]\n", 2);
	while (1)
		;
	return (0);
}
