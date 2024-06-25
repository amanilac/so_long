/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:08:08 by amanilac          #+#    #+#             */
/*   Updated: 2024/05/10 11:35:59 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	nbrlen(int n)
{
	size_t	strlen;
	int		temp;

	strlen = 0;
	temp = n;
	if (temp < 0)
	{
		strlen++;
		temp *= -1;
	}
	while (temp > 0)
	{
		temp = temp / 10;
		strlen++;
	}
	return (strlen);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	len = nbrlen(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = ft_calloc(len + 1, sizeof(char));
	if (str == 0)
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[len-- -1] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
