/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:31:16 by wacista           #+#    #+#             */
/*   Updated: 2024/03/21 17:58:38 by wacista          ###   ########.fr       */
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
		if ((i == 0 && j == 0) || (i == x - 1 && j == y - 1 && x > 1 && y > 1))
			ft_putchar('/');
		else if ((i == 0 && j == y - 1 && y > 1) || \
		(i == x - 1 && j == 0 && x > 1))
			ft_putchar('\\');
		else if ((j > 0 && j < y - 1) && (i > 0 && i < x - 1))
			ft_putchar(' ');
		else
			ft_putchar('*');
		if (i == x - 1)
		{
			i = -1;
			j++;
			ft_putchar('\n');
		}
		i++;
	}
}
