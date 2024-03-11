/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:51:39 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/11 19:59:15 by vdomasch         ###   ########.fr       */
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

# define WIDTH 1800 //3840
# define HEIGHT 1200 //2074

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		c_count;
	int		e_count;
	int		p_count;
	int		reachable_elements;
	int		exit_x;
	int		exit_y;
	int		player_x;
	int		player_y;
}	t_map;

typedef struct s_texture
{
	void	*img;
	int		img_w;
	int		img_h;

}	t_texture;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_map		map;
	int			img_width;
	int			img_height;
	t_texture	w;
	t_texture	c;
	t_texture	e;
	t_texture	e_out;
	t_texture	p;
	t_texture	f;
	int			collectible;
	int			movement;
}	t_data;

int		check_map(t_map *map);

int		create_array(t_map *map, const char *filename);
void	map_state(t_map *map);

void	map_gen(t_data *data, t_map	*map);
void	put_texture(t_data *data, char c, int h, int w);
void	free_all(void *str1, void *str2, char **array);
void	move_up(t_data *data, t_map *m);
void	move_down(t_data *data, t_map *m);
void	move_right(t_data *data, t_map *m);
void	move_left(t_data *data, t_map *m);

#endif
