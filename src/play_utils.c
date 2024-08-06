/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yashevch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:58:56 by yashevch          #+#    #+#             */
/*   Updated: 2024/05/09 20:59:19 by yashevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	count_col(t_data game)
{
	int	i;
	int	col;
	int	t;

	i = 0;
	col = 0;
	while (game.map[i])
	{
		t = 0;
		while (game.map[i][t] != '\n')
		{
			if (game.map[i][t] == 'C')
				col++;
			t++;
		}
		i++;
	}
	return (col);
}

void	init_mlx(t_data *game, t_solong *sl)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		ft_putstr_fd("Error Init MLX", 2);
		exit(127);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			(sl->width - 1) * TILE_SIZE, sl->height * TILE_SIZE, "Mushroom");
	if (!game->mlx_ptr)
	{
		ft_putstr_fd("Error Window MLX", 2);
		exit(127);
	}
}

void	load_img(t_data *game)
{
	int	img_size;

	img_size = TILE_SIZE;
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/wall.xpm", &img_size, &img_size);
	game->floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/floor.xpm", &img_size, &img_size);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/exit.xpm", &img_size, &img_size);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/player.xpm", &img_size, &img_size);
	game->coin = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/coin.xpm", &img_size, &img_size);
}

void	load_img_to_win(t_data *game, t_solong *sl, int x, int y)
{
	while (++y < sl->height)
	{
		x = -1;
		while (++x < sl->width - 1)
		{
			if (sl->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->wall, x * TILE_SIZE, y * TILE_SIZE);
			else if (sl->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->exit, x * TILE_SIZE, y * TILE_SIZE);
			else if (sl->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->player, x * TILE_SIZE, y * TILE_SIZE);
			else if (sl->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->coin, x * TILE_SIZE, y * TILE_SIZE);
			else
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->floor, x * TILE_SIZE, y * TILE_SIZE);
		}
	}
}
