/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   giantsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:04:17 by adechaji          #+#    #+#             */
/*   Updated: 2024/12/24 19:07:32 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	findmaxx(t_list *stack)
{
	int max;
	t_list *tmp;

	if (!stack)
		return -1;
	max = *(int *)(stack->content);
	tmp = stack->next;
	while (tmp)
	{
		if (*(int *)(tmp->content) > max)
			max = *(int *)(tmp->content);
		tmp = tmp->next;
	}
	return max;
}

void	push_to_bv(t_list **stack_a, t_list **stack_b, int min, int max)
{
	t_list *tmp;
	int size = ft_lstsize(*stack_a);
	int index;

	while (size--)
	{
		tmp = *stack_a;
		if (*(int *)(tmp->content) >= min && *(int *)(tmp->content) <= max)
		{
			pb(stack_a, stack_b);
		}
		else
		{
			index = 0;
			tmp = *stack_a;
			while (tmp)
			{
				if (*(int *)(tmp->content) >= min && *(int *)(tmp->content) <= max)
					break ;
				tmp = tmp->next;
				index++;
			}
			whatsidetomove(stack_a, index);
		}
	}
}

void	largerlarger(t_list **stack_a, t_list **stack_b)
{
	int chunk_size;
	int chunks_num;
	int i;
	int min, max;
	int size;

	size = ft_lstsize(*stack_a);
	chunk_size = size / 10 + (size % 10 != 0);
	chunks_num = (size + chunk_size - 1) / chunk_size;
	i = 0;
	while (i < chunks_num)
	{
		min = i * chunk_size;
		max = min + chunk_size - 1;
		push_to_bv(stack_a, stack_b, min, max);
		i++;
	}
	while (ft_lstsize(*stack_b) > 0)
	{
		int max_index = findmaxx(*stack_b);
		whatsidetomove(stack_b, max_index);
		pa(stack_a, stack_b);
	}
}
