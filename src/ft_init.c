/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 13:06:57 by qho               #+#    #+#             */
/*   Updated: 2017/05/22 11:38:33 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_get_piecesize(char *line, t_piece *piece)
{
	piece->height = ft_get_linecount(line);
	piece->width = ft_get_width(line);
}

void	ft_init_piece(char *line, t_map *map)
{
	int		r;
	int		c;

	ft_get_piecesize(line, &map->piece);
	r = -1;
	map->piece.r = map->piece.height - 1;
	map->piece.c = map->piece.width - 1;
	map->piece.true_w = 0;
	map->piece.true_h = 0;
	map->sol_r = 0;
	map->sol_c = 0;
	map->piece.shape = (int **)malloc(sizeof(int*) * map->piece.height);
	while (++r < map->piece.height)
	{
		map->piece.shape[r] = (int *)malloc(sizeof(int) * map->piece.width);
		c = -1;
		while (++c < map->piece.width)
		{
			map->piece.shape[r][c] = 0;
		}
	}
}

void	ft_get_mapsize(char *line, t_map *map)
{
	map->height = ft_get_linecount(line);
	map->width = ft_get_width(line);
}

void	ft_init_map(char *line, t_map *map)
{
	int		r;
	int		c;

	ft_get_mapsize(line, map);
	r = -1;
	map->map = (int **)malloc(sizeof(int*) * map->height);
	while (++r < map->height)
	{
		map->map[r] = (int *)malloc(sizeof(int) * map->width);
		c = -1;
		while (++c < map->width)
		{
			map->map[r][c] = 0;
		}
	}
}
