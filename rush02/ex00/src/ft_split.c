/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:11:14 by wacista           #+#    #+#             */
/*   Updated: 2024/03/30 10:50:33 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

char	*ft_strncpy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	words_count(char *str)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (str[i])
	{
		while (str[i] == '\n')
			i++;
		if (str[i])
			w++;
		while (str[i] && str[i] != '\n')
			i++;
	}
	return (w);
}

void	free_split_fail(char **dest, int k)
{
	int	i;

	i = 0;
	while (i < k)
		free(dest[i++]);
	free(dest);
}

char	**fill_split(char **dest, char *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] == '\n')
			i++;
		j = i;
		while (str[i] && str[i] != '\n')
			i++;
		if (i > j)
		{
			dest[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			if (!dest[k])
				return (free_split_fail(dest, k), NULL);
			ft_strncpy(dest[k++], &str[j], i - j);
		}
	}
	dest[k] = NULL;
	return (dest);
}

char	**ft_split(char *str)
{
	char	**dest;

	dest = (char **)malloc(sizeof(char *) * (words_count(str) + 1));
	if (!dest)
		return (NULL);
	if (!fill_split(dest, str))
		return (NULL);
	return (dest);
}
