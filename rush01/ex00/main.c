/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:31:06 by dpinto            #+#    #+#             */
/*   Updated: 2024/03/23 18:35:53 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	display_pos(int pos[4][4])
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

int	**init_map(void)
{
	int	**map;
	int	i;
	int	j;

	map = (int **)malloc(sizeof(int *) * 4);
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		map[i] = (int *)malloc(sizeof(int) * 4);
		if (map[i] == NULL) // TODO: handle memory leaks
			return (ft_free(map), NULL);
		j = 0;
		while (j < 4)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (map);
}

int	main(int ac, char **av)
{
	int	pos[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};
	int	**map;

	if (ac != 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!parse(av[1], pos))
	{
		ft_putstr("Error parsing\n");
		return (0);
	}
	map = init_map();
	if (map == NULL)
		return (0);
	/*
		{1, 2, 3, 4},
		{2, 3, 4, 1},
		{3, 4, 1, 2},
		{4, 1, 2, 3}

	map[0][0] = 1;
	map[0][1] = 2;
	map[0][2] = 3;
	map[0][3] = 4;

	map[1][0] = 2;
	map[2][0] = 3;
	map[3][0] = 4;
	*/
	if (!compute(pos, map))
		printf("unsolvable\n");
	ft_free(map);
	return (0);
}
