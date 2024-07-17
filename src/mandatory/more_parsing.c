/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:39:55 by amanilac          #+#    #+#             */
/*   Updated: 2024/07/17 19:11:03 by amanilac         ###   ########.fr       */
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
	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			// if (map[y][x] == 'E')
			// {
			// 	if ((map[y][x - 1] && map[y][x - 1] == '1') && (map[y][x + 1] && map[y][x + 1] == '1') && (map[y - 1][x] 
			// 		&& map[y - 1][x] == '1') && (map[y + 1][x] && map[y + 1][x] == '1'))
			// 	print_error("invalid path bro!");
			// }
			// if (map[y][x] == 'C')
			// {
			// 	if ((map[y][x - 1] && map[y][x - 1] == '1' || map[y][x - 1] == 'E') && (map[y][x + 1] && map[y][x + 1] == '1' || map[y][x + 1] == 'E') 
			// 		|| (map[y - 1][x] && map[y  - 1][x] == '1' || map[y - 1][x] == 'E') || (map[y + 1][x] && map[y  + 1][x] == '1' || map[y + 1][x] == 'E'))
			// 	print_error("invalid path bro!");
			// }
			if (map[y][x] == 'P' || map[y][x] == 'E' || map[y][x] == 'C')
			{
				if (map[y][x] == 'E')
				{
					if ((map[y][x - 1] && map[y][x - 1] == '1') && (map[y][x + 1] && map[y][x + 1] == '1') && (map[y - 1][x] 
						&& map[y - 1][x] == '1') && (map[y + 1][x] && map[y + 1][x] == '1'))
					print_error("invalid path bro!");
				}
				else if ((map[y][x - 1] && map[y][x - 1] == '1' || map[y][x - 1] == 'E') && (map[y][x + 1] && map[y][x + 1] == '1' || map[y][x + 1] == 'E') 
					|| (map[y - 1][x] && map[y  - 1][x] == '1' || map[y - 1][x] == 'E') && (map[y + 1][x] && map[y  + 1][x] == '1' || map[y + 1][x] == 'E'))
				print_error("invalid path bro!");
			}
			x++;
		}
		y++;
	}
}

c