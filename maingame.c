/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maingame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:23:58 by nklingsh          #+#    #+#             */
/*   Updated: 2023/05/12 13:58:40 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_img(void)
{
	if (open("img/", __O_DIRECTORY) < 0)
		return (printf("Manque le dossier"), 0);
	if (open("img/coin.xpm", O_RDONLY) < 0)
		return (printf("Manque le fichier coin"), 0);
	if (open("img/floor.xpm", O_RDONLY) < 0)
		return (printf("Manque le fichier floor"), 0);
	if (open("img/player.xpm", O_RDONLY) < 0)
		return (printf("Manque le fichier player"), 0);
	if (open("img/door.xpm", O_RDONLY) < 0)
		return (printf("Manque le fichier door"), 0);
	if (open("img/wall.xpm", O_RDONLY) < 0)
		return (printf("Manque le fichier wall"), 0);
	return (1);
}

int	valid_world(char *argv, char *valid_input, t_player x, char **map)
{
	int	fd;

	if (ft_check_extention(argv) == -1)
		return (0);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (printf("invalid fd"), 0);
	}
	if (valid_map(valid_input, argv, map[0]) == 0)
	{
		free_map(map, argv);
		return (0);
	}
	if (recursion(map, x.y, x.x, argv) != 1)
	{
		printf("Error : map non valide\n");
		free_map(map, argv);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data		game;
	char		**map;
	int			i;
	t_player	x;

	i = 0;
	if (argc != 2)
		return (printf("Error : Arguments"), 0);
	if (ft_check_img() == 0)
		return (0);
	map = char_map(argv[1]);
	if (!map)
		return (0);
	x = found_p(map, argv[1]);
	if (valid_world(argv[1], "0E1PC", x, map) != 1)
		return (0);
	free_map(map, argv[1]);
	ft_init_map(&game);
	init_map(&game, argv[1]);
	mlx_loop_hook(game.mlx, &ft_drawmap_1, &game);
	mlx_hook(game.win, 2, 1L << 0, ft_key, &game);
	mlx_hook(game.win, 33, 1L << 2, ft_close_button, &game);
	mlx_loop(game.mlx);
}
