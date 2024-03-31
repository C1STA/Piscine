/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 07:18:13 by wacista           #+#    #+#             */
/*   Updated: 2024/03/31 19:46:24 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void	ft_putstr_err(char *s)
{
	while (*s)
		write(2, s++, 1);
}

void	ft_free_str(char **str)
{
	if (str != NULL && **str != '\0')
	{
		free(*str);
		*str = NULL;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		len;
	int		i;
	int		j;

	if ((!s1) && (!s2))
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	len = (i + j + 1);
	dest = malloc(sizeof(char) * len);
	if (!dest)
		return (ft_free_str(&s1), NULL);
	i = 0;
	j = 0;
	while (s1[i])
		dest[j++] = s1[i++];
	i = 0;
	while (s2[i])
		dest[j++] = s2[i++];
	dest[j] = '\0';
	ft_free_str(&s1);
	return (dest);
}
