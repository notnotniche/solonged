/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:45:11 by nklingsh          #+#    #+#             */
/*   Updated: 2022/12/03 15:41:42 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// src 2 ce qui est copie en premier dans la chaine
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (res);
}

size_t	ft_strlen(char const *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

void	ft_strcpy(const char *src, char *dest)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_substr(const char *src, unsigned int n, size_t m)
{
	char	*dest;
	size_t	size;
	size_t	i;

	i = 0;
	size = m;
	if (!src)
		return (NULL);
	if (m > ft_strlen(src))
		size = ft_strlen(src);
	dest = malloc(sizeof(char) * size + 1);
	if (!dest)
		return (NULL);
	if (n < ft_strlen(src))
	{
		while (i < size)
		{
			dest[i] = src[n + i];
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *str, int x)
{
	char	*newstr;
	size_t	i;

	i = 0;
	newstr = "";
	while (i < ft_strlen(str))
	{
		if ((unsigned char) str[i] == (unsigned char) x)
		{
			newstr = (char *)str + i + 1;
			return (newstr);
		}
		i++;
	}
	return (newstr);
}
