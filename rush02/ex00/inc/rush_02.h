/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 05:50:53 by wacista           #+#    #+#             */
/*   Updated: 2024/03/31 23:56:26 by wacista          ###   ########.fr       */
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

typedef struct s_keys
{
	char			*key;
	int				count;
}	t_keys;

typedef struct s_process
{
	char	*tmp;
	int		i;
	char	tmp2[3];
	char	tmp3[2];
	char	tmp4[2];
	char	tmp5[3];
}	t_process;

void			ft_putchar(char c);
void			ft_putstr(char *s);
int				ft_strlen(char *s);
char			**ft_split(char *str);
void			free_split(char **src);
int				parse_numbers(char **s);
int				parsing(char **src);
void			ft_putstr_err(char *s);
char			*ft_strjoin(char *s1, char *s2);
struct s_dict	*fill_numbers(char **src);
char			**get_dictionary(int ac, char *av[]);
void			free_fill_key(t_dict *s, int j);
void			free_key(t_dict *s);
struct s_dict	*fill_data(char **src);
void			free_fill_value(t_dict *s, int j);
int				alloc_values(t_dict *s, char **src);
void			free_dict(t_dict *s);
char			*ft_itoa(int nbr);
char			*ft_strndup(char *str, int size);
void			free_keys_value(t_keys *keys, int j);
void			free_keys(t_keys *keys);
t_keys			*define_keys(void);
int				ft_strcmp(char *s1, char *s2);
void			free_all(t_dict *s, t_keys *keys, char **src);
bool			are_double_values(t_dict *s);
void			process(t_dict *s, char *nb);

#endif