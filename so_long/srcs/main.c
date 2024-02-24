/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:58:28 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/24 15:14:52 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	no_event(void *data)
{
	(void)data;
	return (0);
}

int	keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	printf("Keypress: %d\n", keysym);
	return (0);
}

int	keyrelease(int keysym, void *data)
{
	(void)data;
	(void)keysym;
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;
//t_data	data;
	if (argc > 2)
		return (write(1, "INVALID NUMBER OF ARGUMENTS\n", 28));
	if (argc == 2)
	{
		if (!create_array(&map, argv[1]))
			return (write(1, "CREATION MAP FAILED!\n", 23));
		map_state(&map);
	}
	if (check_map(&map))
	{
		free_all(NULL, NULL, map.map);
		return (write(1, "MAP INVALID!\n", 13));
	}
	write(1, "MAP VALID!\n", 11);
	/*data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
		
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "My project!");

	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (1);
	}
	mlx_loop_hook(data.mlx_ptr, &no_event, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &keypress, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &keyrelease, &data);

	mlx_loop(data.mlx_ptr);

	mlx_destroy_display(data.mlx_ptr);*/
	free_all(NULL, NULL, map.map);
	//free(data.mlx_ptr);
	return (0);
}
