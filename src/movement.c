/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:31:50 by annamanilac       #+#    #+#             */
/*   Updated: 2024/07/18 20:01:45 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	key_hooker(mlx_key_data_t keydata, void *param)
{
	t_long	*data;

	data = param;
	if (mlx_is_key_down(data->window, MLX_KEY_UP)
		|| mlx_is_key_down(data->window, MLX_KEY_W))
		move_up(data);
	if (mlx_is_key_down(data->window, MLX_KEY_DOWN)
		|| mlx_is_key_down(data->window, MLX_KEY_S))
		move_down(data);
	if (mlx_is_key_down(data->window, MLX_KEY_LEFT)
		|| mlx_is_key_down(data->window, MLX_KEY_A))
		move_left(data);
	if (mlx_is_key_down(data->window, MLX_KEY_RIGHT)
		|| mlx_is_key_down(data->window, MLX_KEY_D))
		move_right(data);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(data->window);
		mlx_terminate(data->window);
		free_success(data, false);
	}
}

void	move_up(t_long *data)
{
	int	x;
	int	y;

	x = data->player_x;
	y = data->player_y;
	if (!check_grid(y - 1, x, data))
	{
		data->player_y -= 1;
		data->y_pos = data->player_y * data->block_size;
		if (data->map[y - 1][x] == 'E' && data->collectible == 0)
			free_success(data, true);
		if (data->map[y - 1][x] == 'C' && data->collectible > 0)
			hide_collectible(data);
		data->map[y][x] = '0';
		data->map[y - 1][x] = 'P';
		data->moves += 1;
		shift_up(data);
		ft_printf("%d\n", data->moves);
	}
}

void	move_down(t_long *data)
{
	int	x;
	int	y;

	x = data->player_x;
	y = data->player_y;
	if (!check_grid(y + 1, x, data))
	{
		data->player_y += 1;
		data->y_pos = data->player_y * data->block_size;
		if (data->map[y + 1][x] == 'E' && data->collectible == 0)
			free_success(data, true);
		if (data->map[y + 1][x] == 'C' && data->collectible > 0)
			hide_collectible(data);
		data->map[y][x] = '0';
		data->map[y + 1][x] = 'P';
		data->moves += 1;
		shift_down(data);
		ft_printf("%d\n", data->moves);
	}
}

void	move_left(t_long *data)
{
	int	x;
	int	y;

	x = data->player_x;
	y = data->player_y;
	if (!check_grid(y, x - 1, data))
	{
		data->player_x -= 1;
		data->x_pos = data->player_x * data->block_size;
		if (data->map[y][x - 1] == 'E' && data->collectible == 0)
			free_success(data, true);
		if (data->map[y][x - 1] == 'C' && data->collectible > 0)
			hide_collectible(data);
		data->map[y][x] = '0';
		data->map[y][x - 1] = 'P';
		data->moves += 1;
		shift_left(data);
		ft_printf("%d\n", data->moves);
	}
}

void	move_right(t_long *data)
{
	int	x;
	int	y;

	x = data->player_x;
	y = data->player_y;
	if (!check_grid(y, x + 1, data))
	{
		data->player_x += 1;
		data->x_pos = data->player_x * data->block_size;
		if (data->map[y][x + 1] == 'E' && data->collectible == 0)
			free_success(data, true);
		if (data->map[y][x + 1] == 'C' && data->collectible > 0)
			hide_collectible(data);
		data->map[y][x] = '0';
		data->map[y][x + 1] = 'P';
		data->moves += 1;
		shift_right(data);
		ft_printf("%d\n", data->moves);
	}
}
