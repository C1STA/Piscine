/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:16:58 by wacista           #+#    #+#             */
/*   Updated: 2024/03/30 18:33:42 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

struct s_dict	*fill_data(char **src)
{
	int	n;
	t_dict	*s;

	s = fill_numbers(src);
	if (!s)
		return (free_split(src), ft_putstr_error("Error\n"), NULL);
	n = alloc_values(s, src);
	if (!n)
		return (free_split(src), ft_putstr_error("Dict Error\n"), NULL);
	if (n < 0)
		return (free_split(src), ft_putstr_error("Error\n"), NULL);
	fill_values(s, src);
	return (s);
}
