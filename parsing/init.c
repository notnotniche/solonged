/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:18:33 by nklingsh          #+#    #+#             */
/*   Updated: 2023/05/12 17:00:19 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sizeline(char *map_str)
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	fd = open(map_str, O_RDONLY);
	if (fd == -1)
		return (printf("invalid fd"), 0);
	str = get_next_line(fd);
	while (str[i] != '\n' && str[i])
		i++;
	while (str)
	{
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (i);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}

int	ft_check_extention(char *file)
{
	int	i;
	int	fd;

	i = 0;
	while (file[i])
		i++;
	while (file[i] != '.')
		i--;
	fd = open(file, __O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		return (write(2, "Error\nYou tried to open a directory\n", 36), -1);
	}
	if (ft_strncmp(&file[i], ".ber", 5) != 0)
		return (write(2, "Error\nInvalid Extention.\n", 25), -1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (write(2, "Error\nThere's no map with that name.\n", 37), -1);
	close(fd);
	return (0);
}

char	**init(char *map_str)
{
	char	*line;
	int		fd;
	char	**str;
	int		i;

	i = 0;
	str = malloc(sizeof(char *) * number_of_occ(map_str) + 1);
	if (!str)
		return (NULL);
	fd = open(map_str, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		str[i] = ft_strcat(line);
		if (!str[i])
			return (NULL);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (str);
}

int	size_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}
