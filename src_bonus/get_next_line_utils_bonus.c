/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:53:57 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/02 01:01:26 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "../push_swap_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	int		slen;
	int		i;

	i = 0;
	slen = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * slen + 1);
	if (!str)
		return (NULL);
	while (i < slen)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 && s2)
		return (ft_strdup(s2));
	else if (!s2 && s1)
		return (s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(len + 1);
	if (!str)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (free(s1), str);
}

char	*ft_subfornorm(char *s, char *str, int line, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		str[j] = s[j];
		j++;
	}
	if (line)
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char *s)
{
	char	*str;
	int		i;
	int		new_line;
	int		j;

	if (!s || !*s)
		return (NULL);
	i = 0;
	j = 1;
	new_line = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
	{
		new_line = 1;
		j = 2;
	}
	str = malloc(i + j);
	if (!str)
		return (NULL);
	return (ft_subfornorm(s, str, new_line, i));
}
