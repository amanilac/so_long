/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:09:25 by amanilac          #+#    #+#             */
/*   Updated: 2024/02/21 16:27:30 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9999
# endif

size_t	strlen_gnl(char *str);
char	*strchr_gnl(char *str, int c);
char	*strdup_gnl(char *src);
char	*strjoin_mod(char *s1, char *s2);
char	*substr_gnl(char *s, unsigned int start, size_t len);
void	free_my_stuff(char **str);
char	*get_next_line(int fd);

#endif