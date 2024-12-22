/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotateop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:03:27 by adechaji          #+#    #+#             */
/*   Updated: 2024/12/22 22:44:30 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	int		size;
	t_list	*last;
	t_list	*bfr_last;

	size = ft_lstsize(*stack);
	if (size >= 2)
	{
		last = ft_lstlast(*stack);
		bfr_last = *stack;
		while (bfr_last->next != last)
			bfr_last = bfr_last->next;
		bfr_last->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
