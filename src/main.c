/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 17:21:50 by qho               #+#    #+#             */
/*   Updated: 2017/05/20 09:27:05 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_array_del(char **values)
{
	int	idx;

	idx = -1;
	while (values[++idx])
		free(values[idx]);
	free(values);
}

int		ft_get_player(char *line)
{
	char	**split;
	int		p;

	split = ft_strsplit(line, ' ');
	p = (split[2][1]) - 48;
	ft_array_del(split);
	// if (p < 1 && p > 2)   DO I REALLY NEED TO ERROR CHECK FOR THIS?
	// 	return (-1);
	return (p);
}

int		ft_get_linecount(char *line)
{
	int		count;
	char	**split;

	count = 0;
	split = ft_strsplit(line, ' ');
	count = ft_atoi(split[1]);
	ft_array_del(split);
	return (count);
}

int		ft_get_width(char *line)
{
	int		count;
	char	**split;

	count = 0;
	split = ft_strsplit(line, ' ');
	count = ft_atoi(split[2]);
	ft_array_del(split);
	return (count);
}

void	ft_get_mapsize(char *line, t_map *map)
{
	map->height = ft_get_linecount(line);
	map->width = ft_get_width(line);
}

void	ft_get_piecesize(char *line, t_piece *piece)
{
	piece->height = ft_get_linecount(line);
	piece->width = ft_get_width(line);
}

int		ft_parse(char *line, t_map *map)
{
	static int	m_row = 0;
	static int	p_row = 0;
	int			row;

	(void)map;
	if ((!(ft_strncmp(line, "$$$", 3))) && (ft_strstr(line, NAME)))
	{
		map->player = ft_get_player(line);
		// fprintf(stderr, "%s%s%s\n", G, line, W);
		fprintf(stderr, "%s player: %d%s\n", Y, map->player, W);
	}
	if (!(ft_strncmp(line, "Plateau", 7)))
	{
		// m_row = ft_get_linecount(line);
		ft_get_mapsize(line, map);
		m_row = map->height + 1;
		fprintf(stderr, "%s map len: %d, map width %d%s\n", Y, m_row, map->width, W);
	}
	if (!(ft_strncmp(line, "Piece", 5)))
	{
		ft_get_piecesize(line, &map->piece);
		p_row = map->piece.height;
		// p_row = ft_get_linecount(line);
		fprintf(stderr, "%s piece len: %d, piece width %d%s\n", Y, p_row, map->piece.width, W);
	}
	return (0);
}

int		main(void)
{
	char	*line;
	t_map	map;
	int		i;

	i = 0;
	while ((get_next_line(0, &line)) == 1)
	{
		if (ft_parse(line, &map) == 1) // ft_parse returns 1 when it's done reading the whole map and piece
		{
			// Analize map, analize piece and place piece
		}
		fprintf(stderr, "%d: %s%s%s\n", i, G, line, W);
		// fprintf(stderr, "test line\n");
		free(line);
		i++;
	}
	// fprintf(stderr, "%stest line: %d %s%s\n", G, i, line, W);
	return (0);
}
