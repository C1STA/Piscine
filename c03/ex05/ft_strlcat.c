/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:08:04 by wacista           #+#    #+#             */
/*   Updated: 2024/03/20 23:33:51 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dest;
	unsigned int	len_src;
	unsigned int	buffer;
	unsigned int	i;
	unsigned int	j;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (!size)
		return (len_src);
	if (!*src && size > len_dest)
		return (len_dest);
	if (size <= len_dest || !*src)
		return (size + len_src);
	buffer = size - len_dest;
	i = 0;
	j = len_dest;
	while (src[i] && i < buffer - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (len_dest + len_src);
}
