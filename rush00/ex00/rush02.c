/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:09:59 by wacista           #+#    #+#             */
/*   Updated: 2024/03/21 18:00:17 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < y)
	{
		if ((i == 0 || i == x - 1) && j == 0)
			ft_putchar('A');
		else if ((i == 0 || i == x - 1) && (j == y - 1 && y > 1))
			ft_putchar('C');
		else if ((j > 0 && j < y - 1) && (i > 0 && i < x - 1))
			ft_putchar(' ');
		else
			ft_putchar('B');
		if (i == x - 1)
		{
			i = -1;
			j++;
			ft_putchar('\n');
		}
		i++;
	}
}
