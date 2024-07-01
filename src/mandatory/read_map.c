/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annamanilaci <annamanilaci@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:16:24 by amanilac          #+#    #+#             */
/*   Updated: 2024/07/01 16:51:56 by annamanilac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// void generate_map(char **map)

// void	read_map(char **map)
// {
	
// }

void	open_window(void)
{
	mlx_t			*window;
	mlx_image_t 	*img;
	mlx_texture_t	*sale;

	sale = mlx_load_png("./textures/sale.png");
		mlx_set_setting(MLX_MAXIMIZED, true);
	window = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!window)
		print_error("Error opening new window");
	sale = mlx_load_png("./textures/sale.png");
	if (!sale)
		print_error("oops");
	img = mlx_texture_to_image(window, sale);
	if (!img || (mlx_image_to_window(window, img, 0, 0) < 0))
		print_error("Error generating image");
	// ft_memset(img->pixels, 255, img->width * img->height * sizeof(int));
	// if (mlx_image_to_window(window, img, 0, 0) < 0)
	// 	print_error("Error generating image");
	mlx_loop(window);
	mlx_terminate(window);
}
