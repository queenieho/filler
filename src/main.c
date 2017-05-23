/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 17:21:50 by qho               #+#    #+#             */
/*   Updated: 2017/05/22 21:50:10 by qho              ###   ########.fr       */
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

int		ft_get_linecount(char *line)
{
	int		count;
	char	**split;

	count = 0;
	split = ft_strsplit(line, ' ');
	if ((ft_array_len(split)) >= 2)
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
	if ((ft_array_len(split)) >= 3)
		count = ft_atoi(split[2]);
	ft_array_del(split);
	return (count);
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

int		main(void)
{
	char	*line;
	char	*solution;
	t_map	map;
	int		i;

	i = 0;
	while ((get_next_line(0, &line)) == 1)
	{
		if (ft_parse(line, &map) == 1)
		{
			if ((map.width < 50 && map.player == 'O') ||
				(map.width > 50 && map.player == 'X'))
				ft_play(&map);
			else
				ft_play2(&map, map.piece);
			solution = ft_solution(&map);
			ft_print_answer(solution, map);
			free(solution);
			ft_cleanup_map(&map);
		}
		free(line);
		i++;
	}
	return (0);
}
