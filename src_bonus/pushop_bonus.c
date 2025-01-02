/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushop_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:45:11 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/02 01:01:14 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

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

void	pa(t_list **stack_a, t_list **stack_b, int f)
{
	pushups(stack_a, stack_b);
	if (f)
		write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b, int f)
{
	pushups(stack_b, stack_a);
	if (f)
		write(1, "pb\n", 3);
}
