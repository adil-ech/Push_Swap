/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 02:10:55 by adechaji          #+#    #+#             */
/*   Updated: 2024/12/30 19:51:25 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_evtg(t_list **chst_a, t_list **chst_b, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(chst_a, 0);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(chst_b, 0);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(chst_a, chst_b, 0);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(chst_a, chst_b, 0);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(chst_a, chst_b, 0);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(chst_a, 0);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(chst_b, 0);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(chst_a, chst_b, 0);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(chst_a, 0);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(chst_b, 0);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(chst_a, chst_b, 0);
}

int	is_valid(char *str)
{
	static char	*actions[] = {"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr", NULL};
	int			i;

	i = 0;
	while (actions[i])
	{
		if (ft_strncmp(str, actions[i], ft_strllen(actions[i])) == 0
			&& str[ft_strllen(actions[i])] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	checker(t_list **chst_a, t_list **chst_b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (!is_valid(line))
		{
			free(line);
			write(2, "Error\n", 6);
			free_stack(chst_a);
			free_stack(chst_b);
			exit(EXIT_FAILURE);
		}
		exec_evtg(chst_a, chst_b, line);
		free(line);
		line = get_next_line(0);
	}
	if (checkifsorted(chst_a) && !*chst_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_list	*chst_a;
	t_list	*chst_b;

	chst_a = NULL;
	chst_b = NULL;
	if (ac < 2)
		return (0);
	parsargs(ac, av, &chst_a);
	checker(&chst_a, &chst_b);
	free_stack(&chst_a);
	return (0);
}
