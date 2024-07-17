/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:16:19 by amanilac          #+#    #+#             */
/*   Updated: 2024/07/17 16:46:23 by amanilac         ###   ########.fr       */
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

void	check_height(char *map, t_long *game_data)
{
	int	i;

	i = 0;
	game_data->height = 1;
	while (map[i])
	{
		if ((map[i] == '\n' && (map[i + 1] != '1' || map[i - 1] != '1')))
			print_error("uh-oh, that's not a valid map!\n");
		if (map[i] == '\n')
			game_data->height += 1;
		i++;
	}
}

void	parse_map(char *file, t_long *game_data)
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
	}
	check_height(boner, game_data);
	game_data->map = ft_split(boner, '\n');
	map_checker(game_data);
	is_rectangle(game_data);
}

char *boner_grower(char *s1, char *s2)
{
	char	*final;
	int		i;
	int		j;
	
	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	final = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (final == 0)
		return (NULL);
	i = ft_strlen(s1);
	j = 0;
	ft_memcpy((void *)final,(const void *)s1,ft_strlen(s1));
	while (s2[j])
	{
		final[i + j] = s2[j];
		j++;
	}
	if (s1)
		free(s1);
	return (final);
}

int	main(int argc, char **argv)
{
	char			*file;
	t_long			game_data;
	t_files			blox;
	t_img			imgs;

	if (argc != 2)
		print_error("learn to input proper arguments bruv\n");
	argv++;
	file = *argv;
	*argv = *argv + (ft_strlen(*argv) - 4);
	if (ft_strncmp(*argv,".ber", 4) != 0)
		print_error("erm, what the flip!? that's not a .ber file...\n");
	game_data.blox = &blox;
	blox.imgs = &imgs;
	parse_map(file, &game_data);
	init_textures(&game_data, &blox, &imgs);
	open_window(&game_data);
	abandon(game_data.map);
	return(EXIT_SUCCESS);
}
