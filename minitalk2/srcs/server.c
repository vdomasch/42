/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:53:25 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/28 11:03:53 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

char *g_message;

int	alloc_fifty(unsigned int *position, int *bits, unsigned char *c)
{
	static char array[50];
	
	if (*position == 0)
	{
		g_message = malloc(sizeof(char) * 50);
		if (g_message)
			ft_memset(g_message, 0, 50);
		ft_memset(array, 0, 50);
	}
	else
		g_message = ft_strfreejoin(g_message, array);
	if (!g_message)
	{
		*position = 0;
		*bits = 0;
		*c = 0;
		return (1);
	}
	return (0);
}

void	bits_to_str(int sig)
{
	static unsigned int		position = 0;
	static int				bits = 0;
	static unsigned char	c;
	
	if (position % 49 == 0 && bits == 0 && alloc_fifty(&position, &bits, &c) && write(1, "Malloc failed.\n", 15))
		exit (1);
	c |= (sig == 1);
	if (++bits == 8)
	{
		bits = 0;
		if (c == 0)
		{
			write(1, g_message, ft_strlen(g_message));
			position = 0;
			free(g_message);
			return ;
		}
		while (g_message[position])
			position++;
		g_message[position] = c;
		c = 0;
	}
	else
		c <<= 1;
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
