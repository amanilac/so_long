/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:13:23 by amanilac          #+#    #+#             */
/*   Updated: 2024/07/18 19:34:01 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	hide_collectible(t_long *data)
{
	int	i;

	i = 0;
	while (i < data->collectible_origin)
	{
		if (data->blox->imgs->collectible[i]->instances->y
			== data->y_pos && data->blox->imgs->collectible[i]
			->instances->x == data->x_pos)
			data->blox->imgs->collectible[i]->instances->enabled = false;
		i++;
	}
	data->collectible -= 1;
}

void	shift_up(t_long *data)
{
	int	move;

	move = 0;
	while (move < data->block_size)
	{
		data->blox->imgs->player->instances->y -= 1;
		move++;
	}
}

void	shift_down(t_long *data)
{
	int	move;

	move = 0;
	while (move < data->block_size)
	{
		data->blox->imgs->player->instances->y += 1;
		move++;
	}
}

void	shift_left(t_long *data)
{
	int	move;

	move = 0;
	while (move < data->block_size)
	{
		data->blox->imgs->player->instances->x -= 1;
		move++;
	}
}

void	shift_right(t_long *data)
{
	int	move;

	move = 0;
	while (move < data->block_size)
	{
		data->blox->imgs->player->instances->x += 1;
		move++;
	}
}
