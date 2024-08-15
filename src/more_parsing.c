/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:39:55 by amanilac          #+#    #+#             */
/*   Updated: 2024/08/15 15:56:38 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_path(t_long *data)
{
	create_temp(data);
}

int	check_grid(int y, int x, t_long *data)
{
	if ((data->map[y][x] && data->map[y][x] != 'E'
		&& data->map[y][x] != '1') || (data->map[y][x]
			&& data->map[y][x] == 'E' && data->collectible == 0))
		return (0);
	return (1);
}

void	check_walls(t_long *data)
{
	int	x;
	int	y;

	x = 0;
	y = data->height;
	while (data->map[0][x])
	{
		if (data->map[0][x] != '1')
			print_error("valid map must be closed off by walls!\n");
		x++;
	}
	x = 0;
	y -= 1;
	while (data->map[y][x])
	{
		if (data->map[y][x] != '1')
			print_error("valid map must be closed off by walls!\n");
		x++;
	}
}

void	reset_pos(t_long *data)
{
	data->x_pos = 0;
	data->y_pos = 0;
}
