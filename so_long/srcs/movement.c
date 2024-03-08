/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:17:56 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/08 15:54:40 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_data *data, t_map *m)
{
	printf("Up | x:%d, y:%d\n", m->player_x, m->player_y);
	if (data->map.map[m->player_x][m->player_y - 1] == '1')
		return ;
	if (data->map.map[m->player_x][m->player_y - 1] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->f.img, m->player_x * 64, m->player_y * 64);
		m->player_y -= 1;
		data->collectible +=1;
		data->movement += 1;
		mlx_put_image_to_window(data->mlx, data->win, data->p.img, m->player_x * 64, m->player_y * 64);
	}
	if (data->map.map[m->player_x][m->player_y - 1] == 'E')
		return ;
	if (data->map.map[m->player_x][m->player_y - 1] == '0' || data->map.map[m->player_x][m->player_y - 1] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->f.img, m->player_x * 64, m->player_y * 64);
		m->player_y -= 1;
		data->movement += 1;
		mlx_put_image_to_window(data->mlx, data->win, data->p.img, m->player_x * 64, m->player_y * 64);
	}
}

void	move_down(t_data *data, t_map *m)
{
	printf("Down\n");
	if (data->map.map[m->player_x][m->player_y + 1] == '1' || data->map.map[m->player_x][m->player_y + 1] == 'E')
		return ;
	if (data->map.map[m->player_x][m->player_y + 1] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->f.img, m->player_x * 64, m->player_y * 64);
		m->player_y += 1;
		data->collectible +=1;
		data->movement += 1;
		mlx_put_image_to_window(data->mlx, data->win, data->p.img, m->player_x * 64, m->player_y * 64);
	}
	if (data->map.map[m->player_x][m->player_y + 1] == '0' || data->map.map[m->player_x][m->player_y + 1] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->f.img, m->player_x * 64, m->player_y * 64);
		m->player_y += 1;
		data->movement += 1;
		mlx_put_image_to_window(data->mlx, data->win, data->p.img, m->player_x * 64, m->player_y * 64);
	}
}

void	move_right(t_data *data, t_map *m)
{
	printf("Right\n");
	if (data->map.map[m->player_x + 1][m->player_y] == '1')
		return ;
	if (data->map.map[m->player_x + 1][m->player_y] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->f.img, m->player_x * 64, m->player_y * 64);
		m->player_x += 1;
		data->collectible +=1;
		data->movement += 1;
		mlx_put_image_to_window(data->mlx, data->win, data->p.img, m->player_x * 64, m->player_y * 64);
	}
	if (data->map.map[m->player_x + 1][m->player_y] == 'E')
		return ;
	if (data->map.map[m->player_x + 1][m->player_y] == '0' || data->map.map[m->player_x + 1][m->player_y] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->f.img, m->player_x * 64, m->player_y * 64);
		m->player_x += 1;
		data->movement += 1;
		mlx_put_image_to_window(data->mlx, data->win, data->p.img, m->player_x * 64, m->player_y * 64);
	}
}

void	move_left(t_data *data, t_map *m)
{
	printf("Left\n");
	if (data->map.map[m->player_x - 1][m->player_y] == '1')
		return ;
	if (data->map.map[m->player_x - 1][m->player_y] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->f.img, m->player_x * 64, m->player_y * 64);
		m->player_x -= 1;
		data->collectible +=1;
		data->movement += 1;
		mlx_put_image_to_window(data->mlx, data->win, data->p.img, m->player_x * 64, m->player_y * 64);
	}
	if (data->map.map[m->player_x - 1][m->player_y] == 'E')
		return ;
	if (data->map.map[m->player_x - 1][m->player_y] == '0' || data->map.map[m->player_x - 1][m->player_y] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->f.img, m->player_x * 64, m->player_y * 64);
		m->player_x -= 1;
		data->movement += 1;
		mlx_put_image_to_window(data->mlx, data->win, data->p.img, m->player_x * 64, m->player_y * 64);
	}
}
