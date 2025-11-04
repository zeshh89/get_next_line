/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-an2 <jose-an2@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 21:53:41 by jose-an2          #+#    #+#             */
/*   Updated: 2025/11/03 20:10:44 by jose-an2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*fill_buff(int fd, char *lchar, char *buffer);

static char	*get_line(char *line_buff);

char	*get_next_line(int fd)
{
	static char	*lchars[MAX_FD];
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(lchars[fd]), lchars[fd] = NULL, NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	lchars[fd] = fill_buff(fd, lchars[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (!lchars[fd] || *lchars[fd] == '\0')
		return (free(lchars[fd]), lchars[fd] = NULL, NULL);
	line = ft_strdup(lchars[fd]);
	free(lchars[fd]);
	lchars[fd] = get_line(line);
	return (line);
}

static char	*get_line(char *line_buff)
{
	char	*lchar;
	ssize_t	i;

	i = 0;
	if (!line_buff)
		return (NULL);
	while (line_buff[i] != '\n' && line_buff[i] != '\0')
		i++;
	if (line_buff[i] == '\0')
		return (NULL);
	lchar = ft_substr(line_buff, i + 1, ft_strlen(line_buff) - i - 1);
	if (!lchar || *lchar == 0)
	{
		free(lchar);
		lchar = NULL;
	}
	line_buff[i + 1] = '\0';
	return (lchar);
}

static char	*fill_buff(int fd, char *lchar, char *buffer)
{
	ssize_t	bytes_read;
	char	*temp;

	if (!lchar)
		lchar = ft_strdup("");
	if (!lchar)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = lchar;
		lchar = ft_strjoin(temp, buffer);
		free(temp);
		if (!lchar || ft_strchr(buffer, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read < 0)
		return (free(lchar), NULL);
	return (lchar);
}
