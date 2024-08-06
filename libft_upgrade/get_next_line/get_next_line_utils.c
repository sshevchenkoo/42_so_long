/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yashevch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:09:33 by yashevch          #+#    #+#             */
/*   Updated: 2024/03/15 12:51:11 by yashevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h" 

int	ft_nl_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_strcpy(char *dest, char *src)
{
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
}

char	*ft_n_strjoin(char *s1, char *s2, int i, int t)
{
	char	*s3;
	char	*s4;

	s3 = malloc((ft_nl_strlen(s1) + ft_nl_strlen(s2) + 1));
	if (!s3)
		return (ft_free(&s1), ft_free(&s2), NULL);
	s4 = s3;
	while (s1 && s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2 && s2[t] != '\0')
	{
		s3[i] = s2[t];
		i++;
		t++;
	}
	s3[i] = '\0';
	ft_free(&s1);
	ft_free(&s2);
	return (s4);
}
