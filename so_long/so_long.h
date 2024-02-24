/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:51:39 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/24 15:06:07 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"

# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# define WIDTH 600
# define HEIGHT 300

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		c_count;
	int		e_count;
	int		p_count;
	int		player_x;
	int		player_y;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

int		check_map(t_map *map);
int		create_array(t_map *map, const char *filename);
void	map_state(t_map *map);
void	free_all(char *str1, char *str2, char **array);

#endif
