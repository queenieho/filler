/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 17:21:50 by qho               #+#    #+#             */
/*   Updated: 2017/05/19 22:01:48 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_array_del(char **values)
{
	int	idx;

	idx = -1;
	while (values[++idx])
		free(values[idx]);
	free(values);
}

int		ft_get_player(char *line)
{
	char	**split;
	int		p;

	split = ft_strsplit(line, ' ');
	p = (split[2][1]) - 48;
	ft_array_del(split);
	// if (p < 1 && p > 2)   DO I REALLY NEED TO ERROR CHECK FOR THIS?
	// 	return (-1);
	return (p);
}

int		ft_parse(char *line, t_map *map)
{
	(void)map;
	if (!(ft_strncmp(line, "$$$", 3)))
	{
		if (ft_strstr(line, NAME))
		{
			map->player = ft_get_player(line);
			fprintf(stderr, "%s%s%s\n", G, line, W);
			fprintf(stderr, "%s player: %d%s\n", G, map->player, W);
		}
	}
	return (0);
}

int		main(void)
{
	char	*line;
	t_map	map;
	int		i;

	i = 0;
	while ((get_next_line(0, &line)) == 1)
	{
		if (ft_parse(line, &map) == 1) // ft_parse returns 1 when it's done reading the whole map and piece
		{
			// Analize map, analize piece and place piece
		}
		fprintf(stderr, "%d: %s%s%s\n", i, G, line, W);
		// fprintf(stderr, "test line\n");
		free(line);
		i++;
	}
	// fprintf(stderr, "%stest line: %d %s%s\n", G, i, line, W);
	return (0);
}
