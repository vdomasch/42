/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:17:56 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/13 19:00:30 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	move_up(t_data *data, t_map *m)
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

static void	move_down(t_data *data, t_map *m)
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

static void	move_right(t_data *data, t_map *m)
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

static void	move_left(t_data *data, t_map *m)
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

void	move_player(int keysym, t_data *data)
{
	int		temp;
	char	*move;

	temp = data->movement;
	if (keysym == XK_w || keysym == XK_Up)
		move_up(data, &data->map);
	else if (keysym == XK_s || keysym == XK_Down)
		move_down(data, &data->map);
	else if (keysym == XK_d || keysym == XK_Right)
		move_right(data, &data->map);
	else if (keysym == XK_a || keysym == XK_Left)
		move_left(data, &data->map);
	if (data->movement != temp)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->w.img, 0, 0);
		mlx_string_put(data->mlx, data->win, 4, 13, 0x922B21, "Move: ");
		move = ft_itoa(data->movement);
		if (move)
		{
			mlx_string_put(data->mlx, data->win, 36, 13, 0x922B21, move);
			free(move);
		}
		write(1, "\n", 1);
	}
}
