/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:10:59 by wacista           #+#    #+#             */
/*   Updated: 2024/03/26 15:12:32 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*hex_base;

	i = 0;
	hex_base = "0123456789abcdef";
	while (str[i])
	{
		if ((str[i] < 32) || str[i] > 126)
		{
			ft_putchar('\\');
			ft_putchar(hex_base[(unsigned char)str[i] / 16]);
			ft_putchar(hex_base[(unsigned char)str[i] % 16]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
