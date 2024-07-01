/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_comms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:03:39 by annamanilac       #+#    #+#             */
/*   Updated: 2024/07/01 17:56:36 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	key_hooker(mlx_key_data_t keydata, void *param)
{
	t_long	*data;

	data = param;
	data->moves = 0;
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W) && (keydata.action == MLX_PRESS))
		ft_printf("MOVE UP\n");
	if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S) && (keydata.action == MLX_PRESS))
		ft_printf("MOVE DOWN\n");	
	if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A) && (keydata.action == MLX_PRESS))
		ft_printf("MOVE LEFT\n");
	if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D) && (keydata.action == MLX_PRESS))
		ft_printf("MOVE RIGHT\n");
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(data->window);
		mlx_terminate(data->window);
		exit(EXIT_SUCCESS);
	}
}


