/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annamanilaci <annamanilaci@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:59:52 by annamanilac       #+#    #+#             */
/*   Updated: 2024/07/03 14:46:42 by annamanilac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	place_wall(t_long *game_utils)
{
	int	x;
	int	y;

	x = game_utils->x_pos;
	y = game_utils->y_pos;
	mlx_resize_image(game_utils->blox->imgs->wall, game_utils->block_size, game_utils->block_size);
	if (mlx_image_to_window(game_utils->window, game_utils->blox->imgs->wall, x, y) < 0)
		print_error("Trouble generating blocks🫥");
}

void	place_floor(t_long *game_utils)
{
	int x;
	int y;

	x = game_utils->x_pos;
	y = game_utils->y_pos;
	mlx_resize_image(game_utils->blox->imgs->floor, game_utils->block_size, game_utils->block_size);
	if (mlx_image_to_window(game_utils->window, game_utils->blox->imgs->floor, x, y) < 0)
		print_error("Trouble generating blocks🫥");
}

void	place_collectible(t_long *game_utils)
{
	int x;
	int y;

	x = game_utils->x_pos;
	y = game_utils->y_pos;
	mlx_resize_image(game_utils->blox->imgs->collectible, game_utils->block_size, game_utils->block_size);
	if (mlx_image_to_window(game_utils->window, game_utils->blox->imgs->collectible, x, y) < 0)
		print_error("Trouble generating blocks🫥");
}

void	place_exit(t_long *game_utils)
{
	int x;
	int y;

	x = game_utils->x_pos;
	y = game_utils->y_pos;
	mlx_resize_image(game_utils->blox->imgs->exit, game_utils->block_size, game_utils->block_size);
	if (mlx_image_to_window(game_utils->window, game_utils->blox->imgs->exit, x, y) < 0)
		print_error("Trouble generating blocks🫥");
}

void	place_player(t_long *game_utils)
{
	int x;
	int y;

	x = game_utils->x_pos;
	y = game_utils->y_pos;
	mlx_resize_image(game_utils->blox->imgs->player, game_utils->block_size, game_utils->block_size);
	if (mlx_image_to_window(game_utils->window, game_utils->blox->imgs->player, x, y) < 0)
		print_error("Trouble generating blocks🫥");
}