/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:20:28 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/29 10:54:33 by vdomasch         ###   ########.fr       */
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
			return (write(1, "Wrong width border.\n", 20));
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			return (write(1, "Wrong height border.\n", 21));
		i++;
	}
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
	return (0);
}
