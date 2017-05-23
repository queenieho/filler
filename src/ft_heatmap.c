/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heatmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:57:16 by qho               #+#    #+#             */
/*   Updated: 2017/05/22 18:59:38 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_check_surround(t_map *m, int r, int c, int t)
{
	if (c > 0 && m->map[r][c - 1] == t)
		return (1);
	else if (r > 0 && m->map[r - 1][c] == t)
		return (1);
	else if (c > 0 && r > 0 && m->map[r - 1][c - 1] == t)
		return (1);
	else if (c + 1 < m->width && m->map[r][c + 1] == t)
		return (1);
	else if (c + 1 < m->width && r > 0 && m->map[r - 1][c + 1] == t)
		return (1);
	else if (c + 1 < m->width && r + 1 < m->height &&
		m->map[r + 1][c + 1] == t)
		return (1);
	else if (r + 1 < m->height && m->map[r + 1][c] == t)
		return (1);
	else if (r + 1 < m->height && c > 0 && m->map[r + 1][c - 1] == t)
		return (1);
	return (0);
}

void	ft_add_ring(t_map *map, int nb, int t)
{
	int		r;
	int		c;
	int		**m;

	r = -1;
	m = map->map;
	(void)nb;
	(void)t;
	while (++r < map->height)
	{
		c = -1;
		while (++c < map->width)
		{
			if (m[r][c] == 0 && ft_check_surround(map, r, c, t) == 1)
				m[r][c] = nb;
		}
	}
}

void	ft_heatmap(t_map *map)
{
	int		ring;

	ring = 0;
	while (++ring <= 3)
	{
		if (ring == 1)
			ft_add_ring(map, ring, 9);
		else
			ft_add_ring(map, ring, ring - 1);
	}
	ring--;
	while (--ring > 0)
	{
		ft_add_ring(map, ring, ring + 1);
	}
}

void	ft_load_map2(t_map *map, char p, int r, int c)
{
	if (ft_toupper(p) == map->player)
		map->map[r][c] = 5;
	else if (ft_toupper(p) == map->enemy)
		map->map[r][c] = 9;
	else
		map->map[r][c] = 0;
}

void	ft_load_map(t_map *map, char *line)
{
	char		**split;
	static int	r = 0;
	int			c;
	int			idx;

	if (*line == '\0')
		return ;
	split = ft_strsplit(line, ' ');
	if ((ft_array_len(split)) < 2)
	{
		ft_array_del(split);
		return ;
	}
	idx = 0;
	c = -1;
	while (++c < map->width)
	{
		ft_load_map2(map, split[1][idx], r, c);
		idx++;
	}
	r++;
	if (r == map->height)
		r = 0;
	ft_array_del(split);
}
