/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:01:18 by wacista           #+#    #+#             */
/*   Updated: 2024/03/25 19:33:17 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
		return (NULL);
	max -= min;
	tab = (int *)malloc(sizeof(int) * max);
	if(!tab)
		return (NULL);
	i = 0;
	while (i < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	return (tab);
}
