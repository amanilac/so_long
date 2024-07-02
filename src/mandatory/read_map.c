/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annamanilaci <annamanilaci@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:16:24 by amanilac          #+#    #+#             */
/*   Updated: 2024/07/02 18:54:25 by annamanilac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	size_blocks(t_long	*game_data)
{
	int	block;
	int	new_size;

	if (game_data->width > game_data->height)
		block = game_data->width;
	else
		block = game_data->height;
	if (WIDTH > HEIGHT)
		new_size = WIDTH / block;
	else
		new_size = HEIGHT / block;
	game_data->block_size = new_size;
}

void init_textures(t_long *game_data, t_files *blox)
{
	blox->wall = mlx_load_png("./textures/wall.png");
	if (!blox->wall)
		print_error(":()");
	blox->imgs->wall = mlx_texture_to_image(game_data->window, blox->wall);
	blox->floor = mlx_load_png("./textures/floor.png");
	if (!blox->floor)
		print_error(":()");
	blox->imgs->floor = mlx_texture_to_image(game_data->window, blox->floor);
	blox->collectible = mlx_load_png("./textures/diamond.png");
	if (!blox->collectible)
		print_error(":()");
	blox->imgs->collectible = mlx_texture_to_image(game_data->window, blox->collectible);
	blox->exit = mlx_load_png("./textures/exit.png");
	if (!blox->exit)
		print_error(":()");
	blox->imgs->exit = mlx_texture_to_image(game_data->window, blox->exit);
	blox->player = mlx_load_png("./textures/player.png");
	if (!blox->player)
		print_error(":()");
	blox->imgs->player = mlx_texture_to_image(game_data->window, blox->player);
}

void	put_stuff(t_long *game_data)
{
	int	i;
	int	j;

	i = 0;
	game_data->x_pos = 0;
	game_data->y_pos = 0;
	size_blocks(game_data);
	init_textures(game_data, game_data->blox);
	while (game_data->map[i])
	{
		j = 0;
		while(game_data->map[i][j])
		{
			if (game_data->map[i][j] == '1')
				place_wall(game_data);
			if (game_data->map[i][j] == '0')
				place_floor(game_data);
			if (game_data->map[i][j] == 'C')
				place_collectible(game_data);
			if (game_data->map[i][j] == 'E')
				place_exit(game_data);
			if (game_data->map[i][j] == 'P')
				place_player(game_data);
			j++;
			game_data->y_pos += game_data->block_size;
		}
		i++;
		game_data->x_pos += game_data->block_size;
	}	
}

void	open_window(t_long *game_data)
{
	mlx_image_t 	*img;
	mlx_texture_t	*sale;

	game_data->window = mlx_init(WIDTH, HEIGHT, "so_long", false);
	if (!game_data->window)
		print_error("Error opening new game_data->window");
	mlx_key_hook(game_data->window, &key_hooker, game_data);
	mlx_loop(game_data->window);
	mlx_terminate(game_data->window);
}
