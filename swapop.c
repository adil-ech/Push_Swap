/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:21:55 by adechaji          #+#    #+#             */
/*   Updated: 2024/12/29 18:57:11 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a, int f)
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
	if (f)
		write(1, "sa\n", 3);
}

void	sb(t_list **stack_b, int f)
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
	if (f)
		write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b, int f)
{
	sa(stack_a, 1);
	sb(stack_b, 1);
	if (f)
		write(1, "ss\n", 3);
}
