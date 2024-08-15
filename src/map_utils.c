/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:59:52 by annamanilac       #+#    #+#             */
/*   Updated: 2024/08/15 15:56:38 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	place_floor(t_long *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		data->x_pos = 0;
		while (data->map[y][x])
		{
			if (mlx_image_to_window(data->window,
					data->blox->imgs->floor, data->x_pos,
					data->y_pos) < 0)
				print_error("trouble generating blocks🫥");
			x++;
			data->x_pos += data->block_size;
		}
		y++;
		data->y_pos += data->block_size;
	}
	reset_pos(data);
}

void	place_wall(t_long *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		data->x_pos = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
			{
				if (mlx_image_to_window(data->window,
						data->blox->imgs->wall, data->x_pos,
						data->y_pos) < 0)
					print_error("trouble generating blocks🫥");
			}
			x++;
			data->x_pos += data->block_size;
		}
		y++;
		data->y_pos += data->block_size;
	}
	reset_pos(data);
}

void	place_collectible(t_long *data)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (data->map[y])
	{
		x = 0;
		data->x_pos = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x++] == 'C')
			{
				if (mlx_image_to_window(data->window, data->blox->imgs
						->collectible[i], data->x_pos, data->y_pos) < 0)
					print_error("trouble generating blocks🫥");
				i++;
			}
			data->x_pos += data->block_size;
		}
		y++;
		data->y_pos += data->block_size;
	}
	reset_pos(data);
}

void	place_exit(t_long *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		data->x_pos = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'E')
			{
				if (mlx_image_to_window(data->window,
						data->blox->imgs->exit, data->x_pos,
						data->y_pos) < 0)
					print_error("trouble generating blocks🫥");
			}
			x++;
			data->x_pos += data->block_size;
		}
		y++;
		data->y_pos += data->block_size;
	}
	reset_pos(data);
}

void	place_player(t_long *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		data->x_pos = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				if (mlx_image_to_window(data->window,
						data->blox->imgs->player, data->x_pos,
						data->y_pos) < 0)
					print_error("trouble generating blocks🫥");
				data->player_x = x;
				data->player_y = y;
			}
			x++;
			data->x_pos += data->block_size;
		}
		y++;
		data->y_pos += data->block_size;
	}
}
