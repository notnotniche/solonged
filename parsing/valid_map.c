/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:24:51 by nklingsh          #+#    #+#             */
/*   Updated: 2023/05/12 16:53:13 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_word(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	verif_str(char *str, char *valid_word)
{
	int	i;

	i = 0;
	while (str[i + 1])
	{
		if (verif_word(str[i], valid_word) == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_word_in_str(char *str, char *valid_word)
{
	int	i;
	int	y;
	int	compteur;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		compteur = 0;
		y = 0;
		while (valid_word[y])
		{
			if (valid_word[y] == str[i])
				compteur = 1;
			y++;
		}
		if (compteur != 1)
			return (0);
		i++;
	}
	return (1);
}

int	check_size_map_word(int len, char *map_str, char *valid_word)
{
	int		fd;
	char	*str;

	fd = open(map_str, O_RDONLY);
	if (fd == -1)
		return (0);
	str = get_next_line(fd);
	while (str)
	{
		if (size_str(str) != len)
			return (printf("Error :probleme de taille de map"), (0));
		if (check_word_in_str(str, valid_word) == 0)
			return (printf("Error: pas une bonne map a cause des lettres"), 0);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	free(str);
	return (1);
}

int	valid_map(char *valid_word, char *map_str, char *line)
{
	int	len;

	(void)valid_word;
	len = number_of_occ(map_str);
	printf("len ----> %d \n", len);
	if (size_str(line) == 0 || len == 0)
		return (printf("Error : map cant have 0 line"));
	if (valid_start(map_str) == 0 )
		return (printf("Error :map is not valid"), 0);
	if (number_of_occ(map_str) == size_str(line))
		return (printf("Error :map is square"), 0);
	if (check_wall_line(map_str, len) == 0)
		return (printf("Error :map is not in good format "), 0);
	if (check_world_of_wall(map_str, len) == 0)
		return (printf("Error :map is not in good format "), 0);
	if (check_size_map_word(size_str(line), map_str, valid_word) == 0)
		return (0);
	return (1);
}
