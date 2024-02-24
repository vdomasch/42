/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:12:16 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/24 15:11:41 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*void	initialize_struct(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->c_count = 0;
	map->e_count = 0;
	map->p_count = 0;
	map->player_x = 0;
	map->player_y = 0;
}

static void	map_size(t_map *map)
{
	int	i;
	
	i = 0;
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

static void	map_initialize(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map_size(map);
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
				map->c_count++;
			if (map->map[i][j] == 'E')
				map->e_count++;
			if (map->map[i][j] == 'P')
			{
				map->player_x = i;
				map->player_y = j;
				map->p_count++;
			}
			j++;
		}
		i++;
	}
}*/



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

/*int	create_array(t_map *map, const char *location)
{
	int		fd;
	char	*str;
	char	*map_str;

	str = NULL;
	fd = open(location, O_RDONLY);
	if (fd < 0)
		return (0);
	map_str = ft_strdup("");
	if (!map_str)
		return (close(fd));
	while (str || ft_strncmp(map_str, "", 1))
	{
		str = get_next_line(fd);
		map_str = ft_strfreejoin(map_str, str);
		free(str);
		if (!map_str)
			return (close(fd));
	}
	close(fd);
	map->map = ft_split(map_str, '\n');
	return (1);
}*/

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
