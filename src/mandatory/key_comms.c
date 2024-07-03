/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_comms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:03:39 by annamanilac       #+#    #+#             */
/*   Updated: 2024/07/03 18:53:58 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	print_array(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

void	move_up(t_long *game_data)
{
	int x;
	int y;

	x = game_data->player_x;
	y = game_data->player_y;
	if ((game_data->map[x - 1][y] && game_data->map[x - 1][y] != 'E') || (game_data->map[x - 1][y] && game_data->map[x - 1][y] == 'E' && game_data->collectible == 0))
	{
		if (game_data->map[x - 1][y] && game_data->map[x - 1][y] != '1')
		{
			if (game_data->map[x - 1][y] == 'E' && game_data->collectible == 0)
				exit (EXIT_SUCCESS);
			if (game_data->map[x - 1][y] == 'C' && game_data->collectible > 0)
				game_data->collectible -= 1;
			game_data->map[x][y] = '0';
			game_data->map[x - 1][y] = 'P';
			game_data->player_x -= 1;
			game_data->moves += 1;
			game_data->x_pos = game_data->player_x * game_data->block_size;
			game_data->y_pos = game_data->player_y * game_data->block_size;
			move_player(game_data, game_data->x_pos, game_data->y_pos);
			ft_printf("%d\n", game_data->moves);
		}
	}
}

void	move_down(t_long *game_data)
{
	int x;
	int y;

	x = game_data->player_x;
	y = game_data->player_y;
	if ((game_data->map[x + 1][y] && game_data->map[x + 1][y] != 'E') || (game_data->map[x + 1][y] && game_data->map[x + 1][y] == 'E' && game_data->collectible == 0))
	{
		if (game_data->map[x + 1][y] && game_data->map[x + 1][y] != '1')
		{
			if (game_data->map[x + 1][y] == 'E' && game_data->collectible == 0)
				exit (EXIT_SUCCESS);
			if (game_data->map[x + 1][y] == 'C' && game_data->collectible > 0)
					game_data->collectible -= 1;
			game_data->map[x][y] = '0';
			game_data->map[x + 1][y] = 'P';
			game_data->player_x += 1;
			game_data->moves += 1;
			game_data->x_pos = game_data->player_x * game_data->block_size;
			game_data->y_pos = game_data->player_y * game_data->block_size;
			move_player(game_data, game_data->x_pos, game_data->y_pos);
			ft_printf("%d\n", game_data->moves);
		}
	}
}

void	move_left(t_long *game_data)
{
	int x;
	int y;

	x = game_data->player_x;
	y = game_data->player_y;
	if ((game_data->map[x][y - 1] && game_data->map[x][y - 1] != 'E') || (game_data->map[x][y - 1] && game_data->map[x][y - 1] == 'E' && game_data->collectible == 0))
	{
		if (game_data->map[x][y - 1] && game_data->map[x][y - 1] != '1')
		{
			if (game_data->map[x][y - 1] == 'E' && game_data->collectible == 0)
				exit (EXIT_SUCCESS);
			if (game_data->map[x][y - 1] == 'C' && game_data->collectible > 0)
					game_data->collectible -= 1;
			game_data->map[x][y] = '0';
			game_data->map[x][y - 1] = 'P';
			game_data->player_y -= 1;
			game_data->moves += 1;
			game_data->x_pos = game_data->player_x * game_data->block_size;
			game_data->y_pos = game_data->player_y * game_data->block_size;
			move_player(game_data, game_data->x_pos, game_data->y_pos);
			ft_printf("%d\n", game_data->moves);
		}
	}
}

void	move_right(t_long *game_data)
{
	int x;
	int y;

	x = game_data->player_x;
	y = game_data->player_y;
	if ((game_data->map[x][y + 1] && game_data->map[x][y + 1] != 'E') || (game_data->map[x][y + 1] && game_data->map[x][y + 1] == 'E' && game_data->collectible == 0))
	{
		if (game_data->map[x][y + 1] && game_data->map[x][y + 1] != '1')
		{
			if (game_data->map[x][y + 1] == 'E' && game_data->collectible == 0)
				exit (EXIT_SUCCESS);
			if (game_data->map[x][y + 1] == 'C' && game_data->collectible > 0)
					game_data->collectible -= 1;
			game_data->map[x][y] = '0';
			game_data->map[x][y + 1] = 'P';
			game_data->player_y += 1;
			game_data->moves += 1;
			game_data->x_pos = game_data->player_x * game_data->block_size;
			game_data->y_pos = game_data->player_y * game_data->block_size;
			move_player(game_data, game_data->x_pos, game_data->y_pos);
			ft_printf("%d\n", game_data->moves);
		}
	}
}

void key_hooker(mlx_key_data_t keydata, void *param)
{
	t_long *data;

	data = param;
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W) && (keydata.action == MLX_PRESS))
		move_up(data);
	if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S) && (keydata.action == MLX_PRESS))
		move_down(data);
	if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A) && (keydata.action == MLX_PRESS))
		move_left(data);
	if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D) && (keydata.action == MLX_PRESS))
		move_right(data);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(data->window);
		mlx_terminate(data->window);
		exit(EXIT_SUCCESS);
	}
	print_array(data->map);
}