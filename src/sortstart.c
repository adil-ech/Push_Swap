/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortstart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:18:31 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/02 01:38:44 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sorttwo(t_list **stack)
{
	int	i;
	int	j;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	i = *(int *)((*stack)->content);
	j = *(int *)((*stack)->next->content);
	if (i > j)
		sa(stack, 1);
}

void	sortthree(t_list **stack)
{
	int	i;
	int	j;
	int	k;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	i = *(int *)((*stack)->content);
	j = *(int *)((*stack)->next->content);
	k = *(int *)((*stack)->next->next->content);
	if (i > j && j < k && i < k)
		sa(stack, 1);
	else if (i > j && j > k)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (i > j && j < k && i > k)
		ra(stack, 1);
	else if (i < j && j > k && i < k)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (i < j && j > k && i > k)
		rra(stack, 1);
}
