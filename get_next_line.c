/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-an2 <jose-an2@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 21:53:41 by jose-an2          #+#    #+#             */
/*   Updated: 2025/10/29 23:43:55 by jose-an2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *get_line(char *line_buff);

static char *fill_buff(int fd, char *lchar, char *buffer);

char	*get_next_line(int fd)
{
	static char	*lchars;
	char		*buffer;
	char		*line;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(lchars);
		free(buffer);
		buffer = NULL;
		lchars = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = fill_buff(fd, lchars, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	lchars = get_line(line);
	return (line);
}

static char	*get_line(char *line_buff)
{
	char	*lchar;
	ssize_t	i;

	i = 0;
	while (line_buff[i] != '\n' || line_buff[i] != '\0')
		i++;
	if (line_buff[i] == 0 || line_buff[1] == 0)
		return (NULL);
	lchar = ft_substr(line_buff, i + 1, ft_strlen(line_buff) - i);
	if (*lchar == 0)
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

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(lchar);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!lchar)
			lchar = ft_strdup("");
		temp = lchar;
		lchar = ft_strjoin(temp, buffer);
		free (temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (lchar);
}
