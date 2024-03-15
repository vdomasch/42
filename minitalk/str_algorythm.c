#include "minitalk.h"
#include <signal.h>
/*
#define SIGUSR1 1
#define SIGUSR2 2
*/

void	bits_to_str(int	position, int number)
{
	static char		*str;
	
	if (position == 0)
	{
		str = malloc(sizeof(char) * (number + 1));
		if (!str)
			return ;
		str[number] = '\0';
	}
	else
	{
		str[position - 1] = number;
	}
	if (number == 0)
	{
		write(STDIN_FILENO, str, strlen(str));
	}
}

void	handler(int sig)
{
	static int	bits;
	static int	position;
	static int	number;
	
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
	if (bits == 8)
	{
		printf("%d\n", number);
		bits_to_str(position, number);
		bits = 0;
		number = 0;
		position++;
	}
	
}

void	str_to_bits(char *str)
{
	int		i;
	int		size;
	char	c;

	size = 0;
	i = 8;
	while(str[size])
		size++;
	while (--i >= 0)
	{
		if (size >> i & 1)
				handler(SIGUSR1);
			else
				handler(SIGUSR2);
	}
	while(*str)
	{
		i = 8;
		c = *str;
		while (--i >= 0)
		{
			if (c >> i & 1)
				handler(SIGUSR1);
			else
				handler(SIGUSR2);
		}
		str++;
	}
	while (i < 8)
	{
		handler(SIGUSR2);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return(write(1, "argc\n", 5));
	str_to_bits(argv[1]);
	
		
}
