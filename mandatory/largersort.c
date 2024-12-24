/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   largersort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:33:38 by adechaji          #+#    #+#             */
/*   Updated: 2024/12/24 17:04:26 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list *stack)
{
	int		max;
	int		index;
	int		i;
	t_list *tmp;

	if (!stack)
		return (-1);
	max = *(int*)(stack->content);
	index = 0;
	i = 0;
	tmp = stack;
	while (tmp)
	{
		if (*(int *)(tmp->content) > max)
		{
			max = *(int*)(tmp->content);
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}

void	pushitto_b(t_list **stack_a, t_list **stack_b, int min, int max)
{
	t_list	*tmp;
	int		size;
	int		index;

	size = ft_lstsize(*stack_a);
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

void	largesort(t_list **stack_a, t_list **stack_b)
{
	int chunk_size;
	int	chunks_num;
	int	i;
	int	min;
	int	max;
	int	size;
	int	maxindex;

	size = ft_lstsize(*stack_a);
	chunk_size = size / 10 + (size % 10 != 0);
	chunks_num = (size + chunk_size - 1) / chunk_size;
	i = 0;
	while (i < chunks_num)
	{
		min = i * chunk_size;
		max = min + chunk_size - 1;
		pushitto_b(stack_a, stack_b, min, max);
		i++;
	}
	while (ft_lstsize(*stack_b) > 0)
	{
		maxindex = find_max(*stack_b);
		whatsidetomove(stack_b, maxindex);
		pa(stack_a, stack_b);
	}
}
