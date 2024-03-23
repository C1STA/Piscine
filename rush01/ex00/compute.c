/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:30:47 by dpinto            #+#    #+#             */
/*   Updated: 2024/03/23 16:13:01 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	display_map(int **pos)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%d ", pos[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	can_put_tower(int **map, int y, int x, int (*pos)[4])
{
	if (!verif_rightleft(map, y, pos))
		return (0);
	if (!verif_leftright(map, y, pos))
		return (0);
	if (!verif_downtop(map, x, pos))
		return (0);
	if (!verif_topdown(map, x, pos))
		return (0);
	return (1);
}
int	brute_force(int (*pos)[4], int **map, int n)
{
	int	y;
	int	x;
	int	tower;

	if (n == 16)
		return (1);
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			tower = 1;
			while (map[y][x] == 0 && tower < 5)
			{
				map[y][x] = tower;
				if (can_put_tower(map, y, x, pos))
					if (brute_force(pos, map, n + 1))
						return (1);
				map[y][x] = 0;
				if (tower == 4)
					return (0);
				tower++;
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	compute(int (*pos)[4], int **map)
{
	int r = brute_force(pos, map, 0);
	display_map(map);
	return (r);
}
