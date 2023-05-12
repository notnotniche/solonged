/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_positions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:19:16 by nklingsh          #+#    #+#             */
/*   Updated: 2023/05/12 13:46:31 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	ft_where(t_data *game)
{
	t_player	i;

	i.y = 0;
	while (game->map.map[i.y])
	{
		i.x = 0;
		while (game->map.map[i.y][i.x])
		{
			if (game->map.map[i.y][i.x] == 'P')
				return (i);
			i.x++;
		}
		i.y++;
	}
	return (i);
}

int	ft_check_up(t_data *game, int key)
{
	t_player	i;

	(void)key;
	i = ft_where(game);
	if (game->map.map[i.y - 1][i.x] == '1')
		return (printf("cest de la lave fait attention !!\n"), 0);
	if (game->map.coin != 0 && game->map.map[i.y - 1][i.x] == 'E')
		return (printf("tu nas pas assez de piece !\n"), 0);
	return (1);
}

int	ft_check_down(t_data *game, int key)
{
	t_player	i;

	(void)key;
	i = ft_where(game);
	if (game->map.map[i.y + 1][i.x] == '1')
		return (printf("cest de la lave fait attention !!\n"), 0);
	if (game->map.coin != 0 && game->map.map[i.y + 1][i.x] == 'E')
		return (printf("tu nas pas assez de piece !\n"), 0);
	return (1);
}

int	ft_check_right(t_data *game, int key)
{
	t_player	i;

	(void)key;
	i = ft_where(game);
	if (game->map.map[i.y][i.x + 1] == '1')
		return (printf("cest de la lave fait attention !!\n"), 0);
	if (game->map.coin != 0 && game->map.map[i.y][i.x + 1] == 'E')
		return (printf("tu nas pas assez de piece !\n"), 0);
	return (1);
}

int	ft_check_left(t_data *game, int key)
{
	t_player	i;

	(void)key;
	i = ft_where(game);
	if (game->map.map[i.y][i.x - 1] == '1')
		return (printf("cest de la lave fait attention !!\n"), 0);
	if (game->map.coin != 0 && game->map.map[i.y][i.x - 1] == 'E')
		return (printf("tu nas pas assez de piece !\n"), 0);
	return (1);
}
