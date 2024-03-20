/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:11:24 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/19 16:42:15 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	g_global;	

void	handler(int	sig, siginfo_t *info, void *context)
{
	static int	received;

	g_global = 1;
	(void)info;
	(void)context;	
	if (sig == SIGUSR1)
		received++;
	if (sig == SIGUSR2)
	{
		printf("Received: %d\n", received/8);
		exit(0);
	}
}

void	str_to_bits(int pid, char *str)
{
	//int		i;
	int		bits;
	//int		size;
	unsigned char	c;

	/*size = 0;
	i = 32;
	while(str[size])
		size++;
	while (--i >= 0)
	{
		if (size >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
	}*/
	//i = 0;
	printf("Send: %d\n", (int)strlen(str));
	while(*str)
	{
		c = *str;
		bits = 8;
		while (bits--)
		{
			g_global = 0;
			if (c >> bits & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (!g_global)
				;
		}
		str++;
	}
	bits = 0;
	while (bits++ < 8)
	{
		g_global = 0;
		kill(pid, SIGUSR2);
		while (!g_global)
			;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sig_action;
	int pid;

	if (argc != 3)
		return (write(STDOUT_FILENO, "Invalid number of arguments.\n", 29));
	pid = atoi(argv[2]);
	if (pid < 0)
		return (write(STDOUT_FILENO, "Invalid PID.\n", 13));
	sig_action.sa_sigaction = &handler;
	sigemptyset(&sig_action.sa_mask);
	sig_action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig_action, NULL);
	sigaction(SIGUSR2, &sig_action, NULL);
	str_to_bits(pid, argv[1]);
	while(1)
		;
	return (0);
}