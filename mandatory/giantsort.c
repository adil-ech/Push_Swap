/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   giantsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:36:58 by adechaji          #+#    #+#             */
/*   Updated: 2024/12/27 15:29:21 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunking(t_list **stack_a, t_list **stack_b)
{
	int	sizeA;
	int	count;
	int	pv1;
	int	pv2;

	sizeA = ft_lstsize(*stack_a);
	pv1 = sizeA / 3;
	pv2 = pv1 / 2;
	count = 0;
	while (ft_lstsize(*stack_a) > 5)
	{
		if (*stack_b && (*stack_b)->index <= pv2 && ft_lstsize(*stack_b) > 1)
			rb(stack_b);
		if ((*stack_a)->index <= pv1)
		{
			pb(stack_a, stack_b);
			count++;
		}
		else
			ra(stack_a);
		if (count>= pv1)
		{
			sizeA = ft_lstsize(*stack_a);
			pv1 = sizeA / 3;
			pv2 = pv1 / 2;
			count = 0;
		}
	}
}


void	indexmepls(t_list **stack_a, t_list *node)
{
	t_list *curr;

	curr = *stack_a;
	node->index = 0;
	while (curr)
	{
		if (*(int *)node->content > *(int *)curr->content)
			node->index++;
		curr = curr->next;
	}
}

void	largerlarger(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;

	tmp = *stack_a;
	while (tmp)
	{
		indexmepls(stack_a, tmp);
		tmp = tmp->next;
	}
	chunking(stack_a, stack_b);
	sortfive(stack_a, stack_b);
	backto_a(stack_a, stack_b);
}
