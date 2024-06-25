/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:46:02 by amanilac          #+#    #+#             */
/*   Updated: 2024/05/06 15:45:37 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_ptr(unsigned long ptr, t_print *res)
{
	if (ptr >= 16)
	{
		ft_put_ptr(ptr / 16, res);
		ft_put_ptr(ptr % 16, res);
	}
	else
	{
		if (ptr <= 9)
			ft_print_char(ptr + '0', res);
		else if (ptr <= 16)
			ft_print_char(ptr - 10 + 'a', res);
	}
}

void	ft_print_ptr(unsigned long ptr, t_print *res)
{
	print_str("0x", res);
	if (ptr == 0)
		ft_print_char('0', res);
	else
		ft_put_ptr(ptr, res);
}
