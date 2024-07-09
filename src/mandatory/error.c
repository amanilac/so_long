/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:29:21 by amanilac          #+#    #+#             */
/*   Updated: 2024/07/09 11:45:02 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	print_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	abandon(char **ptr)
{
	size_t i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}

void	destroy_texture(t_files *blox)
{
	mlx_delete_texture(blox->collectible);
	mlx_delete_texture(blox->wall);
	mlx_delete_texture(blox->floor);
	mlx_delete_texture(blox->player);
	mlx_delete_texture(blox->exit);
}