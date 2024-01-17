/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:35:52 by vdomasch          #+#    #+#             */
/*   Updated: 2023/12/19 17:48:21 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	findnline(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

static char	*read_line(int fd, char *buffer, char *stack)
{
	char	*tmp;
	size_t	empty;
	size_t	value;

	empty = 0;
	value = 1;
	while (!findnline(stack) && value > 0)
	{
		value = read(fd, buffer, BUFFER_SIZE);
		buffer[value] = '\0';
		if (value > 0)
		{
			tmp = ft_strjoin(stack, buffer);
			free(stack);
			stack = ft_strdup(tmp);
			free(tmp);
			empty = 1;
		}
	}
	if (!empty && !stack[0])
		return (free(stack), NULL);
	return (stack);
}

static char	*extract_line(char	*stack)
{
	size_t	i;
	size_t	endl;
	char	*line;

	i = 0;
	endl = findnline(stack);
	if (!endl)
		return (ft_strdup(stack));
	line = malloc(sizeof(char) * (endl + 1));
	line[endl] = '\0';
	while (i < endl)
	{
		line[i] = stack[i];
		i++;
	}
	return (line);
}

static void	extract_memory(char buffer[BUFFER_SIZE + 1])
{
	size_t	i;
	size_t	endl;

	i = 0;
	endl = findnline(buffer);
	while (buffer[endl])
		buffer[i++] = buffer[endl++];
	while (i <= BUFFER_SIZE)
		buffer[i++] = '\0';
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*stack;
	static char	buffer[1005][BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer[fd], 0) < 0)
		return (NULL);
	if (buffer[fd][0] == '\n')
	{
		extract_memory(buffer[fd]);
		line = malloc(sizeof(char) * 2);
		return (line[0] = '\n', line[1] = '\0', line);
	}
	stack = ft_strdup(buffer[fd]);
	stack = read_line(fd, buffer[fd], stack);
	if (!stack)
		return (extract_memory(buffer[fd]), line = NULL, line);
	line = extract_line(stack);
	extract_memory(buffer[fd]);
	free(stack);
	return (line);
}

/*int	main(void)
{
	int		i;
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDWR);
	i = 3;
	while (i)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i--;
	}
	close(fd);
	return (0);
}*/