/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 05:57:00 by wacista           #+#    #+#             */
/*   Updated: 2024/04/04 07:55:24 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	ft_do_op(char *a, char *op, char *b)
{
	void	(*ops[5])(int, int);

	ops[0] = &ft_add;
	ops[1] = &ft_sub;
	ops[2] = &ft_mul;
	ops[3] = &ft_div;
	ops[4] = &ft_mod;
	if (*op != '+' && *op != '-' && *op != '/' && *op != '*' && *op != '%')
		return (ft_putstr("0\n"));
	if (*op == '+')
		ops[0](ft_atoi(a), ft_atoi(b));
	else if (*op == '-')
		ops[1](ft_atoi(a), ft_atoi(b));
	else if (*op == '*')
		ops[2](ft_atoi(a), ft_atoi(b));
	else if (*op == '/')
		ops[3](ft_atoi(a), ft_atoi(b));
	else
		ops[4](ft_atoi(a), ft_atoi(b));
	ft_putchar('\n');
}
