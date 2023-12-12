/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:03:27 by vdomasch          #+#    #+#             */
/*   Updated: 2023/12/12 17:19:53 by vdomasch         ###   ########.fr       */
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

size_t	strendl(const char *str)
{
	size_t	endl;

	endl = 0;
	while (str[endl] && str[endl] != '\n')
		endl++;
	if (str[endl] == '\n')
		endl++;
	return (endl);
}

char	*get_current_line(const char *stack)
{
	size_t		i;
	size_t		endl;
	char		*line;
	char		*str;
	static char	memory[BUFFER_SIZE + 1];

	i = 0;
	str = NULL;
	if (!stack)
	{
		str = ft_strdup(memory);
		while (i <= BUFFER_SIZE + 1)
			memory[i++] = '\0';
		return (str);
	}
	str = ft_strdup(stack);
	endl = strendl(str);
	line = ft_strndup(str, 0, endl);
	i = 0;
	while (str[endl])
		memory[i++] = str[endl++];
	free(str);
	while (i <= BUFFER_SIZE + 1)
		memory[i++] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char	*stack;
	char	*temp;
	char	*line;
	char	buffer[BUFFER_SIZE + 1];
	size_t	i;

	i = 0;
	stack = NULL;
	while (i <= BUFFER_SIZE)
		buffer[i++] = '\0';
	if (fd < 0 || read(fd, buffer, BUFFER_SIZE) == -1 || !buffer[0])
		return (NULL);
	temp = get_current_line(NULL);
	stack = ft_strjoin(temp, buffer);
	free(temp);
	while (!findnline(stack) && !(read(fd, buffer, BUFFER_SIZE) == 0))
	{
		temp = ft_strjoin(stack, buffer);
		free(stack);
		stack = ft_strdup(temp);
		free(temp);
	}
	line = get_current_line(stack);
	return (free(stack), line);
}

/*int	main(void)
{
	int		i;
	int		fd;
	char	*str;

	i = 15;
	fd = open("test.txt", O_RDWR);
	while (i--)
	{
		str = get_next_line(fd);
		//printf("(%zu)", ft_strlen(str));
		printf("%s", str);
		free(str);
	}
	return (0);
}*/
