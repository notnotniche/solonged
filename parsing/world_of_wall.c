/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_of_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:17:15 by nklingsh          #+#    #+#             */
/*   Updated: 2023/05/12 16:43:29 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	world_of_wall(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1] != '\n' && str[i + 1])
		i++;
	if (str[0] != '1' || str[i] != '1')
	{
		return (0);
	}
	return (1);
}

int	check_line_wall(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_wall_line(char *map_str, int number_of_occ)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open(map_str, O_RDONLY);
	if (fd == -1)
		return (close(fd), 0);
	str = get_next_line(fd);
	while (str)
	{
		if ((i == 0 || i == number_of_occ))
		{
			if (check_line_wall(str) == 0)
				return (close(fd), free(str), 0);
		}
		free(str);
		str = get_next_line(fd);
		i++;
	}
	return (close(fd), free(str), 1);
}

int	check_world_of_wall(char *map_str, int number_of_occ)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open(map_str, O_RDONLY);
	if (fd == -1)
		return (close(fd), 0);
	str = get_next_line(fd);
	while (str)
	{
		if (i > 0 && i < number_of_occ)
		{
			if (world_of_wall(str) == 0)
				return (close(fd), free(str), 0);
		}
		free(str);
		str = get_next_line(fd);
		i++;
	}
	return (close(fd), free(str), 1);
}

int	number_of_collectibles(char *map_str)
{
	static int	compteur;
	int			fd;
	char		*str;
	int			i;

	fd = open(map_str, O_RDONLY);
	if (fd == -1)
		return (close(fd), 0);
	str = get_next_line(fd);
	compteur = 0;
	while (str)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == 'C')
				compteur++;
			i++;
		}
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	free(str);
	return (compteur);
}
