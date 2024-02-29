/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:12:16 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/29 10:55:53 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_init(t_map *map)
{
	int	i;
	
	i = 0;
	map->height = 0;
	map->width = 0;
	map->c_count = 0;
	map->e_count = 0;
	map->p_count = 0;
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

void	map_state(t_map *map)
{
	size_t	i;
	size_t	j;

	map_init(map);
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
				map->c_count++;
			else if (map->map[i][j] == 'E')
				map->e_count++;
			else if (map->map[i][j] == 'P')
			{
				map->player_x = i;
				map->player_y = j;
				map->p_count++;
			}
			j++;
		}
		i++;
	}
}

int	create_array(t_map *map, const char *filename)
{
	int		fd;
	int		rd;
	char	buff[1025];
	char	*map_extract;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (close(fd));
	rd = 1024;
	map_extract = calloc(sizeof(char), 1);
	if (map_extract == NULL)
		return (close(fd));
	while (rd == 1024)
	{
		rd = read(fd, buff, 1024);
		if (rd < 0)
			return (free(map_extract), close(fd));
		buff[rd] = 0;
		map_extract = ft_strfreejoin(map_extract, buff);
		if (map_extract == NULL)
			return (close(fd));
	}
	map->map = ft_split(map_extract, '\n');
	free(map_extract);
	return (close (fd) + 1);
}

void	free_all(char	*str1, char *str2, char **array)
{
	int	i;

	if (str1)
		free(str1);
	if (str2)
		free(str2);
	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	return ;
}
