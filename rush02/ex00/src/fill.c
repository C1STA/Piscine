/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:16:58 by wacista           #+#    #+#             */
/*   Updated: 2024/03/31 04:58:01 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

void	print_keys(t_keys *keys)
{
	int	i;

	i = 0;
	while (keys[i].key)
		printf("%s\n", keys[i++].key);
}

bool	is_key(t_dict *s, t_keys *keys)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (keys[i].key)
	{
		j = 0;
		while (s[j].key)
		{
			if (!ft_strcmp(keys[i].key, s[j].key))
				keys[i].count++;
			j++;
		}
		i++;
	}
	i = 0;
	while (keys[i].key)
	{
		if (keys[i].count != 1)
			return (false);
		i++;
	}
	return (true);
}

struct s_dict	*fill_data(char **src)
{
	int		n;
	t_dict	*s;
	t_keys	*keys;

	s = fill_numbers(src);
	if (!s)
		return (free_split(src), ft_putstr_err("Error\n"), NULL);
	n = alloc_values(s, src);
	if (!n)
		return (free_split(src), ft_putstr_err("Dict Error\n"), NULL);
	if (n < 0)
		return (free_split(src), ft_putstr_err("Error\n"), NULL);
	keys = define_keys();
	if (!keys)
		return (free_split(src), free_dict(s), ft_putstr_err("Error\n"), NULL);
	if (!is_key(s, keys))
		return (free_all(s, keys, src), ft_putstr_err("Dict Error\n"), NULL);
	free_keys(keys);
	return (s);
}
