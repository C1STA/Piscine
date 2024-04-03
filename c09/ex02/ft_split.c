/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:29:48 by wacista           #+#    #+#             */
/*   Updated: 2024/04/03 13:03:05 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

int	to_find(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	**fill_words(char **dest, char *str, char *charset)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (to_find(str[i], charset))
			i++;
		j = i;
		while (str[i] && !to_find(str[i], charset))
			i++;
		if (i > j)
		{
			dest[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			if (!dest[k])
				return (NULL);
			ft_strncpy(dest[k++], &str[j], i - j);
		}
	}
	dest[k] = NULL;
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		w;
	char	**dest;

	i = 0;
	w = 0;
	while (str[i])
	{
		while (to_find(str[i], charset))
			i++;
		if (str[i])
			w++;
		while (str[i] && !to_find(str[i], charset))
			i++;
	}
	dest = (char **)malloc(sizeof(char *) * (w + 1));
	if (!dest)
		return (NULL);
	return (fill_words(dest, str, charset));
}
