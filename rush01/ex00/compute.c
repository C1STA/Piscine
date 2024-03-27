/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:30:47 by dpinto            #+#    #+#             */
/*   Updated: 2024/03/24 15:52:28 by wacista          ###   ########.fr       */
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
			ft_putchar(pos[i][j] + 48);
			if (j != 3)
				ft_putchar(' ');
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}

int	cpt(int **map, int y, int x, int pos[4][4])
{
	if (check_doublon_topdown(map, x))
		return (0);
	if (check_doublon_rightleft(map, y))
		return (0);
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

int	brut(int pos[4][4], int **map, int n)
{
	int	y;
	int	x;
	int	tower;

	if (n == 16)
		return (1);
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			tower = 0;
			while (map[y][x] == 0 && ++tower < 5)
			{
				map[y][x] = tower;
				if (cpt(map, y, x, pos) && brut(pos, map, n + 1))
					return (1);
				map[y][x] = 0;
				if (tower == 4)
					return (0);
			}
		}
	}
	return (0);
}

int	compute(int pos[4][4], int **map)
{
	int	r;

	r = brut(pos, map, 0);
	if (r)
		display_map(map);
	return (r);
}
