/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annamanilaci <annamanilaci@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:24:52 by amanilac          #+#    #+#             */
/*   Updated: 2024/07/02 14:07:44 by annamanilac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	is_rectangle(t_long *game_data)
{
	int width;
	int i;

	i = 0;
	width = (int)ft_strlen(game_data->map[i]);
	game_data->width = width;
	while (game_data->map[i])
	{
		if ((int)ft_strlen(game_data->map[i]) != width)
			print_error("uh-oh! that's not a rectangle!\n");
		i++;
	}
}

void	map_checker(t_long *game_data)
{
	int collectible;
	int start;
	int exit;
	int i;
	int j;

	collectible = 0;
	start = 0;
	exit = 0;
	i = 0;
	while (game_data->map[i])
	{
		j = 0;
		while (game_data->map[i][j])
		{
			if (game_data->map[i][j] == 'C')
				collectible++;
			else if (game_data->map[i][j] == 'E')
				exit++;
			else if (game_data->map[i][j] == 'P')
			{
				start++;
				game_data->player_x = i;
				game_data->player_y = j;
			}
			else if (game_data->map[i][j] != '0' && game_data->map[i][j] != '1')
				print_error("whoopsie, that's not a valid map!\n");
			j++;
		}
		i++;
	}
	if (collectible < 1 || start != 1 || exit != 1)
		print_error("a valid map must contain 1 exit, 1 starting position and at least 1 collectible 🤓\n");
	game_data->collectible = collectible;
}

char	*boner_grower(char *s1, char *s2)
{
	char *final;
	size_t i;
	size_t j;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	final = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (final == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		final[i] = s1[i];
		i++;
	}
	if (!s1[i])
	{
		while (s2[j])
		{
			final[i + j] = s2[j];
			j++;
		}
	}
	if (s1)
		free (s1);
	return (final);
}