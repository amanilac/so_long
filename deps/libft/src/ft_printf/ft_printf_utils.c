/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:45:53 by amanilac          #+#    #+#             */
/*   Updated: 2024/05/06 15:45:05 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(const char *str, t_print *res)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		ft_print_char(str[i], res);
		i++;
	}
}

void	ft_print_char(const char c, t_print *res)
{
	if (res->error == -1)
		return ;
	if (write(1, &c, 1) < 0)
		res->error = -1;
	else
		res->length += 1;
}
