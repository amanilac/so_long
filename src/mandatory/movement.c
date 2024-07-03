/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:31:50 by annamanilac       #+#    #+#             */
/*   Updated: 2024/07/03 19:03:28 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_player(t_long *game_data, int x, int y)
{
	mlx_delete_image(game_data->window, game_data->blox->imgs->player);
	mlx_image_to_window(game_data->window, game_data->blox->imgs->player, x , y);
}