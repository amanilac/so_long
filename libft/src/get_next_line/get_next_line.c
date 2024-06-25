/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:33:38 by amanilac          #+#    #+#             */
/*   Updated: 2024/02/20 18:32:15 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_my_stuff(char **str)
{
	if (*str)
	{
		free (*str);
		*str = NULL;
	}
}

static char	*cut_and_resize(char **stash)
{
	char	*temp;
	char	*line;

	if (!*stash)
		return (NULL);
	if (!strchr_gnl(*stash, '\n'))
	{
		line = *stash;
		if (*line == '\0')
		{
			free_my_stuff(stash);
			return (NULL);
		}
		*stash = NULL;
		return (line);
	}
	line = substr_gnl(*stash, 0, strchr_gnl(*stash, '\n') - *stash + 1);
	temp = substr_gnl(*stash,
			strchr_gnl(*stash, '\n') - *stash + 1, strlen_gnl(*stash));
	free_my_stuff(stash);
	*stash = temp;
	return (line);
}

static void	free_and_join(char **stash, char *buf)
{
	if (*stash)
		*stash = strjoin_mod(*stash, buf);
	else
		*stash = strdup_gnl(buf);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free_my_stuff(&stash);
			return (NULL);
		}
		buf[bytes] = '\0';
		free_and_join(&stash, buf);
		if (bytes < BUFFER_SIZE || (stash && strchr_gnl(stash, '\n')))
			break ;
	}
	line = cut_and_resize(&stash);
	if (!line)
		free_my_stuff(&stash);
	return (line);
}
