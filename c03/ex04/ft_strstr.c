/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:19:54 by wacista           #+#    #+#             */
/*   Updated: 2024/03/21 00:10:32 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*start;
	char	*tmp;

	if (!*to_find)
		return (str);
	tmp = to_find;
	while (*str)
	{
		to_find = tmp;
		start = str;
		while (*to_find && *str == *to_find)
		{
			str++;
			to_find++;
		}
		if (!*to_find)
			return (start);
		else
			str = start + 1;
	}
	return ((void *)0);
}

/* #include <string.h>
#include <stdio.h>
int	main(void)
{
	char	*str = "ratatatatatatata0abc";
	char	*find = "tata0";
	printf("%s\n", ft_strstr(str, find));
	printf("%s\n", strstr(str, find));
} */
