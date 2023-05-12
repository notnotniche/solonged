/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:48:35 by nklingsh          #+#    #+#             */
/*   Updated: 2022/12/01 17:28:55 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(char const *s);
char	*ft_substr(const char *src, unsigned int n, size_t m);
char	*ft_strchr(const char *str, int x);
char	*get_next_line(int fd);
char	*fd_line(char *save, char *buffer, char *tmp, int fd);
char	*pastaliner(char *save, char *tmp, char *buffer);
size_t	until_line(char *str);
char	*freejoin(char *tmp, char *buffer);
void	ft_strcpy(const char *src, char *dest);
#endif