/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:31:29 by amanilac          #+#    #+#             */
/*   Updated: 2024/07/01 19:52:11 by amanilac         ###   ########.fr       */
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

typedef	struct s_long
{
	mlx_t	*window;
	char	**map;
	int		player_x;
	int		player_y;
	int		x_pos;
	int		y_pos;
	int		collectible;
	int		width;
	int		height;
	int		moves;
	int		block_size;
}	t_long;	

void	print_error(char *str);
void	abandon(char **strings);

void	map_checker(t_long *game_data);
void	is_rectangle(t_long *game_data);
char	*boner_grower(char *s1, char *s2);

void	generate_map(char **map);
void	open_window(t_long *game_data);

int		map_height(char **map); 
int		map_width(char **map);

void	move_player(char **map, mlx_t *window);
void key_hooker(mlx_key_data_t keydata, void *param);

#endif
