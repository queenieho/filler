/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 13:05:06 by qho               #+#    #+#             */
/*   Updated: 2017/05/20 22:05:42 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_print_grid(int **grid, int height, int width)
{
	int		r;
	int		c;

	r = -1;
	while (++r < height)
	{
		c = -1;
		while (++c < width)
		{
			if (grid[r][c] == 1)
			{
				ft_putstr_fd(G, 2);
				ft_putnbr_fd(grid[r][c], 2);
			}
			else if (grid[r][c] == 2)
			{
				ft_putstr_fd(Y, 2);
				ft_putnbr_fd(grid[r][c], 2);
			}
			else if (grid[r][c] == 3)
			{
				ft_putstr_fd(R, 2);
				ft_putnbr_fd(grid[r][c], 2);
			}
			else if (grid[r][c] == 5)
			{
				ft_putstr_fd(B, 2);
				ft_putnbr_fd(grid[r][c], 2);
			}
			else
				ft_putnbr_fd(grid[r][c], 2);
			ft_putstr_fd(W, 2);
		}
		ft_putchar_fd('\n', 2);
	}
}
