/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 17:21:32 by qho               #+#    #+#             */
/*   Updated: 2017/05/22 19:07:46 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

# define NAME	"./filler"

/*
** DEFINE COLORS
*/
# define GR		"\x1b[90;1m"
# define G		"\x1b[32;1m"
# define Y		"\x1b[33;1m"
# define R		"\x1b[31;1m"
# define B		"\x1b[34;1m"
# define M		"\x1b[35;1m"
# define C		"\x1b[36;1m"
# define W		"\x1b[0m"

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
	int			true_w;
	int			true_h;
	int			r;
	int			c;
	int			**shape;
}				t_piece;

typedef struct	s_map
{
	char		player;
	char		enemy;
	int			width;
	int			height;
	t_piece		piece;
	int			**map;
	int			sol_r;
	int			sol_c;
	char		*move;
}				t_map;

/*
** FT_HEATMAP_C
*/
int				ft_check_surround(t_map *m, int r, int c, int t);
void			ft_add_ring(t_map *map, int nb, int t);
void			ft_heatmap(t_map *map);
void			ft_load_map2(t_map *map, char p, int r, int c);
void			ft_load_map(t_map *map, char *line);

/*
** FT_INIT_C
*/
void			ft_get_piecesize(char *line, t_piece *piece);
void			ft_init_piece(char *line, t_map *map, int *p_row);
void			ft_get_mapsize(char *line, t_map *map);
void			ft_init_map(char *line, t_map *map, int *m_row);

/*
** FT_LOAD_C
*/
int				ft_array_len(char **args);
void			ft_get_piece_origin(t_piece *piece, int r, int c);
int				ft_get_count(int *ar, int len);
void			ft_get_truesize(t_piece *piece);
void			ft_load_piece(t_piece *piece, char *line);

/*
** FT_PARSE_C
*/
char			ft_get_player(char *line);
void			ft_do_map(int *m_row, t_map *map, char *line);
void			ft_do_piece(int *p_row, t_map *map, char *line);
int				ft_parse(char *line, t_map *map);

/*
** FT_PLAY_C
*/
char			*ft_solution(t_map *m);
int				ft_check_place(int piece, int map, int *p_flag, int *score);
int				ft_try_place(t_map *m, t_piece p, int r, int c);
void			ft_save_position(t_map *m, int r, int c);
void			ft_play(t_map *m);

/*
** FT_PRINT_C
*/
int				ft_get_piece_width(t_piece *piece);
int				ft_get_piece_height(t_piece *piece);
void			ft_print(int **grid, int r, int c);
void			ft_print_grid(int **grid, int height, int width);
void			ft_print_answer(char *solution, t_map map);

/*
** MAIN_C
*/
void			ft_array_del(char **values);
int				ft_get_linecount(char *line);
int				ft_get_width(char *line);
void			ft_cleanup_map(t_map *map);

#endif
