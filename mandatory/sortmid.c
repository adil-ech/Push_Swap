/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortmid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:58:21 by adechaji          #+#    #+#             */
/*   Updated: 2024/12/23 18:42:31 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list *stack)
{
	int	min;
	int	index;
	int	i;
	t_list *tmp;

	if (!stack)
		return (-1);
	min = *(int*)(stack->content);
	index = 0;
	i = 0;
	tmp = stack;
	while (tmp)
	{
		if (*(int *)(tmp->content) < min)
		{
			min = *(int*)(tmp->content);
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}
void	whatsidetomove(t_list **stack, int index)
{
	int	size;

	size = ft_lstsize(*stack);

	if (index <= size / 2)
	{
		while (index > 0)
		{
			ra(stack);
			index--;
		}
	}
	else
	{
		index = size - index;
		while (index > 0)
		{
			rra(stack);
			index--;
		}
	}
}

void	sortfour(t_list **stack_a, t_list **stack_b)
{
	int	min;

	if (ft_lstsize(*stack_a) != 4)
		return ;
	min = find_min(*stack_a);
	whatsidetomove(stack_a, min);
	pb(stack_a, stack_b);
	sortthree(stack_a);
	pa(stack_a, stack_b);
}

void sortfive(t_list **stack_a, t_list **stack_b)
{
	int	min;

	if (ft_lstsize(*stack_a) != 5)
		return ;
	min = find_min(*stack_a);
	whatsidetomove(stack_a, min);
	pb(stack_a, stack_b);

	min = find_min(*stack_a);
	whatsidetomove(stack_a, min);
	pb(stack_a, stack_b);

	sortthree(stack_a);

	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}