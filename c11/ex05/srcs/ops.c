/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 06:01:06 by wacista           #+#    #+#             */
/*   Updated: 2024/04/04 06:48:21 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	ft_add(int a, int b)
{
	ft_putnbr(a + b);
}

void	ft_sub(int a, int b)
{
	ft_putnbr(a - b);
}

void	ft_mul(int a, int b)
{
	ft_putnbr(a * b);
}

void	ft_div(int a, int b)
{
	if (!b)
		return (ft_putstr("Stop : division by zero"));
	ft_putnbr(a / b);
}

void	ft_mod(int a, int b)
{
	if (!b)
		return (ft_putstr("Stop : modulo by zero"));
	ft_putnbr(a % b);
}
