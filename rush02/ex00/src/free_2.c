/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 04:07:35 by wacista           #+#    #+#             */
/*   Updated: 2024/03/31 04:20:19 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

void	free_keys_value(t_keys *keys, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(keys[i].key);
		i++;
	}
	free(keys);
}

void	free_keys(t_keys *keys)
{
	free_keys_value(keys, 41);
}
