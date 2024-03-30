/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 05:50:53 by wacista           #+#    #+#             */
/*   Updated: 2024/03/30 18:24:01 by wacista          ###   ########.fr       */
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
}	t_dict;

void			ft_putchar(char c);
void			ft_putstr(char *s);
int				ft_strlen(char *s);
char			**ft_split(char *str);
void			free_split(char **src);
int				parse_numbers(char **s);
int				parsing(char **src);
void			ft_putstr_error(char *s);
char			*ft_strjoin(char *s1, char *s2);
struct s_dict	*fill_numbers(char **src);
char			**get_dictionary(int ac, char *av[]);
void			print_numbers(t_dict *s);
void			free_fill_key(t_dict *s, int j);
void			free_key(t_dict *s);
struct s_dict	*fill_data(char **src);
void			fill_values(t_dict *s, char **src);
void			free_fill_value(t_dict *s, int j);
int				alloc_values(t_dict *s, char **src);
void			free_struct(t_dict *s);

#endif