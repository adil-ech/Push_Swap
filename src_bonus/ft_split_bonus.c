/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:58:21 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/02 01:01:46 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static int	countwords(char const *str)
{
	int	i;
	int	cword;
	int	count;

	i = 0;
	cword = 0;
	count = 0;
	while (str[i])
	{
		if (iswhitespace(str[i]))
			cword = 0;
		else if (cword == 0)
		{
			count++;
			cword = 1;
		}
		i++;
	}
	return (count);
}

static int	wordlen(char const *str)
{
	int	len;

	len = 0;
	while (str[len] && !iswhitespace(str[len]))
		len++;
	return (len);
}

static void	freewords(char **res, int i)
{
	while (i--)
		free(res[i]);
	free(res);
}

static int	fillwords(char **res, const char *s)
{
	int	i;
	int	len;

	i = 0;
	while (*s)
	{
		while (*s && iswhitespace(*s))
			s++;
		if (*s)
		{
			len = wordlen(s);
			res[i] = (char *)malloc(sizeof(char) * (len + 1));
			if (!res[i])
			{
				freewords(res, i);
				return (0);
			}
			ft_memcpy(res[i], s, len);
			res[i++][len] = '\0';
			s += len;
		}
	}
	res[i] = NULL;
	return (1);
}

char	**ft_split(char const *s)
{
	int		cwords;
	char	**res;

	if (!s)
		return (NULL);
	cwords = countwords(s);
	res = (char **)malloc(sizeof(char *) * (cwords + 1));
	if (!res)
		return (NULL);
	if (!fillwords(res, s))
		return (NULL);
	return (res);
}
