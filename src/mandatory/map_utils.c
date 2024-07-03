/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:59:52 by annamanilac       #+#    #+#             */
/*   Updated: 2024/07/03 15:37:49 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	place_wall(t_long *game_data)
{
	int	x;
	int	y;

	x = game_data->x_pos;
	y = game_data->y_pos;
	if (mlx_image_to_window(game_data->window, game_data->blox->imgs->wall, x, y) < 0)
		print_error("Trouble generating blocks🫥");
}

void	place_floor(t_long *game_data)
{
	int x;
	int y;

	x = game_data->x_pos;
	y = game_data->y_pos;
	if (mlx_image_to_window(game_data->window, game_data->blox->imgs->floor, x, y) < 0)
		print_error("Trouble generating blocks🫥");
}

void	place_collectible(t_long *game_data)
{
	int x;
	int y;

	x = game_data->x_pos;
	y = game_data->y_pos;
	place_floor(game_data);
	if (mlx_image_to_window(game_data->window, game_data->blox->imgs->collectible, x, y) < 0)
		print_error("Trouble generating blocks🫥");
}

void	place_exit(t_long *game_data)
{
	int x;
	int y;

	x = game_data->x_pos;
	y = game_data->y_pos;
	place_floor(game_data);
	if (mlx_image_to_window(game_data->window, game_data->blox->imgs->exit, x, y) < 0)
		print_error("Trouble generating blocks🫥");
}

void	place_player(t_long *game_data)
{
	int x;
	int y;

	x = game_data->x_pos;
	y = game_data->y_pos;
	place_floor(game_data);
	if (mlx_image_to_window(game_data->window, game_data->blox->imgs->player, x, y) < 0)
		print_error("Trouble generating blocks🫥");
}