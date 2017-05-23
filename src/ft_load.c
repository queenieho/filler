/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 15:11:57 by qho               #+#    #+#             */
/*   Updated: 2017/05/22 19:01:53 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_array_len(char **args)
{
	int		len;
	char	**tmp;

	len = 0;
	tmp = args;
	while (*tmp)
	{
		tmp++;
		len++;
	}
	return (len);
}

void	ft_get_piece_origin(t_piece *piece, int r, int c)
{
	piece->r = r < piece->r ? r : piece->r;
	piece->c = c < piece->c ? c : piece->c;
}

int		ft_get_count(int *ar, int len)
{
	int	idx;
	int	cnt;

	idx = -1;
	cnt = 0;
	while (++idx < len)
	{
		if (ar[idx] == 1)
			cnt++;
	}
	return (cnt);
}

void	ft_get_truesize(t_piece *piece)
{
	piece->true_h = ft_get_piece_height(piece);
	piece->true_w = ft_get_piece_width(piece);
}

void	ft_load_piece(t_piece *piece, char *line)
{
	static int	r = 0;
	int			c;
	int			idx;

	c = -1;
	idx = 0;
	if (*line == '\0')
		return ;
	while (++c < piece->width)
	{
		if (line[idx] == '.')
			piece->shape[r][c] = 0;
		else
		{
			ft_get_piece_origin(piece, r, c);
			piece->shape[r][c] = 1;
		}
		idx++;
	}
	r++;
	if (r == piece->height)
	{
		ft_get_truesize(piece);
		r = 0;
	}
}
