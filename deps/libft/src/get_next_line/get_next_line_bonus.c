/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:46:28 by amanilac          #+#    #+#             */
/*   Updated: 2024/02/22 16:03:43 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*stash[256];
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	int			bytes;

	if (fd < 0 || fd > 256 || BUFFER_SIZE < 1)
		return (NULL);
	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free_my_stuff(&stash[fd]);
			return (NULL);
		}
		buf[bytes] = '\0';
		free_and_join(&stash[fd], buf);
		if (bytes < BUFFER_SIZE || (stash[fd] && strchr_gnl(stash[fd], '\n')))
			break ;
	}
	line = cut_and_resize(&stash[fd]);
	if (!line)
		free_my_stuff(&stash[fd]);
	return (line);
}
