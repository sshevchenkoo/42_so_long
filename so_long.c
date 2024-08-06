/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yashevch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:12:09 by yashevch          #+#    #+#             */
/*   Updated: 2024/05/07 21:57:50 by yashevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	check_path_map(char *argv)
{
	int	i;
	int	l;

	i = 3;
	l = ft_strlen(argv);
	l--;
	while (argv[l] == MAP_EXT[i])
	{
		l--;
		i--;
	}
	if (i > 0)
		return (0);
	return (1);
}

int	check_len_map(char *argv)
{
	char	*map;
	int		len;
	int		fd_map;

	len = 0;
	fd_map = open(argv, O_RDONLY);
	if (fd_map == -1)
	{
		perror("Invalid Input");
		exit(127);
	}
	map = get_next_line(fd_map);
	while (map)
	{
		free(map);
		map = get_next_line(fd_map);
		len++;
	}
	close(fd_map);
	return (len);
}

char	**init_map(int len_map, char *argv)
{
	char	*map_row;
	char	**map;
	int		i;
	int		fd_map;

	i = 0;
	fd_map = open(argv, O_RDONLY);
	map = malloc(sizeof(char *) * (len_map + 1));
	map_row = get_next_line(fd_map);
	while (map_row)
	{
		map[i] = ft_strdup(map_row);
		free(map_row);
		map_row = get_next_line(fd_map);
		i++;
	}
	map[len_map] = NULL;
	close(fd_map);
	return (map);
}

int	main(int argc, char **argv)
{
	t_solong	solong;
	int			e;
	int			m;

	if (argc != 2 || check_path_map(argv[1]) == 0)
		return (ft_putstr_fd("Invalid Input\n", 1), 0);
	solong.height = check_len_map(argv[1]);
	solong.map = init_map(solong.height, argv[1]);
	solong.width = ft_strlen(solong.map[0]);
	e = can_reach_exit(solong);
	m = check_map(solong);
	if (m && e)
		play(&solong);
	free_arr(&solong);
	if (!m || !e)
		return (ft_putstr_fd("Invalid Map\n", 1), 0);
}
