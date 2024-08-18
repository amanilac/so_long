/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:24:52 by amanilac          #+#    #+#             */
/*   Updated: 2024/08/18 20:00:34 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	is_rectangle(t_long *data)
{
	int	width;
	int	y;

	y = 0;
	width = (int)ft_strlen(data->map[y]);
	data->width = width;
	while (data->map[y])
	{
		if ((int)ft_strlen(data->map[y]) != width)
			print_error("uh-oh! that's not a rectangle!\n", data);
		y++;
	}
	check_walls(data);
}

void	map_checker(t_long *data)
{
	int		y;
	int		x;

	count_collectible(data);
	count_exit(data);
	count_start(data);
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] != '0' && data->map[y][x] != '1'
				&& data->map[y][x] != 'P' && data->map[y][x] != 'E'
				&& data->map[y][x] != 'C')
				print_error("whoopsie, that's not a valid map!\n", data);
			x++;
		}
		y++;
	}
}

void	count_collectible(t_long *data)
{
	int	x;
	int	y;
	int	collectible;

	y = 0;
	collectible = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'C')
				collectible++;
			x++;
		}
		y++;
	}
	if (collectible < 1)
		print_error("a map must contain 1 exit, 1 start & collectibles\n", data);
	data->collectible = collectible;
	data->collectible_origin = collectible;
}

void	count_exit(t_long *data)
{
	int	x;
	int	y;
	int	exit;

	y = 0;
	exit = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'E')
				exit++;
			x++;
		}
		y++;
	}
	if (exit != 1)
		print_error("a map must contain 1 exit, 1 start & collectibles\n", data);
}

void	count_start(t_long *data)
{
	int	x;
	int	y;
	int	start;

	y = 0;
	start = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
				start++;
			}
			x++;
		}
		y++;
	}
	if (start != 1)
		print_error("a map must contain 1 exit, 1 start & collectibles\n", data);
}
