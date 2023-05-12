/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:52:15 by nklingsh          #+#    #+#             */
/*   Updated: 2023/05/11 17:40:59 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**char_map(char *argv)
{
	int		fd;
	char	**map;
	char	*str;
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (close(fd), NULL);
	map = malloc(sizeof(char *) * number_of_occ(argv) + 1);
	if (!map)
		return (NULL);
	str = get_next_line(fd);
	while (str)
	{
		map[i] = copy_until_end(map[i], str);
		free(str);
		str = get_next_line(fd);
		i++;
	}
	close(fd);
	return (map);
}
