/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpmepls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 01:07:47 by adechaji          #+#    #+#             */
/*   Updated: 2024/12/29 00:20:45 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int isitsortedalr(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
    if (!tmp || !tmp->next)
        return (1);
    while (tmp->next)
    {
        if (tmp->index > tmp->next->index)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int	checkifsorted(t_list **stack_a)
{
	t_list *tmp;

	tmp = *stack_a;
	while (tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	positions(t_list **stack, int	index)
{
	t_list *tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp && tmp->index != index)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void indexmepls(t_list **stack)
{
	t_list	*curtmp1;
	t_list	*tmp2;

	curtmp1 = *stack;
	while (curtmp1)
	{
		tmp2 = *stack;
		while (tmp2)
		{
			if (*(int *)curtmp1->content > *(int *)tmp2->content)
				curtmp1->index++;
			tmp2 = tmp2->next;
		}
		curtmp1 = curtmp1->next;
	}
}
// 	tmp = *stack_a;
// 	tmp2 = *stack_b;

// 	printf("==============\n");
// 	while (tmp)
// 	{
// 		printf("[value = %d] -> [index = %d]\n", *(int *)tmp->content, tmp->index);
// 		tmp = tmp->next;
// 	}
// 	printf("================= B\n");
// 	while (tmp2)
// 	{
// 		printf("[value = %d] -> [index = %d]\n", *(int *)tmp2->content, tmp2->index);
// 		tmp2 = tmp2->next;
// 	}