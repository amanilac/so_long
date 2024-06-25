/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:12:56 by amanilac          #+#    #+#             */
/*   Updated: 2024/05/10 11:36:20 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;

	nbr = n;
	{
		if (nbr < 0)
		{
			write(fd, "-", 1);
			nbr = nbr * -1;
		}
		if (nbr >= 10)
		{
			ft_putnbr_fd(nbr / 10, fd);
			ft_putchar_fd(nbr % 10 + '0', fd);
		}
		else
		{
			ft_putchar_fd(nbr + '0', fd);
		}
	}
}
