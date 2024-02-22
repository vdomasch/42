/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:58:28 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/22 16:35:46 by vdomasch         ###   ########.fr       */
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

void	free_map(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

char	**allocate_map(char *location, size_t height)
{
	char	**array;
	int		fd;
	size_t	i;

	i = 0;
	fd = open(location, O_RDONLY);
	array = malloc(sizeof(char *) * height);
	while ((i < height))
	{
		array[i] = get_next_line(fd);
		if (array[i] == NULL)
		{
			while (array[i--])
				free(array[i]);
			free(array);
			close(fd);
			return (NULL);
		}
		i++;
	}
	close(fd);
	return (array);
}

char	**map_array(char *location)
{
	int		fd;
	char	*str;
	size_t	len;
	size_t	height;

	fd = open(location, O_RDONLY);
	if (fd == -1)
		return (NULL);
	str = get_next_line(fd);
	len = ft_strlen(str);
	while (str != NULL)
	{
		if (ft_strlen(str) != len)
		{
			printf("Invalid Map\n");
			free(str);
			close(fd);
			return (NULL);
		}
		height++;
		free(str);
	}
	close(fd);
	return (allocate_map(location, height));
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	**map;
	
	map = NULL;
	if (argc > 2)
		return (write(1, "INVALID NUMBER OF ARGUMENTS\n", 28));
	if (argc == 2)
	{
		map = map_array(argv[1]);
		if (!map)
			return (write(1, "ALLOCATION MAP FAILED!\n", 23));
	}
	data.mlx_ptr = mlx_init();
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

	mlx_destroy_display(data.mlx_ptr);
	free_map(map);
	free(data.mlx_ptr);
}
