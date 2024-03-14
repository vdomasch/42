/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:17:56 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/14 07:10:16 by vdomasch         ###   ########.fr       */
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
		|| data->map.map[m->player_y - 1][m->player_x] == 'P')
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
		|| data->map.map[m->player_y + 1][m->player_x] == 'P')
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
		|| data->map.map[m->player_y][m->player_x + 1] == 'P')
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
		|| data->map.map[m->player_y][m->player_x - 1] == 'P')
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
		write(STDOUT_FILENO, "Movement: ", 10);
		move = ft_itoa(data->movement);
		if (move)
		{
			write(STDOUT_FILENO, move, ft_strlen(move));
			free(move);
		}
		write(STDOUT_FILENO, "\n", 1);
	}
}
