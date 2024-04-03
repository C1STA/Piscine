/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:54:21 by wacista           #+#    #+#             */
/*   Updated: 2024/04/03 17:52:36 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*res;

	i = 0;
	res = (int *)malloc(sizeof(int) * length);
	if (!res)
		return (0);
	while (i < length)
	{
		res[i] = f(tab[i]);
		i++;
	}
	return (res);
}

/* int	fill(int nb)
{
	return (nb);
}
#include <stdio.h>
int	main(void)
{
	int i = 0;
	int array[10] = {0, 1, 2, 4, 4, 5, 6, 7, 8, 9};
	int	*tab = ft_map(array, 10, &fill);
	while (i < 10)
	{
		printf("%d\n", tab[i]);
		i++;
	}
	free(tab);
} */
