/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:27:36 by wacista           #+#    #+#             */
/*   Updated: 2024/03/31 04:24:23 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int	parsing(char **src)
{
	int	res;

	res = parse_numbers(src);
	if (!res)
		return (free_split(src), ft_putstr_err("Dict Error\n"), false);
	else if (res < 0)
		return (free_split(src), ft_putstr_err("Error\n"), false);
	return (true);
}
