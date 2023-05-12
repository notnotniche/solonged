/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:05:05 by nklingsh          #+#    #+#             */
/*   Updated: 2023/05/02 14:48:19 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_images(t_data *game)
{
	int	pixel;

	pixel = PIXEL;
	game->img.floor = mlx_xpm_file_to_image(game->mlx,
			"./img/floor.xpm", &pixel, &pixel);
	game->img.wall = mlx_xpm_file_to_image(game->mlx,
			"./img/wall.xpm", &pixel, &pixel);
	game->img.exit = mlx_xpm_file_to_image(game->mlx,
			"./img/door.xpm", &pixel, &pixel);
	game->img.coin = mlx_xpm_file_to_image(game->mlx,
			"./img/coin.xpm", &pixel, &pixel);
	game->img.player = mlx_xpm_file_to_image(game->mlx,
			"./img/player.xpm", &pixel, &pixel);
}

void	ft_init_map(t_data *game)
{
	game->map.map = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.player = 0;
	game->map.exit = 0;
	game->map.coin = 0;
	game->steps = 1;
	game->argv = NULL;
}

void	ft_draw_map(t_data *game, int x, int y)
{
	int	pixel;

	pixel = PIXEL;
	if (game->map.map[y][x] == '0')
		mlx_put_image_to_window(game->mlx,
			game->win, game->img.floor, x * pixel, y * pixel);
	if (game->map.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx,
			game->win, game->img.wall, x * pixel, y * pixel);
	if (game->map.map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx,
			game->win, game->img.coin, x * pixel, y * pixel);
	if (game->map.map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx,
			game->win, game->img.exit, x * pixel, y * pixel);
	if (game->map.map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx,
			game->win, game->img.player, x * pixel, y * pixel);
}

int	ft_drawmap_1(t_data *game)
{
	t_player	p1;

	p1.y = 0;
	while (p1.y < game->map.height)
	{
		p1.x = 0;
		while (p1.x < game->map.width)
		{
			ft_draw_map(game, p1.x, p1.y);
			p1.x++;
		}
		p1.y++;
	}
	return (0);
}
