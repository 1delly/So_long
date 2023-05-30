/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:41:37 by tdelgran          #+#    #+#             */
/*   Updated: 2023/05/30 16:49:47 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_rec(t_game *game)
{
	int		i;
	size_t	first;

	i = -1;
	first = ft_strlen(game->map[0]);
	while (game->map[++i])
	{
		if (ft_strlen(game->map[i]) != 0 && first != ft_strlen(game->map[i]))
			the_error(1);
		if (ft_strlen(game->map[i]) == 0 && game->map[i + 1] \
			&& ft_strlen(game->map[i + 1]) == 0)
			the_error(2);
	}
}

void	check_wall(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if ((game->map[0][x] != '1' \
				|| game->map[game->ylong - 1][x] != '1') \
				&& game->map[0][x] != '\n')
				the_error(0);
			if (game->map[y][0] != '1' || game->map[y][game->xlong - 1] != '1')
				the_error(0);
		}
	}
}

void	check_char(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'C')
				game->comes++;
			else if (game->map[y][x] == 'E')
				game->exit++;
			else if (game->map[y][x] == 'P')
				game->player++;
			else if (game->map[y][x] != '0' && game->map[y][x] != '1' \
				&& game->map[y][x] != '\n')
				the_error(6);
		}
	}
	if (game->comes < 1 || game->exit != 1 || game->player != 1)
		the_error(5);
}

void	parsing(t_game *game, char *av)
{
	int	*tab;

	ft_get_map(av, game);
	declar_struct(game);
	check_rec(game);
	check_wall(game);
	check_char(game);
	mapcpy(game);
	tab = search_player(game);
	first_path(game, tab[0], tab[1]);
	check_path(game);
	free(tab);
}
