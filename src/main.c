/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 17:21:50 by qho               #+#    #+#             */
/*   Updated: 2017/05/22 01:36:22 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_array_del(char **values)
{
	int	idx;

	idx = -1;
	while (values[++idx] != NULL)
		free(values[idx]);
	free(values);
}

char		ft_get_player(char *line)
{
	char	**split;
	int		p;
	char	player;

	split = ft_strsplit(line, ' ');
	p = (split[2][1]) - 48;
	if (p == 1)
		player = 'O';
	else
		player = 'X';
	ft_array_del(split);
	return (player);
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

int		ft_parse(char *line, t_map *map)
{
	static int	m_row = 0;
	static int	p_row = 0;
	int			row;

	row = 0;
	(void)map;
	if ((!(ft_strncmp(line, "$$$", 3))))
	{
		map->player = ft_get_player(line);
		map->enemy = (map->player == 'O') ? 'X' : 'O';
		// fprintf(stderr, "%s player: %c  enemy: %c%s\n", Y, map->player, map->enemy, W);
	}
	if (!(ft_strncmp(line, "Plateau", 7)))
	{
		ft_init_map(line, map);
		// fprintf(stderr, "%s map len: %d, map width %d%s\n", Y, map->height, map->width, W);
		// ft_print_grid(map->map, map->height, map->width);
		// ft_get_mapsize(line, map);
		m_row = map->height + 2;
	}
	if (!(ft_strncmp(line, "Piece", 5)))
	{
		ft_init_piece(line, map);
		// fprintf(stderr, "%s piece len: %d, piece width %d%s\n", Y, map->piece.height, map->piece.width, W);
		// ft_print_grid(map->piece.shape, map->piece.height, map->piece.width);
		// ft_get_piecesize(line, &map->piece);
		p_row = map->piece.height + 1;
		// p_row = ft_get_linecount(line);
	}
	if (m_row > 0 && row == 0)
	{
		if (m_row <= map->height)
			ft_load_map(map, line);
		m_row--;
		if (m_row == 0)
		{
			ft_heatmap(map);
			// fprintf(stderr, "%s•••• Done reading map%s\n", B, W);
			// ft_print_grid(map->map, map->height, map->width);
		}
	}

	if (p_row > 0 && m_row == 0)
	{
		row = 1;
		if (p_row <= map->piece.height)
		{
			ft_load_piece(&map->piece, line);
			// fprintf(stderr, "%s%s%s\n", R, line, W);
		}
		p_row--;
		if (p_row == 0)
		{
			// fprintf(stderr, "%s•••• Done reading piece%s\n", R, W);
			// fprintf(stderr, "MAP\n");
			// ft_print_grid(map->map, map->height, map->width);
			// fprintf(stderr, "\nPIECE\n");
			// ft_print_grid(map->piece.shape, map->piece.height, map->piece.width);
			// fprintf(stderr, "Origin: row: %d - col: %d\n", map->piece.r, map->piece.c);
			// fprintf(stderr, "Size: w: %d - h: %d\n", map->piece.width, map->piece.height);
			// fprintf(stderr, "TRUE Size: w: %d - h: %d\n", map->piece.true_w, map->piece.true_h);
			return (1);
		}
	}
	return (0);
}

void	ft_cleanup_map(t_map *map)
{
	int		r;

	r = -1;
	free(map->move);
	while (++r < map->height)
		free(map->map[r]);
	free(map->map);
	map->height = 0;
	map->width = 0;
	r = -1;
	while (++r < map->piece.height)
		free(map->piece.shape[r]);
	free(map->piece.shape);
	map->piece.height = 0;
	map->piece.width = 0;
}

char	*ft_solution(t_map *m)
{
	char	*ret;
	char	*col;
	char	*tmp;

	ret = ft_itoa(m->sol_r);
	col = ft_itoa(m->sol_c);
	tmp = ft_strjoin(ret, " ");
	free(ret);
	ret = ft_strjoin(tmp, col);
	free(tmp);
	free(col);
	tmp = ft_strjoin(ret, "\n");
	free(ret);
	return (tmp);
}

int		main(void)
{
	char	*line;
	char	*solution;
	t_map	map;
	int		i;

	i = 0;
	while ((get_next_line(0, &line)) == 1)
	{
		if (ft_parse(line, &map) == 1) // ft_parse returns 1 when it's done reading the whole map and piece
		{
			// ft_print_grid(map->map, map->height, map->width);
			// ft_print_grid(map->piece.shape, map->piece.height, map->piece.width);
			ft_play(&map);
			solution = ft_solution(&map);
			// fprintf(stderr, "place piece at: %s\n", solution);
			ft_putstr_fd(solution, 1);
			free(solution);
			// write(1, "8 2\n", 5);
			ft_cleanup_map(&map);
			
			// sleep(1);
			// Analize map, analize piece and place piece
		}
		// fprintf(stderr, "%3d: %s%s%s\n", i, G, line, W);
		// fprintf(stderr, "test line\n");
		free(line);
		i++;
	}
	// fprintf(stderr, "%stest line: %d %s%s\n", G, i, line, W);
	return (0);
}
