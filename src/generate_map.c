/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:16:24 by amanilac          #+#    #+#             */
/*   Updated: 2024/07/19 14:44:54 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	size_blocks(t_long	*data)
{
	int	new_size;

	if (WIDTH > HEIGHT)
		new_size = WIDTH / data->width;
	else
		new_size = HEIGHT / data->height;
	data->block_size = new_size;
}

void	init_textures(t_long *data, t_files *blox, t_img *imgs)
{
	data->window = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!data->window)
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
	init_imgs(data, blox, imgs);
}

void	init_imgs(t_long *data, t_files *blox, t_img *imgs)
{
	int	i;

	i = 0;
	imgs->collectible
		= ft_calloc(data->collectible, sizeof (mlx_image_t *));
	size_blocks(data);
	imgs->wall = mlx_texture_to_image(data->window, blox->wall);
	mlx_resize_image(imgs->wall, data->block_size, data->block_size);
	imgs->floor = mlx_texture_to_image(data->window, blox->floor);
	mlx_resize_image(imgs->floor, data->block_size, data->block_size);
	while (i < data->collectible)
	{
		imgs->collectible[i]
			= mlx_texture_to_image(data->window, blox->collectible);
		mlx_resize_image(imgs->collectible[i],
			data->block_size, data->block_size);
		i++;
	}
	imgs->exit = mlx_texture_to_image(data->window, blox->exit);
	mlx_resize_image(imgs->exit, data->block_size, data->block_size);
	imgs->player = mlx_texture_to_image(data->window, blox->player);
	mlx_resize_image(imgs->player,
		data->block_size, data->block_size);
	destroy_texture(blox);
}

void	put_stuff(t_long *data)
{
	data->x_pos = 0;
	data->y_pos = 0;
	place_floor(data);
	place_wall(data);
	place_collectible(data);
	place_exit(data);
	place_player(data);
	data->x_pos = data->player_x * data->block_size;
	data->y_pos = data->player_y * data->block_size;
}

void	open_window(t_long *data)
{
	data->moves = 0;
	put_stuff(data);
	mlx_key_hook(data->window, &key_hooker, data);
	mlx_loop(data->window);
	mlx_terminate(data->window);
}