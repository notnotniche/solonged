/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:35:30 by nklingsh          #+#    #+#             */
/*   Updated: 2023/01/15 11:52:13 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>

char	*freejoin(char *tmp, char *buffer)
{
	char	*newtmp;

	newtmp = ft_strjoin(tmp, buffer);
	free(tmp);
	return (newtmp);
}

size_t	until_line(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n' && i < ft_strlen(str))
		i++;
	return (i);
}

char	*pastaliner(char *save, char *tmp, char *buffer)
{
	size_t	i;
	char	*line;
	char	*stmp;

	i = until_line(tmp);
	stmp = ft_substr(tmp, 0, i + 1);
	if (!stmp)
	{
		free(buffer);
		free(tmp);
		return (NULL);
	}
	line = ft_strjoin(save, stmp);
	free(stmp);
	ft_strcpy(ft_strchr(buffer, '\n'), save);
	free(tmp);
	free(buffer);
	return (line);
}

char	*fd_line(char *save, char *buffer, char *tmp, int fd)
{
	int	rdbytes;

	rdbytes = read(fd, buffer, BUFFER_SIZE);
	if ((save[0] == '\0' && rdbytes <= 0) || rdbytes < 0)
	{
		free(tmp);
		free(buffer);
		return (NULL);
	}
	buffer[rdbytes] = '\0';
	while ((rdbytes > 0) && (until_line(buffer) == ft_strlen(buffer)))
	{
		tmp = freejoin(tmp, buffer);
		rdbytes = read(fd, buffer, BUFFER_SIZE);
		if (rdbytes < 0)
		{
			free(tmp);
			free(buffer);
			return (NULL);
		}
		buffer[rdbytes] = '\0';
	}
	tmp = freejoin(tmp, buffer);
	return (pastaliner(save, tmp, buffer));
}

char	*get_next_line(int fd)
{
	static char	save[1024][BUFFER_SIZE + 1];
	char		*tmp;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1023)
		return (NULL);
	if (until_line(save[fd]) != ft_strlen(save[fd]))
	{
		line = ft_substr(save[fd], 0, until_line(save[fd]) + 1);
		return (ft_strcpy(ft_strchr(save[fd], '\n'), save[fd]), line);
	}
	tmp = malloc(sizeof(char));
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(tmp);
		free(buffer);
		return (NULL);
	}
	line = fd_line(save[fd], buffer, tmp, fd);
	return (line);
}
