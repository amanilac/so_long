/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:45:42 by amanilac          #+#    #+#             */
/*   Updated: 2024/05/06 15:44:56 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_spec(const char *format, va_list args, t_print *res)
{
	if (*format == 's')
		print_str(va_arg(args, char *), res);
	else if (*format == 'd' || *format == 'i')
		print_nbr(va_arg(args, int), res);
	else if (*format == 'c')
		ft_print_char(va_arg(args, int), res);
	else if (*format == 'x' || *format == 'X')
		ft_print_hex(va_arg(args, unsigned int), format, res);
	else if (*format == 'u')
		print_unsigned_nbr(va_arg(args, unsigned int), res);
	else if (*format == '%')
		ft_print_char('%', res);
	else if (*format == 'p')
		ft_print_ptr(va_arg(args, unsigned long), res);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_print	res;

	res.error = 0;
	res.length = 0;
	va_start(args, format);
	while (*format && res.error == 0)
	{
		if (*format == '%')
		{
			ft_handle_spec(format + 1, args, &res);
			format++;
		}
		else if (*format != '%')
			ft_print_char(*format, &res);
		format++;
	}
	va_end(args);
	if (res.error == -1)
		return (-1);
	return (res.length);
}
