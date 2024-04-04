/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 08:30:02 by wacista           #+#    #+#             */
/*   Updated: 2024/04/04 09:06:53 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int		res;
	int		sign;
	int		base_len;

	res = 0;
	sign = 1;
	base_len = ft_strlen(base);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_strchr(base, *str))
	{
		res = res * base_len + (ft_strchr(base, *str) - base);
		str++;
	}
	return (res * sign);
}

/* #include <stdio.h>
int	main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("%d\n", ft_atoi_base(av[1], av[2]));
	}
	return (0);
}
 */