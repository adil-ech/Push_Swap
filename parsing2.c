/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:13:39 by adechaji          #+#    #+#             */
/*   Updated: 2024/12/30 18:26:05 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free((*stack)->content);
		free(*stack);
		*stack = tmp;
	}
}

void	free_splited(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}

void	ultimaterror(t_list **stack, char **splited)
{
	write(2, "Error\n", 6);
	if (stack)
		free_stack(stack);
	if (splited)
		free_splited(splited);
	exit(EXIT_FAILURE);
}

int	theresdupp(t_list *stack)
{
	t_list	*tmp;
	t_list	*pass;

	tmp = stack;
	while (tmp)
	{
		pass = tmp->next;
		while (pass)
		{
			if (*(int *)(tmp->content) == *(int *)(pass->content))
				return (1);
			pass = pass->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
