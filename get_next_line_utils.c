/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-an2 <jose-an2@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:03:02 by jose-an2          #+#    #+#             */
/*   Updated: 2025/10/29 23:45:41 by jose-an2         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*dest;
	size_t	l;

	l = 0;
	if (start >= (unsigned int)ft_strlen((char *)str))
		return (ft_strdup(""));
	if (len > (unsigned int)ft_strlen((char *)str + start))
		len = (unsigned int)ft_strlen((char *)str + start);
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (NULL);
	while (l < len && str[start + l] != '\0')
	{
		dest[l] = str[start + l];
		l++;
	}
	dest[l] = '\0';
	return (dest);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str)
		i++;
	return (i);
}
