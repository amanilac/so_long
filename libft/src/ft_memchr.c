/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 01:47:27 by amanilac          #+#    #+#             */
/*   Updated: 2024/05/10 11:36:01 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	chr;
	unsigned char	*str;

	str = (unsigned char *)s;
	chr = (unsigned char)c;
	while (n)
	{
		if (*str == chr)
			return (str);
		str++;
		n--;
	}
	return (0);
}
