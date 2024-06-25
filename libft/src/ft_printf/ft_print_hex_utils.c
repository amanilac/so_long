/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:46:06 by amanilac          #+#    #+#             */
/*   Updated: 2024/05/06 15:44:38 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_hex(unsigned int nbr, const char *format, t_print *res)
{
	if (nbr >= 16)
	{
		ft_put_hex(nbr / 16, format, res);
		ft_put_hex(nbr % 16, format, res);
	}
	else
	{
		if (nbr <= 9)
			ft_print_char(nbr + '0', res);
		else
		{
			if (*format == 'x')
				ft_print_char(nbr - 10 + 'a', res);
			else if (*format == 'X')
				ft_print_char(nbr - 10 + 'A', res);
		}
	}
}

void	ft_print_hex(unsigned int nbr, const char *format, t_print *res)
{
	if (nbr == '0')
		ft_print_char('0', res);
	ft_put_hex(nbr, format, res);
}
