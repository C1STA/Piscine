/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 05:50:53 by wacista           #+#    #+#             */
/*   Updated: 2024/03/30 14:48:55 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_02_H
# define RUSH_02_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_dict
{
	char			*key;
	char			*value;
	struct s_dict	*next;
}	t_dict;

void	ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_strlen(char *s);
char	**ft_split(char *str);
void	free_split(char **src);
int		parse_numbers(char **s);
int		parsing(char **src);
void	ft_putstr_error(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	**get_dictionary(int ac, char *av[]);

#endif