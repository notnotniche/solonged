/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:44:36 by nklingsh          #+#    #+#             */
/*   Updated: 2023/05/12 13:48:43 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*copy_until_end(char *dest, char *source)
{
	int	i;

	i = 0;
	dest = malloc(sizeof(char) * ft_strlen(source) + 1);
	if (!dest)
		return (NULL);
	while (source[i] && source[i] != '\n')
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	init_map(t_data *game, char *map_str)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open(map_str, O_RDONLY);
	game->map.map = malloc(sizeof(char *) * number_of_occ(map_str) + 1);
	if (!game->map.map)
		return (0);
	str = get_next_line(fd);
	while (str)
	{
		game->map.map[i] = copy_until_end(game->map.map[i], str);
		if (!game->map.map[i])
			return (free(str), close(fd), 0);
		free(str);
		str = get_next_line(fd);
		i++;
	}
	game->mlx = mlx_init();
	if (ft_map_rows_height(game, map_str) == 0)
		return (0);
	game->win = mlx_new_window(game->mlx, \
		game->map.width * PIXEL, game->map.height * PIXEL, "troisieme push");
	return (free(str), close(fd), init_images(game), 1);
}

int	ft_copy(t_data *game, char *src)
{
	int	i;

	i = 0;
	game->argv = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!game->argv)
		return (0);
	while (src[i])
	{	
		game->argv[i] = src[i];
		i++;
	}
	game->argv[i] = '\0';
	return (1);
}

int	ft_map_rows_height(t_data *game, char *map_str)
{
	game->map.height = number_of_occ(map_str);
	game->map.width = sizeline(map_str);
	game->map.coin = number_of_collectibles(map_str);
	if (ft_copy(game, map_str) == 0)
		return (0);
	return (1);
}
