/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:35:52 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/02 08:28:52 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	findnline(const char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '\n')
				return (i + 1);
			i++;
		}
	}
	return (0);
}

static char	*read_line(int fd, char *buffer, char *stack)
{
	char	*tmp;
	int		empty;
	int		value;

	empty = 0;
	value = 1;
	while (!findnline(stack) && value > 0)
	{
		value = read(fd, buffer, BUFFER_SIZE);
		if (value != -1)
			buffer[value] = '\0';
		if (value > 0)
		{
			tmp = ft_strjoin(stack, buffer);
			if (stack)
				free(stack);
			stack = ft_strdup(tmp);
			if (tmp)
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
	if (!line)
		return (NULL);
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
	if (endl)
	{
		while (buffer[endl])
			buffer[i++] = buffer[endl++];
		while (i <= BUFFER_SIZE)
			buffer[i++] = '\0';
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*stack;
	static char	buffer[1005][BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer[fd], 0) < 0 || fd > 1004)
		return (NULL);
	if (buffer[fd][0] == '\n')
	{
		extract_memory(buffer[fd]);
		return (line_feed());
	}
	stack = ft_strdup(buffer[fd]);
	stack = read_line(fd, buffer[fd], stack);
	if (!stack)
	{
		extract_memory(buffer[fd]);
		return (NULL);
	}
	line = extract_line(stack);
	extract_memory(buffer[fd]);
	free(stack);
	return (line);
}

// int	main(void)
// {
// 	int		i;
// 	int		fd;
//	int		fd1;
// 	char	*line;

// 	fd = open("test.txt", O_RDWR);
//	fd1 = open("", O_RDWR);
// 	i = 3;
// 	while (i)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
//		line = get_next_line(fd1);
// 		printf("%s", line);
// 		free(line);
// 		i--;
// 	}
// 	close(fd);
// 	return (0);
// }
