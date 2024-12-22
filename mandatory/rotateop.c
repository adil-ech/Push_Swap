/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotateop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:25:05 by adechaji          #+#    #+#             */
/*   Updated: 2024/12/22 22:44:36 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	int		size;
	t_list	*last;
	t_list	*secnd;
	t_list	*first;

	size = ft_lstsize(*stack);
	if (size >= 2)
	{
		first = *stack;
		secnd = first->next;
		last = ft_lstlast(*stack);
		*stack = secnd;
		last->next = first;
		first->next = NULL;
	}
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
