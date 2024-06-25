/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:45:29 by amanilac          #+#    #+#             */
/*   Updated: 2024/03/06 18:31:07 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct t_print
{
	int	length;
	int	error;
}	t_print;

int		ft_printf(const char *format, ...);
void	ft_handle_spec(const char *format, va_list args, t_print *res);
void	print_str(const char *str, t_print *res);
void	print_nbr(int n, t_print *res);
void	ft_print_char(const char c, t_print *res);
void	ft_put_hex(unsigned int nbr, const char *format, t_print *res);
void	ft_print_hex(unsigned int nbr, const char *format, t_print *res);
void	print_unsigned_nbr(unsigned int n, t_print *res);
void	ft_put_ptr(unsigned long ptr, t_print *res);
void	ft_print_ptr(unsigned long ptr, t_print *res);

#endif