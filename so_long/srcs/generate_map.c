/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:22:48 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/08 18:22:00 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_texture(t_data *data, char c, int h, int w)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->w.img, h * 64, w * 64);
	if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->f.img, h * 64, w * 64);
	if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->c.img, h * 64, w * 64);
	if (c == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->p.img, h * 64, w * 64);
	if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->e.img, h * 64, w * 64);

}

int	image_load(t_data *data)
{
	data->w.img = mlx_xpm_file_to_image(data->mlx,
			"./sprites/wall64.xpm", &data->w.img_w, &data->w.img_h);
	data->c.img = mlx_xpm_file_to_image(data->mlx,
			"./sprites/key64.xpm", &data->c.img_w, &data->c.img_h);
	data->e.img = mlx_xpm_file_to_image(data->mlx,
			"./sprites/chest64.xpm", &data->e.img_w, &data->e.img_h);
	data->p.img = mlx_xpm_file_to_image(data->mlx,
			"./sprites/player64.xpm", &data->p.img_w, &data->p.img_h);
	data->f.img = mlx_xpm_file_to_image(data->mlx,
			"./sprites/floor64.xpm", &data->f.img_w, &data->f.img_h);
	if (!data->w.img || !data->c.img || !data->e.img
		|| !data->p.img || !data->f.img)
		return (1);
	return (0);
}

void	map_gen(t_data *data, t_map	*map)
{
	int		h;
	int		w;

	data->collectible = 0;
	if (image_load(data))
	{
		printf("Error load image\n");
		return ;
	}
	h = 0;
	while (map->map[h])
	{
		w = 0;
		while(map->map[h][w])
		{
			put_texture(data, map->map[h][w], h, w);
			w++;
		}
		h++;
	}
}
