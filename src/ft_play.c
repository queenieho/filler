/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 00:49:14 by qho               #+#    #+#             */
/*   Updated: 2017/05/22 21:33:19 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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

int		ft_check_place(int piece, int map, int *p_flag, int *score)
{
	if (piece == 1 && map == 5 && *p_flag == 0)
		*p_flag = 1;
	else if (piece == 1 && map == 5 && *p_flag == 1)
		return (-1);
	else if (piece == 1 && map == 9)
		return (-1);
	else if (piece == 1 && (map != 5 || map != 9))
		*score += map;
	return (0);
}

int		ft_try_place(t_map *m, t_piece p, int r, int c)
{
	int		score;
	int		pr;
	int		pc;
	int		mc;
	int		p_flag;

	score = 0;
	p_flag = 0;
	pr = -1;
	while (++pr < p.height && r < (m->height))
	{
		pc = -1;
		mc = c;
		while (++pc < p.width && mc < (m->width))
		{
			if (r >= 0 && mc >= 0)
				if (ft_check_place(p.shape[pr][pc], m->map[r][mc],
					&p_flag, &score) == -1)
					return (-1);
			mc++;
		}
		r++;
	}
	return ((p_flag == 1) ? score : -1);
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
	while (++r < (m->height - p.true_h - p.r + 1))
	{
		c = 0 - p.c - 1;
		while (++c < (m->width - p.true_w - p.c + 1))
		{
			if ((score = ft_try_place(m, p, r, c)) != -1)
			{
				if ((saved_score == 0 && score == 0) || score > saved_score)
				{
					saved_score = score;
					ft_save_position(m, r, c);
				}
			}
		}
	}
}
