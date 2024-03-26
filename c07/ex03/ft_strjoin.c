/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:09:52 by wacista           #+#    #+#             */
/*   Updated: 2024/03/26 15:00:38 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_full_size(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	len_sep;
	int	len_strs;

	i = 0;
	len_strs = 0;
	if (!size || size < 0)
		return (0);
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			j++;
			len_strs++;
		}
		i++;
	}
	len_sep = 0;
	while (sep[len_sep])
		len_sep++;
	return (len_strs + ((size - 1) * len_sep));
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	*dest;

	len = get_full_size(size, strs, sep);
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			dest[k++] = strs[i][j++];
		j = 0;
		while (sep[j] && i < size - 1)
			dest[k++] = sep[j++];
		i++;
	}
	dest[k] = '\0';
	return (dest);
}
