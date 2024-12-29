/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:44:31 by adechaji          #+#    #+#             */
/*   Updated: 2024/12/29 18:18:24 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_list *stack_a;
	t_list *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return(0);
	parsargs(ac, av, &stack_a);
	if (!stack_a)
		return(0);
	indexmepls(&stack_a);
	if (isitsortedalr(&stack_a) == 1)
	{
    	free_stack(&stack_a);
   		return 0;
	}
	if(ft_lstsize(stack_a) <= 5)
	{
		if (ft_lstsize(stack_a) == 2)
			sorttwo(&stack_a);
		else if (ft_lstsize(stack_a) == 3)
			sortthree(&stack_a);
		else if (ft_lstsize(stack_a) == 4)
			sortfour(&stack_a, &stack_b);
		else if (ft_lstsize(stack_a) == 5)
			sortfive(&stack_a, &stack_b);
	}
	else 
		largerlarger(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
