/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 13:05:06 by qho               #+#    #+#             */
/*   Updated: 2017/05/20 13:17:46 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_print_grid(int **grid, int height, int width)
{
	int		r;
	int		c;

	r = -1;
	ft_putstr_fd(G, 2);
	while (++r < height)
	{
		c = -1;
		while (++c < width)
		{
			ft_putnbr_fd(grid[r][c], 2);
		}
		ft_putchar_fd('\n', 2);
	}
	ft_putstr_fd(W, 2);
}
