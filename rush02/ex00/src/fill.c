/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:16:58 by wacista           #+#    #+#             */
/*   Updated: 2024/03/31 04:42:06 by wacista          ###   ########.fr       */
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
	free_keys(keys);
	return (s);
}
