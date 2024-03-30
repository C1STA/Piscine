/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 06:04:40 by wacista           #+#    #+#             */
/*   Updated: 2024/03/30 18:24:15 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int	main(int ac, char *av[])
{
	char	**dict;
	t_dict	*s;

	if (ac != 2 && ac != 3)
		return (ft_putstr_error("Error\n"), 1);
	dict = get_dictionary(ac, av);
	if (!dict)
		return (2);
	if (!parsing(dict))
		return (3);
	s = fill_data(dict);
	if (!s)
		return (4);
	free_split(dict);
	print_numbers(s);
	free_struct(s);
	return (0);
}
