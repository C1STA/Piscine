/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_reference.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 04:37:35 by wacista           #+#    #+#             */
/*   Updated: 2024/03/31 04:38:15 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

bool	declare_last_keys(t_keys *keys)
{
	int	i;
	int	j;

	i = 20;
	j = 20;
	while (i <= 28)
	{
		keys[i].key = ft_itoa(j);
		if (!keys[i].key)
			return (free_keys_value(keys, i), false);
		keys[i++].count = 0;
		j += 10;
	}
	j = 4;
	while (i < 41)
	{
		keys[i].key = ft_strndup("1000000000000000000000000000000000000", j);
		if (!keys[i].key)
			return (free_keys_value(keys, i), false);
		keys[i++].count = 0;
		j += 3;
	}
	keys[i].key = NULL;
	keys[i].count = 0;
	return (true);
}

t_keys	*define_keys(void)
{
	int		i;
	t_keys	*keys;

	keys = (t_keys *)malloc(sizeof(t_keys) * 42);
	if (!keys)
		return (NULL);
	i = 0;
	while (i < 20)
	{
		keys[i].key = ft_itoa(i);
		if (!keys[i].key)
			return (free_keys_value(keys, i), NULL);
		keys[i++].count = 0;
	}
	if (!declare_last_keys(keys))
		return (NULL);
	return (keys);
}
