/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:39:55 by amanilac          #+#    #+#             */
/*   Updated: 2024/07/18 17:50:24 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_path(t_long *game_data)
{
	char	**map;
	int		y;
	int		x;

	y = 0;
	map = game_data->map;
	while (map[++y])
	{
		x = 0;
		while (map[y][++x])
		{
			if (map[y][x] == 'P' || map[y][x] == 'E' || map[y][x] == 'C')
			{
				if ((map[y][x - 1] == '1' || map[y][x - 1] == 'E')
					&& (map[y][x + 1] == '1' || map[y][x + 1] == 'E')
						&& (map[y - 1][x] == '1' || map[y - 1][x] == 'E')
							&& (map[y + 1][x] == '1' || map[y + 1][x] == 'E'))
					print_error("invalid path bro!");
			}
		}
	}
}

int	check_grid(int y, int x, t_long *game_data)
{
	if ((game_data->map[y][x] && game_data->map[y][x] != 'E'
		&& game_data->map[y][x] != '1') || (game_data->map[y][x]
			&& game_data->map[y][x] == 'E' && game_data->collectible == 0))
		return (0);
	return (1);
}