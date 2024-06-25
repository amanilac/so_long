/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:30:00 by amanilac          #+#    #+#             */
/*   Updated: 2024/05/10 11:33:57 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *str)
{
	long	nbr;
	int		sign;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	nbr = 0;
	while (*str && ft_isdigit(*str))
	{
		if (nbr > _LONG_MAX / 10 || (nbr == _LONG_MAX / 10 && *str > '7'))
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
		nbr = nbr * 10 + (*str++ - '0');
	}
	return (nbr * sign);
}
