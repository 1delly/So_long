/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:46:09 by tdelgran          #+#    #+#             */
/*   Updated: 2023/05/30 14:39:52 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	first_path(t_game *game, int y, int x)
{
	if (game->mapcpy[y][x] == 'C')
		game->verif_comes++;
	if (game->mapcpy[y][x] == 'E')
	{
		game->verif_exit = 1;
		game->mapcpy[y][x] = '1';
		return ;
	}
	game->mapcpy[y][x] = '1';
	if (x + 1 < game->xlong && game->mapcpy[y][x + 1] != '1')
		first_path(game, y, x + 1);
	if (x - 1 >= 0 && game->mapcpy[y][x - 1] != '1')
		first_path(game, y, x - 1);
	if (y + 1 < game->ylong && game->mapcpy[y + 1][x] != '1')
		first_path(game, y + 1, x);
	if (y - 1 >= 0 && game->mapcpy[y - 1][x] != '1')
		first_path(game, y - 1, x);
}

void	check_path(t_game *game)
{
	if (game->verif_comes != game->comes || game->verif_exit == 0)
		the_error(7);
}

int	mapcpy(t_game *game)
{
	int	x;
	int	y;

	game->mapcpy = ft_calloc(game->line.y + 1, (sizeof(char *)));
	if (!game->mapcpy)
		return (0);
	x = 0;
	while (x < game->line.y)
	{
		game->mapcpy[x] = ft_calloc(game->line.x + 1, sizeof(char));
		if (!game->mapcpy)
			return (0);
		y = -1;
		while (game->map[x][++y])
			game->mapcpy[x][y] = game->map[x][y];
		x++;
	}
	return (1);
}

int	*search_player(t_game *game)
{
	int	*tab;
	int	x;
	int	y;

	tab = malloc(sizeof(int) * 2);
	y = -1;
	while (game->mapcpy[++y])
	{
		x = -1;
		while (game->mapcpy[y][++x])
		{
			if (game->mapcpy[y][x] == 'P')
			{
				tab[0] = y;
				tab[1] = x;
				game->player_posx = x;
				game->player_posy = y;
				return (tab);
			}
		}
	}
	return (NULL);
}
