/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-an2 <jose-an2@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:03:02 by jose-an2          #+#    #+#             */
/*   Updated: 2025/10/23 18:09:25 by jose-an2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	size_t	i;
	size_t	n;
	char	*dup;

	i = ft_strlen(str) + 1;
	n = 0;
	dup = (char *)malloc(i);
	if (!dup)
		return (NULL);
	while (n < i)
	{
		dup[n] = str [n];
		n++;
	}
	dup[n] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2);
{

}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{

}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str)
		i++;
	return (i);
}

