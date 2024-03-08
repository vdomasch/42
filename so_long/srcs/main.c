/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:58:28 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/08 17:59:37 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


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
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_all(data->mlx, NULL, map->map);
}

int	keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_loop_end(data->mlx);
	else if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
		move_up(data, &data->map);
	else if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
		move_down(data, &data->map);
	else if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
		move_right(data, &data->map);
	else if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
		move_left(data, &data->map);
	printf("Keypress: %d\n", keysym);
	printf("key: %d\n", data->collectible);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

////////////    MY MAP    ///////////
	if (argc != 2)
		return (write(1, "INVALID NUMBER OF ARGUMENTS\n", 28));
	if (create_array(&data.map, argv[1]))
		return (write(1, "CREATION MAP FAILED!\n", 23));
	map_state(&data.map);
	if (check_map(&data.map))
	{
		free_all(NULL, NULL, data.map.map);
		return (write(1, "MAP INVALID!\n", 13));
	}
///////////////////////////////////////

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "My project!");
	if (!data.win)
	{
		mlx_destroy_display(data.mlx);
		return (1);
	}
	map_gen(&data, &data.map);
	mlx_hook(data.win, 17, 1L<<2, mlx_loop_end, data.mlx);
	mlx_hook(data.win, 2, 1L<<0, keypress, &data);
	mlx_loop(data.mlx);
	clean(&data, &data.map);	
	return (0);
}
