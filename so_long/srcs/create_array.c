/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:12:16 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/15 16:32:17 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	map_init(t_map *map)
{
	int	i;

	i = 0;
	map->height = 0;
	map->width = 0;
	map->c_count = 0;
	map->e_count = 0;
	map->p_count = 0;
	map->reachable_elements = 0;
	map->player_x = 0;
	map->player_y = 0;
	if (map)
	{
		while (map->map[i])
			i++;
		map->height = i;
		i = 0;
		while (map->map[0][i])
			i++;
		map->width = i;
	}
}

static void	save_position(t_map *map, int x, int y, char c)
{
	if (c == 'e')
	{
		map->exit_x = x;
		map->exit_y = y;
		map->e_count++;
	}
	if (c == 'p')
	{
		map->player_x = x;
		map->player_y = y;
		map->p_count++;
	}
}

int	map_state(t_map *map)
{
	size_t	i;
	size_t	j;

	map_init(map);
	if (map->height > 32 || map->width > 60)
		return (1);
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
				map->c_count++;
			else if (map->map[i][j] == 'E')
				save_position(map, j, i, 'e');
			else if (map->map[i][j] == 'P')
				save_position(map, j, i, 'p');
			else if (map->map[i][j] != '1' && map->map[i][j] != '0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static char	*read_file(char *map_extract, int fd)
{
	int		rd;
	char	buffer[1025];

	if (!map_extract)
		return (NULL);
	rd = 1024;
	while (rd == 1024)
	{
		rd = read(fd, buffer, 1024);
		if (rd < 0)
		{
			free(map_extract);
			return (NULL);
		}
		buffer[rd] = '\0';
		map_extract = ft_strfreejoin(map_extract, buffer);
		if (map_extract == NULL)
			return (NULL);
	}
	return (map_extract);
}

int	create_array(t_map *map, const char *filename)
{
	int		fd;
	char	*map_extract;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	map_extract = ft_calloc(sizeof(char), 1);
	map_extract = read_file(map_extract, fd);
	if (!map_extract)
	{
		close(fd);
		return (1);
	}
	map->map = ft_split(map_extract, '\n');
	free(map_extract);
	close(fd);
	return (0);
}
