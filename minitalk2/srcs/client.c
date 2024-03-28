/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:53:27 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/28 11:10:45 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int		g_pause;
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
		g_message = ft_strfreejoinfifty(g_message, array);
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
			write(1, &g_message[0], ft_strlen(g_message));
			position = 0;
			free(g_message);
			return ;
		}
		printf("%d, %c\n", position, c);
		g_message[position] = c;
		position++;
		printf ("|position: %d, %c\n",position, c);
		c = 0;
	}
	else
		c <<= 1;
}

void	str_to_bits(int pid, char *str)
{
	int	bits;
	unsigned char c;

	(void)pid;
	while (*str)
	{
		c = *str;
		bits = 8;
		while (bits--)
		{
			if (c >> bits & 1)
				bits_to_str(1);
			else
				bits_to_str(0);
		}
		str++;		
	}
	while (++bits < 8)
	{
		bits_to_str(0);
	}
}

int main(int argc, char **argv)
{
	//struct sigaction	sig_action;
	int pid;

	if (argc != 3)
		return (write(1, "Wrong numbe of arguments.\n", 26));
	pid = atoi(argv[1]);
	//if (pid < 0 || kill(pid, SIGUSR2) == -1)
	//	return (write(STDOUT_FILENO, "Invalid PID.\n", 13));
	//sig_action.sa_sigaction = &signal_handler;
	//sigemptyset(&sig_action.sa_mask);
	//sig_action.sa_flags = SA_SIGINFO;
	//sigaction(SIGUSR1, &sig_action, NULL);
	//sigaction(SIGUSR2, &sig_action, NULL);
	str_to_bits(pid, argv[2]);
	/*while (1)
	{
		printf("here\n");
	}*/
	return (0);
}