/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annamanilaci <annamanilaci@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:16:19 by amanilac          #+#    #+#             */
/*   Updated: 2024/06/28 15:45:18 by annamanilac      ###   ########.fr       */
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

// static void	is_rectangle(char **map)
// {
// 	int 	width;
// 	int		i;

// 	i = 0;
// 	width = (int)ft_strlen(map[i]);
// 	while (map[i])
// 	{
// 		if ((int)ft_strlen(map[i]) != width)
// 			print_error("uh-oh! that's not a rectangle!\n");
// 		i++;
// 	}
// }

// static void	map_checker(char **map)
// {
// 	size_t	collectible;
// 	size_t	start;
// 	size_t	exit;
// 	int 	i;
// 	int		j;

// 	collectible = 0;
// 	start = 0;
// 	exit = 0;
// 	i = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			if (map[i][j] == 'C')
// 				collectible++;
// 			else if (map[i][j] == 'E')
// 				exit++;
// 			else if (map[i][j] == 'P')
// 				start++;
// 			else if (map[i][j] != '0' && map[i][j] != '1')
// 					print_error("whoopsie, that's not a valid map!\n");
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (collectible < 1 || start != 1 || exit != 1)
// 		print_error("a valid map must contain 1 exit, 1 starting position and at least 1 collectible 🤓\n");
// }

static char	**parse_map(char *file)
{
	int fd;
	char **map;
	char *boner;
	char *line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	boner = NULL;
	while (line)
	{
		boner = boner_grower(boner, line);
		free(line);
		line = get_next_line(fd);
	}
	map = ft_split(boner, '\n');
	free(boner);
	map_checker(map);
	is_rectangle(map);
	return (map);
}

int	main(int argc, char **argv)
{
	char	*file;
	char	**map;

	if (argc != 2)
		print_error("learn to input proper arguments bruv\n");
	argv++;
	file = *argv;
	*argv = *argv + (ft_strlen(*argv) - 4);
	if (ft_strncmp(*argv,".ber", 4) != 0)
		print_error("erm, what the flip!? that's not a .ber file...\n");
	map = parse_map(file);
	open_window(map);
	ft_printf("%d\n", calculate_block_size(map));
	abandon(map);
	return(EXIT_SUCCESS);
}
