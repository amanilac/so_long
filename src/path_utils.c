/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annamanilaci <annamanilaci@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:57:36 by annamanilac       #+#    #+#             */
/*   Updated: 2024/08/07 20:37:48 by annamanilac      ###   ########.fr       */
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
	char	**temp;
	int		y;
	int		x;

	temp = malloc(data->height + 1 * sizeof(char *));
	if (!temp)
		return (NULL);
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			temp[y][x] = data->map[y][x];
			x++;
		}
		y++;
	}
	return (temp);
}

void	flood(t_temp temp, int y, int x)
{
	if (temp.map[y][x] == '1' || y >= temp.height || x >= temp.width
			|| y <= 0 || x <= 0 || temp.map[y][x] == '1')
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
				print_error("Error: no valid path:()");
			}
			else
				x++;
		}
		y++;
	}
}