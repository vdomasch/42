/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:20:28 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/11 20:04:40 by vdomasch         ###   ########.fr       */
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
			write(1, "Wrong width border.\n", 20);
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
		{
			write(1, "Wrong height border.\n", 21);
			return (1);
		}
		i++;
	}
	return (0);
}

static void	flood(t_map *m, char **map, int x, int y)
{
	if (map[x][y] == 'C')
		m->reachable_elements += 1;
	map[x][y] = 'X';
	if (map[x + 1][y] == '0' || map[x + 1][y] == 'C')
		flood(m, map, x + 1, y);
	if (map[x - 1][y] == '0' || map[x - 1][y] == 'C')
		flood(m, map, x - 1, y);
	if (map[x][y + 1] == '0' || map[x][y + 1] == 'C')
		flood(m, map, x, y + 1);
	if (map[x][y - 1] == '0' || map[x][y - 1] == 'C')
		flood(m, map, x, y - 1);
	if (map[x + 1][y] == 'E' || map[x - 1][y] == 'E'
		|| map[x][y + 1] == 'E' || map[x][y - 1] == 'E')
		m->e_count = 0;
}

static int	reachable(t_map *map)
{
	char	**map_cpy;
	int		x;

	x = 0;
	map_cpy = malloc(sizeof(char *) * map->height);
	while (map->map[x])
	{
		map_cpy[x] = ft_strdup(map->map[x]);
		if (map_cpy[x] == NULL)
		{
			free_all(NULL, NULL, map_cpy);
			return (1);
		}
		x++;
	}
	flood(map, map_cpy, map->player_x, map->player_y);
	while (--x >= 0)
		free(map_cpy[x]);
	free (map_cpy);
	if (map->reachable_elements != map->c_count || map->e_count)
		return (2);
	return (0);
}

int	check_map(t_map *map)
{
	if (check_map_size(map))
	{
		write(1, "Irregular size.\n", 16);
		return (1);
	}
	if (check_map_border(map))
	{
		write(1, "Border not standard.\n", 21);
		return (2);
	}
	if (map->e_count != 1 || map->p_count != 1 || map->c_count < 1)
	{
		write(1, "Incorrect number of entities\n", 29);
		return (3);
	}
	if (reachable(map))
	{
		write(1, "Collectible or exit unreachable\n", 32);
		return (4);
	}
	return (0);
}
