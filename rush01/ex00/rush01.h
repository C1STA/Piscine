/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:51:30 by wacista           #+#    #+#             */
/*   Updated: 2024/03/23 18:04:18 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_free(int **map);
int	parse(char *str, int (*pos)[4]);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int	compute(int (*pos)[4], int **map);
int	can_put_tower(int **map, int y, int x, int (*pos)[4]);

int	verif_topdown(int **map, int x, int (*pos)[4]);
int	verif_downtop(int **map, int x, int (*pos)[4]);
int	verif_leftright(int **map, int y, int (*pos)[4]);
int	verif_rightleft(int **map, int y, int (*pos)[4]);

int	is_playable(int pos[4][4]);

#endif