/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:24:52 by amanilac          #+#    #+#             */
/*   Updated: 2024/06/27 16:41:21 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char *boner_grower(char *s1, char *s2)
{
	char *final;
	size_t i;
	size_t j;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
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
	if (s1)
		free (s1);
	return (final);
}