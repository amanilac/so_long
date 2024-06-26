/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:16:19 by amanilac          #+#    #+#             */
/*   Updated: 2024/06/26 16:28:58 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	print_array(char **arr)
{
	while(*arr)
	{
		ft_printf("%s\n", *arr);
		arr++;
	}
}

static int	girth_check(char *map)
{
	int width;

	width = 0;
	while (map[width] != '\n')
		width++;
	return (width);
}

static void	is_rectangle(char **map)
{
	int 	width;
	char	**temp;

	temp = map;
	width = girth_check(*temp);
	temp++;
	while (*temp)
	{
		if (girth_check(*temp) != width)
			print_error("uh-oh! that's not a rectangle!");
		temp++;
	}
}

static void	map_checker(char **map)
{
	size_t	collectible;
	size_t	start;
	size_t	exit;
	int		i;

	is_rectangle(map);
	collectible = 0;
	start = 0;
	exit = 0;
	while (*map)
	{
		i = 0;
		while (*map[i])
		{
			if (*map[i] == 'C')
				collectible++;
			if (*map[i] == 'E')
				exit++;
			if (*map[i] == 'P')
				start++;
			else if (*map[i] != '0' || *map[i] != '1')
				print_error("whoopsie, that's not a valid map!");
			i++;
		}
		map++;
	}
	if (collectible != 1 && start != 1 && exit != 1)
		print_error("a valid map must contain 1 exit, 1 starting position and at least 1 collectible 🤯");
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
		boner = boner_joiner(line, boner);
		free (line);
		line = get_next_line(fd);
	}
	map = ft_split(boner, '\n');
	free(boner);
	map_checker(map);
	print_array(map);
	abandon(map);
	return(EXIT_SUCCESS);
}
