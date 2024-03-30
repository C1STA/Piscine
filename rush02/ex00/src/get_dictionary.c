/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dictionary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:21:11 by wacista           #+#    #+#             */
/*   Updated: 2024/03/30 15:01:38 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

char	*read_dictionary(int fd)
{
	char	*buffer;
	char	*dest;
	int		n;

	buffer = malloc(sizeof(char) * 1025);
	if (!buffer)
		return (NULL);
	n = 1;
	dest = "\0";
	while (n)
	{
		n = read(fd, buffer, 1024);
		if (n == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[n] = '\0';
		if (*buffer)
			dest = ft_strjoin(dest, buffer);
	}
	free(buffer);
	if (!n && !(*dest))
		return (NULL);
	return (dest);
}

char	**get_dictionary(int ac, char *av[])
{
	int		fd;
	char	*s;
	char	**dest;

	if (ac == 2)
		fd = open("numbers.dict", O_RDONLY);
	else
		fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_putstr("Error\n"), NULL);
	s = read_dictionary(fd);
	close (fd);
	if (!s)
		return (ft_putstr("Error\n"), NULL);
	dest = ft_split(s);
	free(s);
	if (!dest)
		return (ft_putstr("Error\n"), NULL);
	return (dest);
}
