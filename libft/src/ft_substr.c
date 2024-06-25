/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:22:40 by amanilac          #+#    #+#             */
/*   Updated: 2024/05/10 11:36:57 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < start)
		return (ft_calloc(1, 1));
	if (len > (slen - start))
		len = ((slen - start));
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == 0)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
