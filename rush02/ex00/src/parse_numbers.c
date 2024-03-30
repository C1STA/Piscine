/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:09:17 by wacista           #+#    #+#             */
/*   Updated: 2024/03/30 14:14:44 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

bool	isspace_and_signs(char **s, int *i, int *j)
{
	while ((s[*i][*j] >= 9 && s[*i][*j] <= 13) || s[*i][*j] == 32)
		(*j)++;
	if (s[*i][*j] == '-')
		return (false);
	else if (s[*i][*j] == '+')
		(*j)++;
	return (true);
}

int	is_digit(char **s, int *i, int *j)
{
	int	k;

	k = 0;
	while (s[*i][*j] >= '0' && s[*i][*j] <= '9')
	{
		(*j)++;
		k++;
	}
	if ((s[*i][*j] == '.' || s[*i][*j] == ',') \
	&& (s[*i][*j + 1] >= '0' && s[*i][*j + 1] <= '9'))
		return (-1);
	if (!k || k > 37)
		return (false);
	return (true);
}

bool	parse_colon(char **s, int *i, int *j)
{
	while (s[*i][*j])
	{
		if (s[*i][*j] == ':')
			return (true);
		(*j)++;
	}
	return (false);
}

int	parse_numbers(char **s)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	while (s[i])
	{
		j = 0;
		if (!isspace_and_signs(s, &i, &j))
			return (-1);
		n = is_digit(s, &i, &j);
		if (!n)
			return (false);
		else if (n < 0)
			return (-1);
		if (!parse_colon(s, &i, &j))
			return (false);
		i++;
	}
	return (true);
}
