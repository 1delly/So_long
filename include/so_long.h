/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:02:19 by tdelgran          #+#    #+#             */
/*   Updated: 2023/05/30 16:26:09 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <string.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define KEY_A 0
# define KEY_W 13
# define KEY_S 1
# define KEY_D 2
# define KEY_ECHAP 53

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_game
{
	char	**map;
	char	**mapcpy;
	void	*window;
	void	*mlxwin;
	t_pos	line;
	int		xlong;
	int		ylong;
	int		player;
	int		exit;
	int		comes;
	int		verif_comes;
	int		verif_exit;
	void	*floor;
	void	*character;
	void	*wall;
	void	*object;
	void	*f_exit;
	int		player_posy;
	int		player_posx;
	int		step;
}				t_game;

/*Fonction Parsing*/

void	ft_get_map(const char *file, t_game *game);
void	init_struc(t_game *game);
void	check_rec(t_game *game);
void	check_wall(t_game *game);
void	parsing(t_game *game, char *av);
void	declar_struct(t_game *game);
void	the_error(int er);
void	check_char(t_game *game);
int		mapcpy(t_game *game);
void	first_path(t_game *game, int y, int x);
void	check_path(t_game *game);
int		*search_player(t_game *game);
void	check_extension(char *ber);

/*Fonction MLX*/

void	start_window(t_game *game);
void	set_image(t_game *game);
int		key(int key_code, t_game *game);
void	move_w(t_game *game);
void	move_s(t_game *game);
void	move_a(t_game *game);
void	move_d(t_game *game);

/*Fonction utils*/

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*read_line(char *line, int fd, char **stock);
char	*format_line(char *line, char **stock);
char	*trim(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_printf(const char *format, ...);
void	format_char(int c, int *stock);
void	format_putstr(char *str, int *stock);
void	format_putnbr(int nb, int *stock);
void	format_putnbrbase(unsigned long nb, char *a, int *stock);
void	printf_conversion(va_list arg, char format, int *stock);
void	format_putnbr_u(unsigned int nb, int *stock);
void	format_hexa(unsigned int nb, int a, int *stock);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
void	*ft_calloc(size_t a, size_t b);
void	ft_bzero(void *s, size_t n);

#endif