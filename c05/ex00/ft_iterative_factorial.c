/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:54:07 by wacista           #+#    #+#             */
/*   Updated: 2024/03/22 12:05:54 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	res;

	if (nb < 0)
		return (0);
	i = 1;
	res = 1;
	while (i <= nb)
	{
		res *= i;
		i++;
	}
	return (res);
}
