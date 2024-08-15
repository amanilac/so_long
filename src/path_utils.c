/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:57:36 by annamanilac       #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/08/11 15:48:45 by annamanilac      ###   ########.fr       */
=======
/*   Updated: 2024/08/15 16:22:55 by amanilac         ###   ########.fr       */
>>>>>>> 1dd832e0f53541fe6d43c09f0bb3580769c827c3
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	create_temp(t_long *data)
{
	t_temp	temp;

	ft_memset(&temp, 0, sizeof(temp));
	temp.height = data->height;
	temp.width = data->width;
	temp.x = data->player_x;
	temp.y = data->player_y;
	temp.map = duplicate_map(data);
	flood(temp, temp.y, temp.x);
	path_is_valid(temp);
	if (temp.map)
		abandon(temp.map);
}

char	**duplicate_map(t_long *data)
{
	char	**temp_map;
	int		y;

	temp_map = malloc((data->height + 1) * sizeof(char *));
	if (!temp_map)
		return (NULL);
	y = 0;
	while (data->map[y])
	{
		temp_map[y] = ft_strdup(data->map[y]);
		y++;
	}
	temp_map[y] = NULL;
	return (temp_map);
}

void	flood(t_temp temp, int y, int x)
{
	if (temp.map[y][x] == '1' || y >= temp.height || x >= temp.width
			|| y <= 0 || x <= 0)
		return ;
	if (temp.map[y][x] == '0' || temp.map[y][x] == 'C'
		|| temp.map[y][x] == 'E' || temp.map[y][x] == 'P')
	{
		temp.map[y][x] = 'X';
		flood(temp, y + 1, x);
		flood(temp, y - 1, x);
		flood(temp, y, x + 1);
		flood(temp, y, x - 1);
	}
}

void	path_is_valid(t_temp temp)
{
	int	y;
	int	x;

	y = 0;
	while (temp.map[y])
	{
		x = 0;
		while (temp.map[y][x])
		{
			if (temp.map[y][x] == 'E' || temp.map[y][x] == 'C')
			{
				abandon(temp.map);
<<<<<<< HEAD
				print_error("Error: no valid path🙁\n");
=======
				print_error("no valid path:(\n");
>>>>>>> 1dd832e0f53541fe6d43c09f0bb3580769c827c3
			}
			else
				x++;
		}
		y++;
	}
}
