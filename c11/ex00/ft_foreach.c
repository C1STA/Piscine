/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:46:20 by wacista           #+#    #+#             */
/*   Updated: 2024/04/03 17:59:17 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int lenght, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < lenght)
		f(tab[i++]);
}

/* #include <stdio.h>
void	print_int(int nb)
{
	printf("%d\n", nb);
}

int	main(void)
{
	int	tab[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	ft_foreach(tab, 10, &print_int);
} */