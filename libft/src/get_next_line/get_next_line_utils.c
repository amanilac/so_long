/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:09:46 by amanilac          #+#    #+#             */
/*   Updated: 2024/02/20 18:32:10 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	strlen_gnl(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*strchr_gnl(char *str, int c)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == (char) c)
			return (str + i);
		i++;
	}
	if (str[i] == (char) c)
		return (str + i);
	return (NULL);
}

char	*strdup_gnl(char *src)
{
	char	*dest;
	int		src_size;
	int		i;

	if (!src)
		return (NULL);
	i = 0;
	src_size = strlen_gnl(src);
	dest = malloc(sizeof(char) * src_size + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*substr_gnl(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	i;

	if (!s)
		return (NULL);
	slen = strlen_gnl(s);
	i = 0;
	if (len > (slen - start))
		len = ((slen - start));
	sub = malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	while (s[i + start] && i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*strjoin_mod(char *s1, char *s2)
{
	char	*final;
	size_t	i;
	size_t	j;

	final = malloc(strlen_gnl(s1) + strlen_gnl(s2) + 1 * sizeof(char));
	if (!final)
	{
		free_my_stuff(&s1);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1[i])
	{
		final[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		final[i + j] = s2[j];
		j++;
	}
	free_my_stuff(&s1);
	final[i + j] = '\0';
	return (final);
}
