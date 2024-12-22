/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:44:31 by adechaji          #+#    #+#             */
/*   Updated: 2024/12/22 23:32:41 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_stack(t_list **stack)
{
	t_list *tmp;
	
	while (*stack)
	{
		tmp = (*stack)->next;
		free((*stack)->content);
		free(*stack);
		*stack = tmp;
	}
}
// int notover(const char *str)
// {
// 	int		i;
// 	long	res;
// 	i = 0;
// 	while (str[i])
// }
int	validnum(const char *str)
{
	int		i;
	long	res;
	int		flag;

	i = 0;
	res = 0;
	flag = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res > INT_MAX)
			return (0);
		if (res < INT_MIN)
			return (0);
		i++;
	}
	res *= flag;
	if (str[i] != '\0')
		return (0);
	if (res > INT_MAX || res < INT_MIN)
		return (0);
	return(1);
}

int theresdupp(t_list *stack)
{
	t_list *tmp;
	t_list *pass;

	tmp = stack;
	while (tmp)
	{
		pass = tmp->next;
		while (pass)
		{
			if (*(int *)(tmp->content) == *(int *)(pass->content))
				return (1);
			pass = pass->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

void	parsargs(int ac, char **av, t_list **stack_a)
{
	int i;
	int	*num;

	i = 1;
	while (i < ac)
	{
		num = malloc(sizeof(int));
		if (!num)
		{
			write(1, "Error\n", 6);
			free_stack(stack_a);
			exit(EXIT_FAILURE);
		}
		*num = ft_atoi(av[i]);
		if (!validnum(av[i]))
		{
			free(num);
			write(1, "Error\n", 6);
			free_stack(stack_a);
			exit(EXIT_FAILURE);
		}
		ft_lstadd_back(stack_a, ft_lstnew(num));
		i++;
	}
	
	if (theresdupp(*stack_a))
	{
		write (1, "Error\n", 6);
		free_stack(stack_a);
		exit(EXIT_FAILURE);
	}
}

int main(int ac, char **av)
{
	t_list *stack_a;
	t_list *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return(0);
	parsargs(ac, av, &stack_a);
	if(ac - 1 <= 5)
	{
		if (ac - 1 == 2)
			sa(&stack_a);
		else if (ac - 1 == 3)
			write(1, "three_sort", 10);
			//sort_three(&stack_a, &stack_b);
		else if (ac - 1 == 4)
			write(1, "fourr_sort", 10);
			//sort_four(&stack_a, &stack_b);
		else if (ac - 1 == 5)
			write(1, "fivee_sort", 10);
			//sort_five(&stack_a, &stack_b);
	}
	else
		write(1, "large_sort", 10);
		//large_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
