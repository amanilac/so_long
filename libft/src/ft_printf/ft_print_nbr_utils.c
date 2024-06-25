/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:45:57 by amanilac          #+#    #+#             */
/*   Updated: 2024/05/06 15:45:18 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_nbr(int n, t_print *res)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_print_char('-', res);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		print_nbr(nbr / 10, res);
		nbr = nbr % 10;
	}
	if (nbr < 10)
		ft_print_char(nbr + 48, res);
}

void	print_unsigned_nbr(unsigned int n, t_print *res)
{
	unsigned long	nbr;

	nbr = n;
	if (nbr > 9)
	{
		print_nbr(nbr / 10, res);
		nbr = nbr % 10;
	}
	if (nbr < 10)
		ft_print_char(nbr + 48, res);
}
