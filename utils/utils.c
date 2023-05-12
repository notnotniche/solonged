/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:58:34 by nklingsh          #+#    #+#             */
/*   Updated: 2023/05/12 16:43:53 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strcat(char *new_line)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(new_line)) + 1);
	if (!str)
		return (NULL);
	while (new_line[i])
	{
		str[i] = new_line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	size_of_tab(int *tab)
{
	int	i;

	i = 0;
	while (*tab)
	{
		tab++;
		i++;
	}
	return (i);
}

int	number_of_occ(char *map_str)
{
	static int	compteur;
	int			fd;
	char		*str;

	fd = open(map_str, O_RDONLY);
	if (fd == -1)
		return (close(fd), 0);
	str = get_next_line(fd);
	compteur = 0;
	while (str)
	{
		compteur++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	free(str);
	return (compteur);
}
