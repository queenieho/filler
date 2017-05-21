/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 15:11:57 by qho               #+#    #+#             */
/*   Updated: 2017/05/20 22:05:53 by qho              ###   ########.fr       */
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
		// fprintf(stderr, "ring: %d\n", ring);
		if (ring == 1)
			ft_add_ring(map, ring, 9);
		else
			ft_add_ring(map, ring, ring - 1);
		// sleep(1);
	}
	ring--;
	while (--ring > 0)
	{
		// fprintf(stderr, "ring: %d\n", ring);
		ft_add_ring(map, ring, ring + 1);
		// sleep(1);
	}
}

void	ft_load_piece(t_piece *piece, char *line)
{
	static int	r = 0;
	int			c;
	int			idx;

	c = -1;
	idx = 0;
	while (++c < piece->width)
	{
		if (line[idx] == '.')
			piece->shape[r][c] = 0;
		else
			piece->shape[r][c] = 1;
		idx++;
	}
	r++;
	if (r == piece->height)
		r = 0;
}

void	ft_load_map(t_map *map, char *line)
{
	// fprintf(stderr, "%s\n", "loading line");
	char		**split;
	static int	r = 0;
	int			c;
	int			idx;

	split = ft_strsplit(line, ' ');
	// fprintf(stderr, "%s\n", "line split");
	idx = 0;
	c = -1;
	while (++c < map->width)
	{
		if (ft_toupper(split[1][idx]) == map->player)
			map->map[r][c] = 5;
		else if (ft_toupper(split[1][idx]) == map->enemy)
			map->map[r][c] = 9;
		else
			map->map[r][c] = 0;
		idx++;
	}
	r++;
	if (r == map->height)
		r = 0;
	ft_array_del(split);
}