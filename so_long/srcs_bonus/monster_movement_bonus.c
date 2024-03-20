/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_movement_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:37:37 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/15 17:22:07 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	monster_move_up(t_data *data, t_map *m, int monster_movement)
{
	mlx_put_image_to_window(data->mlx, data->win, data->f.img,
		m->m_x * 64, m->m_y * 64);
	m->m_y -= 1;
	if (monster_movement % 5 == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->m2.img,
			m->m_x * 64, m->m_y * 64);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->m.img,
			m->m_x * 64, m->m_y * 64);
	data->map.map[m->m_y][m->m_x] = 'm';
	return ('u');
}

static char	monster_move_down(t_data *data, t_map *m, int monster_movement)
{
	mlx_put_image_to_window(data->mlx, data->win, data->f.img,
		m->m_x * 64, m->m_y * 64);
	m->m_y += 1;
	data->movement += 1;
	if (monster_movement % 5 == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->m2.img,
			m->m_x * 64, m->m_y * 64);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->m.img,
			m->m_x * 64, m->m_y * 64);
	data->map.map[m->m_y][m->m_x] = 'm';
	return ('d');
}

static char	monster_move_right(t_data *data, t_map *m, int monster_movement)
{
	mlx_put_image_to_window(data->mlx, data->win, data->f.img,
		m->m_x * 64, m->m_y * 64);
	m->m_x += 1;
	if (monster_movement % 5 == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->m2.img,
			m->m_x * 64, m->m_y * 64);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->m.img,
			m->m_x * 64, m->m_y * 64);
	data->map.map[m->m_y][m->m_x] = 'm';
	return ('r');
}

static char	monster_move_left(t_data *data, t_map *m, int monster_movement)
{
	mlx_put_image_to_window(data->mlx, data->win, data->f.img,
		m->m_x * 64, m->m_y * 64);
	m->m_x -= 1;
	if (monster_movement % 5 == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->m2.img,
			m->m_x * 64, m->m_y * 64);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->m.img,
			m->m_x * 64, m->m_y * 64);
	data->map.map[m->m_y][m->m_x] = 'm';
	return ('l');
}

void	move_monster(t_data *data, t_map *m)
{
	static char	c = 0;
	static int	m_move = 0;

	if (player_dead(data, m))
		return ;
	if (data->map.map[m->m_y - 1][m->m_x] == 'm' && c != 'd')
		c = monster_move_up(data, m, m_move);
	else if (data->map.map[m->m_y + 1][m->m_x] == 'm' && c != 'u')
		c = monster_move_down(data, m, m_move);
	else if (data->map.map[m->m_y][m->m_x + 1] == 'm' && c != 'l')
		c = monster_move_right(data, m, m_move);
	else if (data->map.map[m->m_y][m->m_x - 1] == 'm' && c != 'r')
		c = monster_move_left(data, m, m_move);
	else if (c != 0)
		c = 0;
	else
	{
		c = 1;
		move_monster(data, m);
	}
	m_move++;
	if (player_dead(data, m))
		return ;
}
