/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:21:24 by tdelgran          #+#    #+#             */
/*   Updated: 2023/05/30 16:37:10 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*img(t_game *game, char *img)
{
	int		img_w;
	int		img_h;
	void	*image;

	image = mlx_xpm_file_to_image(game->mlxwin, img, &img_w, &img_h);
	if (!image)
		the_error(4);
	return (image);
}

void	start_window(t_game *game)
{
	game->mlxwin = mlx_init();
	game->window = mlx_new_window(game->mlxwin, game->xlong * 50, \
		game->ylong * 50, "Hello bro");
	game->floor = img(game, "./xpm/floor.xpm");
	game->character = img(game, "./xpm/char.xpm");
	game->wall = img(game, "./xpm/wall.xpm");
	game->object = img(game, "./xpm/object.xpm");
	game->f_exit = img(game, "./xpm/f_exit.xpm");
}

void	player_move(t_game *game)
{
	int	x;
	int	y;

	x = game->player_posx;
	y = game->player_posy;
	mlx_put_image_to_window(game->mlxwin, game->window, \
		game->character, x * 50, y * 50);
}

void	set_image(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '0' || game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlxwin, game->window, \
					game->floor, x * 50, y * 50);
			else if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlxwin, game->window, \
					game->wall, x * 50, y * 50);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlxwin, game->window, \
					game->object, x * 50, y * 50);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlxwin, game->window, \
					game->f_exit, x * 50, y * 50);
		}
	}
	player_move(game);
}
