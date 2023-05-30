/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:40:03 by tdelgran          #+#    #+#             */
/*   Updated: 2023/05/30 14:17:47 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_w(t_game *game)
{
	int	x;
	int	y;

	x = game->player_posx;
	y = game->player_posy;
	if (game->map[y - 1][x] == '1' || (game->map[y - 1][x] == 'E' \
		&& game->comes > 0))
		return ;
	else
	{
		if (game->map[y - 1][x] == 'C')
			game->comes--;
		else if (game->map[y - 1][x] == 'E' && game->comes == 0)
			exit(EXIT_SUCCESS);
		game->map[y - 1][x] = 'p';
		game->map[y][x] = '0';
	}
	game->step += 1;
	ft_printf("%d\n", game->step);
	game->player_posy = y - 1;
}

void	move_s(t_game *game)
{
	int	x;
	int	y;

	x = game->player_posx;
	y = game->player_posy;
	if (game->map[y + 1][x] == '1' || (game->map[y + 1][x] == 'E' \
		&& game->comes > 0))
		return ;
	else
	{
		if (game->map[y + 1][x] == 'C')
			game->comes--;
		else if (game->map[y + 1][x] == 'E' && game->comes == 0)
			exit(EXIT_SUCCESS);
		game->map[y + 1][x] = 'p';
		game->map[y][x] = '0';
	}
	game->step += 1;
	ft_printf("%d\n", game->step);
	game->player_posy = y + 1;
}

void	move_a(t_game *game)
{
	int	x;
	int	y;

	x = game->player_posx;
	y = game->player_posy;
	if (game->map[y][x - 1] == '1' || (game->map[y][x - 1] == 'E' \
		&& game->comes > 0))
		return ;
	else
	{
		if (game->map[y][x - 1] == 'C')
			game->comes--;
		else if (game->map[y][x - 1] == 'E' && game->comes == 0)
			exit(EXIT_SUCCESS);
		game->map[y][x - 1] = 'p';
		game->map[y][x] = '0';
	}
	game->step += 1;
	ft_printf("%d\n", game->step);
	game->player_posx = x - 1;
}

void	move_d(t_game *game)
{
	int	x;
	int	y;

	x = game->player_posx;
	y = game->player_posy;
	if (game->map[y][x + 1] == '1' || (game->map[y][x + 1] == 'E' \
		&& game->comes > 0))
		return ;
	else
	{
		if (game->map[y][x + 1] == 'C')
			game->comes--;
		else if (game->map[y][x + 1] == 'E' && game->comes == 0)
			exit(EXIT_SUCCESS);
		game->map[y][x + 1] = 'p';
		game->map[y][x] = '0';
	}
	game->step += 1;
	ft_printf("%d\n", game->step);
	game->player_posx = x + 1;
}

int	key(int key_code, t_game *game)
{
	if (key_code == KEY_ECHAP)
		exit(EXIT_SUCCESS);
	if (key_code == KEY_W)
		move_w(game);
	if (key_code == KEY_S)
		move_s(game);
	if (key_code == KEY_A)
		move_a(game);
	if (key_code == KEY_D)
		move_d(game);
	return (0);
}
