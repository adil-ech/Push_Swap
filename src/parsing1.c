/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:16:28 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/02 01:38:25 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	validnum(const char *str)
{
	int		i;
	long	res;
	int		flag;

	i = 0;
	res = 0;
	flag = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - '0');
		if (flag * res > INT_MAX || flag * res < INT_MIN)
			return (0);
	}
	return (str[i] == '\0');
}

void	normiesprocess(t_list **stack_a, char **splited)
{
	int	*num;
	int	j;

	j = 0;
	while (splited[j])
	{
		num = malloc(sizeof(int));
		if (!num || !validnum(splited[j]))
		{
			free(num);
			ultimaterror(stack_a, splited);
		}
		*num = ft_atoi(splited[j]);
		ft_lstadd_back(stack_a, ft_lstnew(num));
		j++;
	}
}

void	parsargs(int ac, char **av, t_list **stack_a)
{
	int		i;
	char	**splited;

	i = 1;
	while (i < ac)
	{
		splited = ft_split(av[i]);
		if (!splited || !splited[0])
			ultimaterror(stack_a, splited);
		normiesprocess(stack_a, splited);
		free_splited(splited);
		i++;
	}
	if (theresdupp(*stack_a))
		ultimaterror(stack_a, NULL);
}
