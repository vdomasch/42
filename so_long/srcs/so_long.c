/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:58:28 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/14 07:08:21 by vdomasch         ###   ########.fr       */
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

int	keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_loop_end(data->mlx);
	move_player(keysym, data);
	if (data->collectible == data->map.c_count)
	{
		put_texture(data, 'e', data->map.exit_x, data->map.exit_y);
		data->map.map[data->map.exit_x][data->map.exit_y] = '0';
	}
	if (data->map.player_x == data->map.exit_x
		&& data->map.player_y == data->map.exit_y)
		{
			write(STDOUT_FILENO, "You won the game!\n", 18);
			mlx_loop_end(data->mlx);
		}
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
