/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 15:11:57 by qho               #+#    #+#             */
/*   Updated: 2017/05/20 15:32:40 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_load_map(t_map *map, char *line)
{
	char			**split;
	static int		r = 0;
	int				c;
	int				idx;

	split = ft_strsplit(line, ' ');
	idx = 0;
	c = -1;
	while (++c < map->width)
	{
		if (split[1][idx] == 'o' || split[1][idx] == 'O')
			map->map[r][c] = 5;
		else if (split[1][idx] == 'x' || split[1][idx] == 'X')
			map->map[r][c] = 9;
		else
			map->map[r][c] = 0;
		idx++;
	}
	r++;
	ft_array_del(split);
}