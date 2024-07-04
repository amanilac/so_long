/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:59:52 by annamanilac       #+#    #+#             */
/*   Updated: 2024/07/04 17:11:03 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void place_floor(t_long *game_data)
{
	int x;
	int y;

	y = 0;
	while (game_data->map[y])
	{
		x = 0;
		game_data->x_pos = 0;
		while (game_data->map[y][x])
		{
			if (mlx_image_to_window(game_data->window, game_data->blox->imgs->floor, game_data->x_pos, game_data->y_pos) < 0)
				print_error("Trouble generating blocks🫥");
			x++;
			game_data->x_pos += game_data->block_size;
		}
		y++;
		game_data->y_pos += game_data->block_size;
	}
	game_data->x_pos = 0;
	game_data->y_pos = 0;
}

void	place_wall(t_long *game_data)
{
	int	x;
	int	y;

	y = 0;
	while (game_data->map[y])
	{
		x = 0;
		game_data->x_pos = 0;
		while (game_data->map[y][x])
		{
			if (game_data->map[y][x] == '1')
			{
				if (mlx_image_to_window(game_data->window, game_data->blox->imgs->wall, game_data->x_pos, game_data->y_pos) < 0)
					print_error("Trouble generating blocks🫥");
			}
			x++;
			game_data->x_pos += game_data->block_size;
		}
		y++;
		game_data->y_pos += game_data->block_size;
	}
	game_data->x_pos = 0;
	game_data->y_pos = 0;
}

void place_collectible(t_long *game_data)
{
	int x;
	int y;

	y = 0;
	while (game_data->map[y])
	{
		x = 0;
		game_data->x_pos = 0;
		while (game_data->map[y][x])
		{
			if (game_data->map[y][x] == 'C')
			{
				if (mlx_image_to_window(game_data->window, game_data->blox->imgs->collectible, game_data->x_pos, game_data->y_pos) < 0)
					print_error("Trouble generating blocks🫥");
			}
			x++;
			game_data->x_pos += game_data->block_size;
		}
		y++;
		game_data->y_pos += game_data->block_size;
	}
	game_data->x_pos = 0;
	game_data->y_pos = 0;
}

void place_exit(t_long *game_data)
{
	int x;
	int y;

	y = 0;
	while (game_data->map[y])
	{
		x = 0;
		game_data->x_pos = 0;
		while (game_data->map[y][x])
		{
			if (game_data->map[y][x] == 'E')
			{
				if (mlx_image_to_window(game_data->window, game_data->blox->imgs->exit, game_data->x_pos, game_data->y_pos) < 0)
					print_error("Trouble generating blocks🫥");
			}
			x++;
			game_data->x_pos += game_data->block_size;
		}
		y++;
		game_data->y_pos += game_data->block_size;
	}
	game_data->x_pos = 0;
	game_data->y_pos = 0;
}

void place_player(t_long *game_data)
{
	int x;
	int y;

	y = 0;
	while (game_data->map[y])
	{
		x = 0;
		game_data->x_pos = 0;
		while (game_data->map[y][x])
		{
			if (game_data->map[y][x] == 'P')
			{
				if (mlx_image_to_window(game_data->window, game_data->blox->imgs->player, game_data->x_pos, game_data->y_pos) < 0)
					print_error("Trouble generating blocks🫥");
			}
			x++;
			game_data->x_pos += game_data->block_size;
		}
		y++;
		game_data->y_pos += game_data->block_size;
	}
	game_data->x_pos = 0;
	game_data->y_pos = 0;
}

// void	place_floor(t_long *game_data)
// {
// 	int x;
// 	int y;

// 	x = game_data->x_pos;
// 	y = game_data->y_pos;
// 	if (mlx_image_to_window(game_data->window, game_data->blox->imgs->floor, x, y) < 0)
// 		print_error("Trouble generating blocks🫥");
// }

// void	place_collectible(t_long *game_data)
// {
// 	int x;
// 	int y;

// 	x = game_data->x_pos;
// 	y = game_data->y_pos;
// 	place_floor(game_data);
// 	if (mlx_image_to_window(game_data->window, game_data->blox->imgs->collectible, x, y) < 0)
// 		print_error("Trouble generating blocks🫥");
// }

// void	place_exit(t_long *game_data)
// {
// 	int x;
// 	int y;

// 	x = game_data->x_pos;
// 	y = game_data->y_pos;
// 	place_floor(game_data);
// 	if (mlx_image_to_window(game_data->window, game_data->blox->imgs->exit, x, y) < 0)
// 		print_error("Trouble generating blocks🫥");
// }

// void	place_player(t_long *game_data)
// {
// 	int x;
// 	int y;

// 	x = game_data->x_pos;
// 	y = game_data->y_pos;
// 	place_floor(game_data);
// 	if (mlx_image_to_window(game_data->window, game_data->blox->imgs->player, x, y) < 0)
// 		print_error("Trouble generating blocks🫥");
// }