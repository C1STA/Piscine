/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:48:05 by wacista           #+#    #+#             */
/*   Updated: 2024/03/31 01:23:37 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int	get_len(char *src)
{
	int	i;
	int	len;
	int	space;

	i = 0;
	len = 0;
	space = 1;
	while (src[i])
	{
		if (src[i] > 32 && src[i] <= 126)
		{
			len++;
			space = 0;
		}
		else if (src[i] == ' ' && !space)
		{
			len++;
			space = 1;
		}
		i++;
	}
	return (len);
}

void	fill_values(t_dict *s, char *src, int *i, int start)
{
	int	j;
	int	k;
	int	space;

	k = 0;
	j = start;
	space = 1;
	while (src[j])
	{
		if (src[j] > 32 && src[j] <= 126)
		{
			s[*i].value[k++] = src[j];
			space = 0;
		}
		else if (src[j] == ' ' && !space)
		{
			s[*i].value[k++] = src[j];
			space = 1;
		}
		j++;
	}
	s[*i].value[k] = '\0';
}

int	alloc_values(t_dict *s, char **src)
{
	int	i;
	int	j;

	i = 0;
	while (src[i])
	{
		j = 0;
		while (src[i][j] != ':')
			j++;
		if (src[i][j] == ':')
			j++;
		while (src[i][j] && (src[i][j] <= 32 || src[i][j] > 126))
			j++;
		if (!src[i][j])
			return (free_fill_value(s, i), false);
		s[i].value = (char *)malloc(sizeof(char) * (get_len(&src[i][j]) + 1));
		if (!s[i].value)
			return (free_fill_value(s, i), -1);
		fill_values(s, src[i], &i, j);
		i++;
	}
	return (true);
}
