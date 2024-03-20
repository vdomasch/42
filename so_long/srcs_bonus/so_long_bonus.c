/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:58:28 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/15 17:33:09 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_filename(char *str)
{
	int		i;

	i = ft_strlen(str);
	if (str[i - 1] == 'r' && str[i - 2] == 'e'
		&& str[i - 3] == 'b' && str[i - 4] == '.')
		return (0);
	write(STDERR_FILENO, "Invalid map extension.\n", 23);
	return (1);
}

static int	keypress(int keysym, t_data *data)
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
		write(STDOUT_FILENO, "Congratulations!", 16);
		mlx_loop_end(data->mlx);
	}
	if (data->map.m_count == 1)
		move_monster(data, &data->map);
	return (0);
}

static int	mlx_part(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->win = mlx_new_window(data->mlx, data->map.width * 64,
			data->map.height * 64, "My project!");
	if (!data->win)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (2);
	}
	if (!map_gen(data, &data->map))
	{
		mlx_hook(data->win, 17, 1L << 2, mlx_loop_end, data->mlx);
		mlx_hook(data->win, 2, 1L << 0, keypress, data);
		mlx_loop(data->mlx);
	}
	clean(data, &data->map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		write(STDERR_FILENO, "Invalid number of arguments.\n", 29);
		return (1);
	}
	if (check_filename(argv[1]))
		return (2);
	if (create_array(&data.map, argv[1]))
	{
		write (STDERR_FILENO, "Creation map failed.\n", 21);
		return (3);
	}
	if (map_state(&data.map, -1, -1) || check_map(&data.map))
	{
		free_all(NULL, NULL, data.map.map);
		write(STDERR_FILENO, "Map invalid!\n", 13);
		return (4);
	}
	if (mlx_part(&data))
		free_all(NULL, NULL, data.map.map);
	return (0);
}
