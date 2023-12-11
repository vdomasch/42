/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:03:27 by vdomasch          #+#    #+#             */
/*   Updated: 2023/12/11 16:09:03 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	findnline(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == '\n')
			return (1);
	}
	return (0);
}

char	*get_line(char *stack)
{
	size_t		i;
	size_t		endl;
	char		*line;
	char		*str;
	static char	memory[BUFFER_SIZE + 1];

	i = 0;
	endl = 0;
	if (memory[0] == '\n')
	{
		while (i + 1 < BUFFER_SIZE)
			memory[i] = memory[i + 1];
		return ("\n\0");
	}
	if (!stack)
		return (NULL);
	if (memory[0] != '\0')
		str = ft_strjoin(memory, stack);
	else 
		str = ft_strdup(stack);
	while (str[endl] && str[endl] != '\n')
		endl++;
	line = ft_strndup(str, 0, endl);
	i = 0;
	while (str[endl++])
		memory[i] = str[endl++];
	while (i < BUFFER_SIZE + 1)
		memory[i++] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	int		i;
	char	*stack;
	char	*temp;
	char	buffer[BUFFER_SIZE + 1];

	i = 0;
	if (read(fd, buffer, 0) == -1)
		return (NULL);
	stack = get_line(NULL);
	if (stack == NULL)
		stack = ft_strdup(buffer);
	while (!findnline(stack) && read(fd, buffer, BUFFER_SIZE) != 0)
	{
		temp = ft_strjoin(stack, buffer);
		free(stack);
		stack = ft_strdup(temp);
		free(temp);
	}
	return (get_line(stack));
}

int main(void)
{
	int	i = 11;
	int	fd;
	
	fd = open("test.txt", O_RDWR);
	while (i--)
	{
		printf("%s", get_next_line(fd));
	}
	return (0);		
}