/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:13:23 by amanilac          #+#    #+#             */
/*   Updated: 2024/07/18 17:55:43 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	hide_collectible(t_long *game_data)
{
	int	i;

	i = 0;
	while (i < game_data->collectible_origin)
	{
		if (game_data->blox->imgs->collectible[i]->instances->y == game_data->y_pos
			&& game_data->blox->imgs->collectible[i]->instances->x == game_data->x_pos)
			game_data->blox->imgs->collectible[i]->instances->enabled = false;
		i++;
	}
	game_data->collectible -= 1;
}

void	shift_up(t_long *game_data)
{
	int	move;

	move = 0;
	while (move < game_data->block_size)
	{
		game_data->blox->imgs->player->instances->y -= 1;
		move++;
	}
}

void	shift_down(t_long *game_data)
{
	int	move;

	move = 0;
	while (move < game_data->block_size)
	{
		game_data->blox->imgs->player->instances->y += 1;
		move++;
	}
}

void	shift_left(t_long *game_data)
{
	int move;

	move = 0;
	while (move < game_data->block_size)
	{
		game_data->blox->imgs->player->instances->x -= 1;
		move++;
	}
}

void	shift_right(t_long *game_data)
{
	int move;

	move = 0;
	while (move < game_data->block_size)
	{
		game_data->blox->imgs->player->instances->x += 1;
		move++;
	}
}