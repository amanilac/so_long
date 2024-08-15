/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:31:29 by amanilac          #+#    #+#             */
/*   Updated: 2024/08/15 16:27:16 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH 2048
# define HEIGHT 2048

# include "libft.h"
# include "MLX42.h"
# include "get_next_line_bonus.h"
# include "ft_printf.h"
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_temp
{
	char	**map;
	int		x;
	int		y;
	int		width;
	int		height;
}	t_temp;

typedef struct s_img
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*exit;
	mlx_image_t	*player;
	mlx_image_t	**collectible;
}	t_img;

typedef struct s_files
{
	mlx_texture_t	*wall;
	mlx_texture_t	*player;
	mlx_texture_t	*exit;
	mlx_texture_t	*collectible;
	mlx_texture_t	*floor;
	t_img			*imgs;
}	t_files;

typedef struct s_long
{
	mlx_t	*window;
	char	**map;
	int		player_x;
	int		player_y;
	int		x_pos;
	int		y_pos;
	int		collectible;
	int		exit;
	int		start;
	int		collectible_origin;
	int		width;
	int		height;
	int		moves;
	int		block_size;
	t_files	*blox;
}	t_long;

// ################################## main ##################################

void	check_height(char *map, t_long *data);
void	parse_map(char *file, t_long *data);

// ################################## error #################################

void	print_error(char *str);
void	abandon(char **ptr);
void	destroy_texture(t_files *blox);
void	free_success(t_long *data, bool status);

// ################################# parsing ################################

void	map_checker(t_long *data);
void	is_rectangle(t_long *data);
char	*free_and_join(char *s1, char *s2);
void	count_collectible(t_long *data);
void	count_start(t_long *data);
void	count_exit(t_long *data);

// ############################### generate_map ##############################

void	open_window(t_long *data);
void	init_textures(t_long *data, t_files *blox, t_img *imgs);
void	init_imgs(t_long *data, t_files *blox, t_img *imgs);
void	put_stuff(t_long *data);
void	size_blocks(t_long *data);

// ################################ map_utils ###############################

void	place_wall(t_long *game_utils);
void	place_floor(t_long *game_utils);
void	place_collectible(t_long *game_utils);
void	place_exit(t_long *game_utils);
void	place_player(t_long *game_utils);

// ################################ movement ################################

void	key_hooker(mlx_key_data_t keydata, void *param);
void	move_up(t_long *data);
void	move_down(t_long *data);
void	move_left(t_long *data);
void	move_right(t_long *data);

// ############################### move_utils ###############################

void	shift_up(t_long *data);
void	shift_down(t_long *data);
void	shift_left(t_long *data);
void	shift_right(t_long *data);
void	hide_collectible(t_long *data);

// ############################### more_parsing #############################

void	check_path(t_long *data);
int		check_grid(int y, int x, t_long *data);
void	check_walls(t_long *data);
void	reset_pos(t_long *data);

// ############################### path_utils ###############################

void	create_temp(t_long *data);
char	**duplicate_map(t_long *data);
void	flood(t_temp temp, int y, int x);
void	path_is_valid(t_temp temp);

#endif
