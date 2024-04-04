/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 04:14:05 by wacista           #+#    #+#             */
/*   Updated: 2024/04/04 04:45:08 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	asc;
	int	desc;

	i = 0;
	asc = 1;
	desc = 1;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			asc = 0;
		else if (f(tab[i], tab[i + 1]) < 0)
			desc = 0;
		i++;
	}
	return (asc || desc);
}

/* #include <stdio.h>
int	compare(int a, int b)
{
	return (a - b);
}
int main(void)
{
	int tab[] = {1, 2, 3, 3, 5};
	printf("%d\n", ft_is_sort(tab, 5, &compare));
	return (0);
} */
