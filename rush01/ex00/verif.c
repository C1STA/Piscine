/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:22:20 by dpinto            #+#    #+#             */
/*   Updated: 2024/03/24 15:52:28 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	verif_topdown(int **map, int x, int pos[4][4])
{
	int	curr_y;
	int	tower_viewed;
	int	max_tower;
	int	size_tower;

	size_tower = 0;
	curr_y = 0;
	tower_viewed = 0;
	max_tower = 0;
	while (curr_y < 4)
	{
		if (map[curr_y][x] != 0)
			size_tower++;
		if (map[curr_y][x] > max_tower)
		{
			max_tower = map[curr_y][x];
			tower_viewed++;
		}
		curr_y++;
	}
	if (size_tower == 4 && pos[0][x] != tower_viewed)
		return (0);
	return (1);
}

int	verif_downtop(int **map, int x, int pos[4][4])
{
	int	curr_y;
	int	tower_viewed;
	int	max_tower;
	int	size_tower;

	curr_y = 3;
	tower_viewed = 0;
	max_tower = 0;
	size_tower = 0;
	while (curr_y >= 0)
	{
		if (map[curr_y][x] != 0)
			size_tower++;
		if (map[curr_y][x] > max_tower)
		{
			max_tower = map[curr_y][x];
			tower_viewed++;
		}
		curr_y--;
	}
	if (size_tower == 4 && pos[1][x] != tower_viewed)
		return (0);
	return (1);
}

int	verif_leftright(int **map, int y, int pos[4][4])
{
	int	curr_x;
	int	tower_viewed;
	int	max_tower;
	int	size_tower;

	curr_x = 0;
	tower_viewed = 0;
	max_tower = 0;
	size_tower = 0;
	while (curr_x < 4)
	{
		if (map[y][curr_x] != 0)
			size_tower++;
		if (map[y][curr_x] > max_tower)
		{
			max_tower = map[y][curr_x];
			tower_viewed++;
		}
		curr_x++;
	}
	if (size_tower == 4 && pos[2][y] != tower_viewed)
		return (0);
	return (1);
}

int	verif_rightleft(int **map, int y, int pos[4][4])
{
	int	curr_x;
	int	tower_viewed;
	int	max_tower;
	int	size_tower;

	curr_x = 3;
	tower_viewed = 0;
	max_tower = 0;
	size_tower = 0;
	while (curr_x >= 0)
	{
		if (map[y][curr_x] != 0)
			size_tower++;
		if (map[y][curr_x] > max_tower)
		{
			max_tower = map[y][curr_x];
			tower_viewed++;
		}
		curr_x--;
	}
	if (size_tower == 4 && pos[3][y] != tower_viewed)
		return (0);
	return (1);
}
