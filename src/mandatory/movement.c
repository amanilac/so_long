/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:31:50 by annamanilac       #+#    #+#             */
/*   Updated: 2024/07/16 13:27:08 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void key_hooker(mlx_key_data_t keydata, void *param)
{
	t_long *data;

	data = param;
	if (mlx_is_key_down(data->window, MLX_KEY_UP) || mlx_is_key_down(data->window, MLX_KEY_W))
		move_up(data);
	if (mlx_is_key_down(data->window, MLX_KEY_DOWN) || mlx_is_key_down(data->window, MLX_KEY_S))
		move_down(data);
	if (mlx_is_key_down(data->window, MLX_KEY_LEFT) || mlx_is_key_down(data->window, MLX_KEY_A))
		move_left(data);
	if (mlx_is_key_down(data->window, MLX_KEY_RIGHT) || mlx_is_key_down(data->window, MLX_KEY_D))
		move_right(data);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(data->window);
		mlx_terminate(data->window);
		exit(EXIT_SUCCESS);
	}
}

void move_up(t_long *game_data)
{
	int x;
	int y;

	x = game_data->player_x;
	y = game_data->player_y;
	if ((game_data->map[y - 1][x] && game_data->map[y - 1][x] != 'E') || (game_data->map[y - 1][x] && game_data->map[y - 1][x] == 'E' && game_data->collectible == 0))
	{
		if (game_data->map[y - 1][x] && game_data->map[y - 1][x] != '1')
		{
			game_data->player_y -= 1;
			game_data->y_pos = game_data->player_y * game_data->block_size;
			if (game_data->map[y - 1][x] == 'E' && game_data->collectible == 0)
				exit(EXIT_SUCCESS);
			if (game_data->map[y - 1][x] == 'C' && game_data->collectible > 0)
				hide_collectible(game_data);
			game_data->map[y][x] = '0';
			game_data->map[y - 1][x] = 'P';
			game_data->moves += 1;
			shift_up(game_data);
			// game_data->blox->imgs->player->instances->y -= game_data->block_size;
			ft_printf("%d\n", game_data->moves);
		}
	}
}

void move_down(t_long *game_data)
{
	int x;
	int y;

	x = game_data->player_x;
	y = game_data->player_y;
	if ((game_data->map[y + 1][x] && game_data->map[y + 1][x] != 'E') || (game_data->map[y + 1][x] && game_data->map[y + 1][x] == 'E' && game_data->collectible == 0))
	{
		if (game_data->map[y + 1][x] && game_data->map[y + 1][x] != '1')
		{
			game_data->player_y += 1;
			game_data->y_pos = game_data->player_y * game_data->block_size;
			if (game_data->map[y + 1][x] == 'E' && game_data->collectible == 0)
				exit(EXIT_SUCCESS);
			if (game_data->map[y + 1][x] == 'C' && game_data->collectible > 0)
				hide_collectible(game_data);
			game_data->map[y][x] = '0';
			game_data->map[y + 1][x] = 'P';
			game_data->moves += 1;
			shift_down(game_data);
			// game_data->blox->imgs->player->instances->y += game_data->block_size;
			ft_printf("%d\n", game_data->moves);
		}
	}
}

void move_left(t_long *game_data)
{
	int x;
	int y;

	x = game_data->player_x;
	y = game_data->player_y;
	if ((game_data->map[y][x - 1] && game_data->map[y][x - 1] != 'E') || (game_data->map[y][x - 1] && game_data->map[y][x - 1] == 'E' && game_data->collectible == 0))
	{
		if (game_data->map[y][x - 1] && game_data->map[y][x - 1] != '1')
		{
			game_data->player_x -= 1;
			game_data->x_pos = game_data->player_x * game_data->block_size;
			if (game_data->map[y][x - 1] == 'E' && game_data->collectible == 0)
				exit(EXIT_SUCCESS);
			if (game_data->map[y][x - 1] == 'C' && game_data->collectible > 0)
				hide_collectible(game_data);
			game_data->map[y][x] = '0';
			game_data->map[y][x - 1] = 'P';
			game_data->moves += 1;
			shift_left(game_data);
			// game_data->blox->imgs->player->instances->x -= game_data->block_size;
			ft_printf("%d\n", game_data->moves);
		}
	}
}

void move_right(t_long *game_data)
{
	int x;
	int y;

	x = game_data->player_x;
	y = game_data->player_y;
	if ((game_data->map[y][x + 1] && game_data->map[y][x + 1] != 'E') || (game_data->map[y][x + 1] && game_data->map[y][x + 1] == 'E' && game_data->collectible == 0))
	{
		if (game_data->map[y][x + 1] && game_data->map[y][x + 1] != '1')
		{
			game_data->player_x += 1;
			game_data->x_pos = game_data->player_x * game_data->block_size;
			if (game_data->map[y][x + 1] == 'E' && game_data->collectible == 0)
				exit(EXIT_SUCCESS);
			if (game_data->map[y][x + 1] == 'C' && game_data->collectible > 0)
				hide_collectible(game_data);
			game_data->map[y][x] = '0';
			game_data->map[y][x + 1] = 'P';
			game_data->moves += 1;
			shift_right(game_data);
			// game_data->blox->imgs->player->instances->x += game_data->block_size;
			ft_printf("%d\n", game_data->moves);
		}
	}
}
