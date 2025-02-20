/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:10:43 by wacista           #+#    #+#             */
/*   Updated: 2024/04/04 03:47:29 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < length)
	{
		if (f(tab[i]))
			count++;
		i++;
	}
	return (count);
}

/* #include <stdio.h>
int	is_n(char *s)
{
	int	i = 0;
	while (s[i])
	{
		if (s[i] == 'n')
			return (1);
		i++;
	}
	return (0);
}
int	main(int ac, char *av[])
{
	(void)ac;
	printf("%d\n", ft_count_if(av, 5, &is_n));
} */
