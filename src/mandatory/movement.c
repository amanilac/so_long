/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annamanilaci <annamanilaci@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:31:50 by annamanilac       #+#    #+#             */
/*   Updated: 2024/06/28 16:44:47 by annamanilac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_player(char **map, mlx_t *window)
{
	int i;
	int j;
	int	collectible;

	i = 1;
	j = 5;
	collectible = map_checker(map);
	while (collectible > 0 && map[i][j] != 'E')
	{
		if (mlx_is_key_down(window, MLX_KEY_UP))
			{
				while ((i > 0) && (i < map_height(map)) && (map[i][j] != '1'))
				{
					i++;
					if (map[i][j] == 'C')
						collectible--;
					map[i - 1][j] = '0';
					map[i][j] = 'P';
				}
			}
		else if (mlx_is_key_down(window, MLX_KEY_DOWN))
		{
			while ((i > 0) && (i < map_height(map)) && (map[i][j] != '1'))
			{
				i--;
				if (map[i][j] == 'C')
					collectible--;
				map[i + 1][j] = '0';
				map[i][j] = 'P';
			}
		}
	}
}
