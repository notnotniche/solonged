/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_start_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:37:22 by nklingsh          #+#    #+#             */
/*   Updated: 2023/05/12 16:39:30 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_start(char *str)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			start = start + 1;
		i++;
	}
	return (start);
}

int	check_end(char *str)
{
	int	i;
	int	end;

	i = 0;
	end = 0;
	while (str[i])
	{
		if (str[i] == 'E')
			end = end + 1;
		i++;
	}
	return (end);
}

int	check_coin(char *str)
{
	int	i;
	int	coin;

	i = 0;
	coin = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			coin = coin + 1;
		i++;
	}
	return (coin);
}

int	open_map(char *map_str)
{
	int		fd;
	char	*str;
	int		start;
	int		coin;
	int		end;

	coin = 0;
	end = 0;
	start = 0;
	fd = open(map_str, O_RDONLY);
	if (fd == -1)
		return (close(fd), printf("ERROR INVALID FD"), 0);
	str = get_next_line(fd);
	while (str)
	{
		start = start + check_start(str);
		coin = coin + check_coin(str);
		end = end + check_end(str);
		free(str);
		str = get_next_line(fd);
	}
	if (start != 1 || end != 1 || coin < 1)
		return (close(fd), free(str), 0);
	else
		return (close(fd), free(str), 1);
}

int	valid_start(char *map_str)
{
	if (open_map(map_str) == 0)
		return (0);
	return (1);
}
