/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:31:29 by amanilac          #+#    #+#             */
/*   Updated: 2024/07/03 18:53:57 by amanilac         ###   ########.fr       */
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

typedef struct s_img
{
	mlx_image_t *wall;
	mlx_image_t *floor;
	mlx_image_t *exit;
	mlx_image_t *player;
	mlx_image_t *collectible;
} t_img;

typedef struct s_files
{
	mlx_texture_t *wall;
	mlx_texture_t *player;
	mlx_texture_t *exit;
	mlx_texture_t *collectible;
	mlx_texture_t *floor;
	t_img *imgs;
} t_files;

typedef	struct	s_long
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
	t_files	*blox;
}	t_long;	

void	print_error(char *str);
void	abandon(char **strings);

void	map_checker(t_long *game_data);
void	is_rectangle(t_long *game_data);
char	*boner_grower(char *s1, char *s2);

void	generate_map(char **map);
void	open_window(t_long *game_data);

void 	key_hooker(mlx_key_data_t keydata, void *param);
void	move_up(t_long *game_data);
void	move_down(t_long *game_data);
void	move_left(t_long *game_data);
void	move_right(t_long *game_data);

void	init_textures(t_long *game_data, t_files *blox, t_img *imgs);
void	init_imgs(t_long *game_data, t_files *blox, t_img *imgs);

void	place_wall(t_long *game_utils);
void	place_floor(t_long *game_utils);
void	place_collectible(t_long *game_utils);
void	place_exit(t_long *game_utils);
void	place_player(t_long *game_utils);

void	move_player(t_long *game_data, int x, int y);

#endif
