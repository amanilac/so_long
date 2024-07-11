/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:24:52 by amanilac          #+#    #+#             */
/*   Updated: 2024/07/10 14:54:17 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	is_rectangle(t_long *game_data)
{
	int width;
	int y;
	int x;

	y = 0;
	x = 0;
	width = (int)ft_strlen(game_data->map[y]);
	game_data->width = width;
	while (game_data->map[y])
	{
		if ((int)ft_strlen(game_data->map[y]) != width)
			print_error("uh-oh! that's not a rectangle!\n");
		y++;
	}
	// while (game_data->map[0][x])
	// {
	// 	if (game_data->map[0][x] != '1')
	// 		print_error("a valid map must be closed by walls:3c");
	// }
	// while (game_data->map[game_data->height][x])
	// {
	// 	if (game_data->map[game_data->height][x] != '1')
	// 		print_error("a valid map must be closed by walls:3c");
	// }
}

void	map_checker(t_long *game_data)
{
	int y;
	int x;

	count_collectible(game_data);
	count_exit(game_data);
	count_start(game_data);
	y = 0;
	while (game_data->map[y])
	{
		x = 0;
		while (game_data->map[y][x])
		{
			if (game_data->map[y][x] != '0' && game_data->map[y][x] != '1' && game_data->map[y][x] != 'P' && game_data->map[y][x] != 'E' && game_data->map[y][x] != 'C')
				print_error("whoopsie, that's not a valid map!\n");
			x++;
		}
		y++;
	}
}

void count_collectible(t_long *game_data)
{
	int x;
	int y;
	int collectible;

	y = 0;
	collectible = 0;
	while (game_data->map[y])
	{
		x = 0;
		while (game_data->map[y][x])
		{
			if (game_data->map[y][x] == 'C')
				collectible++;
			x++;
		}
		y++;
	}
	if (collectible < 1)
		print_error("a valid map must contain 1 exit, 1 starting position and at least 1 collectible 🤓\n");
	game_data->collectible = collectible;
	game_data->collectible_origin = collectible;
}

void count_exit(t_long *game_data)
{
	int x;
	int y;
	int exit;

	y = 0;
	exit = 0;
	while (game_data->map[y])
	{
		x = 0;
		while (game_data->map[y][x])
		{
			if (game_data->map[y][x] == 'E')
				exit++;
			x++;
		}
		y++;
	}
	if (exit != 1)
		print_error("a valid map must contain 1 exit, 1 starting position and at least 1 collectible 🤓\n");
}

void count_start(t_long *game_data)
{
	int	x;
	int	y;
	int	start;

	y = 0;
	start = 0;
	while(game_data->map[y])
	{
		x = 0;
		while (game_data->map[y][x])
		{
			if (game_data->map[y][x] == 'P')
				start++;
			x++;
		}
		y++;
	}
	if (start != 1)
		print_error("a valid map must contain 1 exit, 1 starting position and at least 1 collectible 🤓\n");
	game_data->player_x = x;
	game_data->player_y = y;
}
