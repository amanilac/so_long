/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annamanilaci <annamanilaci@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:16:19 by amanilac          #+#    #+#             */
/*   Updated: 2024/07/02 20:38:57 by annamanilac      ###   ########.fr       */
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

static void	parse_map(char *file, t_long *game_data)
{
	int fd;
	char *boner;
	char *line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	game_data->height = 0;
	boner = NULL;
	while (line)
	{
		boner = boner_grower(boner, line);
		free(line);
		line = get_next_line(fd);
		game_data->height++;
	}
	game_data->map = ft_split(boner, '\n');
	free(boner);
	map_checker(game_data);
	is_rectangle(game_data);
}

int	main(int argc, char **argv)
{
	char	*file;
	t_long	game_data;
	t_files	blox;
	
	if (argc != 2)
		print_error("learn to input proper arguments bruv\n");
	argv++;
	file = *argv;
	*argv = *argv + (ft_strlen(*argv) - 4);
	if (ft_strncmp(*argv,".ber", 4) != 0)
		print_error("erm, what the flip!? that's not a .ber file...\n");
	parse_map(file, &game_data);
	init_textures(&game_data, &blox);
	open_window(&game_data);
	abandon(game_data.map);
	return(EXIT_SUCCESS);
}
