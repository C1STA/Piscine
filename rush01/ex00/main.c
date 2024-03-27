/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:31:06 by dpinto            #+#    #+#             */
/*   Updated: 2024/03/24 15:53:44 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

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
		if (map[i] == NULL)
		{
			ft_free(map);
			return (NULL);
		}
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
	int	pos[4][4];
	int	**map;

	if (ac != 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!parse(av[1], pos))
	{
		ft_putstr("Error\n");
		return (0);
	}
	map = init_map();
	if (map == NULL)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!compute(pos, map))
		ft_putstr("Error\n");
	ft_free(map);
	return (0);
}
