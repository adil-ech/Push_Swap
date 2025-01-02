/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   giantsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:41:12 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/02 01:38:37 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	isitsorted(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	size;

	size = ft_lstsize(*stack_b);
	while (*stack_b)
	{
		size = ft_lstsize(*stack_b) - 1;
		i = positions(stack_b, size);
		if ((*stack_b)->index == size)
			pa(stack_a, stack_b, 1);
		else if (i > size / 2)
			rrb(stack_b, 1);
		else
			rb(stack_b, 1);
	}
}

int	assignsize(t_list **stack_a)
{
	int	size;
	int	j;

	size = ft_lstsize(*stack_a) - 1;
	if (size < 101)
		j = 15;
	else if (size + 1 > 100)
		j = 35;
	else
		j = 20;
	return (j);
}

void	largerlarger(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	j;

	i = 0;
	j = assignsize(stack_a);
	while ((*stack_a))
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b, 1);
			i++;
		}
		else if ((*stack_a)->index < (i + j))
		{
			pb(stack_a, stack_b, 1);
			rb(stack_b, 1);
			i++;
		}
		else
			ra(stack_a, 1);
	}
	isitsorted(stack_a, stack_b);
}
