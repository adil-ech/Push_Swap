/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:21:55 by adechaji          #+#    #+#             */
/*   Updated: 2024/12/22 22:45:20 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a)
{
	int		size;
	t_list	*first;
	t_list	*secnd;

	size = ft_lstsize(*stack_a);
	if (size >= 2)
	{
		first = *stack_a;
		secnd = first->next;
		first->next = secnd->next;
		secnd->next = first;
		*stack_a = secnd;
	}
}

void	sb(t_list **stack_b)
{
	int		size;
	t_list	*first;
	t_list	*secnd;

	size = ft_lstsize(*stack_b);
	if (size >= 2)
	{
		first = *stack_b;
		secnd = first->next;
		first->next = secnd->next;
		secnd->next = first;
		*stack_b = secnd;
	}
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
