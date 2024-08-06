/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yashevch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:39:56 by yashevch          #+#    #+#             */
/*   Updated: 2024/03/15 12:55:24 by yashevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	ft_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

int	ft_check_len(char *remind)
{
	int	i;

	i = 0;
	if (!remind)
		return (0);
	while (remind[i] != '\n' && remind[i])
		i++;
	if (remind[i] == '\n')
		return (i);
	return (0);
}

char	*ft_get_line(char **ft_remind, int i)
{
	char	*str;
	char	*temp;
	int		t;

	t = -1;
	if (!*ft_remind)
		return (NULL);
	if (**ft_remind == '\0')
		return (ft_free(ft_remind), NULL);
	while ((*ft_remind)[i] != '\n' && (*ft_remind)[i])
		i++;
	if ((*ft_remind)[i] == '\n')
		i++;
	str = malloc(i + 1);
	if (!str)
		return (ft_free(ft_remind), NULL);
	while (i > ++t)
		str[t] = (*ft_remind)[t];
	str[t] = '\0';
	temp = malloc((ft_nl_strlen(*ft_remind) - i + 1));
	if (!temp)
		return (free(str), ft_free(ft_remind), NULL);
	ft_strcpy(temp, (*ft_remind + i));
	ft_free(ft_remind);
	return (*ft_remind = temp, str);
}

char	*get_next_line(int fd)
{
	static char	*remind;
	char		*buffer;
	int			ft_read;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	while (42)
	{
		if (ft_check_len(remind))
			return (ft_get_line(&remind, 0));
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (ft_free(&remind), NULL);
		ft_read = read(fd, buffer, BUFFER_SIZE);
		if (ft_read == 0)
		{
			ft_free(&buffer);
			return (ft_get_line(&remind, 0));
		}
		if (ft_read == -1)
			return (ft_free(&buffer), ft_free(&remind), NULL);
		buffer[ft_read] = '\0';
		remind = ft_n_strjoin(remind, buffer, 0, 0);
	}
}
