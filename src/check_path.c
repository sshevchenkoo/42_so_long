/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yashevch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:41:50 by yashevch          #+#    #+#             */
/*   Updated: 2024/05/06 12:57:13 by yashevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	find_exit(t_solong sl, int x, int y, int **visited)
{
	if (sl.map[x][y] == '1' || visited[x][y])
		return (0);
	if (sl.map[x][y] == 'E')
		return (1);
	visited[x][y] = 1;
	if (find_exit(sl, x + 1, y, visited)
		|| find_exit(sl, x - 1, y, visited)
		|| find_exit(sl, x, y + 1, visited)
		|| find_exit(sl, x, y - 1, visited))
		return (1);
	return (0);
}

int	**create_visited(int height, int width)
{
	int	**visited;
	int	i;
	int	j;

	i = 0;
	j = 0;
	visited = malloc(sizeof(int *) * height);
	while (i < height)
	{
		visited[i] = malloc(width * sizeof(int));
		j = 0;
		while (j < width)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	return (visited);
}

void	free_visited(int **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

void	find_start_position(t_solong sl, int *start_x, int *start_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < sl.height)
	{
		j = 0;
		while (j < sl.width)
		{
			if (sl.map[i][j] == 'P')
			{
				*start_x = i;
				*start_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	can_reach_exit(t_solong sl)
{
	int	**visited;
	int	start_x;
	int	start_y;
	int	can_reach;

	visited = create_visited(sl.height, sl.width);
	find_start_position(sl, &start_x, &start_y);
	can_reach = find_exit(sl, start_x, start_y, visited);
	free_visited(visited, sl.height);
	return (can_reach);
}
