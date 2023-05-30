/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:12:05 by tdelgran          #+#    #+#             */
/*   Updated: 2023/05/30 16:47:21 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_struc(t_game *game)
{
	game->map = NULL;
	game->line.x = 0;
	game->line.y = 0;
	game->ylong = 0;
	game->xlong = 0;
	game->player = 0;
	game->comes = 0;
	game->exit = 0;
	game->verif_comes = 0;
	game->verif_exit = 0;
	game->mapcpy = 0;
	game->step = 0;
}

void	declar_struct(t_game *game)
{
	int	i;

	i = -1;
	while (game->map[++i] && game->map != NULL)
		game->ylong++;
	game->xlong = ft_strlen(game->map[0]) - 1;
}

static unsigned int	count_lines(const char *file)
{
	char			*line;
	unsigned int	nbr_lines;
	int				fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		the_error(8);
	line = get_next_line(fd);
	nbr_lines = 0;
	while (line != NULL)
	{
		nbr_lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (nbr_lines);
}

void	ft_get_map(const char *file, t_game *game)
{
	char	*line;
	int		i;
	int		fd;

	game->line.y = count_lines(file);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		the_error(8);
	game->line.x = ft_strlen(line);
	game->map = malloc(sizeof(char *) * (game->line.y + 1));
	if (!game->map)
		return ;
	i = 0;
	while (line != NULL)
	{
		game->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	game->map[i] = NULL;
	if (*game->map == NULL)
		the_error(8);
}
