/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yashevch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:08:41 by yashevch          #+#    #+#             */
/*   Updated: 2024/05/03 18:11:08 by yashevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdbool.h>
# include "libft_upgrade/ft_printf.h"
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"

# define MAP_EXT ".ber"
# define TILE_SIZE 64

# define W 119
# define A 97
# define S 115
# define D 100

# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

# define ESC 65307

typedef struct s_solong
{
	int		height;
	int		width;
	char	**map;
}	t_solong;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall;
	void	*floor;
	void	*exit;
	void	*player;
	void	*coin;
	int		p_x;
	int		p_y;
	int		col;
	char	**map;
	int		moves;
}	t_data;

int		check_map(t_solong solong);
int	count_col(t_data game);
void	free_img(t_data *game);
void	free_arr(t_solong *solong);
int		check_form_map(t_solong solong);
int		can_reach_exit(t_solong sl);
int		play(t_solong *sl);
void	find_start_position(t_solong sl, int *start_x, int *start_y);
int		destroy(t_data *game);
int		quit_game(t_data *game);
void	init_mlx(t_data *game, t_solong *sl);
void	load_img(t_data *game);
void	load_img_to_win(t_data *game, t_solong *sl, int x, int y);
void	update_p_pos(t_data *game, int hor, int len);

#endif
