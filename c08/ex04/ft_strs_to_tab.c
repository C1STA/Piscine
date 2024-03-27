/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:07:01 by wacista           #+#    #+#             */
/*   Updated: 2024/03/27 15:54:47 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_free(struct s_stock_str *s, int i, int isfree)
{
	int	j;

	j = 0;
	while (j <= i)
	{
		if (j == i)
		{
			if (isfree)
				free(s[j].str);
		}
		else
		{
			free(s[j].str);
			free(s[j].copy);
		}
		j++;
	}
	free(s);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dest;

	dest = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*s;

	i = 0;
	s = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!s)
		return (NULL);
	while (i < ac)
	{
		s[i].size = ft_strlen(av[i]);
		s[i].str = ft_strdup(av[i]);
		if (!s[i].str)
			return (ft_free(s, i, 0), NULL);
		s[i].copy = ft_strdup(s[i].str);
		if (!s[i].copy)
			return (ft_free(s, i, 1), NULL);
		i++;
	}
	s[i].size = 0;
	s[i].str = NULL;
	s[i].copy = NULL;
	return (s);
}
