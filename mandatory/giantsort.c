/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   giantsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:36:58 by adechaji          #+#    #+#             */
/*   Updated: 2024/12/28 19:10:58 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	topshandle(t_list **stack_a, t_list **stack_b, t_list **last, int qima)
{
	if (positions(stack_b, (*stack_a)->index - 1) > ft_lstsize(*stack_b) / 2)
	{
		if ((*last)->index < (*stack_b)->index || (*last)->index == qima)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
			*last = ft_lstlast(*stack_a);
		}
		else if(stack_b)
			rrb(stack_b);
	}
	else
	{
		if ((*last)->index < (*stack_b)->index || (*last)->index == qima)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
			*last = ft_lstlast(*stack_a);
		}
		else if(stack_b)
			rb(stack_b);
	}
}

void	largers(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	int		qima;

	last = ft_lstlast(*stack_a);
	qima = last->index;
	while (stack_b)
	{
		while ((*stack_b) && (*stack_b)->index + 1 != (*stack_a)->index)
		{
			topshandle(stack_a, stack_b, &last, qima);
		}
		while (*stack_b && (*stack_b)->index == (*stack_a)->index - 1)
			pa(stack_a, stack_b);
		if ((*stack_a)->index - 1 == last->index)
		{
			while (last->index == (*stack_a)->index - 1)
			{
				rra(stack_a);
				last = ft_lstlast(*stack_a);
			}
		}
		if (checkifsorted(stack_a) == 1 && *stack_b == NULL)
			break ;
	}
}

void	largerlarger(t_list **stack_a, t_list **stack_b)
{
	int	i1;
	int	piv1;
	int	piv2;

	i1 = -1;
	piv1 = ft_lstsize(*stack_a) / 3;
	piv2 = ft_lstsize(*stack_a) / 6;
	indexmepls(stack_a);
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->index < piv1)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		if (ft_lstsize(*stack_b) > 1 && ((*stack_b)->index >= i1 && (*stack_b)->index <= piv2))
			rb(stack_b);
		if (ft_lstsize(*stack_b) == piv1)
		{
			i1 = piv1;
			piv1 += ft_lstsize(*stack_a) / 3;
			piv2 = ft_lstsize(*stack_a) / 6 + piv1;
		}
	}
	sortthree(stack_a);
	largers(stack_a, stack_b);
}
