/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backto_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 01:07:47 by adechaji          #+#    #+#             */
/*   Updated: 2024/12/27 15:15:07 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		calcdistance(t_list **stack, int target)
{
	int		distance;
	t_list	*tmp;

	distance = 0;
	tmp = *stack;
	while (tmp && tmp->index != target)
	{
		distance++;
		tmp = tmp->next;
	}
	return (distance);
}

void	backto_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*curr;
	int		target;
	int		sizeB;
	int		distance;

	while (*stack_b)
	{
		sizeB = ft_lstsize(*stack_b);
		if (*stack_a)
			target = (*stack_a)->index - 1;
		else
			target = sizeB - 1;
		curr = *stack_b;
		distance = calcdistance(stack_b, target);
		if (curr)
		{
			if (distance < sizeB / 2)
			{
				while ((*stack_b)->index != target)
					rb(stack_b);
			}
			else
			{
				while ((*stack_b)->index != target)
					rrb(stack_b);
			}
			pa(stack_a, stack_b);
		}
		while (*stack_a && (*stack_a)->next && (*stack_a)->next->index == (*stack_a)->index - 1)
			rra(stack_a);
	}
}
