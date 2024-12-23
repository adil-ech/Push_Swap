/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:45:11 by adechaji          #+#    #+#             */
/*   Updated: 2024/12/23 16:17:15 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pushups(t_list **stack, t_list **topush)
{
	int		size;
	t_list	*st_head;
	t_list	*tp_head;

	size = ft_lstsize(*topush);
	if (size >= 1)
	{
		st_head = *stack;
		tp_head = *topush;
		*topush = (*topush)->next;
		tp_head -> next = st_head;
		*stack = tp_head;
	}
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	write(1, "pa\n", 3);
	pushups(stack_a, stack_b);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	write(1, "pb\n", 3);
	pushups(stack_b, stack_a);
}
