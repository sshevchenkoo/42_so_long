/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yashevch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:14:35 by yashevch          #+#    #+#             */
/*   Updated: 2024/05/05 18:16:17 by yashevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	count_symbols(char *row, int *c, int *e, int *p)
{
	int	t;
	int	len;

	t = 0;
	len = ft_strlen(row);
	while (len > t + 1)
	{
		if (ft_strchr("01CEP", row[t]))
		{
			if (row[t] == 'C')
				(*c)++;
			if (row[t] == 'E')
				(*e)++;
			if (row[t] == 'P')
				(*p)++;
		}
		else
			return (0);
		t++;
	}
	return (1);
}

int	check_special_symbols(t_solong solong, int c, int e, int p)
{
	int	i;

	i = 0;
	while (solong.map[i])
	{
		if (!count_symbols(solong.map[i], &c, &e, &p))
			return (0);
		i++;
	}
	if (p != 1 || c < 1 || e != 1)
		return (0);
	return (1);
}

int	check_map(t_solong solong)
{
	int	form_map;
	int	special_symbols;

	form_map = check_form_map(solong);
	special_symbols = check_special_symbols(solong, 0, 0, 0);
	if (!special_symbols || !form_map)
		return (0);
	return (1);
}
