/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:35:52 by vdomasch          #+#    #+#             */
/*   Updated: 2023/12/19 13:30:03 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	tmp = NULL;
	empty = 0;
	while (!findnline(stack) && read(fd, buffer, BUFFER_SIZE) > 0)
	{
		tmp = ft_strjoin(stack, buffer);
		free(stack);
		stack = ft_strdup(tmp);
		free(tmp);
		tmp = NULL;
		empty = 1;
	}
	if (!empty)
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
	while (i < endl)
	{
		line[i] = stack[i];
		i++;
	}
	//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            line [i] = '\0';
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
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (NULL);
	if (buffer[0] == '\n')
	{
		extract_memory(buffer);
		line = malloc(sizeof(char) * 2);
		return (line[0] = '\n', line[1] = '\0', line);
	}
	stack = ft_strdup(buffer);
	stack = read_line(fd, buffer, stack);
	if (!stack)
		return (extract_memory(buffer), line = NULL, line);
	line = extract_line(stack);
	extract_memory(buffer);
	free(stack);
	return (line);
}
/*
int	main(void)
{
	int		i;
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDWR);
	i = 13;
	while (i)
	{
		//printf("%d:\n", 16 - i);
		line = get_next_line(fd);
		printf("%s\n", line);
		free(line);
		i--;
	}
	close(fd);
	return (0);
}*/
