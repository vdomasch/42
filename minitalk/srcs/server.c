/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:59:54 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/19 16:42:13 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

/*void	bits_to_str(int	*position, int number, pid_t client_pid)
{
	static char		*str;

	if (number == 0)
	{
		usleep(100);
		kill(client_pid, SIGUSR1);
		return ;
	}
	else
		write(1, &number, 1);
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
		usleep(100);
		kill(client_pid, SIGUSR1);
	}
}*/

void	signal_handler(int	sig, siginfo_t *info, void *context)
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
	/*static int	bits = 0;
	static int	position = 0;
	static int	number = 0;
	
	(void)context;
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
}*/

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