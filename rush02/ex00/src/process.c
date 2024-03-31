/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 22:12:21 by wacista           #+#    #+#             */
/*   Updated: 2024/04/01 00:34:22 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

void	num_to_word(t_dict *s, char *nb)
{
	int	i;

	i = 0;
	while (s[i].key)
	{
		if (!ft_strcmp(s[i].key, nb))
			ft_putstr(s[i].value);
		i++;
	}
}

void	modulo_two(t_dict *s, char *nb, int len)
{
	t_process	t;

	t.tmp2[0] = nb[0];
	t.tmp2[1] = nb[1];
	t.tmp2[2] = '\0';
	
	if (t.tmp2[0] > '1')
	{
		t.tmp5[0] = t.tmp2[0];
		t.tmp5[1] = '0';
		t.tmp5[2] = '\0';
		num_to_word(s, t.tmp5);
		ft_putchar(' ');
		t.tmp3[0] = t.tmp2[1];
		t.tmp3[1] = '\0';
		num_to_word(s, t.tmp3);
	}
	else
		num_to_word(s, t.tmp2);
	if (len != 2)
	{
		ft_putchar(' ');
		t.tmp = (char *)malloc(sizeof(char) * len);
		if (!t.tmp)
			return ;
		t.tmp[0] = '1';
		t.i = 1;
		while (t.i < len - 1)
			t.tmp[t.i++] = '0';
		t.tmp[t.i] = '\0';
		num_to_word(s, t.tmp);
		ft_putchar(' ');
		free(t.tmp);
		if (t.tmp2[1] == '0')
			return ;
		process(s, nb + 2);
	}
}

void	modulo_one(t_dict *s, char *nb, int len)
{
	t_process	t;

	t.tmp3[0] = nb[0];
	t.tmp3[1] = '\0';
	num_to_word(s, t.tmp3);
	ft_putchar(' ');
	if (len != 1)
	{
		t.tmp = (char *)malloc(sizeof(char) * len + 1);
		if (!t.tmp)
			return ;
		t.tmp[0] = '1';
		t.i = 1;
		while (t.i < len)
			t.tmp[t.i++] = '0';
		t.tmp[t.i] = '\0';
		num_to_word(s, t.tmp);
		free(t.tmp);
	}
	if (len == 1)
		return ;
	ft_putchar(' ');
	if (nb[1] == '0')
		return ;
	process(s, nb + 1);
}

void	modulo_zero(t_dict *s, char *nb, int len)
{
	t_process	t;

	
		t.tmp3[0] = nb[0];
		t.tmp3[1] = '\0';
		num_to_word(s, t.tmp3);
		ft_putchar(' ');
		num_to_word(s, "100");
		if (ft_strcmp(nb, "100"))
			ft_putchar(' ');
		if (nb[1] != '0')
		{
			t.tmp2[0] = nb[1];
			t.tmp2[1] = '0';
			t.tmp2[2] = '\0';
			num_to_word(s, t.tmp2);
			ft_putchar(' ');
		}
		if (nb[2] != '0')
		{
			t.tmp4[0] = nb[2];
			t.tmp4[1] = '\0';
			num_to_word(s, t.tmp4);
			ft_putchar(' ');
		}
		if (len != 3)
		{
			t.tmp = (char *)malloc(sizeof(char) * (len - 2) + 1);
			if (!t.tmp)
				return ;
			t.tmp[0] = '1';
			int i = 1;
			while (i < len - 2)
				t.tmp[i++] = '0';
			t.tmp[i] = '\0';
			num_to_word(s, t.tmp);
			free(t.tmp);
		}
		if (len == 3)
			return ;
		ft_putchar(' ');
		if (t.tmp3[0] == '0')
			return ;
		process(s, nb + 3);
}



void	process(t_dict *s, char *nb)
{
	int		len;

	len = ft_strlen(nb);
	if (!len)
		return ;
	if (len > 1 && nb[0] == '0')
	{
		if (nb[1] == '\0')
			return ;
		process(s, nb + 1);
	}
	else if (len %  3 == 0)
		modulo_zero(s, nb, len);
	else if (len % 3 == 1)
		modulo_one(s, nb, len);
	else if (len % 3 == 2)
		modulo_two(s, nb, len);
}
