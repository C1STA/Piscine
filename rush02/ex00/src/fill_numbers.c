/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:11:51 by wacista           #+#    #+#             */
/*   Updated: 2024/03/31 00:56:41 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int	tablen(char **src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

int	len_key(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
			i++;
			len++;
	}
	return (len);
}

char	*fill_key(char *s)
{
	int		i;
	int		j;
	int		len;
	char	*dest;

	i = 0;
	j = 0;
	len = len_key(s);
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[j] >= '0' && s[j] <= '9')
		dest[i++] = s[j++];
	dest[i] = '\0';
	return (dest);
}

struct s_dict	*fill_numbers(char **src)
{
	t_dict	*s;
	int		len;
	int		i;

	i = 0;
	len = tablen(src);
	s = (t_dict *)malloc(sizeof(t_dict) * (len + 1));
	if (!s)
		return (NULL);
	while (i < len)
	{
		s[i].key = fill_key(src[i]);
		if (!s[i].key)
			return (free_fill_key(s, i), NULL);
		i++;
	}
	s[i].key = NULL;
	s[i].value = NULL;
	return (s);
}

void	print_numbers(t_dict *s)
{
	int	i;

	i = 0;
	while (s[i].key)
	{
		printf("%s\n", s[i].value);
		printf("%s\n", s[i++].key);
	}
}
