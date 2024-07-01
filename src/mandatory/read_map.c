/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:16:24 by amanilac          #+#    #+#             */
/*   Updated: 2024/07/01 19:55:05 by amanilac         ###   ########.fr       */
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

void	put_stuff(t_long *game_data)
{
	int	i;
	int	j;

	size_blocks(game_data);
	
}

void	place_walls(t_long *game_data)
{
	mlx_image_t		*also_wall;
	mlx_texture_t	*wall;
	int				y;
	int				x;
	int				i;
	int				j;

	y = 0;
	x = 0;
	i = 0;
	wall = mlx_load_png("./textures/wall.png");
	if (!wall)
		print_error("oops");
	also_wall = mlx_texture_to_image(game_data->window, wall);
	mlx_resize_image(also_wall, game_data->block_size, game_data->block_size); 
	if (!wall)
		print_error("Error generating image");
	while (game_data->map[i])
	{
		j = 0;
		while (game_data->map[i][j])
		{
			if (game_data->map[i][j] == 1)
				mlx_image_to_window(game_data->window, also_wall, x, y);
			x += game_data->block_size;
			j++;
		}
		y += game_data->block_size;
		i++;
	}
}

void	open_window(t_long *game_data)
{
	mlx_image_t 	*img;
	mlx_texture_t	*sale;

	sale = mlx_load_png("./textures/sale.png");
	game_data->window = mlx_init(WIDTH, HEIGHT, "so_long", false);
	if (!game_data->window)
		print_error("Error opening new game_data->window");
	sale = mlx_load_png("./textures/sale.png");
	if (!sale)
		print_error("oops");
	img = mlx_texture_to_image(game_data->window, sale);
	mlx_resize_image(img, WIDTH, HEIGHT);
	place_walls(game_data);
	if (!img || (mlx_image_to_window(game_data->window, img, 0, 0) < 0))
		print_error("Error generating image");
	// place_walls(game_data);
	mlx_key_hook(game_data->window, &key_hooker, game_data);
	mlx_loop(game_data->window);
	mlx_terminate(game_data->window);
}
