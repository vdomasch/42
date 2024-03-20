/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:20:28 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/20 11:00:16 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_map_size(t_map *map)
{
	int	len;
	int	i;

	i = 0;
	while (i < map->height)
	{
		len = ft_strlen(map->map[i]);
		if (len != map->width)
			return (1);
		i++;
	}
	return (0);
}

static int	check_map_border(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
		{
			write(STDERR_FILENO, "Wrong width border.\n", 20);
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
		{
			write(STDERR_FILENO, "Wrong height border.\n", 21);
			return (1);
		}
		i++;
	}
	return (0);
}

static void	flood(t_map *m, char **map, int x, int y)
{
	if (map[y][x] == 'C')
		m->reachable_elements += 1;
	map[y][x] = 'X';
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C' || map[y][x + 1] == 'm')
		flood(m, map, x + 1, y);
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C' || map[y][x - 1] == 'm')
		flood(m, map, x - 1, y);
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C' || map[y + 1][x] == 'm')
		flood(m, map, x, y + 1);
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C' || map[y - 1][x] == 'm')
		flood(m, map, x, y - 1);
	if (map[y][x + 1] == 'E' || map[y][x - 1] == 'E'
		|| map[y + 1][x] == 'E' || map[y - 1][x] == 'E')
		m->e_count = 0;
}

static int	reachable(t_map *map)
{
	char	**map_cpy;
	int		i;

	i = 0;
	map_cpy = malloc(sizeof(char *) * map->height);
	while (map->map[i])
	{
		map_cpy[i] = ft_strdup(map->map[i]);
		if (map_cpy[i] == NULL)
		{
			free_all(NULL, NULL, map_cpy);
			return (1);
		}
		i++;
	}
	flood(map, map_cpy, map->player_x, map->player_y);
	while (--i >= 0)
		free(map_cpy[i]);
	free (map_cpy);
	if (map->reachable_elements != map->c_count || map->e_count)
		return (2);
	return (0);
}

int	check_map(t_map *map)
{
	if (check_map_size(map))
		return (write(STDERR_FILENO, "Irregular size.\n", 16));
	if (check_map_border(map))
		return (write(STDERR_FILENO, "Border not standard.\n", 21));
	if (map->e_count != 1 || map->p_count != 1
		|| map-> m_count > 1 || map->c_count < 1)
		return (write(STDERR_FILENO, "Incorrect number of entities\n", 29));
	if (reachable(map))
		return (write(STDERR_FILENO, "Collectible or exit unreachable\n", 32));
	if (map->height > 32)
		return (write(STDERR_FILENO, "Map height too big.\n", 20));
	if (map->width > 60)
		return (write(STDERR_FILENO, "Map width too big.\n", 19));
	return (0);
}
