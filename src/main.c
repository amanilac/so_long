/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:16:19 by amanilac          #+#    #+#             */
/*   Updated: 2024/07/18 20:02:50 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_height(char *map, t_long *data)
{
	int	i;

	i = 0;
	data->height = 1;
	while (map[i])
	{
		if ((map[i] == '\n' && (map[i + 1] != '1' || map[i - 1] != '1')))
			print_error("uh-oh, that's not a valid map!\n");
		if (map[i] == '\n')
			data->height += 1;
		i++;
	}
}

void	parse_map(char *file, t_long *data)
{
	int		fd;
	char	*full_string;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	data->height = 0;
	full_string = ft_strdup("");
	while (line)
	{
		full_string = free_and_join(full_string, line);
		free(line);
		line = get_next_line(fd);
	}
	check_height(full_string, data);
	data->map = ft_split(full_string, '\n');
	free (full_string);
	map_checker(data);
	is_rectangle(data);
	check_path(data);
}

char	*free_and_join(char *s1, char *s2)
{
	char	*final;

	final = ft_strjoin(s1, s2);
	free (s1);
	s1 = NULL;
	return (final);
}

int	main(int argc, char **argv)
{
	char			*file;
	t_long			data;
	t_files			blox;
	t_img			imgs;

	if (argc != 2)
		print_error("learn to input proper arguments bruv\n");
	argv++;
	file = *argv;
	*argv = *argv + (ft_strlen(*argv) - 4);
	if (ft_strncmp(*argv, ".ber", 4) != 0)
		print_error("erm, what the flip!? that's not a .ber file...\n");
	data.blox = &blox;
	blox.imgs = &imgs;
	parse_map(file, &data);
	init_textures(&data, &blox, &imgs);
	open_window(&data);
	abandon(data.map);
	free_success(&data, false);
	return (EXIT_SUCCESS);
}
