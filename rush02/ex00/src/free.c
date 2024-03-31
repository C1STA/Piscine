/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:29:44 by wacista           #+#    #+#             */
/*   Updated: 2024/03/31 04:55:07 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

void	free_split(char **src)
{
	char	**tmp;

	tmp = src;
	while (*src)
		free(*src++);
	src = tmp;
	free(src);
}

void	free_fill_key(t_dict *s, int j)
{
	int	i;

	i = 0;
	while (i < j)
		free(s[i++].key);
	free(s);
}

void	free_fill_value(t_dict *s, int j)
{
	int	i;

	i = 0;
	while (i < j)
		free(s[i++].value);
	free_key(s);
	free(s);
}

void	free_key(t_dict *s)
{
	int	i;

	i = 0;
	while (s[i].key)
		free(s[i++].key);
}

void	free_dict(t_dict *s)
{
	int	i;

	i = 0;
	while (s[i].key)
	{
		free(s[i].key);
		free(s[i].value);
		i++;
	}
	free(s);
}
