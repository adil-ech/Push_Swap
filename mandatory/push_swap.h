/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:47:39 by adechaji          #+#    #+#             */
/*   Updated: 2024/12/29 00:21:15 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_list
{
	void			*content;
	int				index;
	struct s_list	*next;
}					t_list;

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	**ft_split(char const *s);
void	*ft_memcpy(void *dest, const void *src, size_t num);
int		iswhitespace(int c);

void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

void	sorttwo(t_list **stack);
void	sortthree(t_list **stack);
void	sortfour(t_list **stack_a, t_list **stack_b);
void	sortfive(t_list **stack_a, t_list **stack_b);
void	largerlarger(t_list **stack_a, t_list **stack_b);

int		find_min(t_list *stack);
void	whatsidetomove(t_list **stack, int index);
int		positions(t_list **stack, int	index);
int		checkifsorted(t_list **stack_a);
void	indexmepls(t_list **stack);
int		isitsortedalr(t_list **stack_a);

# endif
