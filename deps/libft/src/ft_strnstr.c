/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:30:00 by amanilac          #+#    #+#             */
/*   Updated: 2024/05/10 11:36:48 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	n_len;

	if (!*needle)
		return ((char *)haystack);
	n_len = ft_strlen(needle);
	while (n > 0 && *haystack && n_len <= n)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle, n_len) == 0)
			return ((char *)(haystack));
		haystack++;
		n--;
	}
	return (NULL);
}
