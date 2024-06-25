/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:28:52 by amanilac          #+#    #+#             */
/*   Updated: 2024/05/10 11:35:49 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	bytesize;

	if (!count || !size)
		return (ft_calloc(1, 1));
	bytesize = size * count;
	if (bytesize / size != count)
		return (0);
	ptr = malloc(bytesize);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, bytesize);
	return (ptr);
}
