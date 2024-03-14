/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 07:36:54 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/14 07:37:16 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_all(void *str1, void *str2, char **array)
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
	if (data->f.img)
		mlx_destroy_image(data->mlx, data->f.img);
	if (data->e2.img)
		mlx_destroy_image(data->mlx, data->e2.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_all(data->mlx, NULL, map->map);
}