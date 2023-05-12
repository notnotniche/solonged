/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inputs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:18:57 by nklingsh          #+#    #+#             */
/*   Updated: 2023/05/11 18:54:03 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key(int key, t_data *game)
{
	if (key == XK_w)
	{
		printf("action : %d\n", game->steps++);
		ft_move_up(game, key);
	}
	else if (key == XK_a)
	{
		printf("action : %d\n", game->steps++);
		ft_move_left(game, key);
	}
	else if (key == XK_s)
	{
		printf("action : %d\n", game->steps++);
		ft_move_down(game, key);
	}
	else if (key == XK_d)
	{
		printf("action :%d\n", game->steps++);
		ft_move_right(game, key);
	}
	else if (key == 65307)
		ft_exit(game);
	return (0);
}

int	ft_close_button(t_data *game)
{
	ft_exit(game);
	return (0);
}

void	ft_destroy(t_data *game)
{
	mlx_destroy_image(game->mlx, game->img.coin);
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_image(game->mlx, game->img.player);
	mlx_destroy_image(game->mlx, game->img.floor);
	mlx_destroy_image(game->mlx, game->img.exit);
}

void	ft_freemap(t_data *game, char *map_str)
{
	int	i;

	i = 0;
	if (game->map.map != NULL)
	{
		while (i < number_of_occ(map_str))
		{
			free(game->map.map[i]);
			i++;
		}
	}
	free(game->map.map);
}

int	ft_exit(t_data *game)
{
	ft_freemap(game, game->argv);
	if (game->mlx != NULL && game->win != NULL)
	{
		ft_destroy(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
	}
	free(game->argv);
	free(game->mlx);
	exit(0);
}
