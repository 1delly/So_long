/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:05:52 by tdelgran          #+#    #+#             */
/*   Updated: 2023/05/30 14:16:21 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_extension(char *ber)
{
	int	i;

	i = ft_strlen(ber);
	if ((ber[i - 4] != '.') || (ber[i - 3] != 'b') || (ber[i - 2] != 'e') \
		|| (ber[i - 1] != 'r'))
		the_error (4);
}

void	the_error(int er)
{
	if (er == 0)
		ft_printf("Error\nnot walls\n");
	if (er == 1)
		ft_printf("Error\nnot rectangular map\n");
	if (er == 2)
		ft_printf("Error\ninvalid map\n");
	if (er == 3)
		ft_printf("Error\narguments\n");
	if (er == 4)
		ft_printf("Error\nnot good file\n");
	if (er == 5)
		ft_printf("Error\ninvalid char\n");
	if (er == 6)
		ft_printf("Error\nYou are not char\n");
	if (er == 7)
		ft_printf("Error\nproblem path\n");
	if (er == 8)
		ft_printf("Error\nmap\n");
	exit(EXIT_FAILURE);
}

int	loop(t_game *game)
{
	set_image(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		the_error(3);
	check_extension(av[1]);
	init_struc(&game);
	parsing(&game, av[1]);
	start_window(&game);
	mlx_loop_hook(game.mlxwin, &loop, &game);
	mlx_hook(game.window, 2, 0, &key, &game);
	mlx_loop(game.mlxwin);
}
