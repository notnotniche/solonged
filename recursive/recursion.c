/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:46:02 by nklingsh          #+#    #+#             */
/*   Updated: 2023/05/12 18:18:06 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	found_p(char **map, char *map_str)
{
	t_player	pos;

	pos.y = 0;
	while (pos.y < number_of_occ(map_str))
	{
		pos.x = 0;
		while (pos.x < sizeline(map_str))
		{
			if (map[pos.y][pos.x] == 'P')
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	return (pos);
}

void	free_map(char **map, char *map_str)
{
	int	i;

	i = 0;
	while (i < number_of_occ(map_str))
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

int	collected(char **map, char *map_str)
{
	int	x;
	int	y;
	int	compteur;

	compteur = 0;
	x = 0;
	while (x < number_of_occ(map_str))
	{
		y = 0;
		while (y < sizeline(map_str))
		{
			if (map[x][y] == 'C')
				compteur++;
			y++;
		}
		x++;
	}
	if (compteur == 0)
		return (1);
	else
		return (0);
}

int check_all_dir(char **map,int x, int y)
{
	if (map[x][y + 1] == 'X')
		return (1);
	if (map[x][y - 1] == 'X')
		return (1);
	if (map[x + 1][y] == 'X')
		return (1);
	if (map[x - 1][y] == 'X')
		return (1);
	return (0);
}

int check_e(char **map, char *map_str)
{
	int	x;
	int	y;
	int	compteur;

	compteur = 0;
	x = 0;
	while (x < number_of_occ(map_str))
	{
		y = 0;
		while (y < sizeline(map_str))
		{
			if (map[x][y] == 'E')
			{
				if (check_all_dir(map,x,y) == 1)
					return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int	recursion(char **map, int y, int x, char *map_str)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return (0);
	if (map[y][x] == 'E' && collected(map, map_str) == 0)
		return(0);
	map[y][x] = 'X';
	printf("%d \n", collected(map, map_str));
	recursion(map, y + 1, x, map_str);
	recursion(map, y - 1, x, map_str);
	recursion(map, y, x + 1, map_str);
	recursion(map, y, x - 1, map_str);
	if (collected(map, map_str) == 1 && check_e(map, map_str) == 1)
		return (1);
	else
		return (-1);
}
