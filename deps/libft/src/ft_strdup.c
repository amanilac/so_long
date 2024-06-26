/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:08:20 by amanilac          #+#    #+#             */
/*   Updated: 2024/05/10 11:36:29 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		src_size;
	int		i;

	src_size = ft_strlen(src);
	dest = (char *) malloc(sizeof(char) * (src_size + 1));
	if (dest == 0)
		return (0);
	i = 0;
	while (i < src_size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
