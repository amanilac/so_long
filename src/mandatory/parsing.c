/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annamanilaci <annamanilaci@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:24:52 by amanilac          #+#    #+#             */
/*   Updated: 2024/06/28 15:46:38 by annamanilac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	is_rectangle(char **map)
{
	int width;
	int i;

	i = 0;
	width = (int)ft_strlen(map[i]);
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != width)
			print_error("uh-oh! that's not a rectangle!\n");
		i++;
	}
}

int	map_checker(char **map)
{
	size_t collectible;
	size_t start;
	size_t exit;
	int i;
	int j;

	collectible = 0;
	start = 0;
	exit = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				collectible++;
			else if (map[i][j] == 'E')
				exit++;
			else if (map[i][j] == 'P')
				start++;
			else if (map[i][j] != '0' && map[i][j] != '1')
				print_error("whoopsie, that's not a valid map!\n");
			j++;
		}
		i++;
	}
	if (collectible < 1 || start != 1 || exit != 1)
		print_error("a valid map must contain 1 exit, 1 starting position and at least 1 collectible 🤓\n");
	return (collectible);
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