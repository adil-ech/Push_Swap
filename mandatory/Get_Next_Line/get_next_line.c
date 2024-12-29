/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 00:39:25 by adechaji          #+#    #+#             */
/*   Updated: 2024/12/07 20:03:29 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*checker(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s || !*s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

static char	*ft_nextline(char *s)
{
	int		i;
	int		len;
	char	*tmp;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\0')
		return (free(s), NULL);
	len = ft_strlen(s) - i;
	tmp = malloc(len + 1);
	if (!tmp)
		return (free(s), NULL);
	i++;
	len = 0;
	while (s[i])
		tmp[len++] = s[i++];
	tmp[len] = '\0';
	free(s);
	return (tmp);
}

static void	remfree(char **rem)
{
	if (rem && *rem)
	{
		free(*rem);
		*rem = NULL;
	}
}

static char	*readappend(int fd, char *buffer, char *rem)
{
	int	bread;

	bread = 1;
	while (bread > 0)
	{
		bread = read(fd, buffer, BUFFER_SIZE);
		if (bread == -1)
		{
			remfree(&rem);
			break ;
		}
		buffer[bread] = '\0';
		rem = ft_strjoin(rem, buffer);
		if (checker(rem, '\n'))
			break ;
	}
	return (rem);
}

char	*get_next_line(int fd)
{
	static char	*rem = NULL;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	rem = readappend(fd, buffer, rem);
	free(buffer);
	if (!rem || !*rem)
		return (remfree(&rem), NULL);
	line = ft_substr(rem);
	rem = ft_nextline(rem);
	return (line);
}
