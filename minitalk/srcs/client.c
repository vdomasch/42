/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:11:24 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/28 18:08:31 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	g_global;	

void	handler(int sig, siginfo_t *info, void *context)
{
	static size_t	count = 0;

	(void)info;
	(void)context;
	if (sig == SIGUSR1)
	{
		ft_putnbr_fd(count, 1);
		write(1, "\n", 1);
		count++;
	}
	if (sig == SIGUSR2)
	{
		if (count == 0)
			write(1, "Server already used.\n", 21);
		else if (count == 31)
			write(1, "Malloc failed.\n", 15);
		else
			write(1, "Message received.\n", 18);
		exit(0);
	}
	g_global = 1;
}

void	send_size(int pid, const char *str)
{
	int	size;
	int	bits;

	size = 0;
	while (str[size])
		size++;
	bits = 32;
	while (bits--)
	{
		g_global = 0;
		if (size >> bits & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_global)
			;
	}
}

void	str_to_bits(int pid, char *str)
{
	unsigned char	c;
	int				bits;

	send_size(pid, str);
	while (*str)
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
	int					pid;

	if (argc != 3)
		return (write(1, "Invalid number of arguments.\n", 29));
	pid = ft_atoi(argv[2]);
	if (pid < 0 || kill(pid, SIGUSR2) == -1)
		return (write(1, "Invalid PID.\n", 13));
	sig_action.sa_sigaction = &handler;
	sigemptyset(&sig_action.sa_mask);
	sig_action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig_action, NULL);
	sigaction(SIGUSR2, &sig_action, NULL);
	str_to_bits(pid, argv[1]);
	while (1)
		;
	return (0);
}
