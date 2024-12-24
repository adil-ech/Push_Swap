/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:44:31 by adechaji          #+#    #+#             */
/*   Updated: 2024/12/24 19:09:38 by adechaji         ###   ########.fr       */
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

void free_splited(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}

void	ultimaterror(t_list **stack, char **splited)
{
	write(1, "Error\n", 6);
	if (stack)
		free_stack(stack);
	if (splited)
		free_splited(splited);
	exit(EXIT_FAILURE);
}

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
		res = res * 10 + (str[i++] - '0');
		if (flag * res > INT_MAX || flag * res < INT_MIN )
			return (0);
	}
	return (str[i] == '\0');
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
	int		i;
	int		j;
	int		*num;
	char	**splited;

	i = 1;
	while (i < ac)
	{
		splited = ft_split(av[i]);
		if (!splited || !splited[0])
			ultimaterror(stack_a, splited);
		j = 0;
		while (splited[j])
		{
			num = malloc(sizeof(int));
			if (!num || !validnum(splited[j]))
			{
				free(num);
				ultimaterror(stack_a, splited);
			}
			*num = ft_atoi(splited[j]);
			ft_lstadd_back(stack_a, ft_lstnew(num));
			j++;
		}
		free_splited(splited);
		i++;
	}
	if (theresdupp(*stack_a))
		ultimaterror(stack_a, NULL);
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
	if (!stack_a)
		return (0);
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
	{
		// //if (ft_lstsize(stack_a) > 100)
		// 	largerlarger(&stack_a, &stack_b);
		// else
			largesort(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	return (0);
}
