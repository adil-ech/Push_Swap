/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotateop_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:25:05 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/02 01:01:08 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

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

void	ra(t_list **stack_a, int f)
{
	rotate(stack_a);
	if (f)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack_b, int f)
{
	rotate(stack_b);
	if (f)
		write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b, int f)
{
	rotate(stack_a);
	rotate(stack_b);
	if (f)
		write(1, "rr\n", 3);
}
