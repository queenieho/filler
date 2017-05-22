/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 00:49:14 by qho               #+#    #+#             */
/*   Updated: 2017/05/22 00:51:19 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_try_place(t_map *m, t_piece p, int r, int c) // return -1 when no go, if it can be placed, return the score of position.
{
	int		score;
	int		pr;
	int		pc;
	int		mc;
	int		p_flag;

	score = 0;
	p_flag = 0;
	pr = -1;
	// fprintf(stderr, "\n%s testing piece at r: %d and c %d %s\n", R, r, c, W);

	// fprintf(stderr, "piece shape: \n");
	// fprintf(stderr, "map shape: \n");
	while (++pr < p.height && r < (m->height))
	{
		pc = -1;
		mc = c;
		while (++pc < p.width && mc < (m->width))
		{
			// fprintf(stderr, "%s%d%s", Y, p.shape[pr][pc], W);
			if (r >= 0 && mc >= 0)
			{
				// fprintf(stderr, "%s%d%s", C, m->map[r][mc], W);
				
				// if (p.shape[pr][pc] == 1 && m->map[r][mc] == 5)
				// {
				// 	p_flag++;
				// 	// fprintf(stderr, "matching a shape %d!!!\n", p_flag);
				// 	// fprintf(stderr, "r: %d c: %d in piece with r: %d c: %d  in map\n", pr, pc, r, c);
				// }
				if (p.shape[pr][pc] == 1 && m->map[r][mc] == 5 && p_flag == 0)
					p_flag = 1;
				else if (p.shape[pr][pc] == 1 && m->map[r][mc] == 5 && p_flag == 1)
				{
					// fprintf(stderr, "%s NOT THIS!%s\n", R, W);
					return (-1);
				}
				else if (p.shape[pr][pc] == 1 && m->map[r][mc] == 9)
					return (-1);
				else if (p.shape[pr][pc] == 1 && (m->map[r][mc] != 5 || m->map[r][c] != 9))
					score += m->map[r][mc];
			}
			mc++;
		}
		// fprintf(stderr, "\n");
		r++;
	}
	// fprintf(stderr, "\n");
	if (p_flag == 1)
		return (score);
	else
		return (-1);
}

void	ft_save_position(t_map *m, int r, int c)
{
	m->sol_r = r;
	m->sol_c = c;
}

void	ft_play(t_map *m)
{
	int		r; 
	int		c;
	int		score;
	int		saved_score;
	t_piece p;

	saved_score = 0;
	p = m->piece;
	r = 0 - p.r - 1;
	c = 0 - p.c - 1;
	// fprintf(stderr, "start at r: %d and c %d\n", r + 1, c + 1);
	while (++r < (m->height - p.true_h - p.r + 1))
	{
		c = 0 - p.c - 1;
		while (++c < (m->width - p.true_w - p.c + 1))
		{
			// fprintf(stderr, "testing piece at r: %d and c %d\n", r, c);
			if ((score = ft_try_place(m, p, r, c)) != -1) // piece can be placed down
			{
				// fprintf(stderr, "%sCAN BE PLACED at r: %d and c %d%s\n", G, r, c, W);
				// sleep(2);
				if ((saved_score == 0 && score == 0) || score > saved_score) // compare score // if score is higher, save this spot
				{
					saved_score = score;
					ft_save_position(m, r, c);
				}
			}
		}
	}
}