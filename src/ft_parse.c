/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:53:19 by qho               #+#    #+#             */
/*   Updated: 2017/05/22 18:55:55 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	ft_get_player(char *line)
{
	char	**split;
	int		p;
	char	player;

	split = ft_strsplit(line, ' ');
	if ((ft_array_len(split)) < 3)
		player = 'O';
	else
	{
		p = (split[2][1]) - 48;
		if (p == 1)
			player = 'O';
		else
			player = 'X';
	}
	ft_array_del(split);
	return (player);
}

void	ft_do_map(int *m_row, t_map *map, char *line)
{
	if (*m_row <= map->height)
		ft_load_map(map, line);
	*m_row = *m_row - 1;
	if (*m_row == 0)
		ft_heatmap(map);
}

void	ft_do_piece(int *p_row, t_map *map, char *line)
{
	if (*p_row <= map->piece.height)
		ft_load_piece(&map->piece, line);
	*p_row = *p_row - 1;
}

int		ft_parse(char *line, t_map *map)
{
	static int	m_row = 0;
	static int	p_row = 0;
	int			row;

	row = 0;
	if ((!(ft_strncmp(line, "$$$", 3))))
	{
		map->player = ft_get_player(line);
		map->enemy = (map->player == 'O') ? 'X' : 'O';
	}
	if (!(ft_strncmp(line, "Plateau", 7)))
		ft_init_map(line, map, &m_row);
	if (!(ft_strncmp(line, "Piece", 5)))
		ft_init_piece(line, map, &p_row);
	if (m_row > 0 && row == 0)
		ft_do_map(&m_row, map, line);
	if (p_row > 0 && m_row == 0)
	{
		row = 1;
		ft_do_piece(&p_row, map, line);
		if (p_row == 0)
			return (1);
	}
	return (0);
}
