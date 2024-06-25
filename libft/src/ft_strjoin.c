/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:36:47 by amanilac          #+#    #+#             */
/*   Updated: 2024/05/10 11:36:34 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	final = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (final == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		final[i] = s1[i];
		i++;
	}
	if (!s1[i])
	{
		while (s2[j])
		{
			final[i + j] = s2[j];
			j++;
		}
	}
	return (final);
}
