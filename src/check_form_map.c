/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_form_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yashevch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:35:19 by yashevch          #+#    #+#             */
/*   Updated: 2024/05/05 21:50:14 by yashevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	check_inner_row(char *row)
{
	int	t;

	t = 0;
	while (row[t] != '\n' && row[t])
	{
		if (t == 0 || row[t + 1] == '\n')
		{
			if (row[t] != '1')
				return (0);
		}
		t++;
	}
	return (1);
}

int	check_border_row(char *row)
{
	int	t;

	t = 0;
	while (row[t] != '\n' && row[t])
	{
		if (row[t] != '1')
			return (0);
		t++;
	}
	return (1);
}

int	check_border_map(t_solong sl)
{
	int	i;

	i = 0;
	while (sl.map[i])
	{
		if (i == 0 || i + 1 == sl.height)
		{
			if (!check_border_row(sl.map[i]))
				return (0);
		}
		else
		{
			if (!check_inner_row(sl.map[i]))
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_rectangle_map(t_solong solong)
{
	int	i;

	i = 1;
	while (solong.map[i])
	{
		if (ft_strlen(solong.map[i]) != ft_strlen(solong.map[i - 1]))
			return (0);
		i++;
	}
	return (1);
}

int	check_form_map(t_solong solong)
{
	int	rectangle;
	int	border;

	border = check_border_map(solong);
	rectangle = check_rectangle_map(solong);
	if (!rectangle || !border)
		return (0);
	return (1);
}
