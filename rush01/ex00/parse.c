/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:15:41 by dpinto            #+#    #+#             */
/*   Updated: 2024/03/24 15:55:45 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_str(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) != 31)
		return (0);
	while (str[i] != '\0')
	{
		if (i % 2 != 0 && str[i] != ' ')
			return (0);
		else if (i % 2 == 0 && !(str[i] >= '1' && str[i] <= '4'))
			return (0);
		i++;
	}
	return (1);
}

char	*fill(char *str, int pos[4][4], int index)
{
	int	i;
	int	curr;

	i = 0;
	curr = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			pos[index][curr] = str[i] - 48;
			curr++;
		}
		if (curr == 4)
			return (str + i + 1);
		i++;
	}
	return (str);
}

int	parse(char *str, int pos[4][4])
{
	if (!check_str(str))
		return (0);
	str = fill(str, pos, 0);
	str = fill(str, pos, 1);
	str = fill(str, pos, 2);
	str = fill(str, pos, 3);
	return (1);
}
