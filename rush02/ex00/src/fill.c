/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:16:58 by wacista           #+#    #+#             */
/*   Updated: 2024/03/31 04:23:42 by wacista          ###   ########.fr       */
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

void	print_keys(t_keys *keys)
{
	int	i;

	i = 0;
	while (keys[i].key)
		printf("%s\n", keys[i++].key);
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
		return (free_split(src), free_struct(s), ft_putstr_err("Error\n"), NULL);
	print_keys(keys);
	free_keys(keys);
	return (s);
}
