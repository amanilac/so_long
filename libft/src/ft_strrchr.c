/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:31:53 by amanilac          #+#    #+#             */
/*   Updated: 2024/05/10 11:36:51 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = ft_strlen(str);
	while (i != 0)
	{
		if (str[i] == (char) c)
			return ((char *) str + i);
		i--;
	}
	if (str[i] == (char) c)
		return ((char *) str + i);
	return (0);
}
