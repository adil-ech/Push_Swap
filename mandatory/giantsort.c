/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   giantsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:36:58 by adechaji          #+#    #+#             */
/*   Updated: 2024/12/28 22:52:18 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int getpositions(t_list *stack_b, int index)
// {
//     int i = 0;
//     while (stack_b)
//     {
//         if (stack_b->index == index)
//             break;
//         i++;
//         stack_b = stack_b->next;
//     }
//     return (i);
// }

void isitsorted(t_list **stack_a, t_list **stack_b)
{
    int i;
    int size;
	
	size = ft_lstsize(*stack_b);
    while (*stack_b)
    {
        size = ft_lstsize(*stack_b) - 1;
        i = positions(stack_b, size);
        if ((*stack_b)->index == size)
            pa(stack_a, stack_b);
        else if (i > size / 2)
            rrb(stack_b);
        else
            rb(stack_b);
    }
}

void topshandle(t_list **stack_a, t_list **stack_b, t_list **last, int qima)
{
    if (positions(stack_b, (*stack_a)->index - 1) > ft_lstsize(*stack_b) / 2)
    {
        if ((*last)->index < (*stack_b)->index || (*last)->index == qima)
        {
            pa(stack_a, stack_b);
            *last = ft_lstlast(*stack_a);
        }
        else
            rrb(stack_b);
    }
    else
    {
        if ((*last)->index < (*stack_b)->index || (*last)->index == qima)
        {
            pa(stack_a, stack_b);
            *last = ft_lstlast(*stack_a);
        }
        else
            rb(stack_b);
    }
}

void largerlarger(t_list **stack_a, t_list **stack_b)
{
    int size;
    int i = 0;
    int j;

    size = ft_lstsize(*stack_a) - 1;
    indexmepls(stack_a);
    if (size < 101)
        j = 15;
    else if (size + 1 > 100)
        j = 35;
    else
        j = 20;

    while ((*stack_a))
    {
        if ((*stack_a)->index <= i)
        {
            pb(stack_a, stack_b);
            i++;
        }
        else if ((*stack_a)->index < (i + j))
        {
            pb(stack_a, stack_b);
            rb(stack_b);
            i++;
        }
        else
            ra(stack_a);
    }
    isitsorted(stack_a, stack_b);
}
