/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:07:25 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/15 17:22:46 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	player_dead(t_data *data, t_map *m)
{
	if (m->player_x == m->m_x && m->player_y == m->m_y)
	{
		write(STDOUT_FILENO, "You are dead.\n", 14);
		mlx_loop_end(data->mlx);
		return (1);
	}
	return (0);
}

void	*free_all(void *str1, void *str2, char **array)
{
	int	i;

	if (str1)
		free(str1);
	if (str2)
		free(str2);
	if (!array)
		return (NULL);
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	return (NULL);
}

void	clean(t_data *data, t_map *map)
{
	if (data->w.img)
		mlx_destroy_image(data->mlx, data->w.img);
	if (data->c.img)
		mlx_destroy_image(data->mlx, data->c.img);
	if (data->e.img)
		mlx_destroy_image(data->mlx, data->e.img);
	if (data->p.img)
		mlx_destroy_image(data->mlx, data->p.img);
	if (data->p2.img)
		mlx_destroy_image(data->mlx, data->p2.img);
	if (data->f.img)
		mlx_destroy_image(data->mlx, data->f.img);
	if (data->e2.img)
		mlx_destroy_image(data->mlx, data->e2.img);
	if (data->m.img)
		mlx_destroy_image(data->mlx, data->m.img);
	if (data->m2.img)
		mlx_destroy_image(data->mlx, data->m2.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_all(data->mlx, NULL, map->map);
}
