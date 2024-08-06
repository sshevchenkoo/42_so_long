/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yashevch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:45:10 by yashevch          #+#    #+#             */
/*   Updated: 2024/05/10 21:07:07 by yashevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	on_keypress(int key, t_data *game)
{
	if (key == ESC)
		quit_game(game);
	else if (key == W || key == UP)
		update_p_pos(game, 0, -1);
	else if (key == A || key == LEFT)
		update_p_pos(game, 1, -1);
	else if (key == S || key == DOWN)
		update_p_pos(game, 0, 1);
	else if (key == D || key == RIGHT)
		update_p_pos(game, 1, 1);
	return (0);
}

int	play(t_solong *sl)
{
	t_data	game;

	game.moves = 0;
	game.map = sl->map;
	game.col = count_col(game);
	find_start_position(*sl, &game.p_y, &game.p_x);
	init_mlx(&game, sl);
	load_img(&game);
	load_img_to_win(&game, sl, -1, -1);
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, &on_keypress, &game);
	mlx_hook(game.win_ptr, DestroyNotify, StructureNotifyMask, &destroy, &game);
	mlx_loop(game.mlx_ptr);
	return (1);
}
