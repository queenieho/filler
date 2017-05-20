/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 17:21:32 by qho               #+#    #+#             */
/*   Updated: 2017/05/20 08:28:35 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

# define NAME "./filler"
# define P1 "Oo"
# define P2 "Xx"

/*
** DEFINE COLORS
*/
# define G "\033[32;1m"
# define Y "\033[33;1m"
# define R "\033[31;1m"
# define B "\033[34;1m"
# define W "\033[0m"

# ifndef ERRORS
#  define ERR(a, b) if(a){return(b);}
#  define ERR1(a, b, c) if(a){b;return(c);}
#  define ERR2(a, b, c, d) if(a){b;c;return(d);}
# endif

# ifndef W_ERRORS
#  define WERR1(a, b, c) if(a){ft_putendl_fd(b, 2);return(c);}
#  define WERR2(a, b, c, d) if(a){b;ft_putendl_fd(c, 2);return(d);}
# endif

typedef struct	s_piece
{
	int			width;
	int			height;
	int			**shape;
}				t_piece;

typedef struct	s_map
{
	int			player; // indicates if I'm player 1 or 2.
	int			width;
	int			height;
	t_piece		piece;
	int			**map;  //dynamically allocated by the map size. Plateau.
}				t_map;


#endif
