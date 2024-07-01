/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annamanilaci <annamanilaci@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:31:29 by amanilac          #+#    #+#             */
/*   Updated: 2024/06/28 16:36:01 by annamanilac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH 1024
# define HEIGHT 1024

#include "libft.h"
#include "MLX42.h"
#include "get_next_line_bonus.h"
#include "ft_printf.h"
#include <stdio.h>
#include <fcntl.h>

void	print_error(char *str);
void	abandon(char **strings);

int		map_checker(char **map);
void	is_rectangle(char **map);
char	*boner_grower(char *s1, char *s2);

void	generate_map(char **map);
void	open_window(char **map);

int		map_height(char **map); 
int		map_width(char **map);

void	move_player(char **map, mlx_t *window);

#endif
