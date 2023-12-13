/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:35:52 by vdomasch          #+#    #+#             */
/*   Updated: 2023/12/13 14:04:11 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 5

static int	findnline(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if(str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

static char	*get_current_line(const char *str, int value)
{
	size_t		i;
	size_t		endl;
	char		*line;
	static char	memory[BUFFER_SIZE + 1];

	i = 0;
	if (value == 1)
	{
		endl = findnline(str);
		if (!endl)
			endl = ft_strlen(str);
		line = malloc(sizeof(char) * (endl + 1));
		if (!line)
			return (NULL);
		while (++i < endl)
			line[i] = str[i];
		line[endl] = '\0';
		i = 0;
		while (str[endl])
			memory[i++] = str[endl++];
		return (line);
	}
	return (memory);
}

static char	*read_line(int fd, char* buffer)
{
	char	*temp;
	char	*stack;
	
	stack = get_current_line(stack, 0);
	if (!stack)
		stack = ft_strdup("");
	while (!findnline(stack) && read(fd, buffer, BUFFER_SIZE) != 0)
	{
		temp = ft_strjoin(stack, buffer);
		free(stack);
		stack = ft_strdup(temp);
		free(temp);
	}
	return (stack);
}

char	*get_next_line(int fd)
{
	size_t		i;
	char		*line;
	char		*stack;
	char		buffer[BUFFER_SIZE + 1];
	
	i = 0;
	//stack = get_current_line(stack, 0);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stack = read_line(fd, buffer);
	line = get_current_line(stack, 1);
	free(stack);
	return (line);
}

int	main(void)
{
	int		i;
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDWR);
	i = 15;
	while (i--)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = NULL;
	}
	close(fd);
	return (0);
}