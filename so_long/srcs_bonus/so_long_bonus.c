/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:58:28 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/14 07:14:18 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_loop_end(data->mlx);
	move_player(keysym, data);
	if (data->collectible == data->map.c_count)
	{
		put_texture(data, 'e', data->map.exit_y, data->map.exit_x);
		data->map.map[data->map.exit_y][data->map.exit_x] = '0';
	}
	if (data->map.player_x == data->map.exit_x
		&& data->map.player_y == data->map.exit_y)
		{
			write(STDOUT_FILENO, "You won the game!", 18);
			mlx_loop_end(data->mlx);
		}
	if (data->map.m_count == 1)
		move_monster(data, &data->map);
	return (0);
}

int	mlx_part(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "My project!");
	if (!data->win)
	{
		mlx_destroy_display(data->mlx);
		return (2);
	}
	map_gen(data, &data->map);
	mlx_hook(data->win, 17, 1L << 2, mlx_loop_end, data->mlx);
	mlx_hook(data->win, 2, 1L << 0, keypress, data);
	mlx_loop(data->mlx);
	clean(data, &data->map);
	
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		write(STDERR_FILENO, "INVALID NUMBER OF ARGUMENTS\n", 28);
		return (1);
	}
	if (create_array(&data.map, argv[1]))
	{
		write (STDERR_FILENO, "Creation map failed\n", 20);
		return (2);
	}
	if (map_state(&data.map) || check_map(&data.map))
	{
		free_all(NULL, NULL, data.map.map);
		write(STDERR_FILENO, "Map invalid!\n", 13);
		return (3);
	}
	mlx_part(&data);
	return (0);
}
