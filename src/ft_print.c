/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 13:05:06 by qho               #+#    #+#             */
/*   Updated: 2017/05/22 19:03:04 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_get_piece_width(t_piece *piece)
{
	int		ar[piece->width];
	int		r;
	int		c;
	int		idx;
	int		cnt;

	r = -1;
	cnt = 0;
	ft_bzero(ar, sizeof(int) * piece->width);
	while (++r < piece->height)
	{
		c = -1;
		idx = 0;
		while (++c < piece->width)
		{
			if (piece->shape[r][c] == 1)
				ar[idx] = 1;
			idx++;
		}
	}
	cnt = ft_get_count(ar, piece->width);
	return (cnt);
}

int		ft_get_piece_height(t_piece *piece)
{
	int		r;
	int		c;
	int		height;

	r = -1;
	height = 0;
	while (++r < piece->height)
	{
		c = -1;
		while (++c < piece->width)
		{
			if (piece->shape[r][c] == 1 && r >= height)
				height++;
		}
	}
	return (height);
}

void	ft_print(int **grid, int r, int c)
{
	if (grid[r][c] == 1)
		ft_putstr_fd("\033[32;1m1\033[0m", 2);
	else if (grid[r][c] == 2)
		ft_putstr_fd("\033[33;1m2\033[0m", 2);
	else if (grid[r][c] == 3)
		ft_putstr_fd("\033[31;1m3\033[0m", 2);
	else if (grid[r][c] == 5)
		ft_putstr_fd("\033[36;1m5\033[0m", 2);
	else if (grid[r][c] == 0)
		ft_putstr_fd("\033[90;1m0\033[0m", 2);
	else
		ft_putstr_fd("\033[31;1m9\033[0m", 2);
}

void	ft_print_grid(int **grid, int height, int width)
{
	int		r;
	int		c;
	int		idx;

	r = -1;
	idx = -1;
	while (++idx < height * 2)
		ft_putchar_fd('\0', 2);
	ft_putstr_fd("\033[0m\n", 2);
	while (++r < height)
	{
		c = -1;
		while (++c < width)
			ft_print(grid, r, c);
		ft_putchar_fd('\n', 2);
	}
}

void	ft_print_answer(char *solution, t_map map)
{
	ft_print_grid(map.map, map.height, map.width);
	ft_print_grid(map.piece.shape, map.piece.height, map.piece.width);
	ft_putstr_fd(solution, 1);
}
