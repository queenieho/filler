/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 21:49:19 by qho               #+#    #+#             */
/*   Updated: 2017/05/22 21:58:11 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_play22(t_score *s, t_map *m, int r, int c)
{
	if (s->found == 0)
	{
		s->saved_score = s->score;
		ft_save_position(m, r, c);
		s->found = 1;
	}
	if (s->score > s->saved_score)
	{
		s->saved_score = s->score;
		ft_save_position(m, r, c);
	}
}

void	ft_play2(t_map *m, t_piece p)
{
	int			r;
	int			c;
	t_score		s;

	s.saved_score = 0;
	r = 0 - p.r - 1;
	c = 0 - p.c - 1;
	s.found = 0;
	while (++r < (m->height - p.true_h - p.r + 1))
	{
		c = 0 - p.c - 1;
		while (++c < (m->width - p.true_w - p.c + 1))
		{
			if ((s.score = ft_try_place(m, p, r, c)) != -1)
				ft_play22(&s, m, r, c);
		}
	}
}
