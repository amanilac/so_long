/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:16:24 by amanilac          #+#    #+#             */
/*   Updated: 2024/07/08 17:02:43 by amanilac         ###   ########.fr       */
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

void init_textures(t_long *game_data, t_files *blox, t_img *imgs)
{
	game_data->window = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!game_data->window)
		print_error("Error initializing window");
	blox->wall = mlx_load_png("./textures/wall.png");
	if (!blox->wall)
		print_error(":(\n");
	blox->floor = mlx_load_png("./textures/floor.png");
	if (!blox->floor)
		print_error(":(\n");
	blox->collectible = mlx_load_png("./textures/diamond.png");
	if (!blox->collectible)
		print_error(":(\n");
	blox->exit = mlx_load_png("./textures/exit.png");
	if (!blox->exit)
		print_error(":(\n");
	blox->player = mlx_load_png("./textures/player.png");
	if (!blox->player)
		print_error(":(\n");
	init_imgs(game_data, blox, imgs);
}

void	init_imgs(t_long *game_data, t_files *blox, t_img *imgs)
{
	int	i;

	i = 0;
	imgs->collectible = ft_calloc(game_data->collectible, sizeof (mlx_image_t *));
	size_blocks(game_data);
	imgs->wall = mlx_texture_to_image(game_data->window, blox->wall);
	mlx_resize_image(imgs->wall, game_data->block_size, game_data->block_size);
	imgs->floor = mlx_texture_to_image(game_data->window, blox->floor);
	mlx_resize_image(imgs->floor, game_data->block_size, game_data->block_size);
	while (i < game_data->collectible)
	{
		imgs->collectible[i] = mlx_texture_to_image(game_data->window, blox->collectible);
		mlx_resize_image(imgs->collectible[i], game_data->block_size, game_data->block_size);
		i++;
	}
	imgs->exit = mlx_texture_to_image(game_data->window, blox->exit);
	mlx_resize_image(imgs->exit, game_data->block_size, game_data->block_size);
	imgs->player = mlx_texture_to_image(game_data->window, blox->player);
	mlx_resize_image(imgs->player, game_data->block_size, game_data->block_size);
}

void	put_stuff(t_long *game_data)
{
	game_data->x_pos = 0;
	game_data->y_pos = 0;
	place_floor(game_data);
	place_wall(game_data);
	place_collectible(game_data);
	place_exit(game_data);
	place_player(game_data);
}

void	open_window(t_long *game_data)
{
	game_data->moves = 0;
	put_stuff(game_data);
	mlx_key_hook(game_data->window, &key_hooker, game_data);
	mlx_loop(game_data->window);
	mlx_terminate(game_data->window);
}
