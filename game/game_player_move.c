/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_player_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:38:31 by nklingsh          #+#    #+#             */
/*   Updated: 2023/05/12 17:39:25 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_data *game, int key)
{
	t_player	i;

	i = ft_where(game);
	if (ft_check_up(game, key) == 1)
	{
		if (i.y > 0)
		{
			if (game->map.map[i.y - 1][i.x] == 'E')
				ft_exit(game);
			if (game->map.map[i.y - 1][i.x] == 'C')
				game->map.coin = game->map.coin - 1;
			game->map.map[i.y - 1][i.x] = 'P';
			if (game->map.map[i.y][i.x] == 'P')
				game->map.map[i.y][i.x] = '0';
			else
				game->map.map[i.y][i.x] = 'E';
		}
	}
}

void	ft_move_down(t_data *game, int key)
{
	t_player	i;

	i = ft_where(game);
	if (ft_check_down(game, key) == 1)
	{
		if (i.y > 0)
		{
			if (game->map.map[i.y + 1][i.x] == 'E')
				ft_exit(game);
			if (game->map.map[i.y + 1][i.x] == 'C')
				game->map.coin = game->map.coin - 1;
			game->map.map[i.y + 1][i.x] = 'P';
			if (game->map.map[i.y][i.x] == 'P')
				game->map.map[i.y][i.x] = '0';
			else
				game->map.map[i.y][i.x] = 'E';
		}
	}
}

void	ft_move_left(t_data *game, int key)
{
	t_player	i;

	i = ft_where(game);
	if (ft_check_left(game, key) == 1)
	{
		if (game->map.map[i.y][i.x - 1] == 'E')
			ft_exit(game);
		if (game->map.map[i.y][i.x - 1] == 'C')
			game->map.coin = game->map.coin - 1;
		game->map.map[i.y][i.x - 1] = 'P';
		if (game->map.map[i.y][i.x] == 'P')
			game->map.map[i.y][i.x] = '0';
		else
			game->map.map[i.y][i.x] = 'E';
	}
}

void	ft_move_right(t_data *game, int key)
{
	t_player	i;

	i = ft_where(game);
	if (ft_check_right(game, key) == 1)
	{
		if (game->map.map[i.y][i.x + 1] == 'E')
			ft_exit(game);
		if (game->map.map[i.y][i.x + 1] == 'C')
			game->map.coin = game->map.coin - 1;
		game->map.map[i.y][i.x + 1] = 'P';
		if (game->map.map[i.y][i.x] == 'P')
			game->map.map[i.y][i.x] = '0';
		else
			game->map.map[i.y][i.x] = 'E';
	}
}
