/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_quit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yashevch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:33:06 by yashevch          #+#    #+#             */
/*   Updated: 2024/05/13 16:33:26 by yashevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	free_arr(t_solong *solong)
{
	int	i;

	i = 0;
	while (solong->map[i])
	{
		free(solong->map[i]);
		i++;
	}
	free(solong->map);
}

int	destroy(t_data *game)
{
	int	i;

	i = 0;
	free_img(game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	if (game->map)
		free(game->map);
	return (0);
}

int	quit_game(t_data *game)
{
	destroy(game);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	free_img(t_data *game)
{
	if (game->wall)
		mlx_destroy_image(game->mlx_ptr, game->wall);
	if (game->player)
		mlx_destroy_image(game->mlx_ptr, game->player);
	if (game->floor)
		mlx_destroy_image(game->mlx_ptr, game->floor);
	if (game->exit)
		mlx_destroy_image(game->mlx_ptr, game->exit);
	if (game->coin)
		mlx_destroy_image(game->mlx_ptr, game->coin);
}
