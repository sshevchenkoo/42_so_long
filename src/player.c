/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yashevch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 13:53:28 by yashevch          #+#    #+#             */
/*   Updated: 2024/05/12 13:53:53 by yashevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	put_player(t_data *game)
{
	char	*moves_str;
	char	*col_str;

	game->moves += 1;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player,
		TILE_SIZE * game->p_x, TILE_SIZE * game->p_y);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->wall, 0, 0);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->wall, 64, 0);
	moves_str = ft_itoa(game->moves);
	col_str = ft_itoa(game->col);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 32, 10, 1, moves_str);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 72, 10, 1, col_str);
	free(col_str);
	free(moves_str);
}

void	which_tile(t_data *game)
{
	int	img_size;

	img_size = TILE_SIZE;
	if (game->map[game->p_y]
		[game->p_x] == 'C')
	{
		game->map[game->p_y][game->p_x] = '0';
		mlx_destroy_image(game->mlx_ptr, game->player);
		game->player = mlx_xpm_file_to_image(game->mlx_ptr,
				"./textures/player_2.xpm", &img_size, &img_size);
		game->col -= 1;
		return ;
	}
	if (game->map[game->p_y][game->p_x] == 'E'
		&& game->col == 0)
	{
		ft_printf("WIN ^_^\n");
		quit_game(game);
	}
}

void	update_tile(t_data *game)
{
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, game->floor, game->p_x * TILE_SIZE,
		game->p_y * TILE_SIZE);
}

void	update_p_pos(t_data *game, int hor, int len)
{
	if (hor)
	{
		if (game->map[game->p_y][game->p_x + len] == '1')
			return ;
		if (game->map[game->p_y][game->p_x + len] == 'E' && game->col > 0)
			return ;
		update_tile(game);
		game->p_x += len;
	}
	else
	{
		if (game->map[game->p_y + len][game->p_x] == '1')
			return ;
		if (game->map[game->p_y + len][game->p_x] == 'E' && game->col > 0)
			return ;
		update_tile(game);
		game->p_y += len;
	}
	which_tile(game);
	put_player(game);
}
