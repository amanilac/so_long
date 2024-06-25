/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:30:22 by amanilac          #+#    #+#             */
/*   Updated: 2024/05/10 11:36:24 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_skip_delims(const char **s, char c)
{
	while (**s && **s == c)
		(*s)++;
}

static size_t	ft_string_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
		ft_skip_delims(&s, c);
	}
	return (count);
}

static char	**ft_abandon(char **strings)
{
	size_t	i;

	i = 0;
	while (strings[i])
		free(strings[i++]);
	free(strings);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	size_t	i;
	size_t	str_i;

	if (!s)
		return (NULL);
	ft_skip_delims(&s, c);
	strings = ft_calloc(ft_string_count(s, c) + 1, sizeof(char *));
	if (!strings)
		return (NULL);
	str_i = 0;
	while (*s)
	{
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		strings[str_i] = ft_substr(s, 0, i);
		if (!strings[str_i++])
			return (ft_abandon(strings));
		s += i;
		ft_skip_delims(&s, c);
	}
	return (strings);
}
