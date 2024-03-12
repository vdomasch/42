/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:17:56 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/12 16:11:09 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_data *data, t_map *m)
{
	if (data->map.map[m->player_y - 1][m->player_x] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->f.img,
			m->player_x * 64, m->player_y * 64);
		m->player_y -= 1;
		data->collectible += 1;
		data->movement += 1;
		mlx_put_image_to_window(data->mlx, data->win, data->p.img,
			m->player_x * 64, m->player_y * 64);
		data->map.map[m->player_y][m->player_x] = '0';
	}
	else if (data->map.map[m->player_y - 1][m->player_x] == '0'
		|| data->map.map[m->player_y - 1][m->player_x] == 'P'
		|| data->map.map[m->player_y - 1][m->player_x] == 'm')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->f.img, m->player_x * 64, m->player_y * 64);
		m->player_y -= 1;
		data->movement += 1;
		mlx_put_image_to_window(data->mlx, data->win,
			data->p.img, m->player_x * 64, m->player_y * 64);
	}
}

void	move_down(t_data *data, t_map *m)
{
	if (data->map.map[m->player_y + 1][m->player_x] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->f.img,
			m->player_x * 64, m->player_y * 64);
		m->player_y += 1;
		data->collectible += 1;
		data->movement += 1;
		mlx_put_image_to_window(data->mlx, data->win, data->p.img,
			m->player_x * 64, m->player_y * 64);
		data->map.map[m->player_y][m->player_x] = '0';
	}
	else if (data->map.map[m->player_y + 1][m->player_x] == '0'
		|| data->map.map[m->player_y + 1][m->player_x] == 'P'
		|| data->map.map[m->player_y + 1][m->player_x] == 'm')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->f.img, m->player_x * 64, m->player_y * 64);
		m->player_y += 1;
		data->movement += 1;
		mlx_put_image_to_window(data->mlx, data->win,
			data->p.img, m->player_x * 64, m->player_y * 64);
	}
}

void	move_right(t_data *data, t_map *m)
{
	if (data->map.map[m->player_y][m->player_x + 1] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->f.img,
			m->player_x * 64, m->player_y * 64);
		m->player_x += 1;
		data->collectible += 1;
		data->movement += 1;
		mlx_put_image_to_window(data->mlx, data->win, data->p.img,
			m->player_x * 64, m->player_y * 64);
		data->map.map[m->player_y][m->player_x] = '0';
	}
	else if (data->map.map[m->player_y][m->player_x + 1] == '0'
		|| data->map.map[m->player_y][m->player_x + 1] == 'P'
		|| data->map.map[m->player_y][m->player_x + 1] == 'm')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->f.img,
			m->player_x * 64, m->player_y * 64);
		m->player_x += 1;
		data->movement += 1;
		mlx_put_image_to_window(data->mlx, data->win,
			data->p.img, m->player_x * 64, m->player_y * 64);
	}
}

void	move_left(t_data *data, t_map *m)
{
	if (data->map.map[m->player_y][m->player_x - 1] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->f.img,
			m->player_x * 64, m->player_y * 64);
		m->player_x -= 1;
		data->collectible += 1;
		data->movement += 1;
		mlx_put_image_to_window(data->mlx, data->win, data->p.img,
			m->player_x * 64, m->player_y * 64);
		data->map.map[m->player_y][m->player_x] = '0';
	}
	else if (data->map.map[m->player_y][m->player_x - 1] == '0'
		|| data->map.map[m->player_y][m->player_x - 1] == 'P'
		|| data->map.map[m->player_y][m->player_x - 1] == 'm')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->f.img,
			m->player_x * 64, m->player_y * 64);
		m->player_x -= 1;
		data->movement += 1;
		mlx_put_image_to_window(data->mlx, data->win,
			data->p.img, m->player_x * 64, m->player_y * 64);
	}
}
