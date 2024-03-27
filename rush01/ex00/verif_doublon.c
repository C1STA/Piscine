/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpinto <pintodav75@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:41:53 by dpinto            #+#    #+#             */
/*   Updated: 2024/03/24 14:47:08 by dpinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_doublon_topdown(int **map, int x)
{
	int	curr_y;
	int	next_y;

	curr_y = 0;
	while (curr_y < 3)
	{
		next_y = curr_y + 1;
		while (next_y < 4)
		{
			if (map[curr_y][x] != 0 && map[next_y][x] != 0 &&
					map[curr_y][x] == map[next_y][x])
				return (1);
			next_y++;
		}
		curr_y++;
	}
	return (0);
}

int	check_doublon_rightleft(int **map, int y)
{
	int	curr_x;
	int	next_x;

	curr_x = 0;
	while (curr_x < 3)
	{
		next_x = curr_x + 1;
		while (next_x < 4)
		{
			if (map[y][curr_x] != 0 && map[y][next_x] != 0 &&
					map[y][curr_x] == map[y][next_x])
				return (1);
			next_x++;
		}
		curr_x++;
	}
	return (0);
}
