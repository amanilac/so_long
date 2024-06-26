/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:09:25 by amanilac          #+#    #+#             */
/*   Updated: 2024/02/20 18:47:38 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

size_t	strlen_gnl(char *str);
char	*strchr_gnl(char *str, int c);
char	*strdup_gnl(char *src);
char	*strjoin_mod(char *s1, char *s2);
char	*substr_gnl(char *s, unsigned int start, size_t len);
void	free_my_stuff(char **str);
char	*get_next_line(int fd);

#endif