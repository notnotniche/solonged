/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:43:56 by nklingsh          #+#    #+#             */
/*   Updated: 2023/05/12 16:42:40 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "gnl/get_next_line.h"
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define PIXEL 50

typedef struct s_image
{
	void	*player;
	void	*coin;
	void	*floor;
	void	*wall;
	void	*exit;
}	t_image;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		player;
	int		coin;
	int		exit;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_data {
	void		*mlx;
	void		*win;
	t_player	p_pos;
	int			player_x;
	int			player_y;
	t_map		map;
	t_image		img;
	void		*image;
	char		dir;
	int			steps;
	char		*argv;
}	t_data;
// GNL
char		*get_next_line(int fd);
int			valid_map(char *valid_word, char *map_str, char *line);
//world_of_wall
int			world_of_wall(char *str);
int			check_line_wall(char *str);
int			number_of_occ(char *map_str);
int			number_of_collectibles(char *map_str);
//coint_start_end.c
int			valid_start(char *map_str);
int			size_str(char *str);

//
char		**init(char *map_str);
void		print_map(char **map);
int			sizeline(char *map_str);

//////GAME
void		init_images(t_data *game);
int			init_map(t_data *game, char *map_str);
void		ft_init_map(t_data *game);
void		ft_draw_map(t_data *game, int x, int y);
int			ft_drawmap_1(t_data *game);
int			found_start_pos_x(void);
int			found_start_pos_y(t_data *game);
char		*copy_until_end(char *dest, char *source);

int			ft_check_down(t_data *game, int key);
int			ft_check_up(t_data *game, int key);
int			ft_check_left(t_data *game, int key);
int			ft_check_right(t_data *game, int key);

t_player	ft_where(t_data *game);

void		ft_move_right(t_data *game, int key);
void		ft_move_left(t_data *game, int key);
void		ft_move_down(t_data *game, int key);
void		ft_move_up(t_data *game, int key);

int			ft_key(int key, t_data *game);
int			ft_exit(t_data *game);
int			ft_check_extention(char *file);

/////UTILS
char		*ft_strcat(char *new);
void		ft_freemap(t_data *game, char *map_str);
int			ft_map_rows_height(t_data *game, char *map_str);
t_player	found_p(char **map, char *map_str);
char		**char_map(char *argv);
void		free_map(char **map, char *map_str);
int			recursion(char **map, int y, int x, char *map_str);
int			ft_close_button(t_data *game);
int	check_world_of_wall(char *map_str, int number_of_occ);
int	check_wall_line(char *map_str, int number_of_occ);

#endif