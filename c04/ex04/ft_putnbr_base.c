/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:56:26 by wacista           #+#    #+#             */
/*   Updated: 2024/03/21 17:25:56 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	if (!base[0] || !base[1])
		return (1);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		if ((base[i] < 32) || base[i] > 126 || \
		base[i] == '+' || base[i] == '-')
			return (1);
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (check_base(base))
		return ;
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		ft_putnbr_base((2147483648 / 10) / ft_strlen(base), base);
		ft_putchar(base[(2147483648 / 10) % ft_strlen(base)]);
		ft_putchar(base[8 % ft_strlen(base)]);
	}
	else
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = nbr * -1;
		}
		if (nbr < ft_strlen(base))
			ft_putchar(base[nbr]);
		else
		{
			ft_putnbr_base(nbr / ft_strlen(base), base);
			ft_putchar(base[(nbr % ft_strlen(base))]);
		}
	}
}
