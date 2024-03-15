/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:51:39 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/15 17:19:47 by vdomasch         ###   ########.fr       */
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

# define WIDTH 3840
# define HEIGHT 2074

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		c_count;
	int		e_count;
	int		p_count;
	int		m_count;
	int		reachable_elements;
	int		exit_x;
	int		exit_y;
	int		player_x;
	int		player_y;
	int		m_x;
	int		m_y;
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
	t_texture	e2;
	t_texture	p;
	t_texture	p2;
	t_texture	f;
	t_texture	m;
	t_texture	m2;
	int			collectible;
	int			movement;
}	t_data;


int		check_map(t_map *map);

int		create_array(t_map *map, const char *filename);
int		map_state(t_map *map);

int		player_dead(t_data *data, t_map *m);
int	map_gen(t_data *data, t_map	*map);
void	put_texture(t_data *data, char c, int h, int w);
void	free_all(void *str1, void *str2, char **array);
void	clean(t_data *data, t_map *map);

void	move_player(int keysym, t_data *data);
void	move_monster(t_data *data, t_map *m);

char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);

#endif
