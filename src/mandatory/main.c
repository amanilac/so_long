/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:16:19 by amanilac          #+#    #+#             */
/*   Updated: 2024/06/27 18:44:47 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	print_array(char **map)
{
	char	**arr;

	arr = map;
	while(*arr)
	{
		ft_printf("%s\n", *arr);
		arr++;
	}
}

static void	is_rectangle(char **map)
{
	int 	width;
	int		i;

	i = 0;
	width = (int)ft_strlen(map[i]);
	while (map[i])
	{
		// ft_printf("%s\n", map[i]);
		// ft_printf("%d, %d, %d\n", (int)ft_strlen(map[i]), width, (int)ft_strlen(map[i]) == width);
		if ((int)ft_strlen(map[i]) != width)
		{
			write(1, "poopee", 6);
			exit(EXIT_FAILURE);
			// ft_printf("%d, %d\n", width, (int)ft_strlen(map[i]));
			// print_error("fuck");
		}
		i++;
	}
}

static void	map_checker(char **map)
{
	size_t	collectible;
	size_t	start;
	size_t	exit;
	int 	i;
	int		j;

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
}

int	main(int argc, char **argv)
{
	int		fd;
	char	**map;
	char	*boner;
	char	*line;
	char	*file;

	if (argc != 2)
		print_error("learn to input proper arguments bruv\n");
	argv++;
	file = *argv;
	*argv = *argv + (ft_strlen(*argv) - 4);
	if (ft_strncmp(*argv,".ber", 4) != 0)
		print_error("erm, what the flip!? that's not a .ber file...\n");
	fd = open (file, O_RDONLY);
	line = get_next_line(fd);
	boner = NULL;
	while (line)
	{
		boner = boner_grower(boner, line);
		free (line);
		line = get_next_line(fd);
	}
	map = ft_split(boner, '\n');
	free (boner);
	map_checker(map);
	is_rectangle(map);
	print_array(map);
	abandon(map);
	return(EXIT_SUCCESS);
}
